#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QLCDNumber>

class DigitalClock : public QLCDNumber
{
    Q_OBJECT
public:
    DigitalClock(int timeZone, QWidget *parent = 0);

private slots:
    void showTime();

private:
    int m_timeZone;
};

#endif // DIGITALCLOCK_H
