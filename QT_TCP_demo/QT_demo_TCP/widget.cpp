#include "widget.h"
#include "ui_widget.h"
#include <QStyle>
#include <QStyleOption>
#include <QPropertyAnimation> // 包含动画框架的头文件

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , isDragging(false)
    ,ui(new Ui::Widget)
{
    // 设置无边框样式
    setWindowFlags(Qt::FramelessWindowHint);

    setStyleSheet("background-color: #4CAF50;"); // 设置背景颜色
    ui->setupUi(this);
    connect(ui->pushButton_chagetools,&QPushButton::clicked,this,&Widget::on_pushButton_chagetools_clicked);
}

Widget::~Widget()
{
    delete ui;
}




const int MINIMUM_LEFT_FRAME_WIDTH = 1; // 定义一个常量，规定动画的移动距离

void Widget::on_pushButton_chagetools_clicked()
{
    // 获取当前宽度
    int leftFrameWidth = ui->frame->width();
    int rightFrameWidth = ui->frame_2->width();
    int pushbuttonWidth = ui->pushButton_chagetools->width();

    // 定义变化量（可以根据需要调整）
    int changeAmount = 50; // 例如，每次点击按钮时左边缩小 50，右边增大 50

    // 计算新宽度，确保左边不会缩小到小于某个最小值
    int newLeftFrameWidth = std::max(leftFrameWidth - changeAmount, MINIMUM_LEFT_FRAME_WIDTH);
    int newRightFrameWidth = rightFrameWidth + (leftFrameWidth - newLeftFrameWidth);
    int newPushFrameWidth = pushbuttonWidth + (leftFrameWidth - newLeftFrameWidth);

    // 创建动画对象
    QPropertyAnimation *leftFrameAnimation = new QPropertyAnimation(ui->frame, "geometry");
    QPropertyAnimation *rightFrameAnimation = new QPropertyAnimation(ui->frame_2, "geometry");
    QPropertyAnimation *pushbuttonAnimation = new QPropertyAnimation(ui->pushButton_chagetools, "geometry");

    // 设置动画属性
    leftFrameAnimation->setDuration(500); // 动画持续时间，单位为毫秒
    leftFrameAnimation->setStartValue(QRect(ui->frame->geometry().x(), ui->frame->geometry().y(), leftFrameWidth, ui->frame->geometry().height()));
    leftFrameAnimation->setEndValue(QRect(ui->frame->geometry().x(), ui->frame->geometry().y(), newLeftFrameWidth, ui->frame->geometry().height()));

    rightFrameAnimation->setDuration(500); // 与左边动画相同的时间
    // 注意：由于右边框架的 x 位置可能会随着左边框架的缩小而移动，这里需要计算新的 x 位置
    int newRightFrameX = ui->frame_2->geometry().x() - (leftFrameWidth - newLeftFrameWidth);
    rightFrameAnimation->setStartValue(QRect(ui->frame_2->geometry().x(), ui->frame_2->geometry().y(), rightFrameWidth, ui->frame_2->geometry().height()));
    rightFrameAnimation->setEndValue(QRect(newRightFrameX, ui->frame_2->geometry().y(), newRightFrameWidth, ui->frame_2->geometry().height()));


    pushbuttonAnimation->setDuration(500);
    int newPushbotton = ui->pushButton_chagetools->geometry().x()-(leftFrameWidth - newLeftFrameWidth);
    pushbuttonAnimation->setStartValue(QRect(ui->pushButton_chagetools->geometry().x(),ui->pushButton_chagetools->geometry().y(),pushbuttonWidth,ui->pushButton_chagetools->geometry().height()));
    pushbuttonAnimation->setEndValue(QRect(newPushbotton, ui->pushButton_chagetools->geometry().y(), newPushFrameWidth, ui->pushButton_chagetools->geometry().height()));

    // 启动动画
    leftFrameAnimation->start(QAbstractAnimation::DeleteWhenStopped); // 动画结束后自动删除对象
    rightFrameAnimation->start(QAbstractAnimation::DeleteWhenStopped); // 同上
    pushbuttonAnimation->start(QAbstractAnimation::DeleteWhenStopped);
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
