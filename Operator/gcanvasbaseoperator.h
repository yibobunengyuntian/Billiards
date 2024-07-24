
#ifndef GCANVASBASEOPERATOR_H
#define GCANVASBASEOPERATOR_H


#include <QObject>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWheelEvent>

#include "gcanvasview.h"

class GCanvasView;
class GCanvasBaseOperator : public QObject
{
    Q_OBJECT
public:
    explicit GCanvasBaseOperator(GCanvasView *parent);
    ~GCanvasBaseOperator();

    GCanvasView *view();
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
    GCanvasView *m_pGView               = nullptr;
};

#endif // GCANVASBASEOPERATOR_H
