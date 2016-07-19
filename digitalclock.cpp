#include "digitalclock.h"
#include <QtWidgets>
#include <QDebug>

DigitalClock::DigitalClock(int timeZone, QWidget *parent)
    : QLCDNumber(parent)
    , m_timeZone(timeZone)
{
    //set style
    setFrameShape(QFrame::NoFrame);
    setSegmentStyle(QLCDNumber::Flat);
    setStyleSheet("color: white");

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);

    showTime();
    setMaximumSize(100, 30);
}

void DigitalClock::showTime()
{
    QTime time = QTime::currentTime();
    int hour = (time.hour() + m_timeZone) > 0 ? (time.hour() + m_timeZone) : (time.hour() + m_timeZone) + 24;

    //set time differece
    QString text = time.toString("hh:mm");
    text.replace(0, 2, QString::number(hour));

    if (text.size() == 4)
        text.insert(0, "0");

    if ((time.second() % 2) == 0)
        text[2] = ' ';

    display(text);
}
