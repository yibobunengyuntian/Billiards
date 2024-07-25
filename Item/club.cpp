#include "club.h"

Club::Club()
{
    m_type = club;

    QPainterPath path1, path2;
    path1.addEllipse(QPointF(0, 0), m_headWidth/2.6/2, m_headWidth/2.6/2);
    m_headPath.addRect(0, -m_headWidth/2/2.6, m_headWidth/2/2.6, m_headWidth/2/2.6);
    m_headPath.addPath(path1 - m_headPath);
    QPolygonF polygon(QVector<QPointF>()
                      << QPointF(m_headWidth/2/2.6, -m_headWidth/2/2.6)
                      << QPointF((m_length - 200)/2.6, -m_headWidth/2/2.6 - 2)
                      << QPointF((m_length - 200)/2.6, m_headWidth/2/2.6 + 2)
                      << QPointF(m_headWidth/2/2.6, m_headWidth/2/2.6));
    m_polePath.addPolygon(polygon);
    polygon.clear();
    polygon.append(QVector<QPointF>()
                   << QPointF((m_length - 200)/2.6, -m_headWidth/2/2.6 - 2)
                   << QPointF(m_length/2.6, -m_headWidth/2/2.6 - 3)
                   << QPointF(m_length/2.6, m_headWidth/2/2.6 + 3)
                   << QPointF((m_length - 200)/2.6, m_headWidth/2/2.6 + 2));
    path2.addEllipse(QPointF(m_length/2.6, 0),m_headWidth/2.6/2 + 3, m_headWidth/2.6/2 + 3);
    m_gripPath.addPolygon(polygon);
    m_gripPath.addPath(path2 - m_gripPath);
}

Club::~Club()
{

}

void Club::setDir(const QVector2D &dir)
{
    m_dir = dir;
    double angle = atan2(-m_dir.y(), -m_dir.x());
    double degree = angle * 180 / M_PI;
    this->setRotation(degree);
}

QVector2D Club::dir()
{
    return m_dir;
}

float Club::length()
{
    return m_length;
}

QRectF Club::boundingRect() const
{
    QPainterPath path = m_headPath + m_polePath + m_gripPath;
    return path.boundingRect();
}

QPainterPath Club::shape() const
{
    QPainterPath path = m_headPath + m_polePath + m_gripPath;
    return path;
}


void Club::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setRenderHint(QPainter::Antialiasing,true);
    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor(Qt::white).light(30));
    painter->drawPath(m_headPath);
    painter->setBrush(QColor(Qt::white).light(70));
    painter->drawPath(m_polePath);
    painter->setBrush(QColor(150, 75, 0).light(70));
    painter->drawPath(m_gripPath);
}
