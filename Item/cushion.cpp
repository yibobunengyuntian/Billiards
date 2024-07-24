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
    for(auto point:m_pocketPoints)
    {
        if(QVector2D(ballPos - point).length() <  m_pocket_r*2/2.6/2 - ball->r() + 1)
        {
            return true;
        }
        else if(QVector2D(ballPos - point).length() <  m_pocket_r*2/2.6/2 + 2)
        {
            ball->setMoveDir(QVector2D(point - ballPos).normalized());
            ball->setSpeed(ball->speed() + 20);
        }
    }
    if(ball->speed()  < 1e-6)
    {
        return false;
    }

    for(auto point:m_filletedCornerPoints)
    {
        if(QVector2D(ballPos - point).length() <=  m_pocket_r*2/2.6/2 + ball->r() + 1e-6)
        {
            QVector2D pos_dif = QVector2D(point - ballPos);
            QVector2D temp1 = (ball->moveDir()*pos_dif);
            float pos_difCosBallDir = (temp1.x() + temp1.y())/(pos_dif.length()*ball->moveDir().length());
            if(pos_difCosBallDir > 0)
            {
                ball->addSpeedVector(-0.9*pos_difCosBallDir*ball->speed()*pos_dif.normalized());
                return false;
            }
        }
    }
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
    qreal adjust = 2;
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
    painter->drawRect((-m_inRect.x()-m_pocket_r*2)/2.6/2, (-m_inRect.y()-m_pocket_r*2)/2.6/2, (m_inRect.x()+m_pocket_r*2)/2.6, (m_inRect.y()+m_pocket_r*2)/2.6);
    painter->setBrush(QColor(Qt::white).light(70));
    painter->drawPath(m_pointPath);

    painter->setPen(Qt::black);
    painter->setBrush(QColor(Qt::green).light(50));
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
    painter->drawPath(outFramePath - inFramePath);
    painter->setPen(QColor(Qt::white).light(70));
    painter->drawLine(QPointF(m_inRect.x()/2/2.6 - m_inRect.x()*737/3569/2.6, -m_inRect.y()/2.6/2), QPointF(m_inRect.x()/2/2.6 - m_inRect.x()*737/3569/2.6, m_inRect.y()/2.6/2));
    painter->drawArc(m_inRect.x()/2/2.6 - m_inRect.x()*737/3569/2.6 - m_inRect.x()*292/3569/2.6 , -m_inRect.x()*292/3569/2.6, m_inRect.x()*292/3569/2.6*2, m_inRect.x()*292/3569/2.6*2, -m_pocket_r*2*16, 180*16);

    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor(Qt::black));
    painter->drawPath(m_pocketPath);
}
