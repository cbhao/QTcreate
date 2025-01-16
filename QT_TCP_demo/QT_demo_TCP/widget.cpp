#include "widget.h"
#include "ui_widget.h"
#include <QStyle>
#include <QStyleOption>
#include <QPropertyAnimation> // 包含动画框架的头文件
#include <QTimer>
#include <QPainter>
#include <QPen>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , isDragging(false)
    ,ui(new Ui::Widget)
{
    // 设置无边框样式
    setWindowFlags(Qt::FramelessWindowHint);
    frame_tools();





    ui->setupUi(this);
    // 初始化半圆的大小和位置（这些可以在构造函数中设置，或者通过其他方法设置）
    QRect semiCircleRect = QRect(width() / 4, height() / 4, width() / 2, height() / 2);

}

Widget::~Widget()
{
    delete ui;
}


const int MINIMUM_LEFT_FRAME_WIDTH = 0; // 定义一个常量，规定动画的移动距离
void Widget::on_pushButton_chagetools_clicked()
{
    qDebug() << "on_pushButton_chagetools_clicked" << Qt::endl;
    static bool isExpanded = false;

    // 获取左侧工具栏、右侧工具栏和中间按钮的宽度及位置
    int leftFrameWidth = ui->frame->width();
    int rightFrameWidth = ui->frame_2->width();
    int pushButtonMiddleWidth = ui->pushButton_chagetools->width();

    //实现在收缩时，frame-widget也同时收缩(这里单独列出一个函数)



   //frame下的也同时扩大



    QRect pushButtonMiddleRect = ui->pushButton_chagetools->geometry();
    QRect rightFrameRect = ui->frame_2->geometry();

    qDebug() << "leftFrameWidth:" << leftFrameWidth << Qt::endl;
    qDebug() << "rightFrameWidth:" << rightFrameWidth << Qt::endl;
    qDebug() << "pushButtonMiddleWidth:" << pushButtonMiddleWidth << Qt::endl;

    // 计算新的左侧工具栏宽度
    int newLeftFrameWidth = isExpanded ? 86 : 0;

    // 计算右侧工具栏的新宽度
    int newRightFrameWidth = rightFrameWidth + (leftFrameWidth - newLeftFrameWidth);

    // 创建左侧工具栏的动画对象
    QPropertyAnimation *leftFrameAnimation = new QPropertyAnimation(ui->frame, "geometry");
    leftFrameAnimation->setDuration(500);
    QRect leftStartRect = ui->frame->geometry();
    QRect leftEndRect(leftStartRect.x(), leftStartRect.y(), newLeftFrameWidth, leftStartRect.height());
    leftFrameAnimation->setStartValue(leftStartRect);
    leftFrameAnimation->setEndValue(leftEndRect);

    // 创建右侧工具栏的动画对象
    QPropertyAnimation *rightFrameAnimation = new QPropertyAnimation(ui->frame_2, "geometry");
    rightFrameAnimation->setDuration(500);
    QRect rightEndRect(leftEndRect.right()+22, rightFrameRect.y(), newRightFrameWidth, rightFrameRect.height());
    rightFrameAnimation->setStartValue(rightFrameRect);
    rightFrameAnimation->setEndValue(rightEndRect);

    // 计算按钮的新位置
    int newPushButtonX = leftEndRect.right() +1.5; // 假设按钮与左侧工具栏之间有一定的间隔
    QRect pushButtonEndRect(newPushButtonX, pushButtonMiddleRect.y(), pushButtonMiddleRect.width(), pushButtonMiddleRect.height());

    // 创建按钮的动画对象
    QPropertyAnimation *buttonAnimation = new QPropertyAnimation(ui->pushButton_chagetools, "geometry");
    buttonAnimation->setDuration(500);
    buttonAnimation->setStartValue(pushButtonMiddleRect);
    buttonAnimation->setEndValue(pushButtonEndRect);

    leftFrameAnimation->start(QAbstractAnimation::DeleteWhenStopped);
    rightFrameAnimation->start(QAbstractAnimation::DeleteWhenStopped);
    buttonAnimation->start(QAbstractAnimation::DeleteWhenStopped);
    // 更新状态
    isExpanded = !isExpanded;
}

void Widget::updateTime()
{
    // 获取当前时间
    QTime currentTime = QTime::currentTime();

    // 更新标签上的时间
    // timeLabel->setText("Current time: " + currentTime.toString("hh:mm:ss"));

    // 打印当前时间到控制台（可选）
    qDebug() << "Current time:" << currentTime.toString("hh:mm:ss");
}

void Widget::frame_tools()
{
    //创建一个定时器
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::updateTime);
    //获取当前时间
    curren_time =  QTime::currentTime();
    qDebug() << "Current time:" << curren_time.toString("hh:mm:ss");
    //设计widget下的button的UI设计，设计图标，以及布局

    // 启动定时器，每隔1000毫秒（1秒）触发一次
    timer->start(1000);

    // 初始更新时间
    updateTime();






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
