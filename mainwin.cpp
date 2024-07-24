#include "mainwin.h"
#include "ui_mainwin.h"

#include <QtMath>
#include "gcanvasdefualtoperator.h"
#include "cushion.h"
#include "club.h"

MainWin::MainWin(QWidget *parent)
    : QWidget(parent)
{
    setupUi(this);
    initialzed();
}

MainWin::~MainWin()
{

}

void MainWin::initialzed()
{
    this->setWindowTitle("Billiards");
    m_pCushion = new Cushion();
    m_pGraphicsView->createScene();
    ADDITEM(m_pCushion);
    m_pClub = new Club();
    m_pWhite  = new Ball(Ball::white);
    m_pBlack  = new Ball(Ball::black);
    m_pPink   = new Ball(Ball::pink);
    m_pBlue   = new Ball(Ball::blue);
    m_pYellow = new Ball(Ball::yellow);
    m_pCoffee = new Ball(Ball::coffee);
    m_pGreen  = new Ball(Ball::green);
    for(int i = 0; i < 15; ++i)
    {
        m_redBalls.append(new Ball(Ball::red));
    }
    static_cast<GCanvasDefualtOperator*>(m_pGraphicsView->operatorObj().get())->setWhiteBall(m_pWhite);
    static_cast<GCanvasDefualtOperator*>(m_pGraphicsView->operatorObj().get())->setCushion(m_pCushion);
    static_cast<GCanvasDefualtOperator*>(m_pGraphicsView->operatorObj().get())->setClub(m_pClub);
    rst();
    m_pBtnRst = new QPushButton("重置", m_pGraphicsView);
    m_pBtnRst->setFixedSize(100, 30);
    connect(m_pBtnRst, SIGNAL(clicked(bool)), this, SLOT(rst()));

    m_pBtnUndo = new QPushButton("回退", m_pGraphicsView);
    m_pBtnUndo->setFixedSize(100, 30);
    m_pBtnUndo->move(m_pBtnRst->pos() + QPoint(m_pBtnRst->width(), 0));
    connect(m_pBtnUndo, SIGNAL(clicked(bool)), static_cast<GCanvasDefualtOperator*>(m_pGraphicsView->operatorObj().get()), SLOT(onUndo()));

    m_pBtnRedo = new QPushButton("恢复", m_pGraphicsView);
    m_pBtnRedo->setFixedSize(100, 30);
    m_pBtnRedo->move(m_pBtnUndo->pos() + QPoint(m_pBtnUndo->width(), 0));
    connect(m_pBtnRedo, SIGNAL(clicked(bool)), static_cast<GCanvasDefualtOperator*>(m_pGraphicsView->operatorObj().get()), SLOT(onRedo()));
}

bool MainWin::event(QEvent *event)
{
    static float scale = 1;
    if(event->type() == QEvent::Resize)
    {
        m_pGraphicsView->scale(1/scale, 1/scale);
        if(m_pGraphicsView->width()/m_pGraphicsView->height() >
                m_pCushion->boundingRect().width()/m_pCushion->boundingRect().height())
        {
            scale = m_pGraphicsView->height()/m_pCushion->boundingRect().height()/1.0;
        }
        else
        {
            scale = m_pGraphicsView->width()/m_pCushion->boundingRect().width()/1.0;
        }
        scale *= 0.8f;
        m_pGraphicsView->scale(scale, scale);
        m_pGraphicsView->scene()->setSceneRect(m_pCushion->boundingRect());
    }
    return QWidget::event(event);
}

void MainWin::rst()
{
    if(m_pGraphicsView->scene()->items().contains(m_pWhite))
    {
        m_pGraphicsView->scene()->removeItem(m_pWhite);
    }
    m_pBlack->setPos(-m_pCushion->m_inRect.x()/2.6/2 + 324/2.6, 0);
    m_pBlack->setSpeed(0);
    m_pPink->setPos(-m_pCushion->m_inRect.x()/2.6/2/2, 0);
    m_pPink->setSpeed(0);
    m_pBlue->setPos(0, 0);
    m_pBlue->setSpeed(0);
    m_pYellow->setPos(m_pCushion->m_inRect.x()/2/2.6 - 737/2.6, 292/2.6);
    m_pYellow->setSpeed(0);
    m_pCoffee->setPos(m_pCushion->m_inRect.x()/2/2.6 - 737/2.6, 0);
    m_pCoffee->setSpeed(0);
    m_pGreen->setPos(m_pCushion->m_inRect.x()/2/2.6 - 737/2.6, -292/2.6);
    m_pGreen->setSpeed(0);
    m_pWhite->setSpeed(0);

    float baseX = -m_pCushion->m_inRect.x()/2.6/2/2 - m_pBlack->r()*2 - 20/2.6;
    for(int i = 0; i < 15; ++i)
    {
        float x = 0;
        float y = 0;
        if(i < 1)
        {
            x = baseX;
            y = 0;
        }
        else if(i < 3)
        {
            x = baseX - m_pBlack->r()*qPow(3, 0.5);
            y = 0 + (i - 1.5)*20;
        }
        else if(i < 6)
        {
            x = baseX - m_pBlack->r()*qPow(3, 0.5)*2;
            y = 0 + (i - 4)*20;
        }
        else if(i < 10)
        {
            x = baseX - m_pBlack->r()*qPow(3, 0.5)*3;
            y = 0 + (i - 7.5)*20;
        }
        else
        {
            x = baseX - m_pBlack->r()*qPow(3, 0.5)*4;
            y = 0 + (i - 12)*20;
        }
        m_redBalls[i]->setPos(x, y);
        m_redBalls[i]->setSpeed(0);
        m_redBalls[i]->setZValue(QVector2D(m_redBalls[i]->pos()).distanceToLine(QVector2D(-10000, -10000), QVector2D(1, 1)));
        ADDITEM(m_redBalls[i]);
    }
    m_pClub->setZValue(20000);
    m_pClub->setDir(QVector2D(-1, 0));
    m_pClub->setPos(-m_pClub->length()/2.6/2, m_pCushion->m_outRect.y()/2.6/2 + 100/2.6);
    ADDITEM(m_pBlack);
    ADDITEM(m_pPink);
    ADDITEM(m_pBlue);
    ADDITEM(m_pYellow);
    ADDITEM(m_pCoffee);
    ADDITEM(m_pGreen);
    ADDITEM(m_pClub);
    static_cast<GCanvasDefualtOperator*>(m_pGraphicsView->operatorObj().get())->start();
}

