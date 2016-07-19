#include "clockwidget.h"
#include "digitalclock.h"
#include <QApplication>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget mainWidget;
    mainWidget.setStyleSheet("background-color:#404040;");

    QHBoxLayout *horizontalLayout = new QHBoxLayout(&mainWidget);
    horizontalLayout->addWidget(new ClockWidget(City::LONDON, TimeZone::LONDON));
    horizontalLayout->addWidget(new ClockWidget(City::BEIJING, TimeZone::BEIJING));
    horizontalLayout->addWidget(new ClockWidget(City::NEWYORK, TimeZone::NEWYORK));
    horizontalLayout->addWidget(new ClockWidget(City::TOKYO, TimeZone::TOKYO));

    mainWidget.setWindowTitle("World Clock");
    mainWidget.resize(900, 250);
    mainWidget.show();

    return a.exec();
}
