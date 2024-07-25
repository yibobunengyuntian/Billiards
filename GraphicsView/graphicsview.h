
#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H


#include <QObject>
#include <QGraphicsView>
#include <QTimer>


class BaseOperator;
class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphicsView(QWidget *parent = nullptr);
    ~GraphicsView();

    void createScene();

    void setOperatorObj(QSharedPointer<BaseOperator> op);
    QSharedPointer<BaseOperator> operatorObj();

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
    QSharedPointer<BaseOperator> m_pOperator;
    bool m_isPressed                    = false;
    bool m_isDoubleClick                = false;
};

#endif // GRAPHICSVIEW_H
