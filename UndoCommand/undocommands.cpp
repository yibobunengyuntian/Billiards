#include "undocommands.h"

UndoCommandBase::UndoCommandBase(const QString &text, QUndoCommand *parent):
    QUndoCommand(text,parent)
{

}

UndoCommandBase::~UndoCommandBase()
{

}

void UndoCommandBase::redo()
{

}

void UndoCommandBase::undo()
{

}
UndoCommandMoveItems::UndoCommandMoveItems(QMap<Ball *, QPointF> oldBallPos,
                                           QMap<Ball *, QPointF> newBallPos,
                                           QGraphicsScene *scene,
                                           const QString &text, QUndoCommand *parent)
    :UndoCommandBase(text, parent)
{
    m_oldBallPos = oldBallPos;
    m_newBallPos = newBallPos;
    m_pScene = scene;
}

UndoCommandMoveItems::~UndoCommandMoveItems()
{
    m_oldBallPos.clear();
    m_newBallPos.clear();
}

void UndoCommandMoveItems::redo()
{
    auto items = m_pScene->items();
    for(auto item:items)
    {
        if(static_cast<ItemBase*>(item)->itemtype() == ItemBase::ball)
        {
            m_pScene->removeItem(item);
        }
    }
    for(auto pBall:m_newBallPos.keys())
    {
        if(!m_pScene->items().contains(pBall))
        {
            m_pScene->addItem(pBall);
        }
        pBall->setPos(m_newBallPos[pBall]);
    }
}

void UndoCommandMoveItems::undo()
{
    auto items = m_pScene->items();
    for(auto item:items)
    {
        if(static_cast<ItemBase*>(item)->itemtype() == ItemBase::ball)
        {
            m_pScene->removeItem(item);
        }
    }
    for(auto pBall:m_oldBallPos.keys())
    {
        if(!m_pScene->items().contains(pBall))
        {
            m_pScene->addItem(pBall);
        }
        pBall->setPos(m_oldBallPos[pBall]);
    }
}
