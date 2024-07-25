#ifndef CUSHION_H
#define CUSHION_H

#include <QDebug>
#include "itembase.h"
#include "ball.h"

class Cushion: public ItemBase
{
public:
    Cushion();
    ~Cushion();

    //与球的碰撞处理（包括进球）返回true表示进球
    bool collisionWithBall(Ball *ball, float fps);
public:
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
public:
    QPointF m_outRect = QPointF(3820, 2035);          //球桌外延尺寸
    QPointF m_inRect = QPoint(3569, 1778);            //球桌内沿尺寸
    float m_pocket_r = 45;                            //袋口半径
private:
    QPainterPath m_ellipsePath;                       //库边圆角
    QPainterPath m_cushionPath;                       //库边
    QPainterPath m_pointPath;                         //辅助点、线
    QPainterPath m_pocketPath;                        //袋口

    QVector<QPointF> m_pocketPoints;                  //袋口原点， 做碰撞检测时使用
    QVector<QPointF> m_filletedCornerPoints;          //库边圆角， 做碰撞检测时使用
};

#endif // CUSHION_H
