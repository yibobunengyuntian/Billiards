
#include "gcanvasview.h"
#include <QMouseEvent>
#include <QDebug>
#include <QVector2D>

#include "gcanvasbaseoperator.h"
#include "gcanvasdefualtoperator.h"

GCanvasView::GCanvasView(QWidget *parent)
    : QGraphicsView{parent}
{
    initialize();
}

GCanvasView::~GCanvasView()
{

}

void GCanvasView::createScene()
{
    if(this->scene() != nullptr){
        return;
    }
    auto pScene = new QGraphicsScene(this);
    this->setScene(pScene);
}

void GCanvasView::setOperatorObj(QSharedPointer<GCanvasBaseOperator> op)
{
    m_pOperator = op;
}

QSharedPointer<GCanvasBaseOperator> GCanvasView::operatorObj()
{
    return m_pOperator;
}

void GCanvasView::initialize()
{
    this->setMouseTracking(true);
    this->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    auto op = QSharedPointer<GCanvasDefualtOperator>(new GCanvasDefualtOperator(this));
    this->setOperatorObj(op);
    startTimer(0);
}

void GCanvasView::mousePressEvent(QMouseEvent *event)
{
    m_isPressed = true;
    QPoint pos = event->pos();
    m_pOperator->mousePressEvent(event,this->mapToScene(pos));
}

void GCanvasView::mouseMoveEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();
    if(m_isPressed){
        m_pOperator->mouseMoveEvent(event,this->mapToScene(pos));
    }else{
        m_pOperator->mouseHoverEvent(event,this->mapToScene(pos));
    }
}

void GCanvasView::mouseReleaseEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();
    m_isPressed = false;
    m_pOperator->mouseReleaseEvent(event,this->mapToScene(pos));
}

void GCanvasView::mouseDoubleClickEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();
    m_pOperator->mouseDoubleClickEvent(event,this->mapToScene(pos));
}

void GCanvasView::wheelEvent(QWheelEvent *event)
{
    QPointF pos = this->mapToScene(event->pos());
    m_pOperator->wheelEvent(event,pos);
}

void GCanvasView::keyPressEvent(QKeyEvent *event)
{
    m_pOperator->keyPressEvent(event);
}

void GCanvasView::keyReleaseEvent(QKeyEvent *event)
{
    m_pOperator->keyReleaseEvent(event);
}

void GCanvasView::resizeEvent(QResizeEvent *event)
{
    //    moveScene(QPoint(0,0));
    m_pOperator->resizeEvent(event);
    QGraphicsView::resizeEvent(event);
}

void GCanvasView::timerEvent(QTimerEvent *event)
{
    m_pOperator->timerEvent(event);
}

bool GCanvasView::event(QEvent *event)
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

