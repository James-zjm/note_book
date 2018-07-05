/********************************************************************************
** Form generated from reading UI file 'Notebook.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEBOOK_H
#define UI_NOTEBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NotebookClass
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addCourseButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *deleteCourseButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *synchronizeButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *teamworkButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QPushButton *pushButton_21;
    QLabel *label;
    QPushButton *pushButton_12;
    QPushButton *pushButton_4;
    QPushButton *pushButton_14;
    QPushButton *pushButton_20;
    QPushButton *pushButton_7;
    QPushButton *pushButton_23;
    QPushButton *pushButton_13;
    QPushButton *pushButton_16;
    QPushButton *pushButton_11;
    QPushButton *pushButton_8;
    QPushButton *pushButton_10;
    QPushButton *pushButton_1;
    QPushButton *pushButton_15;
    QPushButton *pushButton_22;
    QPushButton *pushButton_9;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_25;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_19;
    QPushButton *pushButton_24;
    QLabel *label_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NotebookClass)
    {
        if (NotebookClass->objectName().isEmpty())
            NotebookClass->setObjectName(QStringLiteral("NotebookClass"));
        NotebookClass->resize(785, 580);
        centralWidget = new QWidget(NotebookClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(110, 510, 541, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        addCourseButton = new QPushButton(horizontalLayoutWidget);
        addCourseButton->setObjectName(QStringLiteral("addCourseButton"));

        horizontalLayout->addWidget(addCourseButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        deleteCourseButton = new QPushButton(horizontalLayoutWidget);
        deleteCourseButton->setObjectName(QStringLiteral("deleteCourseButton"));

        horizontalLayout->addWidget(deleteCourseButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        synchronizeButton = new QPushButton(horizontalLayoutWidget);
        synchronizeButton->setObjectName(QStringLiteral("synchronizeButton"));

        horizontalLayout->addWidget(synchronizeButton);

        horizontalSpacer_2 = new QSpacerItem(40, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        teamworkButton = new QPushButton(horizontalLayoutWidget);
        teamworkButton->setObjectName(QStringLiteral("teamworkButton"));

        horizontalLayout->addWidget(teamworkButton);

        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 20, 731, 481));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        pushButton_21 = new QPushButton(gridLayoutWidget);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));

        gridLayout->addWidget(pushButton_21, 4, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 2, 0, 2, 1);

        pushButton_12 = new QPushButton(gridLayoutWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

        gridLayout->addWidget(pushButton_12, 2, 2, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 0, 4, 1, 1);

        pushButton_14 = new QPushButton(gridLayoutWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));

        gridLayout->addWidget(pushButton_14, 2, 4, 1, 1);

        pushButton_20 = new QPushButton(gridLayoutWidget);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));

        gridLayout->addWidget(pushButton_20, 3, 5, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 1, 2, 1, 1);

        pushButton_23 = new QPushButton(gridLayoutWidget);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));

        gridLayout->addWidget(pushButton_23, 4, 3, 1, 1);

        pushButton_13 = new QPushButton(gridLayoutWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));

        gridLayout->addWidget(pushButton_13, 2, 3, 1, 1);

        pushButton_16 = new QPushButton(gridLayoutWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));

        gridLayout->addWidget(pushButton_16, 3, 1, 1, 1);

        pushButton_11 = new QPushButton(gridLayoutWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        gridLayout->addWidget(pushButton_11, 2, 1, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 1, 3, 1, 1);

        pushButton_10 = new QPushButton(gridLayoutWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        gridLayout->addWidget(pushButton_10, 1, 5, 1, 1);

        pushButton_1 = new QPushButton(gridLayoutWidget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));

        gridLayout->addWidget(pushButton_1, 0, 1, 1, 1);

        pushButton_15 = new QPushButton(gridLayoutWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));

        gridLayout->addWidget(pushButton_15, 2, 5, 1, 1);

        pushButton_22 = new QPushButton(gridLayoutWidget);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));

        gridLayout->addWidget(pushButton_22, 4, 2, 1, 1);

        pushButton_9 = new QPushButton(gridLayoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        gridLayout->addWidget(pushButton_9, 1, 4, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 0, 5, 1, 1);

        pushButton_17 = new QPushButton(gridLayoutWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));

        gridLayout->addWidget(pushButton_17, 3, 2, 1, 1);

        pushButton_18 = new QPushButton(gridLayoutWidget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));

        gridLayout->addWidget(pushButton_18, 3, 3, 1, 1);

        pushButton_25 = new QPushButton(gridLayoutWidget);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));

        gridLayout->addWidget(pushButton_25, 4, 5, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 2, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 3, 1, 1);

        pushButton_19 = new QPushButton(gridLayoutWidget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));

        gridLayout->addWidget(pushButton_19, 3, 4, 1, 1);

        pushButton_24 = new QPushButton(gridLayoutWidget);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));

        gridLayout->addWidget(pushButton_24, 4, 4, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 0, 2, 1);

        NotebookClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(NotebookClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        NotebookClass->setStatusBar(statusBar);

        retranslateUi(NotebookClass);
        QObject::connect(addCourseButton, SIGNAL(clicked()), NotebookClass, SLOT(addcourse()));
        QObject::connect(deleteCourseButton, SIGNAL(clicked()), NotebookClass, SLOT(deletecourse()));
        QObject::connect(synchronizeButton, SIGNAL(clicked()), NotebookClass, SLOT(synchronize()));

        QMetaObject::connectSlotsByName(NotebookClass);
    } // setupUi

    void retranslateUi(QMainWindow *NotebookClass)
    {
        NotebookClass->setWindowTitle(QApplication::translate("NotebookClass", "Notebook", Q_NULLPTR));
        addCourseButton->setText(QApplication::translate("NotebookClass", "\346\267\273\345\212\240\350\257\276\347\250\213", Q_NULLPTR));
        deleteCourseButton->setText(QApplication::translate("NotebookClass", "\345\210\240\351\231\244\350\257\276\347\250\213", Q_NULLPTR));
        synchronizeButton->setText(QApplication::translate("NotebookClass", "\345\220\214\346\255\245", Q_NULLPTR));
        teamworkButton->setText(QApplication::translate("NotebookClass", "\345\244\232\344\272\272\345\215\217\344\275\234", Q_NULLPTR));
        label_3->setText(QApplication::translate("NotebookClass", "      \346\231\232\344\270\212", Q_NULLPTR));
        pushButton_21->setText(QString());
        label->setText(QApplication::translate("NotebookClass", "      \344\270\213\345\215\210", Q_NULLPTR));
        pushButton_12->setText(QString());
        pushButton_4->setText(QString());
        pushButton_14->setText(QString());
        pushButton_20->setText(QString());
        pushButton_7->setText(QString());
        pushButton_23->setText(QString());
        pushButton_13->setText(QString());
        pushButton_16->setText(QString());
        pushButton_11->setText(QString());
        pushButton_8->setText(QString());
        pushButton_10->setText(QString());
        pushButton_1->setText(QString());
        pushButton_15->setText(QString());
        pushButton_22->setText(QString());
        pushButton_9->setText(QString());
        pushButton_6->setText(QString());
        pushButton_5->setText(QString());
        pushButton_17->setText(QString());
        pushButton_18->setText(QString());
        pushButton_25->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_19->setText(QString());
        pushButton_24->setText(QString());
        label_2->setText(QApplication::translate("NotebookClass", "      \344\270\212\345\215\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NotebookClass: public Ui_NotebookClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEBOOK_H
