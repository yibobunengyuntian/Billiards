#include "cushion.h"

Cushion::Cushion()
{
    m_type = cushion;
    m_ellipsePath.addEllipse((-m_inRect.x())/2.6/2 + 8, (-m_inRect.y()-2*m_pocket_r*2)/2.6/2, m_pocket_r*2/2.6, m_pocket_r*2/2.6);
    m_ellipsePath.addEllipse((-m_pocket_r*2*3.0/2)/2.6, (-m_inRect.y()-2*m_pocket_r*2)/2.6/2, m_pocket_r*2/2.6, m_pocket_r*2/2.6);
    m_ellipsePath.addEllipse((m_pocket_r*2/2)/2.6, (-m_inRect.y()-2*m_pocket_r*2)/2.6/2, m_pocket_r*2/2.6, m_pocket_r*2/2.6);
    m_ellipsePath.addEllipse((m_inRect.x() - m_pocket_r*2*2)/2.6/2 - 8, (-m_inRect.y()-2*m_pocket_r*2)/2.6/2, m_pocket_r*2/2.6, m_pocket_r*2/2.6);
    m_ellipsePath.addEllipse((-m_inRect.x() - m_pocket_r*2*2)/2.6/2, (-m_inRect.y())/2.6/2 + 8, m_pocket_r*2/2.6, m_pocket_r*2/2.6);
    m_ellipsePath.addEllipse((m_inRect.x())/2.6/2, (-m_inRect.y())/2.6/2 + 8, m_pocket_r*2/2.6, m_pocket_r*2/2.6);

    m_ellipsePath.addEllipse((-m_inRect.x())/2.6/2 + 8, (m_inRect.y())/2.6/2, m_pocket_r*2/2.6, m_pocket_r*2/2.6);
    m_ellipsePath.addEllipse((-m_pocket_r*2*3.0/2)/2.6, (m_inRect.y())/2.6/2, m_pocket_r*2/2.6, m_pocket_r*2/2.6);
    m_ellipsePath.addEllipse((m_pocket_r*2/2)/2.6, (m_inRect.y())/2.6/2, m_pocket_r*2/2.6, m_pocket_r*2/2.6);
    m_ellipsePath.addEllipse((m_inRect.x() - m_pocket_r*2*2)/2.6/2 - 8, (m_inRect.y())/2.6/2, m_pocket_r*2/2.6, m_pocket_r*2/2.6);
    m_ellipsePath.addEllipse((-m_inRect.x() - m_pocket_r*2*2)/2.6/2, (m_inRect.y() - m_pocket_r*2*2)/2.6/2 - 8, m_pocket_r*2/2.6, m_pocket_r*2/2.6);
    m_ellipsePath.addEllipse((m_inRect.x())/2.6/2, (m_inRect.y() - m_pocket_r*2*2)/2.6/2 - 8, m_pocket_r*2/2.6, m_pocket_r*2/2.6);

    m_cushionPath.addRect((-m_inRect.x()+m_pocket_r*2)/2.6/2 + 8, (-m_inRect.y()-m_pocket_r*2)/2.6/2, (m_inRect.x() - m_pocket_r*2*3)/2.6/2 - 8, m_pocket_r*2/2/2.6);
    m_cushionPath.addRect(m_pocket_r*2/2.6, (-m_inRect.y()-m_pocket_r*2)/2.6/2, (m_inRect.x() - m_pocket_r*2*3)/2.6/2 - 8, m_pocket_r*2/2/2.6);
    m_cushionPath.addRect((-m_inRect.x()+m_pocket_r*2)/2.6/2 + 8, (m_inRect.y())/2.6/2, (m_inRect.x() - m_pocket_r*2*3)/2.6/2 - 8, m_pocket_r*2/2/2.6);
    m_cushionPath.addRect(m_pocket_r*2/2.6, (m_inRect.y())/2.6/2, (m_inRect.x() - m_pocket_r*2*3)/2.6/2 - 8, m_pocket_r*2/2/2.6);
    m_cushionPath.addRect((-m_inRect.x()-m_pocket_r*2)/2.6/2, (-m_inRect.y()+m_pocket_r*2)/2.6/2 + 8, m_pocket_r*2/2/2.6, (m_inRect.y() - m_pocket_r*2)/2.6 - 16);
    m_cushionPath.addRect((m_inRect.x())/2.6/2, (-m_inRect.y()+m_pocket_r*2)/2.6/2 + 8, m_pocket_r*2/2/2.6, (m_inRect.y() - m_pocket_r*2)/2.6 - 16);

    m_pointPath.addEllipse(-m_inRect.x()/2.6/2 + 324/2.6 - 2, 0 - 2, 4, 4);
    m_pointPath.addEllipse(-m_inRect.x()/2.6/2/2 - 2, 0 - 2, 4, 4);
    m_pointPath.addEllipse(m_inRect.x()/2/2.6 - m_inRect.x()*737/3569/2.6 - 2, -m_inRect.x()*292/3569/2.6 - 2, 4, 4);
    m_pointPath.addEllipse(m_inRect.x()/2/2.6 - m_inRect.x()*737/3569/2.6 - 2, 0 - 2, 4, 4);
    m_pointPath.addEllipse(m_inRect.x()/2/2.6 - m_inRect.x()*737/3569/2.6 - 2, m_inRect.x()*292/3569/2.6 - 2, 4, 4);

    m_pocketPath.addEllipse(-m_inRect.x()/2.6/2 - m_pocket_r*2/2.6 + 10, -m_inRect.y()/2.6/2 - m_pocket_r*2/2.6 + 10, m_pocket_r*2/2.6, m_pocket_r*2/2.6);
    m_pocketPath.addEllipse(-m_pocket_r*2/2/2.6, -m_inRect.y()/2.6/2 - m_pocket_r*2/2.6, m_pocket_r*2/2.6, m_pocket_r*2/2.6);
    m_pocketPath.addEllipse(m_inRect.x()/2.6/2 - 10, -m_inRect.y()/2.6/2 - m_pocket_r*2/2.6 + 10, m_pocket_r*2/2.6, m_pocket_r*2/2.6);
    m_pocketPath.addEllipse(-m_inRect.x()/2.6/2 - m_pocket_r*2/2.6 + 10, m_inRect.y()/2.6/2 - 10, m_pocket_r*2/2.6, m_pocket_r*2/2.6);
    m_pocketPath.addEllipse(-m_pocket_r*2/2/2.6, m_inRect.y()/2.6/2, m_pocket_r*2/2.6, m_pocket_r*2/2.6);
    m_pocketPath.addEllipse(m_inRect.x()/2.6/2 - 10, m_inRect.y()/2.6/2 - 10, m_pocket_r*2/2.6, m_pocket_r*2/2.6);

    m_pocketPoints<< QPointF(-m_inRect.x()/2.6/2 - m_pocket_r*2/2.6 + 10, -m_inRect.y()/2.6/2 - m_pocket_r*2/2.6 + 10) + QPointF(m_pocket_r*2/2.6, m_pocket_r*2/2.6)/2
                  << QPointF(-m_pocket_r*2/2/2.6, -m_inRect.y()/2.6/2 - m_pocket_r*2/2.6) + QPointF(m_pocket_r*2/2.6, m_pocket_r*2/2.6)/2
                  << QPointF(m_inRect.x()/2.6/2 - 10, -m_inRect.y()/2.6/2 - m_pocket_r*2/2.6 + 10) + QPointF(m_pocket_r*2/2.6, m_pocket_r*2/2.6)/2
                  << QPointF(-m_inRect.x()/2.6/2 - m_pocket_r*2/2.6 + 10, m_inRect.y()/2.6/2 - 10) + QPointF(m_pocket_r*2/2.6, m_pocket_r*2/2.6)/2
                  << QPointF(-m_pocket_r*2/2/2.6, m_inRect.y()/2.6/2) + QPointF(m_pocket_r*2/2.6, m_pocket_r*2/2.6)/2
                  << QPointF(m_inRect.x()/2.6/2 - 10, m_inRect.y()/2.6/2 - 10) + QPointF(m_pocket_r*2/2.6, m_pocket_r*2/2.6)/2;

    m_filletedCornerPoints<< QPointF((-m_inRect.x())/2.6/2 + 8, (-m_inRect.y()-2*m_pocket_r*2)/2.6/2) + QPointF(m_pocket_r*2/2.6, m_pocket_r*2/2.6)/2
                          << QPointF((-m_pocket_r*2*3.0/2)/2.6, (-m_inRect.y()-2*m_pocket_r*2)/2.6/2) + QPointF(m_pocket_r*2/2.6, m_pocket_r*2/2.6)/2
                          << QPointF((m_pocket_r*2/2)/2.6, (-m_inRect.y()-2*m_pocket_r*2)/2.6/2) + QPointF(m_pocket_r*2/2.6, m_pocket_r*2/2.6)/2
                          << QPointF((m_inRect.x() - m_pocket_r*2*2)/2.6/2 - 8, (-m_inRect.y()-2*m_pocket_r*2)/2.6/2) + QPointF(m_pocket_r*2/2.6, m_pocket_r*2/2.6)/2
                          << QPointF((-m_inRect.x() - m_pocket_r*2*2)/2.6/2, (-m_inRect.y())/2.6/2 + 8) + QPointF(m_pocket_r*2/2.6, m_pocket_r*2/2.6)/2
                          << QPointF((m_inRect.x())/2.6/2, (-m_inRect.y())/2.6/2 + 8) + QPointF(m_pocket_r*2/2.6, m_pocket_r*2/2.6)/2

                          << QPointF((-m_inRect.x())/2.6/2 + 8, (m_inRect.y())/2.6/2) + QPointF(m_pocket_r*2/2.6, m_pocket_r*2/2.6)/2
                          << QPointF((-m_pocket_r*2*3.0/2)/2.6, (m_inRect.y())/2.6/2) + QPointF(m_pocket_r*2/2.6, m_pocket_r*2/2.6)/2
                          << QPointF((m_pocket_r*2/2)/2.6, (m_inRect.y())/2.6/2) + QPointF(m_pocket_r*2/2.6, m_pocket_r*2/2.6)/2
                          << QPointF((m_inRect.x() - m_pocket_r*2*2)/2.6/2 - 8, (m_inRect.y())/2.6/2) + QPointF(m_pocket_r*2/2.6, m_pocket_r*2/2.6)/2
                          << QPointF((-m_inRect.x() - m_pocket_r*2*2)/2.6/2, (m_inRect.y() - m_pocket_r*2*2)/2.6/2 - 8) + QPointF(m_pocket_r*2/2.6, m_pocket_r*2/2.6)/2
                          << QPointF((m_inRect.x())/2.6/2, (m_inRect.y() - m_pocket_r*2*2)/2.6/2 - 8) + QPointF(m_pocket_r*2/2.6, m_pocket_r*2/2.6)/2;
}

Cushion::~Cushion()
{

}

bool Cushion::collisionWithBall(Ball *ball, float fps)
{
    if(ball == nullptr)
    {
        return false;
    }
    QPointF ballPos = mapFromItem(ball, 0, 0);

    //先与6个球袋进行判断
    for(auto point:m_pocketPoints)
    {
        //根据两球心距离与半径判断进球，若进球直接返回true， +1是在微调进球范围，与下面的+2效果相同
        if(QVector2D(ballPos - point).length() <  m_pocket_r*2/2.6/2 - ball->r() + 1)
        {
            return true;
        }
        //若还未进球但球心已经进入球袋， 则改变速度及方向，使朝着球袋中心移动
        else if(QVector2D(ballPos - point).length() <  m_pocket_r*2/2.6/2 + 2)
        {
            ball->setMoveDir(QVector2D(point - ballPos).normalized());
            ball->setSpeed(ball->speed() + 20);
        }
    }

    //若速度为0，则无需考虑碰撞
    if(ball->speed()  < 1e-6)
    {
        return false;
    }

    //与库边圆角做碰撞检测（将库边圆角当作圆形处理， 依旧根据球心距离与半径判断）
    for(auto point:m_filletedCornerPoints)
    {
        if(QVector2D(ballPos - point).length() <=  m_pocket_r*2/2.6/2 + ball->r() + 1e-6)
        {
            //计算出球沿着库边圆角中心的速度分量， 这个分量（矢量）便是球的损失速度

            //球心到库边圆角中心的方向
            QVector2D pos_dif = QVector2D(point - ballPos);

            QVector2D temp1 = (ball->moveDir()*pos_dif);
            //向量积
            float vectorValue = (temp1.x() + temp1.y());

            //（向量积/模之积）极为余弦值
            float pos_difCosBallDir = vectorValue/(pos_dif.length()*ball->moveDir().length());

            //pos_dif方向的速度损失量
            float lossSpeed = pos_difCosBallDir*ball->speed();

            //小于0即代表夹角大于90度， 不构成碰撞
            if(pos_difCosBallDir > 0)
            {
                //速度减去pos_dif方向的损失量，0.8为碰撞损耗
                ball->addSpeedVector(-0.8*lossSpeed*pos_dif.normalized());
                return false;
            }
        }
    }

    //分别与除库边圆角外的直边进行碰撞检测0.8为碰撞损耗（与水平边碰撞：x方向不变， y反向， 与竖直边碰撞：x反向， y不变）
    if(ballPos.x() < -m_inRect.x()/2.6/2 + ball->r()
            && ballPos.y() >= (-m_inRect.y()+m_pocket_r*2)/2.6/2 + 8
            && ballPos.y() <= (-m_inRect.y()+m_pocket_r*2)/2.6/2 + 8 + (m_inRect.y() - m_pocket_r*2)/2.6 - 16)
    {
        ball->setPos(-m_inRect.x()/2.6/2 + ball->r(),ball->scenePos().y());
        ball->setMoveDir(QVector2D(-ball->moveDir().x(), ball->moveDir().y()));
        ball->setSpeed(ball->speed()*0.8);
        return false;
    }
    else if(ballPos.x() > m_inRect.x()/2.6/2 - ball->r()
            && ballPos.y() >= (-m_inRect.y()+m_pocket_r*2)/2.6/2 + 8
            && ballPos.y() <= (-m_inRect.y()+m_pocket_r*2)/2.6/2 + 8 + (m_inRect.y() - m_pocket_r*2)/2.6 - 16)
    {
        ball->setPos(m_inRect.x()/2.6/2 - ball->r(),ball->scenePos().y());
        ball->setMoveDir(QVector2D(-ball->moveDir().x(), ball->moveDir().y()));
        ball->setSpeed(ball->speed()*0.6);
        return false;
    }
    else if(ballPos.y() < -m_inRect.y()/2.6/2 + ball->r()
            && ((ballPos.x() >= (-m_inRect.x()+m_pocket_r*2)/2.6/2 + 8
                 && ballPos.x() <= (-m_inRect.x()+m_pocket_r*2)/2.6/2 + 8 + (m_inRect.x() - m_pocket_r*2*3)/2.6/2 - 8)
                || (ballPos.x() >= m_pocket_r*2/2.6
                    && ballPos.x() <= m_pocket_r*2/2.6 + (m_inRect.x() - m_pocket_r*2*3)/2.6/2 - 8)))
    {
        ball->setPos(ball->scenePos().x(), -m_inRect.y()/2.6/2 + ball->r());
        ball->setMoveDir(QVector2D(ball->moveDir().x(), -ball->moveDir().y()));
        ball->setSpeed(ball->speed()*0.8);
        return false;
    }
    else if(ballPos.y() > m_inRect.y()/2.6/2 - ball->r()
            && ((ballPos.x() >= (-m_inRect.x()+m_pocket_r*2)/2.6/2 + 8
                 && ballPos.x() <= (-m_inRect.x()+m_pocket_r*2)/2.6/2 + 8 + (m_inRect.x() - m_pocket_r*2*3)/2.6/2 - 8)
                || (ballPos.x() >= m_pocket_r*2/2.6
                    && ballPos.x() <= m_pocket_r*2/2.6 + (m_inRect.x() - m_pocket_r*2*3)/2.6/2 - 8)))
    {
        ball->setPos(ball->scenePos().x(), m_inRect.y()/2.6/2 - ball->r());
        ball->setMoveDir(QVector2D(ball->moveDir().x(), -ball->moveDir().y()));
        ball->setSpeed(ball->speed()*0.8);
        return false;
    }
    return false;
}

QRectF Cushion::boundingRect() const
{
    return QRectF(-m_outRect.x()/2.6/2, -m_outRect.y()/2.6/2, m_outRect.x()/2.6, m_outRect.y()/2.6);
}

QPainterPath Cushion::shape() const
{
    QPainterPath path;
    path.addRect(-m_outRect.x()/2.6/2, -m_outRect.y()/2.6/2, m_outRect.x()/2.6, m_outRect.y()/2.6);
    return path;
}


void Cushion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing,true);
    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor(Qt::green).light(60));
    //绘制中间绿色运动区域
    painter->drawRect((-m_inRect.x()-m_pocket_r*2)/2.6/2, (-m_inRect.y()-m_pocket_r*2)/2.6/2, (m_inRect.x()+m_pocket_r*2)/2.6, (m_inRect.y()+m_pocket_r*2)/2.6);
    painter->setBrush(QColor(Qt::white).light(70));
    //绘制中间区域的点与线
    painter->drawPath(m_pointPath);

    painter->setPen(Qt::black);
    painter->setBrush(QColor(Qt::green).light(50));
    //绘制库边矩形与圆角
    painter->drawPath(m_cushionPath + m_ellipsePath);
    painter->setBrush(QColor(150, 75, 0).light(70));

    QPainterPath outFramePath;
    outFramePath.addRoundRect(-m_outRect.x()/2.6/2, -m_outRect.y()/2.6/2, m_outRect.x()/2.6, m_outRect.y()/2.6, 3, 5);
    QPainterPath inFramePath;
    inFramePath.addRect((-m_inRect.x()-m_pocket_r*2)/2.6/2, (-m_inRect.y()-m_pocket_r*2)/2.6/2, (m_inRect.x()+m_pocket_r*2)/2.6, (m_inRect.y()+m_pocket_r*2)/2.6);
    //    painter->drawRoundRect(-m_outRect.x()/2.6/2, -m_outRect.y()/2.6/2, m_outRect.x()/2.6, m_outRect.y()/2.6, 3, 5);
    QLinearGradient linear(QPointF(-m_outRect.x()/2.6/2, -m_outRect.y()/2.6/2)*0.2,
                           QPointF(m_outRect.x()/2.6/2, m_outRect.y()/2.6/2)*0.2);
    linear.setColorAt(0, QColor(150, 75, 0).light(70));
    linear.setColorAt(0.3, QColor(150, 75, 0).light(120));
    linear.setColorAt(1,QColor(150, 75, 0).light(70));
//    linear.setSpread(QGradient::ReflectSpread);
    painter->setBrush(linear);
    //绘制外边框（一个大的圆角矩形减去中间一个矩形）
    painter->drawPath(outFramePath - inFramePath);
    painter->setPen(QColor(Qt::white).light(70));
    painter->drawLine(QPointF(m_inRect.x()/2/2.6 - m_inRect.x()*737/3569/2.6, -m_inRect.y()/2.6/2), QPointF(m_inRect.x()/2/2.6 - m_inRect.x()*737/3569/2.6, m_inRect.y()/2.6/2));
    painter->drawArc(m_inRect.x()/2/2.6 - m_inRect.x()*737/3569/2.6 - m_inRect.x()*292/3569/2.6 , -m_inRect.x()*292/3569/2.6, m_inRect.x()*292/3569/2.6*2, m_inRect.x()*292/3569/2.6*2, -m_pocket_r*2*16, 180*16);

    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor(Qt::black));
    //最后绘制球袋
    painter->drawPath(m_pocketPath);
}
