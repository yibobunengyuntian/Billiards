
#include "graphicsview.h"
#include <QMouseEvent>
#include <QDebug>
#include <QVector2D>

#include "baseoperator.h"
#include "defualtoperator.h"

GraphicsView::GraphicsView(QWidget *parent)
    : QGraphicsView{parent}
{
    initialize();
}

GraphicsView::~GraphicsView()
{

}

void GraphicsView::createScene()
{
    if(this->scene() != nullptr){
        return;
    }
    auto pScene = new QGraphicsScene(this);
    this->setScene(pScene);
}

void GraphicsView::setOperatorObj(QSharedPointer<BaseOperator> op)
{
    m_pOperator = op;
}

QSharedPointer<BaseOperator> GraphicsView::operatorObj()
{
    return m_pOperator;
}

void GraphicsView::initialize()
{
    this->setMouseTracking(true);
    this->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    auto op = QSharedPointer<DefualtOperator>(new DefualtOperator(this));
    this->setOperatorObj(op);
    startTimer(0);
}

void GraphicsView::mousePressEvent(QMouseEvent *event)
{
    m_isPressed = true;
    QPoint pos = event->pos();
    m_pOperator->mousePressEvent(event,this->mapToScene(pos));
}

void GraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();
    if(m_isPressed){
        m_pOperator->mouseMoveEvent(event,this->mapToScene(pos));
    }else{
        m_pOperator->mouseHoverEvent(event,this->mapToScene(pos));
    }
}

void GraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();
    m_isPressed = false;
    m_pOperator->mouseReleaseEvent(event,this->mapToScene(pos));
}

void GraphicsView::mouseDoubleClickEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();
    m_pOperator->mouseDoubleClickEvent(event,this->mapToScene(pos));
}

void GraphicsView::wheelEvent(QWheelEvent *event)
{
    QPointF pos = this->mapToScene(event->pos());
    m_pOperator->wheelEvent(event,pos);
}

void GraphicsView::keyPressEvent(QKeyEvent *event)
{
    m_pOperator->keyPressEvent(event);
}

void GraphicsView::keyReleaseEvent(QKeyEvent *event)
{
    m_pOperator->keyReleaseEvent(event);
}

void GraphicsView::resizeEvent(QResizeEvent *event)
{
    //    moveScene(QPoint(0,0));
    m_pOperator->resizeEvent(event);
    QGraphicsView::resizeEvent(event);
}

void GraphicsView::timerEvent(QTimerEvent *event)
{
    m_pOperator->timerEvent(event);
}

bool GraphicsView::event(QEvent *event)
{
    switch (event->type()) {
    case QEvent::Leave:
    {
        if(!m_pOperator.isNull()){
            m_pOperator->graphicsViewLeaveEvent();
        }
    }
        break;
    default:
        break;
    }
    return QGraphicsView::event(event);
}

