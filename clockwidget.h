#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H

#include <QWidget>
#include <QLabel>
#include "digitalclock.h"

namespace TimeZone{
        enum enumTimeZone {NEWYORK = -12, LONDON = -8, BEIJING = 0, TOKYO = 1};
}
namespace City{
        enum enumCity     {NEWYORK, LONDON, BEIJING, TOKYO};
}

class ClockWidget : public QWidget
{
    Q_OBJECT

public:
    ClockWidget(int city, int timeZone, QWidget *parent = 0);
    ~ClockWidget();

public:
    void setupWidget();
    void setupCities();
    void paintEvent(QPaintEvent *event);

private:
    int m_timeZone;
    int m_city;

    QLabel *m_clock;
    QStringList m_cities;
};

#endif // CLOCKWIDGET_H
