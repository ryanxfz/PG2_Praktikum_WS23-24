#include "results.h"
#include "ui_results.h"

Results::Results(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Results)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
}

Results::~Results()
{
    delete ui;
}

void Results::updateTableWidget(const QString &errorType, const QString &result)
{
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    QTableWidgetItem *beschreibung = new QTableWidgetItem(result);
    QTableWidgetItem* fehlerTypItem = new QTableWidgetItem();
    fehlerTypItem->setText(errorType);
    if(errorType == "Missing Hotel"){
        fehlerTypItem->setIcon(QIcon("MissingHotel.png"));
    }else if(errorType == "Overlapping Hotel"){
        fehlerTypItem->setIcon(QIcon("overlappingHotel.png"));
    }else if(errorType == "Overlapping Cars"){
        fehlerTypItem->setIcon(QIcon("overlappingCar.png"));
    }
    ui->tableWidget->setItem(row, 0, fehlerTypItem);
    ui->tableWidget->setItem(row, 1, beschreibung);
}
