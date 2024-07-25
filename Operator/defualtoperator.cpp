#include "defualtoperator.h"


DefualtOperator::DefualtOperator(GraphicsView *parent)
    : BaseOperator{parent}
{
    initialize();
}

DefualtOperator::~DefualtOperator()
{

}

void DefualtOperator::mousePressEvent(QMouseEvent *event, QPointF scenePoint)
{
    //此项目只考虑鼠标左键
    if(event->button() != Qt::LeftButton)
    {
        return;
    }

    //球处于移动状态 或者 在出杆状态，不允许操作
    if(m_isBallsMove || m_isClubMove)
    {
        return;
    }

    //先得到场景中的球及球台
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

    //若场景中没有白球，则需根据当前点击点放置白球
    if(!scene()->items().contains(m_pWhiteBall))
    {
        //放置白球必须在半圆形区域（游戏规则）
        if(!QGraphicsEllipseItem(pCushion->m_inRect.x()/2/2.6 - pCushion->m_inRect.x()*737/3569/2.6 - pCushion->m_inRect.x()*292/3569/2.6,
                             -pCushion->m_inRect.x()*292/3569/2.6,
                             pCushion->m_inRect.x()*292/3569/2.6*2,
                             pCushion->m_inRect.x()*292/3569/2.6*2).shape().toFillPolygon().containsPoint(scenePoint,Qt::WindingFill)
            || scenePoint.x() < pCushion->m_inRect.x()/2/2.6 - pCushion->m_inRect.x()*737/3569/2.6)
        {
            return;
        }
        //不能在已有球的位置放置白球
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
        return;
    }

    //若点击到白球， 不做瞄准处理，直接退出
    if(QVector2D(m_pWhiteBall->pos() - scenePoint).length() < m_pWhiteBall->r() + 1e-6)
    {
        return;
    }

    //以下为进入瞄准状态
    QPointF pos = scenePoint;
    //限制球杆拉伸的距离（最大击球速度）
    if(QVector2D(pos - m_pWhiteBall->pos()).length() > 500)
    {
        pos = QVector2D(QVector2D(m_pWhiteBall->pos()) + QVector2D(pos - m_pWhiteBall->pos()).normalized() * 500).toPointF();
    }
    QLineF line = QLineF(pos,m_pWhiteBall->pos());
    line.setLength(line.length() + 50);
    //设置辅助线
    m_pLine->setLine(line);
    if(!scene()->items().contains(m_pLine))
    {
        scene()->addItem(m_pLine);
    }
    //设置球杆的位置与方向
    m_pClub->setPos(pos);
    m_pClub->setDir(QVector2D(m_pWhiteBall->pos() - pos));
}

void DefualtOperator::mouseMoveEvent(QMouseEvent *event, QPointF scenePoint)
{
    //此事件为鼠标按下移动

    Q_UNUSED(event)
    if(!scene()->items().contains(m_pLine))
    {
        return;
    }

    //若鼠标移动到白球， 退出瞄准状态
    if(QVector2D(m_pWhiteBall->pos() - scenePoint).length() < m_pWhiteBall->r() + 1e-6)
    {
        //移除辅助线
        if(scene()->items().contains(m_pLine))
        {
            scene()->removeItem(m_pLine);
        }
        //球杆放置原位
        m_pClub->setDir(QVector2D(-1, 0));
        m_pClub->setPos(-m_pClub->length()/2.6/2, m_pCushion->m_outRect.y()/2.6/2 + 100/2.6);
        return;
    }

    //根据鼠标位置改变瞄准方向与力度
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

void DefualtOperator::mouseHoverEvent(QMouseEvent *event, QPointF scenePoint)
{
    Q_UNUSED(event)
    Q_UNUSED(scenePoint)
}

void DefualtOperator::mouseReleaseEvent(QMouseEvent *event, QPointF scenePoint)
{
    Q_UNUSED(event)
    Q_UNUSED(scenePoint)
    //判断是否处于瞄准状态（是否有辅助线）
    if(!scene()->items().contains(m_pLine))
    {
        return;
    }
    //退出瞄准状态， 进入出杆状态
    if(scene()->items().contains(m_pLine))
    {
        scene()->removeItem(m_pLine);
    }
    m_isClubMove = true;
}

void DefualtOperator::mouseDoubleClickEvent(QMouseEvent *event, QPointF scenePoint)
{
    Q_UNUSED(event)
    Q_UNUSED(scenePoint)
}

void DefualtOperator::wheelEvent(QWheelEvent *event, QPointF scenePoint)
{
    Q_UNUSED(event)
    Q_UNUSED(scenePoint)
}

void DefualtOperator::keyPressEvent(QKeyEvent *event)
{
    Q_UNUSED(event)
}

void DefualtOperator::keyReleaseEvent(QKeyEvent *event)
{
    Q_UNUSED(event)
}

void DefualtOperator::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    updateView();
}

void DefualtOperator::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event)
}

void DefualtOperator::setWhiteBall(Ball *ball)
{
    m_pWhiteBall = ball;
}

void DefualtOperator::setClub(Club *club)
{
    m_pClub = club;
}

void DefualtOperator::setCushion(Cushion *cushion)
{
    m_pCushion = cushion;
}

void DefualtOperator::start()
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
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(updateView()));
    m_timer.start(1000/240.0);
}

void DefualtOperator::onUndo()
{
    if(m_isBallsMove || m_isClubMove)
    {
        return;
    }
    m_pUndoStack->undo();
}

void DefualtOperator::onRedo()
{
    if(m_isBallsMove || m_isClubMove)
    {
        return;
    }
    m_pUndoStack->redo();
}

void DefualtOperator::initialize()
{
    m_pUndoStack = new QUndoStack(this);
    m_pLine = new QGraphicsLineItem;
    m_pGView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_pGView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void DefualtOperator::calculateFps()
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

void DefualtOperator::updateView()
{
    //先计算帧率
    calculateFps();

    //判断是否所有球是否静止
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
        //若静止则保存上一次位置到撤销栈，并记录这次位置
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

    //若处于出杆状态
    if(m_isClubMove)
    {
        //沿着辅助线计算球杆运动到的位置
        QPointF pos = m_pClub->pos() + QVector2D(m_pLine->line().p2() - m_pLine->line().p1()).toPointF()/m_fps*5;
        //判断与白球碰撞
        if(QVector2D(m_pLine->line().p1() - pos).length() >= m_pLine->line().length() - 50)
        {
            //可根据辅助线的拉伸长度决定速度大小
            float speed = m_pLine->line().length()/50*200;
            //给白球一个沿着击球方向的速度
            m_pWhiteBall->setMoveDir(QVector2D(m_pLine->line().p2() - m_pLine->line().p1()).normalized());
            m_pWhiteBall->setSpeed(speed);
            m_pClub->setDir(QVector2D(-1, 0));
            m_pClub->setPos(-m_pClub->length()/2.6/2, m_pCushion->m_outRect.y()/2.6/2 + 100/2.6);
            //出杆状态结束，球将处于运动状态
            m_isClubMove = false;
            m_isBallsMove = true;
            return;
        }
        //球杆移动
        m_pClub->setPos(pos);
        return;
    }
    //若球都处于静止状态， 则无需下列运动计算
    if(!m_isBallsMove)
    {
        return;
    }
    //先得到场景上的所有球及球台
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
    //保存副本
    auto tempballs = balls;
    foreach (Ball *ball, tempballs)
    {
        //与球台进行碰撞检测并判断进球，若进球， 则移除场景
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
    //计算球与球之间的碰撞
    foreach (Ball *ball, balls)
    {
        foreach (Ball *ball_temp, balls)
        {
            if(ball != ball_temp)
            {
                //计算出球沿着击中球中心的速度分量， 这个分量（矢量）便是球的损失速度
                //两球的相对方向
                QVector2D pos_dif = QVector2D(ball_temp->scenePos() - ball->scenePos());
                //根据距离与半径判断碰撞
                if(pos_dif.length() < ball->r() + ball_temp->r())
                {
                    QVector2D temp1 = (ball->moveDir()*pos_dif);
                    //向量积
                    float vectorValue = (temp1.x() + temp1.y());

                    //（向量积/模之积）极为余弦值
                    float pos_difCosBallDir = vectorValue/(pos_dif.length()*ball->moveDir().length());

                    //pos_dif方向的速度损失量（被击中球的增加量）
                    float lossSpeed = pos_difCosBallDir*ball->speed();
                    if(pos_difCosBallDir > 0)
                    {
                        //被击中球增加这个方向的速度
                        ball_temp->addSpeedVector(0.8*lossSpeed*pos_dif.normalized());

                        //减少这个方向的速度
                        ball->addSpeedVector(-0.8*lossSpeed*pos_dif.normalized());
                    }
                }
            }
        }
    }

    foreach (Ball *ball, balls)
    {
        //根据球到一个偏x方向45度的斜线‘/’的距离， 设置ZValue值，保证右下方的球始终在左上方的球上层， 避免左上方球的阴影会遮挡右下方的球体
        ball->setZValue(QVector2D(ball->pos()).distanceToLine(QVector2D(-10000, -10000), QVector2D(1, 1)));

        //球体运动
        ball->move(m_fps);
    }
}


