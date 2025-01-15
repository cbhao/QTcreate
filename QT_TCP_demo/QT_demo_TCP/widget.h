#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>

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

private:
    bool isDragging;
    bool isOriginalState = false;
    QPoint dragStartPosition;
    void frame_tools(void);
    // bool isExpanded = false; // 初始状态为收缩

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
