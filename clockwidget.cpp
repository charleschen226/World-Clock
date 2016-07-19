#include "clockwidget.h"
#include <QtWidgets>
#include <QSizePolicy>

ClockWidget::ClockWidget(int city, int timeZone, QWidget *parent)
    : QWidget(parent)
    , m_timeZone(timeZone)
    , m_city(city)
{
    setupCities();
    setupWidget();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);

    setMinimumSize(200, 250);
}

ClockWidget::~ClockWidget()
{

}

void ClockWidget::setupCities()
{
    m_cities << "NEW  YORK" << "LONDON" << "BEIJING" << "TOKYO";
}

void ClockWidget::setupWidget()
{
    //setup label
    QLabel *city = new QLabel(m_cities.at(m_city), this);
    QFont font("Calibri", 12, QFont::Black);
    city->setFont(font);
    city->move(73, 230);
    city->show();

    //setup digital clock
    QSplitter *splitter = new QSplitter(Qt::Horizontal, this);
    DigitalClock *digitalClock = new DigitalClock(m_timeZone, splitter);
    splitter->move(65, 0);
}

void ClockWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    //get time difference
    QTime time = QTime::currentTime();
    int hour = (time.hour() + m_timeZone) > 0 ? (time.hour() + m_timeZone) : (time.hour() + m_timeZone) + 24;

    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.save();

    //draw the clock
    if (6 < hour && 19 > hour) {
        painter.drawPixmap(0, 20, QPixmap(":/content/clock.png"));
         painter.restore();
    } else {
        painter.drawPixmap(0, 20, QPixmap(":/content/clock-night.png"));
        painter.restore();
    }

    painter.setPen(Qt::NoPen);
    painter.translate(100, 120);
    painter.save();

    //draw hour hand
    painter.rotate(180 + 30.0 * ((hour  + time.minute() / 60.0)));
    painter.drawPixmap(-8, -8, QPixmap(":/content/hour.png"));
    painter.restore();

    //draw minute hand
    painter.save();
    painter.rotate(180 + 6.0 * (time.minute() + time.second() / 60.0));
    painter.drawPixmap(-5, -5, QPixmap(":/content/minute.png"));
    painter.restore();

    //draw second hand
    painter.save();
    painter.rotate(180 + time.second() * 6);
    painter.drawPixmap(-1, 0, QPixmap(":/content/second.png"));
    painter.restore();

    //draw center
    painter.drawPixmap(-11, -11, QPixmap(":/content/center.png"));
}
