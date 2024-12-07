#ifndef CHECK_H
#define CHECK_H

#include <QObject>
#include <QString>
#include <memory>
#include "TravelAgency.h"
#include <QMessageBox>
#include <vector>

class Check : public QObject
{
    Q_OBJECT
public:

    Check(std::shared_ptr<TravelAgency> travelAgency);
    bool checkTravelDisjunct(const QString& message);
    bool operator()(){
        QString overlapmessage;
        bool result = checkTravelDisjunct(overlapmessage);

        if(!result){
            QMessageBox errorBox;
            errorBox.setText("Save success!, There is no overlap");
            errorBox.exec();
            return false;
        }

        return true;
    }
    void checkNoMissingHotels();
    void checkNoOverlappingHotels();
    void checkNoOverlappingRentalCars();
public slots:

signals:
    void bookingupdated();
    void sendCheckResult(const QString &errorType, const QString message);
private:
    std::shared_ptr<TravelAgency> travelAgency;

    bool checkOverlap(std::shared_ptr<Customer> customer, std::vector<std::shared_ptr<Travel>> travelList, QString message);
    bool isOverlap(std::shared_ptr<Travel> travel1, std::shared_ptr<Travel> travel2);

};

#endif // CHECK_H
