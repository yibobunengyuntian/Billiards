
#ifndef GCANVASVIEW_H
#define GCANVASVIEW_H


#include <QObject>
#include <QGraphicsView>
#include <QTimer>


class GCanvasBaseOperator;
class GCanvasView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GCanvasView(QWidget *parent = nullptr);
    ~GCanvasView();

    void createScene();

    void setOperatorObj(QSharedPointer<GCanvasBaseOperator> op);
    QSharedPointer<GCanvasBaseOperator> operatorObj();

protected:
    void initialize();

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;
    void timerEvent(QTimerEvent *event) override;

    bool event(QEvent *event) override;
private:
    QSharedPointer<GCanvasBaseOperator> m_pOperator;
    bool m_isPressed                    = false;
    bool m_isDoubleClick                = false;
};

#endif // GCANVASVIEW_H
