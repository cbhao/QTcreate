#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void on_pushButton_chagetools_clicked();
    void updateTime();

private:
    Ui::Widget *ui;

    bool isDragging;
    QPoint dragStartPosition;
    void frame_tools(void);
    // bool isExpanded = false; // 初始状态为收缩

public:
    QTime curren_time;


};
#endif // WIDGET_H
