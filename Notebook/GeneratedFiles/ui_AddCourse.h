/********************************************************************************
** Form generated from reading UI file 'AddCourse.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOURSE_H
#define UI_ADDCOURSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddCourse
{
public:
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *okbutton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_19;
    QPushButton *pushButton_13;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_15;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_16;
    QPushButton *pushButton_10;
    QPushButton *pushButton_9;
    QPushButton *pushButton_17;
    QPushButton *pushButton_20;
    QPushButton *pushButton_18;
    QPushButton *pushButton_12;
    QPushButton *pushButton_11;
    QPushButton *pushButton_14;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QPushButton *pushButton_25;

    void setupUi(QDialog *AddCourse)
    {
        if (AddCourse->objectName().isEmpty())
            AddCourse->setObjectName(QStringLiteral("AddCourse"));
        AddCourse->resize(600, 411);
        label_2 = new QLabel(AddCourse);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 100, 91, 31));
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);
        label = new QLabel(AddCourse);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 91, 31));
        label->setFont(font);
        lineEdit = new QLineEdit(AddCourse);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 35, 351, 20));
        okbutton = new QPushButton(AddCourse);
        okbutton->setObjectName(QStringLiteral("okbutton"));
        okbutton->setGeometry(QRect(240, 360, 75, 23));
        gridLayoutWidget = new QWidget(AddCourse);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(40, 140, 521, 211));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_1 = new QPushButton(gridLayoutWidget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));

        gridLayout->addWidget(pushButton_1, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_19 = new QPushButton(gridLayoutWidget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));

        gridLayout->addWidget(pushButton_19, 3, 3, 1, 1);

        pushButton_13 = new QPushButton(gridLayoutWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));

        gridLayout->addWidget(pushButton_13, 2, 2, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 0, 3, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 1, 0, 1, 1);

        pushButton_15 = new QPushButton(gridLayoutWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));

        gridLayout->addWidget(pushButton_15, 2, 4, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 1, 1, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 1, 2, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 0, 4, 1, 1);

        pushButton_16 = new QPushButton(gridLayoutWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));

        gridLayout->addWidget(pushButton_16, 3, 0, 1, 1);

        pushButton_10 = new QPushButton(gridLayoutWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        gridLayout->addWidget(pushButton_10, 1, 4, 1, 1);

        pushButton_9 = new QPushButton(gridLayoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        gridLayout->addWidget(pushButton_9, 1, 3, 1, 1);

        pushButton_17 = new QPushButton(gridLayoutWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));

        gridLayout->addWidget(pushButton_17, 3, 1, 1, 1);

        pushButton_20 = new QPushButton(gridLayoutWidget);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));

        gridLayout->addWidget(pushButton_20, 3, 4, 1, 1);

        pushButton_18 = new QPushButton(gridLayoutWidget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));

        gridLayout->addWidget(pushButton_18, 3, 2, 1, 1);

        pushButton_12 = new QPushButton(gridLayoutWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

        gridLayout->addWidget(pushButton_12, 2, 1, 1, 1);

        pushButton_11 = new QPushButton(gridLayoutWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        gridLayout->addWidget(pushButton_11, 2, 0, 1, 1);

        pushButton_14 = new QPushButton(gridLayoutWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));

        gridLayout->addWidget(pushButton_14, 2, 3, 1, 1);

        pushButton_21 = new QPushButton(gridLayoutWidget);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));

        gridLayout->addWidget(pushButton_21, 4, 0, 1, 1);

        pushButton_22 = new QPushButton(gridLayoutWidget);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));

        gridLayout->addWidget(pushButton_22, 4, 1, 1, 1);

        pushButton_23 = new QPushButton(gridLayoutWidget);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));

        gridLayout->addWidget(pushButton_23, 4, 2, 1, 1);

        pushButton_24 = new QPushButton(gridLayoutWidget);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));

        gridLayout->addWidget(pushButton_24, 4, 3, 1, 1);

        pushButton_25 = new QPushButton(gridLayoutWidget);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));

        gridLayout->addWidget(pushButton_25, 4, 4, 1, 1);


        retranslateUi(AddCourse);
        QObject::connect(lineEdit, SIGNAL(textEdited(QString)), AddCourse, SLOT(getName()));
        QObject::connect(okbutton, SIGNAL(clicked()), AddCourse, SLOT(determine()));

        QMetaObject::connectSlotsByName(AddCourse);
    } // setupUi

    void retranslateUi(QDialog *AddCourse)
    {
        AddCourse->setWindowTitle(QApplication::translate("AddCourse", "AddCourse", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddCourse", "\350\257\276\347\250\213\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("AddCourse", "\350\257\276\347\250\213\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        okbutton->setText(QApplication::translate("AddCourse", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_1->setText(QString());
        pushButton_2->setText(QString());
        pushButton_19->setText(QString());
        pushButton_13->setText(QString());
        pushButton_4->setText(QString());
        pushButton_6->setText(QString());
        pushButton_15->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        pushButton_3->setText(QString());
        pushButton_5->setText(QString());
        pushButton_16->setText(QString());
        pushButton_10->setText(QString());
        pushButton_9->setText(QString());
        pushButton_17->setText(QString());
        pushButton_20->setText(QString());
        pushButton_18->setText(QString());
        pushButton_12->setText(QString());
        pushButton_11->setText(QString());
        pushButton_14->setText(QString());
        pushButton_21->setText(QString());
        pushButton_22->setText(QString());
        pushButton_23->setText(QString());
        pushButton_24->setText(QString());
        pushButton_25->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddCourse: public Ui_AddCourse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOURSE_H
