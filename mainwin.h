#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include <QPushButton>
#include "ui_mainwin.h"
#include "ball.h"
#include "cushion.h"
#include "club.h"

#ifndef ADDITEM
#define ADDITEM(item) if(!m_pGraphicsView->scene()->items().contains(item)){m_pGraphicsView->scene()->addItem(item);}
#endif

class MainWin : public QWidget, public Ui_MainWin
{
    Q_OBJECT

public:
    MainWin(QWidget *parent = nullptr);
    ~MainWin();

    void initialzed();

protected:
    bool event(QEvent *event);

protected slots:
    void rst();

private:
    QList<Ball*> m_redBalls;
    Cushion *m_pCushion     = nullptr;
    Ball *m_pWhite          = nullptr;
    Ball *m_pBlack          = nullptr;
    Ball *m_pPink           = nullptr;
    Ball *m_pBlue           = nullptr;
    Ball *m_pYellow         = nullptr;
    Ball *m_pCoffee         = nullptr;
    Ball *m_pGreen          = nullptr;
    Club *m_pClub           = nullptr;
    QPushButton *m_pBtnRst  = nullptr;
    QPushButton *m_pBtnUndo = nullptr;
    QPushButton *m_pBtnRedo = nullptr;
};
#endif // MAINWIN_H
