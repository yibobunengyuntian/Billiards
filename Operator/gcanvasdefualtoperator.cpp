#include "gcanvasdefualtoperator.h"


GCanvasDefualtOperator::GCanvasDefualtOperator(GCanvasView *parent)
    : GCanvasBaseOperator{parent}
{
    initialize();
}

GCanvasDefualtOperator::~GCanvasDefualtOperator()
{

}

void GCanvasDefualtOperator::mousePressEvent(QMouseEvent *event, QPointF scenePoint)
{
    if(m_pLine == nullptr)
    {
        m_pLine = new QGraphicsLineItem;
    }
    if(event->button() == Qt::RightButton)
    {
        return;
    }
    if(m_pWhiteBall == nullptr)
    {
        return;
    }
    if(m_isBallsMove)
    {
        return;
    }
    Cushion *pCushion;
    QList<Ball*> balls;
    for(auto item:scene()->items())
    {
        if(static_cast<ItemBase*>(item)->itemtype() == ItemBase::ball)
        {
            balls.append(static_cast<Ball*>(item));
        }
        else if(static_cast<ItemBase*>(item)->itemtype() == ItemBase::cushion)
        {
            pCushion = static_cast<Cushion*>(item);
        }
    }
    if(!scene()->items().contains(m_pWhiteBall))
    {
        if(!QGraphicsEllipseItem(pCushion->m_inRect.x()/2/2.6 - pCushion->m_inRect.x()*737/3569/2.6 - pCushion->m_inRect.x()*292/3569/2.6,
                             -pCushion->m_inRect.x()*292/3569/2.6,
                             pCushion->m_inRect.x()*292/3569/2.6*2,
                             pCushion->m_inRect.x()*292/3569/2.6*2).shape().toFillPolygon().containsPoint(scenePoint,Qt::WindingFill)
            || scenePoint.x() < pCushion->m_inRect.x()/2/2.6 - pCushion->m_inRect.x()*737/3569/2.6)
        {
            return;
        }
        for(auto ball:balls)
        {
            if(QVector2D(ball->pos() - scenePoint).length() < 2*ball->r())
            {
                return;
            }
        }
        m_pWhiteBall->setPos(scenePoint);
        if(!scene()->items().contains(m_pWhiteBall))
        {
            scene()->addItem(m_pWhiteBall);
        }
    }
    else
    {
        if(m_isClubMove)
        {
            return;
        }
        if(QVector2D(m_pWhiteBall->pos() - scenePoint).length() < m_pWhiteBall->r() + 1e-6)
        {
            if(scene()->items().contains(m_pLine))
            {
                scene()->removeItem(m_pLine);
            }
            if(scene()->items().contains(m_pClub))
            {
                scene()->removeItem(m_pClub);
            }
            return;
        }
        QPointF pos = scenePoint;
        if(QVector2D(pos - m_pWhiteBall->pos()).length() > 500)
        {
            pos = QVector2D(QVector2D(m_pWhiteBall->pos()) + QVector2D(pos - m_pWhiteBall->pos()).normalized() * 500).toPointF();
        }
        QLineF line = QLineF(pos,m_pWhiteBall->pos());
        line.setLength(line.length() + 50);
        m_pLine->setLine(line);
        if(!scene()->items().contains(m_pLine))
        {
            scene()->addItem(m_pLine);
        }
        m_pClub->setPos(pos);
        m_pClub->setDir(QVector2D(m_pWhiteBall->pos() - pos));
    }
}

void GCanvasDefualtOperator::mouseMoveEvent(QMouseEvent *event, QPointF scenePoint)
{
    Q_UNUSED(event)
    if(!scene()->items().contains(m_pLine))
    {
        return;
    }
    if(QVector2D(m_pWhiteBall->pos() - scenePoint).length() < m_pWhiteBall->r() + 1e-6)
    {
        if(scene()->items().contains(m_pLine))
        {
            scene()->removeItem(m_pLine);
        }
        if(scene()->items().contains(m_pClub))
        {
            scene()->removeItem(m_pClub);
        }
        return;
    }
    else
    {
        if(!scene()->items().contains(m_pLine))
        {
            scene()->addItem(m_pLine);
        }
        if(!scene()->items().contains(m_pClub))
        {
            scene()->addItem(m_pClub);
        }
    }
    QPointF pos = scenePoint;
    if(QVector2D(pos - m_pWhiteBall->pos()).length() > 500)
    {
        pos = QVector2D(QVector2D(m_pWhiteBall->pos()) + QVector2D(pos - m_pWhiteBall->pos()).normalized() * 500).toPointF();
    }
    QLineF line = QLineF(pos,m_pWhiteBall->pos());
    line.setLength(line.length() + 50);
    m_pLine->setLine(line);

    m_pClub->setPos(pos);
    m_pClub->setDir(QVector2D(m_pWhiteBall->pos() - scenePoint));

}

void GCanvasDefualtOperator::mouseHoverEvent(QMouseEvent *event, QPointF scenePoint)
{
    Q_UNUSED(event)
    Q_UNUSED(scenePoint)
}

void GCanvasDefualtOperator::mouseReleaseEvent(QMouseEvent *event, QPointF scenePoint)
{
    Q_UNUSED(event)
    Q_UNUSED(scenePoint)
    if(!scene()->items().contains(m_pLine))
    {
        return;
    }
    if(scene()->items().contains(m_pLine))
    {
        scene()->removeItem(m_pLine);
    }
    m_isClubMove = true;
}

void GCanvasDefualtOperator::mouseDoubleClickEvent(QMouseEvent *event, QPointF scenePoint)
{
    Q_UNUSED(event)
    Q_UNUSED(scenePoint)
}

void GCanvasDefualtOperator::wheelEvent(QWheelEvent *event, QPointF scenePoint)
{
    Q_UNUSED(event)
    Q_UNUSED(scenePoint)
}

void GCanvasDefualtOperator::keyPressEvent(QKeyEvent *event)
{
    Q_UNUSED(event)
}

void GCanvasDefualtOperator::keyReleaseEvent(QKeyEvent *event)
{
    Q_UNUSED(event)
}

void GCanvasDefualtOperator::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    updateView();
}

void GCanvasDefualtOperator::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event)
}

void GCanvasDefualtOperator::setWhiteBall(Ball *ball)
{
    m_pWhiteBall = ball;
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(updateView()));
    m_timer.start(1000/240.0);
}

void GCanvasDefualtOperator::setClub(Club *club)
{
    m_pClub = club;
}

void GCanvasDefualtOperator::setCushion(Cushion *cushion)
{
    m_pCushion = cushion;
}

void GCanvasDefualtOperator::start()
{
    m_pUndoStack->clear();
    m_oldBallPos.clear();
    for(auto item:scene()->items())
    {
        if(static_cast<ItemBase*>(item)->itemtype() == ItemBase::ball)
        {
            m_oldBallPos.insert(static_cast<Ball*>(item), item->pos());
        }
    }
//    m_oldBallPos.insert(m_pWhiteBall, m_pWhiteBall->pos());
}

void GCanvasDefualtOperator::onUndo()
{
    if(m_isBallsMove || m_isClubMove)
    {
        return;
    }
    m_pUndoStack->undo();
}

void GCanvasDefualtOperator::onRedo()
{
    if(m_isBallsMove || m_isClubMove)
    {
        return;
    }
    m_pUndoStack->redo();
}

void GCanvasDefualtOperator::initialize()
{
    m_pUndoStack = new QUndoStack(this);
    m_pGView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_pGView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void GCanvasDefualtOperator::calculateFps()
{
    static QTime time(QTime::currentTime());//
    double key = time.elapsed()/1000.0;
    //this->replot();
    static double lastFpsKey = 0;
    static int  frameCount;
    ++frameCount;
    if(key - lastFpsKey>1){
        lastFpsKey = key;
        frameCount = 0;
    }
    m_fps = frameCount/(key-lastFpsKey);
}

void GCanvasDefualtOperator::updateView()
{
    calculateFps();
    if(m_isBallsMove)
    {
        bool isStatic = true;
        QMap<Ball *, QPointF> newBallPos;
        for(auto item:scene()->items())
        {
            if(static_cast<ItemBase*>(item)->itemtype() == ItemBase::ball)
            {
                if(qAbs(static_cast<Ball*>(item)->speed()) >= 1e-6)
                {
                    isStatic = false;
                    break;
                }
                newBallPos.insert(static_cast<Ball*>(item), item->pos());
            }
        }
        if(isStatic)
        {
            m_pUndoStack->push(new UndoCommandMoveItems(m_oldBallPos, newBallPos, scene(), "balls move"));
            m_oldBallPos = newBallPos;
            m_isBallsMove = false;
        }
    }
    if(isnan(m_fps))
    {
        return;
    }
    if(m_isClubMove)
    {
        QPointF pos = m_pClub->pos() + QVector2D(m_pLine->line().p2() - m_pLine->line().p1()).toPointF()/m_fps*5;
        if(QVector2D(m_pLine->line().p1() - pos).length() >= m_pLine->line().length() - 50)
        {
            m_pWhiteBall->setMoveDir(QVector2D(m_pLine->line().p2() - m_pLine->line().p1()).normalized());
            float speed = m_pLine->line().length()/50*200;
            m_pWhiteBall->setSpeed(speed);
            m_pClub->setDir(QVector2D(-1, 0));
            m_pClub->setPos(-m_pClub->length()/2.6/2, m_pCushion->m_outRect.y()/2.6/2 + 100/2.6);
            m_isClubMove = false;
            m_isBallsMove = true;
            return;
        }
        m_pClub->setPos(m_pClub->pos() + QVector2D(m_pLine->line().p2() - m_pLine->line().p1()).toPointF()/m_fps*5);
        return;
    }
    if(!m_isBallsMove)
    {
        return;
    }
    QList<Ball *> balls;
    Cushion* pCushion = nullptr;
    foreach (QGraphicsItem *item, scene()->items()) {
        if (static_cast<ItemBase*>(item)->itemtype() == ItemBase::ball)
        {
            balls << static_cast<Ball*>(item);
        }
        else if (static_cast<ItemBase*>(item)->itemtype() == ItemBase::cushion)
        {
            pCushion = static_cast<Cushion*>(item);
        }
    }
    auto tempballs = balls;
    foreach (Ball *ball, tempballs)
    {
        if(pCushion->collisionWithBall(ball, m_fps))
        {
            ball->setSpeed(0);
            balls.removeOne(ball);
            if(scene()->items().contains(ball))
            {
                scene()->removeItem(ball);
            }
        }
    }
    foreach (Ball *ball, balls)
    {
        foreach (Ball *ball_temp, balls)
        {
            if(ball != ball_temp)
            {
                QVector2D pos_dif = QVector2D(ball_temp->scenePos() - ball->scenePos());
                if(pos_dif.length() < ball->r() + ball_temp->r())
                {
                    QVector2D temp1 = (ball->moveDir()*pos_dif);
                    float pos_difCosBallDir = (temp1.x() + temp1.y())/(pos_dif.length()*ball->moveDir().length());
                    if(pos_difCosBallDir > 0)
                    {
                        ball_temp->addSpeedVector(0.8*pos_difCosBallDir*ball->speed()*pos_dif.normalized());
                        ball->addSpeedVector(-0.8*pos_difCosBallDir*ball->speed()*pos_dif.normalized());
                    }
                }
            }
        }
    }
    if(!isnan(m_fps))
    {
        foreach (Ball *ball, balls)
        {
            ball->setZValue(QVector2D(ball->pos()).distanceToLine(QVector2D(-10000, -10000), QVector2D(1, 1)));
            ball->move(m_fps);
        }
    }
}


