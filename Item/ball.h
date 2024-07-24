#ifndef BALL_H
#define BALL_H

#include <QVector2D>
#include "itembase.h"

class Ball: public ItemBase
{
public:
    enum BallType
    {
        red,
        green,
        coffee,
        yellow,
        blue,
        pink,
        black,
        white
    };
public:
    Ball(BallType ballType = red);
    void setBallType(BallType ballType, bool isChangeColor = true);
    BallType ballType();
    void setColor(QColor color);
    void setSpeed(const float &speed);
    void addSpeedVector(const QVector2D &speed);
    void setMoveDir(const QVector2D &dir);
    void setR(const float &r);
    float r();
    QVector2D moveDir();
    float speed();
    void move(float fps);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    float m_r = 10;
    QColor m_color = QColor(Qt::red);
    QVector2D m_moveDir = QVector2D(0, 1);
    float m_speed = 0;
    float m_lossSpeed = 0;
    BallType m_ballType = red;
};

#endif // BALL_H
