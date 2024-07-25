
#include "baseoperator.h"

BaseOperator::BaseOperator(GraphicsView *parent)
    : QObject{parent}
{
    m_pGView = parent;
}

BaseOperator::~BaseOperator()
{

}

GraphicsView *BaseOperator::view()
{
    return m_pGView;
}

QGraphicsScene *BaseOperator::scene()
{
    return this->view()->scene();
}

void BaseOperator::mousePressEvent(QMouseEvent *event, QPointF scenePoint)
{
    Q_UNUSED(event)
    Q_UNUSED(scenePoint)
}

void BaseOperator::mouseMoveEvent(QMouseEvent *event, QPointF scenePoint)
{
    Q_UNUSED(event)
    Q_UNUSED(scenePoint)
}

void BaseOperator::mouseHoverEvent(QMouseEvent *event, QPointF scenePoint)
{
    Q_UNUSED(event)
    Q_UNUSED(scenePoint)
}

void BaseOperator::mouseReleaseEvent(QMouseEvent *event, QPointF scenePoint)
{
    Q_UNUSED(event)
    Q_UNUSED(scenePoint)
}

void BaseOperator::mouseDoubleClickEvent(QMouseEvent *event, QPointF scenePoint)
{
    Q_UNUSED(scenePoint)
    Q_UNUSED(event)
}

void BaseOperator::wheelEvent(QWheelEvent *event, QPointF scenePoint)
{
    Q_UNUSED(event)
    Q_UNUSED(scenePoint)
}

void BaseOperator::keyPressEvent(QKeyEvent *event)
{
    Q_UNUSED(event)
}

void BaseOperator::keyReleaseEvent(QKeyEvent *event)
{
    Q_UNUSED(event)
}

void BaseOperator::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
}

void BaseOperator::graphicsViewLeaveEvent()
{

}

void BaseOperator::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event)
}

