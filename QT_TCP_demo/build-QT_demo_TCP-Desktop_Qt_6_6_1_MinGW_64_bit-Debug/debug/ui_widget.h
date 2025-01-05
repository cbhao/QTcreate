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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame_back;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(831, 536);
        Widget->setStyleSheet(QString::fromUtf8("\n"
"color:#ffffff;\n"
"border-radius:4px;\n"
"\n"
""));
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
"    border-radius: 20px;       /* \345\234\206\350\247\222\345\215\212\345\276\204\357\274\214\346\211\200\346\234\211\345\233\233\344\270\252\350\247\222\351\203\275\345\272\224\347\224\250\350\277\231\344\270\252\345\200\274 */\n"
"    padding: 5px;              /* \345\206\205\350\276\271\350\267\235 */\n"
"}\n"
"\n"
"\n"
"\n"
""));
        frame_back->setFrameShape(QFrame::StyledPanel);
        frame_back->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame_back);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
