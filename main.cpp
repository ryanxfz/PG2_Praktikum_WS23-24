#include "travelagencyui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TravelAgencyUI w;
    w.show();
    return a.exec();
}
