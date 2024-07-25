#ifndef BALL_H
#define BALL_H

#include <QVector2D>
#include "itembase.h"

class Ball: public ItemBase
{
public:
    //将球按颜色分类
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

    //设置球的类型
    void setBallType(BallType ballType, bool isChangeColor = true);
    BallType ballType();

    //设置颜色
    void setColor(QColor color);

    //设置移动速度（标量）
    void setSpeed(const float &speed);
    float speed();

    //增加速度（矢量， 因碰撞会改变移动方向）
    void addSpeedVector(const QVector2D &speed);

    //设置移动方向
    void setMoveDir(const QVector2D &dir);
    QVector2D moveDir();

    //设置球体半径
    void setR(const float &r);
    float r();

    //每帧根据帧率做减速直线运动计算
    void move(float fps);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    float m_r = 10;                         //球体半径
    float m_speed = 0;                      //移动速度
    float m_lossSpeed = 0;                  //每帧速度减少量
    QColor m_color = QColor(Qt::red);       //球体颜色
    QVector2D m_moveDir = QVector2D(0, 1);  //移动方向
    BallType m_ballType = red;              //所属类型
};

#endif // BALL_H
