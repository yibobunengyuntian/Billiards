#ifndef CLUB_H
#define CLUB_H
#include <QDebug>
#include "itembase.h"
#include "ball.h"

class Club: public ItemBase
{
public:
    Club();
    ~Club();
    void setDir(const QVector2D &dir);
    QVector2D dir();
    float length();

protected:
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QVector2D m_dir = QVector2D(-1, 0);
    float m_length = 1450;
    float m_headWidth = 9;

    QPainterPath m_headPath;                       //皮头
    QPainterPath m_polePath;                       //主杆
    QPainterPath m_gripPath;                       //把手
};

#endif // CLUB_H
