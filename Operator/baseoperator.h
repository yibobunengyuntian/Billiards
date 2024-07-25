
#ifndef BASEOPERATOR_H
#define BASEOPERATOR_H


#include <QObject>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWheelEvent>

#include "graphicsview.h"

class BaseOperator : public QObject
{
    Q_OBJECT
public:
    explicit BaseOperator(GraphicsView *parent);
    ~BaseOperator();

    GraphicsView *view();
    QGraphicsScene *scene();

    virtual void mousePressEvent(QMouseEvent *event, QPointF scenePoint);
    virtual void mouseMoveEvent(QMouseEvent *event, QPointF scenePoint);
    virtual void mouseHoverEvent(QMouseEvent *event, QPointF scenePoint);
    virtual void mouseReleaseEvent(QMouseEvent *event, QPointF scenePoint);
    virtual void mouseDoubleClickEvent(QMouseEvent *event, QPointF scenePoint);
    virtual void wheelEvent(QWheelEvent *event, QPointF scenePoint);

    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);

    virtual void resizeEvent(QResizeEvent *event);

    virtual void graphicsViewLeaveEvent();
    void timerEvent(QTimerEvent *event) override;
protected:
    GraphicsView *m_pGView               = nullptr;
};

#endif // BASEOPERATOR_H
