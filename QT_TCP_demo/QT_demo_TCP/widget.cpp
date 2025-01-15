#include "widget.h"
#include "ui_widget.h"
#include <QStyle>
#include <QStyleOption>
#include <QPropertyAnimation> // 包含动画框架的头文件
#include <QTimer>

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
    int newLeftFrameWidth = isExpanded ? 84 : 0;

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
// void Widget::on_pushButton_chagetools_clicked()
// {
//     qDebug() << "on_pushButton_chagetools_clicked" << Qt::endl;
//     static bool isExpanded = true;

//     // 获取左侧工具栏和右侧工具栏的宽度
//     int leftFrameWidth = ui->frame->width();
//     int rightFrameWidth = ui->frame_2->width();
//     // 获取按键的宽度和当前位置
//     int pushButtonMiddleWidth = ui->pushButton_chagetools->width();
//     QRect pushButtonMiddleRect = ui->pushButton_chagetools->geometry();

//     int totalWidth = leftFrameWidth + rightFrameWidth + pushButtonMiddleWidth;

//     qDebug() << "leftFrameWidth:" << leftFrameWidth << Qt::endl;
//     qDebug() << "rightFrameWidth:" << rightFrameWidth << Qt::endl;
//     qDebug() << "pushButtonMiddleWidth:" << pushButtonMiddleWidth << Qt::endl;

//     // 计算新的左侧工具栏宽度
//     int newLeftFrameWidth = isExpanded ? 0 : 84;
//     // 确保左边宽度不会小于最小值
//     newLeftFrameWidth = std::max(newLeftFrameWidth, (isExpanded ? MINIMUM_LEFT_FRAME_WIDTH : 84));

//     // 创建左侧工具栏的动画对象
//     QPropertyAnimation *leftFrameAnimation = new QPropertyAnimation(ui->frame, "geometry");
//     leftFrameAnimation->setDuration(500);
//     QRect leftStartRect = ui->frame->geometry();
//     QRect leftEndRect(leftStartRect.x(), leftStartRect.y(), newLeftFrameWidth, leftStartRect.height());
//     leftFrameAnimation->setStartValue(leftStartRect);
//     leftFrameAnimation->setEndValue(leftEndRect);
//     leftFrameAnimation->start(QAbstractAnimation::DeleteWhenStopped);

//     // 计算按钮的新位置
//     int newPushButtonX = leftEndRect.right() + (isExpanded ? 0 : 2);
//     QRect pushButtonEndRect(newPushButtonX, pushButtonMiddleRect.y(), pushButtonMiddleRect.width(), pushButtonMiddleRect.height());

//     // 创建按钮的动画对象
//     QPropertyAnimation *buttonAnimation = new QPropertyAnimation(ui->pushButton_chagetools, "geometry");
//     buttonAnimation->setDuration(500);
//     buttonAnimation->setStartValue(pushButtonMiddleRect);
//     buttonAnimation->setEndValue(pushButtonEndRect);
//     buttonAnimation->start(QAbstractAnimation::DeleteWhenStopped);

//     // 更新状态
//     isExpanded = !isExpanded;
// }
// void Widget::on_pushButton_chagetools_clicked()
// {
//     qDebug()<< "on_pushButton_chagetools_clicked" << Qt::endl;
//     static bool isExpanded = true;
//     //获取左侧工具栏的wideth
//     int leftFrameWidth = ui->frame->width();
//     //获取右侧工具栏的wideth
//     int rightFrameWidth = ui->frame_2->width();
//     //获取按键的宽度
//     int pushButtonMiddleWidth = ui->pushButton_chagetools->width();

//     int totalWidth = leftFrameWidth + rightFrameWidth + pushButtonMiddleWidth; // 包括中间按钮的宽度

//     qDebug()<< "leftFrameWidth:"<< leftFrameWidth << Qt::endl;
//     qDebug()<< "rightFrameWidth:"<< rightFrameWidth << Qt::endl;
//     qDebug()<< "pushButtonMiddleWidth:"<< pushButtonMiddleWidth << Qt::endl;

//     // //计算需要移动的距离
//     // int changeAmount = 100;

//     int newLeftFrameWidth = isExpanded? 0 : 84;

//     // 确保左边宽度不会小于最小值
//     if(isExpanded) newLeftFrameWidth = std::max(newLeftFrameWidth, MINIMUM_LEFT_FRAME_WIDTH);
//     else newLeftFrameWidth = std::max(newLeftFrameWidth, 84);

//     // 创建动画对象
//     QPropertyAnimation *leftFrameAnimation = new QPropertyAnimation(ui->frame, "geometry");

//     //动画持续500ms
//     leftFrameAnimation->setDuration(500);

//     //获取开始的坐标
//     QRect leftStartRect = ui->frame->geometry();


//     QRect leftEndRect(leftStartRect.x(), leftStartRect.y(), newLeftFrameWidth, leftStartRect.height());
//     //开始
//     leftFrameAnimation->setStartValue(leftStartRect);
//     //结束
//     leftFrameAnimation->setEndValue(leftEndRect);


//     leftFrameAnimation->start(QAbstractAnimation::DeleteWhenStopped);
//     isExpanded = !isExpanded;
// }


// void Widget::on_pushButton_chagetools_clicked()
// {

//     // ui->pushButton_chagetools->setEnabled(false);
//     // static int isExpanded = 0;
//     static bool isExpanded = true;
//     static int leftFrameWidth = ui->frame->width();
//     static int rightFrameWidth = ui->frame_2->width();
//     static int pushButtonMiddleWidth = ui->pushButton_chagetools->width();
//     int totalWidth = leftFrameWidth + rightFrameWidth + pushButtonMiddleWidth; // 包括中间按钮的宽度
//     int changeAmount = 100;

//     // 计算新宽度
//     int newLeftFrameWidth = isExpanded ? leftFrameWidth - changeAmount : leftFrameWidth + changeAmount;
//     int newRightFrameWidth = totalWidth - newLeftFrameWidth - pushButtonMiddleWidth; // 减去中间按钮的宽度

//     // 确保左边宽度不会小于最小值
//     newLeftFrameWidth = std::max(newLeftFrameWidth, MINIMUM_LEFT_FRAME_WIDTH);
//     newRightFrameWidth = totalWidth - newLeftFrameWidth - pushButtonMiddleWidth; // 重新计算

//     // 按钮的新位置
//     int newMiddleButtonX = ui->frame->geometry().right() + (isExpanded ? -changeAmount : changeAmount);

//     // 创建动画对象
//     QPropertyAnimation *leftFrameAnimation = new QPropertyAnimation(ui->frame, "geometry");
//     QPropertyAnimation *rightFrameAnimation = new QPropertyAnimation(ui->frame_2, "geometry");
//     QPropertyAnimation *middleButtonAnimation = new QPropertyAnimation(ui->pushButton_chagetools, "geometry");

//     // 设置动画属性
//     leftFrameAnimation->setDuration(500);
//     rightFrameAnimation->setDuration(500);
//     middleButtonAnimation->setDuration(500);

//     QRect leftStartRect = ui->frame->geometry();
//     QRect rightStartRect = ui->frame_2->geometry();
//     QRect middleStartRect = ui->pushButton_chagetools->geometry();
//     QRect leftEndRect(leftStartRect.x(), leftStartRect.y(), newLeftFrameWidth, leftStartRect.height());
//     QRect rightEndRect(leftEndRect.right() + pushButtonMiddleWidth, rightStartRect.y(), newRightFrameWidth, rightStartRect.height());
//     QRect middleEndRect(newLeftFrameWidth, middleStartRect.y(), pushButtonMiddleWidth, middleStartRect.height());

//     // 设置动画的起始和结束值

//     // if (isExpanded)
//     // {
//     //     qDebug()<<isExpanded<<Qt::endl;
//     //     leftFrameAnimation->setStartValue(leftStartRect);
//     //     leftFrameAnimation->setEndValue(leftEndRect);
//     //     rightFrameAnimation->setStartValue(rightStartRect);
//     //     rightFrameAnimation->setEndValue(rightEndRect);
//     //     middleButtonAnimation->setStartValue(middleStartRect);
//     //     middleButtonAnimation->setEndValue(QRect(newLeftFrameWidth, middleStartRect.y(), pushButtonMiddleWidth, middleStartRect.height()));

//     //          } else {
//         qDebug()<<isExpanded<<Qt::endl;


//         leftFrameAnimation->setStartValue(leftEndRect);
//         leftFrameAnimation->setEndValue(leftStartRect);
//         rightFrameAnimation->setStartValue(rightEndRect);
//         rightFrameAnimation->setEndValue(rightStartRect);
//         middleButtonAnimation->setStartValue(QRect(newLeftFrameWidth, middleStartRect.y(), pushButtonMiddleWidth, middleStartRect.height()));
//          middleButtonAnimation->setEndValue(middleStartRect);
//     // }

//     // 启动动画并更新状态
//     leftFrameAnimation->start(QAbstractAnimation::DeleteWhenStopped);
//     rightFrameAnimation->start(QAbstractAnimation::DeleteWhenStopped);
//     middleButtonAnimation->start(QAbstractAnimation::DeleteWhenStopped);

//     isExpanded = !isExpanded;
//     // ui->pushButton_chagetools->setEnabled(true);
// }
// void Widget::on_pushButton_chagetools_clicked()
// {

//     // 获取当前宽度
//     static int leftFrameWidth = ui->frame->width();
//     static int rightFrameWidth = ui->frame_2->width();
//     static int pushbuttonWidth = ui->pushButton_chagetools->width();

//     // 定义变化量（可以根据需要调整）
//     int changeAmount = 50; // 例如，每次点击按钮时左边缩小 50，右边增大 50

//     // 计算新宽度，确保左边不会缩小到小于某个最小值
//     int newLeftFrameWidth = std::max(leftFrameWidth - changeAmount, MINIMUM_LEFT_FRAME_WIDTH);
//     int newRightFrameWidth = rightFrameWidth + (leftFrameWidth - newLeftFrameWidth);
//     int newPushFrameWidth = pushbuttonWidth + (leftFrameWidth - newLeftFrameWidth);

//     // 创建动画对象
//     QPropertyAnimation *leftFrameAnimation = new QPropertyAnimation(ui->frame, "geometry");
//     QPropertyAnimation *rightFrameAnimation = new QPropertyAnimation(ui->frame_2, "geometry");
//     QPropertyAnimation *pushbuttonAnimation = new QPropertyAnimation(ui->pushButton_chagetools, "geometry");

//     // 设置动画属性
//     leftFrameAnimation->setDuration(500); // 动画持续时间，单位为毫秒
//     leftFrameAnimation->setStartValue(QRect(ui->frame->geometry().x(), ui->frame->geometry().y(), leftFrameWidth, ui->frame->geometry().height()));
//     leftFrameAnimation->setEndValue(QRect(ui->frame->geometry().x(), ui->frame->geometry().y(), newLeftFrameWidth, ui->frame->geometry().height()));

//     rightFrameAnimation->setDuration(500); // 与左边动画相同的时间
//     // 注意：由于右边框架的 x 位置可能会随着左边框架的缩小而移动，这里需要计算新的 x 位置
//     int newRightFrameX = ui->frame_2->geometry().x() - (leftFrameWidth - newLeftFrameWidth);
//     rightFrameAnimation->setStartValue(QRect(ui->frame_2->geometry().x(), ui->frame_2->geometry().y(), rightFrameWidth, ui->frame_2->geometry().height()));
//     rightFrameAnimation->setEndValue(QRect(newRightFrameX, ui->frame_2->geometry().y(), newRightFrameWidth, ui->frame_2->geometry().height()));


//     pushbuttonAnimation->setDuration(500);
//     int newPushbotton = ui->pushButton_chagetools->geometry().x()-(leftFrameWidth - newLeftFrameWidth);
//     pushbuttonAnimation->setStartValue(QRect(ui->pushButton_chagetools->geometry().x(),ui->pushButton_chagetools->geometry().y(),pushbuttonWidth,ui->pushButton_chagetools->geometry().height()));
//     pushbuttonAnimation->setEndValue(QRect(newPushbotton, ui->pushButton_chagetools->geometry().y(), newPushFrameWidth, ui->pushButton_chagetools->geometry().height()));

//     // 启动动画
//     leftFrameAnimation->start(QAbstractAnimation::DeleteWhenStopped); // 动画结束后自动删除对象
//     rightFrameAnimation->start(QAbstractAnimation::DeleteWhenStopped); // 同上
//     pushbuttonAnimation->start(QAbstractAnimation::DeleteWhenStopped);
// }

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
