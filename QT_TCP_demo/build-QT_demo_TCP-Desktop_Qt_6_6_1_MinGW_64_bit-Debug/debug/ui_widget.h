/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame_back;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_tools;
    QPushButton *pushButton_close;
    QPushButton *pushButton_sun;
    QPushButton *pushButton;
    QPushButton *pushButton_chagetools;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QFrame *frame_loacal;
    QFrame *frame_fuction;
    QHBoxLayout *horizontalLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1031, 540);
        Widget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame_back = new QFrame(Widget);
        frame_back->setObjectName("frame_back");
        frame_back->setStyleSheet(QString::fromUtf8("#frame_back{\n"
"	border-image: url(:/008 Rainy Ashville.png);\n"
"	 background-color: #4CAF50; /* \350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white;              /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border-radius: 0px;       /* \345\234\206\350\247\222\345\215\212\345\276\204\357\274\214\346\211\200\346\234\211\345\233\233\344\270\252\350\247\222\351\203\275\345\272\224\347\224\250\350\277\231\344\270\252\345\200\274 */\n"
"    padding: 5px;              /* \345\206\205\350\276\271\350\267\235 */\n"
"}\n"
"\n"
"\n"
"\n"
""));
        frame_back->setFrameShape(QFrame::StyledPanel);
        frame_back->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_back);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(frame_back);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(0, 0));
        frame->setMaximumSize(QSize(86, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_tools = new QWidget(frame);
        widget_tools->setObjectName("widget_tools");
        widget_tools->setStyleSheet(QString::fromUtf8("#widget_tools{\n"
"	\n"
"    background-color: transparent;\n"
"    border: 1px solid gray;\n"
"    border-radius: 4px;\n"
"}"));
        pushButton_close = new QPushButton(widget_tools);
        pushButton_close->setObjectName("pushButton_close");
        pushButton_close->setGeometry(QRect(10, 460, 61, 61));
        pushButton_close->setStyleSheet(QString::fromUtf8("#pushButton_close {\n"
"    border: 2px solid #00d3d3; /* \346\265\205\347\201\260\350\211\262\350\276\271\346\241\206 */\n"
"    border-radius:28px;       /* \345\234\206\350\247\222\345\215\212\345\276\204 */\n"
"    width: 40px;               /* \345\233\272\345\256\232\345\256\275\345\272\246 */\n"
"    height: 40px;             /* \345\233\272\345\256\232\351\253\230\345\272\246 */\n"
"    background: transparent;   /* \351\200\217\346\230\216\350\203\214\346\231\257 */\n"
"    color: white;             /* \346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"    font-size: 16px;         /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
""));
        pushButton_sun = new QPushButton(widget_tools);
        pushButton_sun->setObjectName("pushButton_sun");
        pushButton_sun->setGeometry(QRect(2, 480, 21, 21));
        pushButton_sun->setMinimumSize(QSize(0, 0));
        pushButton_sun->setMaximumSize(QSize(30, 30));
        pushButton_sun->setStyleSheet(QString::fromUtf8("border-image: url(:/moon.png);\n"
"/*border-image: url(:/sun.png);*/"));
        pushButton = new QPushButton(widget_tools);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(58, 477, 31, 31));
        pushButton->setMinimumSize(QSize(0, 0));
        pushButton->setMaximumSize(QSize(50, 50));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/sun.png);"));

        horizontalLayout_3->addWidget(widget_tools);


        horizontalLayout_2->addWidget(frame);

        pushButton_chagetools = new QPushButton(frame_back);
        pushButton_chagetools->setObjectName("pushButton_chagetools");
        pushButton_chagetools->setMaximumSize(QSize(20, 45));
        pushButton_chagetools->setStyleSheet(QString::fromUtf8("#pushButton_chagetools {\n"
"    background-color: transparent;\n"
"    border: 1px solid gray;\n"
"    border-radius: 4px;\n"
"    padding: 5px 10px;\n"
"    /* \344\270\215\350\246\201\344\275\277\347\224\250 border-image \346\235\245\350\256\276\347\275\256\345\233\276\346\240\207 */\n"
"}\n"
"\n"
"/* \346\202\250\345\217\257\344\273\245\346\267\273\345\212\240\345\205\266\344\273\226\347\212\266\346\200\201\346\240\267\345\274\217\357\274\214\345\246\202 :hover \345\222\214 :pressed */\n"
"#pushButton_chagetools:hover {\n"
"    border-color: darkgray;\n"
"}\n"
"\n"
"#pushButton_chagetools:pressed {\n"
"    border-color: black;\n"
"}"));

        horizontalLayout_2->addWidget(pushButton_chagetools);

        frame_2 = new QFrame(frame_back);
        frame_2->setObjectName("frame_2");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(8);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame_loacal = new QFrame(frame_2);
        frame_loacal->setObjectName("frame_loacal");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(frame_loacal->sizePolicy().hasHeightForWidth());
        frame_loacal->setSizePolicy(sizePolicy2);
        frame_loacal->setStyleSheet(QString::fromUtf8("    background-color: transparent;\n"
"    border: 1px solid gray;\n"
"    border-radius: 4px;"));
        frame_loacal->setFrameShape(QFrame::StyledPanel);
        frame_loacal->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame_loacal);

        frame_fuction = new QFrame(frame_2);
        frame_fuction->setObjectName("frame_fuction");
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(10);
        sizePolicy3.setHeightForWidth(frame_fuction->sizePolicy().hasHeightForWidth());
        frame_fuction->setSizePolicy(sizePolicy3);
        frame_fuction->setFrameShape(QFrame::StyledPanel);
        frame_fuction->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_fuction);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(frame_fuction);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("    background-color: transparent;\n"
"    border: 1px solid gray;\n"
"    border-radius: 4px;"));
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        horizontalLayout_4->addWidget(stackedWidget);


        verticalLayout->addWidget(frame_fuction);


        horizontalLayout_2->addWidget(frame_2);


        horizontalLayout->addWidget(frame_back);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton_close->setText(QString());
        pushButton_sun->setText(QString());
        pushButton->setText(QString());
        pushButton_chagetools->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
