#ifndef GCANVASDEFUALTOPERATOR_H
#define GCANVASDEFUALTOPERATOR_H

#include "gcanvasbaseoperator.h"

#include <QObject>
#include <QUndoStack>
#include <QTime>

#include "cushion.h"
#include "ball.h"
#include "club.h"
#include "undocommands.h"

class GCanvasDefualtOperator : public GCanvasBaseOperator
{
    Q_OBJECT
public:
    explicit GCanvasDefualtOperator(GCanvasView *parent);
    ~GCanvasDefualtOperator();

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

    void setWhiteBall(Ball *ball);
    void setClub(Club *club);
    void setCushion(Cushion *cushion);
    void start();

public slots:
    void onUndo();
    void onRedo();
protected:
    void initialize();
    void calculateFps();

protected slots:
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
    QTimer m_timer;
    QMap<Ball *, QPointF> m_oldBallPos;
};

#endif // GCANVASDEFUALTOPERATOR_H
