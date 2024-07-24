#ifndef UNDOCOMMANDS_H
#define UNDOCOMMANDS_H

#include <QUndoCommand>
#include <QMap>
#include "ball.h"

class UndoCommandBase : public QObject,public QUndoCommand
{
    Q_OBJECT
public:
    explicit UndoCommandBase(const QString &text, QUndoCommand *parent = nullptr);
    ~UndoCommandBase();

    virtual void redo() override;
    virtual void undo() override;

private:


};

class UndoCommandMoveItems : public UndoCommandBase
{
    Q_OBJECT
public:
    explicit UndoCommandMoveItems(QMap<Ball *, QPointF> oldBallPos,
                                  QMap<Ball *, QPointF> newBallPos,
                                  QGraphicsScene *scene,
                                  const QString &text, QUndoCommand *parent = nullptr);
    ~UndoCommandMoveItems();

    virtual void redo() override;
    virtual void undo() override;

private:
    QMap<Ball *, QPointF> m_oldBallPos;
    QMap<Ball *, QPointF> m_newBallPos;
    QGraphicsScene *m_pScene = nullptr;
};

#endif // UNDOCOMMANDS_H
