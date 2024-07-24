#include "ball.h"

#include <QDebug>

Ball::Ball(BallType ballType)
{
    setBallType(ballType);
    m_type = ball;
}

void Ball::setBallType(Ball::BallType ballType, bool isChangeColor)
{
    m_ballType = ballType;
    if(isChangeColor)
    {
        switch (m_ballType) {
        case green:
            m_color = Qt::green;
            break;
        case coffee:
            m_color = QColor(150, 75, 0);
            break;
        case yellow:
            m_color = QColor(Qt::yellow).light(80);
            break;
        case blue:
            m_color = Qt::blue;
            break;
        case pink:
            m_color = QColor(255, 105, 180);
            break;
        case black:
            m_color = Qt::black;
            break;
        case white:
            m_color = QColor(Qt::white).light(80);
            break;
        default:
            m_color = Qt::red;
            break;
        }
    }
}

Ball::BallType Ball::ballType()
{
    return m_ballType;
}

void Ball::setColor(QColor color)
{
    m_color = color;
}

void Ball::setSpeed(const float &speed)
{
    m_speed = speed;
}

void Ball::addSpeedVector(const QVector2D &speed)
{
    QVector2D temp = m_moveDir*m_speed + speed;
    m_speed = temp.length();
    m_moveDir = temp.normalized();
}

void Ball::setMoveDir(const QVector2D &dir)
{
    m_moveDir = dir.normalized();
}

void Ball::setR(const float &r)
{
    m_r = r;
}

float Ball::r()
{
    return m_r;
}

QVector2D Ball::moveDir()
{
    return m_moveDir;
}

float Ball::speed()
{
    return m_speed;
}

QRectF Ball::boundingRect() const
{
    qreal adjust = 2;
    return QRectF( -m_r - adjust, -m_r - adjust, 2*m_r + adjust, 2*m_r + adjust);
}

QPainterPath Ball::shape() const
{
    QPainterPath path;
    path.addEllipse(-m_r, -m_r, 2*m_r, 2*m_r);
    return path;
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setRenderHint(QPainter::Antialiasing,true);
    painter->setPen(Qt::NoPen);
    QColor color(Qt::black);
    color.setAlpha(90);
    painter->setBrush(color);
    painter->drawEllipse(-7, -7, 2*m_r, 2*m_r);

    QRadialGradient gradient(-3.0/10*m_r, -3.0/10*m_r, m_r/2);
    gradient.setColorAt(0, QColor(Qt::white).light(200));
    gradient.setColorAt(1, m_color);
    painter->setBrush(gradient);

//    painter->setPen(QPen(Qt::black, 0));
    painter->drawEllipse(-m_r, -m_r, 2*m_r, 2*m_r);
}

void Ball::move(float fps)
{
    if(isnan(fps))
        return;
    if(m_speed < 1e-6)
    {
        m_speed = 0;
    }
    if(m_speed > 0)
    {
        setPos(pos() + m_speed/fps*m_moveDir.normalized().toPointF());
        m_lossSpeed = (m_speed > 200)?0.4*m_speed:40;
        m_speed -= m_lossSpeed/fps;
    }
}
