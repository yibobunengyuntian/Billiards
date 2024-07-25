#ifndef DEFUALTOPERATOR_H
#define DEFUALTOPERATOR_H

#include "baseoperator.h"

#include <QObject>
#include <QUndoStack>
#include <QTime>

#include "cushion.h"
#include "ball.h"
#include "club.h"
#include "undocommands.h"

class DefualtOperator : public BaseOperator
{
    Q_OBJECT
public:
    explicit DefualtOperator(GraphicsView *parent);
    ~DefualtOperator();

    virtual void mousePressEvent(QMouseEvent *event, QPointF scenePoint) override;
    virtual void mouseMoveEvent(QMouseEvent *event, QPointF scenePoint) override;
    virtual void mouseHoverEvent(QMouseEvent *event, QPointF scenePoint) override;
    virtual void mouseReleaseEvent(QMouseEvent *event, QPointF scenePoint) override;
    virtual void mouseDoubleClickEvent(QMouseEvent *event, QPointF scenePoint) override;
    virtual void wheelEvent(QWheelEvent *event, QPointF scenePoint) override;

    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;

    virtual void resizeEvent(QResizeEvent *event) override;
    void timerEvent(QTimerEvent *event) override;

    //单独传入白球、球杆、球台方便直接操作
    void setWhiteBall(Ball *ball);
    void setClub(Club *club);
    void setCushion(Cushion *cushion);

    //开始
    void start();

public slots:

    //撤销
    void onUndo();

    //恢复
    void onRedo();
protected:
    void initialize();

    //计算帧率
    void calculateFps();

protected slots:

    //每帧刷新，做相应运动计算
    void updateView();


private:
    bool m_isBallsMove = false;            //球处于移动状态
    bool m_isClubMove = false;             //球杆处于移动状态
    QUndoStack *m_pUndoStack   = nullptr;  //回退处理
    float m_fps;                           //帧率
    Ball *m_pWhiteBall         = nullptr;  //白球
    Cushion *m_pCushion        = nullptr;  //球桌
    Club *m_pClub              = nullptr;  //球杆
    QGraphicsLineItem *m_pLine = nullptr;  //辅助线
    QTimer m_timer;                        //定时器
    QMap<Ball *, QPointF> m_oldBallPos;    //保存上一次球的位置
};

#endif // DEFUALTOPERATOR_H
