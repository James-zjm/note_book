/********************************************************************************
** Form generated from reading UI file 'Notelist.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTELIST_H
#define UI_NOTELIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Notelist
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QWidget *Notelist)
    {
        if (Notelist->objectName().isEmpty())
            Notelist->setObjectName(QStringLiteral("Notelist"));
        Notelist->resize(395, 592);
        pushButton = new QPushButton(Notelist);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(227, 9, 75, 23));
        pushButton_2 = new QPushButton(Notelist);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(308, 9, 75, 23));
        lineEdit = new QLineEdit(Notelist);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 211, 20));
        scrollArea = new QScrollArea(Notelist);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 40, 381, 541));
        scrollArea->setMinimumSize(QSize(0, 0));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 362, 539));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 400));
        verticalLayoutWidget = new QWidget(scrollAreaWidgetContents);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 361, 551));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(Notelist);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Notelist, SLOT(new_note()));

        QMetaObject::connectSlotsByName(Notelist);
    } // setupUi

    void retranslateUi(QWidget *Notelist)
    {
        Notelist->setWindowTitle(QApplication::translate("Notelist", "Notelist", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Notelist", "\346\220\234\347\264\242", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Notelist", "\346\226\260\345\273\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Notelist: public Ui_Notelist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTELIST_H
