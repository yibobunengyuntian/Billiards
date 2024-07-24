
#include "gcanvasbaseoperator.h"

GCanvasBaseOperator::GCanvasBaseOperator(GCanvasView *parent)
    : QObject{parent}
{
    m_pGView = parent;
}

GCanvasBaseOperator::~GCanvasBaseOperator()
{

}

GCanvasView *GCanvasBaseOperator::view()
{
    return m_pGView;
}

QGraphicsScene *GCanvasBaseOperator::scene()
{
    return this->view()->scene();
}

void GCanvasBaseOperator::mousePressEvent(QMouseEvent *event, QPointF scenePoint)
{
    Q_UNUSED(event)
    Q_UNUSED(scenePoint)
}

void GCanvasBaseOperator::mouseMoveEvent(QMouseEvent *event, QPointF scenePoint)
{
    Q_UNUSED(event)
    Q_UNUSED(scenePoint)
}

void GCanvasBaseOperator::mouseHoverEvent(QMouseEvent *event, QPointF scenePoint)
{
    Q_UNUSED(event)
    Q_UNUSED(scenePoint)
}

void GCanvasBaseOperator::mouseReleaseEvent(QMouseEvent *event, QPointF scenePoint)
{
    Q_UNUSED(event)
    Q_UNUSED(scenePoint)
}

void GCanvasBaseOperator::mouseDoubleClickEvent(QMouseEvent *event, QPointF scenePoint)
{
    Q_UNUSED(scenePoint)
    Q_UNUSED(event)
}

void GCanvasBaseOperator::wheelEvent(QWheelEvent *event, QPointF scenePoint)
{
    Q_UNUSED(event)
    Q_UNUSED(scenePoint)
}

void GCanvasBaseOperator::keyPressEvent(QKeyEvent *event)
{
    Q_UNUSED(event)
}

void GCanvasBaseOperator::keyReleaseEvent(QKeyEvent *event)
{
    Q_UNUSED(event)
}

void GCanvasBaseOperator::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
}

void GCanvasBaseOperator::graphicsViewLeaveEvent()
{

}

void GCanvasBaseOperator::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event)
}

