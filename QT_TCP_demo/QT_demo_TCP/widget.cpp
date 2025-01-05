#include "widget.h"
#include "ui_widget.h"
#include <QStyle>
#include <QStyleOption>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , isDragging(false)
    ,ui(new Ui::Widget)
{
    // 设置无边框样式
    setWindowFlags(Qt::FramelessWindowHint);

    setStyleSheet("background-color: #4CAF50;"); // 设置背景颜色
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}



void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        isDragging = true;
        dragStartPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (isDragging) {
        move(event->globalPos() - dragStartPosition);
        event->accept();
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        isDragging = false;
        event->accept();
    }
}
