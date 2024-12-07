#include "check.h"
#include "TravelAgency.h"
#include <vector>
#include <QMessageBox>
#include "customer.h"
#include "hotelbooking.h"
#include "RentalCarReservation.h"

Check::Check(std::shared_ptr<TravelAgency> travelAgency):
    travelAgency{travelAgency}
{}

bool Check::checkTravelDisjunct(const QString &message)
{
    std::vector<std::shared_ptr<Customer>> allcustomers = travelAgency->getAllCustomers();
    for(unsigned int i = 0; i < allcustomers.size(); i++){
        if(checkOverlap(allcustomers.at(i), allcustomers.at(i)->getTravelList(), message)){
            return false;
        }
    }
    return true;
}

bool Check::checkOverlap(std::shared_ptr<Customer> customer, std::vector<std::shared_ptr<Travel> > travelList, QString message)
{
    for(size_t i = 0; i < travelList.size()-1; i++){
        for(size_t j = 0; j < travelList.size(); j++){
            bool overlap = isOverlap(travelList.at(i), travelList.at(j));

            if(overlap){
                QString firstName = QString::fromStdString(customer->getFirstName());
                QString lastName = QString::fromStdString(customer->getLastName());
                QString travelId1 = QString::number(travelList.at(i)->getId());
                QString travelId2 = QString::number(travelList.at(j)->getId());

                message = QString("Kunde: %1 %2 uberlappung in Reise: %3 und Reise %4").arg(firstName, lastName, travelId1, travelId2);

                return true;
            }
        }
    }
    return false;
}

bool Check::isOverlap(std::shared_ptr<Travel> travel1, std::shared_ptr<Travel> travel2)
{
    int fromDate1 = travel1->getFromDate();
    int toDate1 = travel1->getToDate();
    int fromDate2 = travel2->getFromDate();
    int toDate2 = travel2->getToDate();
    return (fromDate1 < toDate2 || toDate1 > fromDate2) && !(fromDate1 == fromDate2 && toDate1 == toDate2);
    /*
    const auto& bookings1 = travel1->getTravelBookings();
    const auto& bookings2 = travel2->getTravelBookings();

    for(const auto& booking1 : bookings1){
        for (const auto& booking2 : bookings2){
            QDate fromDate1 = QDate::fromString(QString::fromStdString(booking1->getFromDate()), "yyyyMMdd");
            QDate toDate1 = QDate::fromString(QString::fromStdString(booking1->getToDate()), "yyyyMMdd");
            QDate fromDate2 = QDate::fromString(QString::fromStdString(booking2->getFromDate()), "yyyyMMdd");
            QDate toDate2 = QDate::fromString(QString::fromStdString(booking2->getToDate()), "yyyyMMdd");

            if (toDate1 >= fromDate2 && fromDate1 <= toDate2) {
                return true; // Overlapping dates found
            }
        }
    }
    return false;
*/
}

void Check::checkNoMissingHotels()
{
    QString errorType = "Missing Hotel";
    QString message;

    for (const auto& travel : travelAgency->getAllTravels()) {
        std::vector<VertexData> data;
        travel->sortGraph(data); // Sorts bookings by their topological order

        // Initialize lastToDate as an empty string
        QString lastToDate;

        for (const VertexData& vertex : data) {
            auto currentBooking = vertex.booking;

            // Only consider hotel bookings for gaps
            if (std::dynamic_pointer_cast<HotelBooking>(currentBooking)) {
                QString currentFromDate = QString::fromStdString(currentBooking->getFromDate());

                // If lastToDate is not empty and currentFromDate is not the same day, we have a gap
                if (!lastToDate.isEmpty() && lastToDate != currentFromDate) {
                    message = "Gap found in travelID " + QString::number(travel->getId())
                              + " between bookings ending on " + lastToDate
                              + " and starting on " + currentFromDate + ".\n";
                    // Emit the message for this specific gap
                    emit sendCheckResult(errorType, message);
                }

                // Update lastToDate to the current booking's toDate
                lastToDate = QString::fromStdString(currentBooking->getToDate());
            }
        }
    }

    if (!message.isEmpty()) {
        qDebug() << message;
    } else {
        qDebug() << "No missing hotel bookings in any travels.";
    }
}

void Check::checkNoOverlappingHotels(){
    QString errorType = "Overlapping Hotel";
    QString message;

    for (const auto& travel : travelAgency->getAllTravels()) {
        std::vector<VertexData> data;
        travel->sortGraph(data); // Sorts bookings by their topological order

        for (size_t i = 0; i < data.size() - 1; ++i) {
            auto currentBooking = data[i].booking;
            auto nextBooking = data[i + 1].booking;

            // Only consider hotel bookings for overlaps
            if (std::dynamic_pointer_cast<HotelBooking>(currentBooking) && std::dynamic_pointer_cast<HotelBooking>(nextBooking)) {
                QDate toDateCurrent = QDate::fromString(QString::fromStdString(currentBooking->getToDate()), "yyyyMMdd");
                QDate fromDateNext = QDate::fromString(QString::fromStdString(nextBooking->getFromDate()), "yyyyMMdd");

                // If the toDate of the current booking is after the fromDate of the next, we have an overlap
                if (toDateCurrent > fromDateNext) {
                    message = "Overlap found in travelID " + QString::number(travel->getId())
                              + " between hotel bookings ending on " + toDateCurrent.toString("yyyyMMdd")
                              + " and starting on " + fromDateNext.toString("yyyyMMdd") + ".\n";
                    // Emit the message for this specific overlap
                    emit sendCheckResult(errorType, message);
                }
            }
        }
    }

    if (!message.isEmpty()) {
        qDebug() << message;
    } else {
        qDebug() << "No overlapping hotel bookings in any travels.";
    }
}

void Check::checkNoOverlappingRentalCars(){
    QString errorType = "Overlapping Cars";
    QString message;

    for (const auto& travel : travelAgency->getAllTravels()) {
        std::vector<VertexData> data;
        travel->sortGraph(data); // Assuming this method sorts the bookings and fills 'data'

        std::shared_ptr<Booking> lastCarBooking = nullptr;

        for (const VertexData& vertex : data) {
            auto currentBooking = vertex.booking;

            // Only consider rental car bookings for overlap
            if (std::dynamic_pointer_cast<RentalCarReservation>(currentBooking)) {
                if (lastCarBooking) {
                    QDate toDateLast = QDate::fromString(QString::fromStdString(lastCarBooking->getToDate()), "yyyyMMdd");
                    QDate fromDateCurrent = QDate::fromString(QString::fromStdString(currentBooking->getFromDate()), "yyyyMMdd");

                    // If the end date of the last car booking is later than the start date of the current, it's an overlap
                    if (toDateLast > fromDateCurrent) {
                        message = "Overlap found in travelID " + QString::number(travel->getId())
                                  + " between car rental bookings ending on " + toDateLast.toString("yyyyMMdd")
                                  + " and starting on " + fromDateCurrent.toString("yyyyMMdd") + ".\n";
                        // Emit the message for this specific overlap
                        emit sendCheckResult(errorType, message);
                        break; // Since we found an overlap, we break out of the loop
                    }
                }
                lastCarBooking = currentBooking; // Update the last car booking
            }
        }
    }

    if (!message.isEmpty()) {
        qDebug() << message;
    } else {
        qDebug() << "No overlapping car rentals in any travels.";
    }
}

