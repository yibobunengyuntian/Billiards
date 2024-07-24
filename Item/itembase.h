#ifndef ITEMBASE_H
#define ITEMBASE_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>
#include <QList>
#include <QtMath>

class ItemBase :public QGraphicsItem
{
public:
    enum itemType
    {
        ball = 1,    //球
        cushion = 2, //桌子
        club = 3     //球杆
    };

    ItemBase();
    itemType itemtype();

public:

    virtual QRectF boundingRect() const override = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override = 0;

protected:
    itemType m_type;
};

#endif // ITEMBASE_H
