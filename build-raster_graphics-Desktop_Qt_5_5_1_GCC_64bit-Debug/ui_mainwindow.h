/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *Y0spinBox_2;
    QSpinBox *X0spinBox;
    QSpinBox *X1spinBox_3;
    QSpinBox *Y1spinBox_4;
    QHBoxLayout *horizontalLayout;
    QSpinBox *RspinBox_5;
    QSpinBox *GspinBox_6;
    QSpinBox *BspinBox_7;
    QPushButton *DrawLinepushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *clearButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(742, 632);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 400, 400));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(500, 10, 230, 228));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 6, 0, 1, 2);

        Y0spinBox_2 = new QSpinBox(verticalLayoutWidget);
        Y0spinBox_2->setObjectName(QStringLiteral("Y0spinBox_2"));
        Y0spinBox_2->setMaximum(400);

        gridLayout->addWidget(Y0spinBox_2, 1, 1, 1, 1);

        X0spinBox = new QSpinBox(verticalLayoutWidget);
        X0spinBox->setObjectName(QStringLiteral("X0spinBox"));
        X0spinBox->setMaximum(400);

        gridLayout->addWidget(X0spinBox, 1, 0, 1, 1);

        X1spinBox_3 = new QSpinBox(verticalLayoutWidget);
        X1spinBox_3->setObjectName(QStringLiteral("X1spinBox_3"));
        X1spinBox_3->setMaximum(400);

        gridLayout->addWidget(X1spinBox_3, 2, 0, 1, 1);

        Y1spinBox_4 = new QSpinBox(verticalLayoutWidget);
        Y1spinBox_4->setObjectName(QStringLiteral("Y1spinBox_4"));
        Y1spinBox_4->setMaximum(400);

        gridLayout->addWidget(Y1spinBox_4, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        RspinBox_5 = new QSpinBox(verticalLayoutWidget);
        RspinBox_5->setObjectName(QStringLiteral("RspinBox_5"));
        RspinBox_5->setMaximum(255);

        horizontalLayout->addWidget(RspinBox_5);

        GspinBox_6 = new QSpinBox(verticalLayoutWidget);
        GspinBox_6->setObjectName(QStringLiteral("GspinBox_6"));
        GspinBox_6->setMaximum(255);

        horizontalLayout->addWidget(GspinBox_6);

        BspinBox_7 = new QSpinBox(verticalLayoutWidget);
        BspinBox_7->setObjectName(QStringLiteral("BspinBox_7"));
        BspinBox_7->setMaximum(255);

        horizontalLayout->addWidget(BspinBox_7);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 2);

        DrawLinepushButton = new QPushButton(verticalLayoutWidget);
        DrawLinepushButton->setObjectName(QStringLiteral("DrawLinepushButton"));

        gridLayout->addWidget(DrawLinepushButton, 7, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 2);

        clearButton = new QPushButton(verticalLayoutWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        gridLayout->addWidget(clearButton, 8, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        DrawLinepushButton->setText(QApplication::translate("MainWindow", "Draw Line", 0));
        clearButton->setText(QApplication::translate("MainWindow", "Clear", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
