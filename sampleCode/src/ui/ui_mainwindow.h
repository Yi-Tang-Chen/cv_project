/********************************************************************************
** Form generated from reading UI file 'mainwindowqaXGZL.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWQAXGZL_H
#define MAINWINDOWQAXGZL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *button_verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QPushButton *captureButton;
    QPushButton *blendButton;
    QPushButton *calculateButton;
    QPushButton *DrawCircleButton;
    QPushButton *DrawLineButton;
    QPushButton *saveButton;
    QPushButton *resetButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *camera_horizontalLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1062, 620);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        button_verticalLayout = new QVBoxLayout();
        button_verticalLayout->setSpacing(5);
        button_verticalLayout->setObjectName(QString::fromUtf8("button_verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        button_verticalLayout->addItem(verticalSpacer_2);

        captureButton = new QPushButton(centralwidget);
        captureButton->setObjectName(QString::fromUtf8("captureButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(captureButton->sizePolicy().hasHeightForWidth());
        captureButton->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font.setPointSize(18);
        captureButton->setFont(font);

        button_verticalLayout->addWidget(captureButton);

        blendButton = new QPushButton(centralwidget);
        blendButton->setObjectName(QString::fromUtf8("blendButton"));
        blendButton->setFont(font);

        button_verticalLayout->addWidget(blendButton);

        calculateButton = new QPushButton(centralwidget);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));
        calculateButton->setFont(font);

        button_verticalLayout->addWidget(calculateButton);

        DrawCircleButton = new QPushButton(centralwidget);
        DrawCircleButton->setObjectName(QString::fromUtf8("DrawCircleButton"));
        DrawCircleButton->setFont(font);

        button_verticalLayout->addWidget(DrawCircleButton);

        DrawLineButton = new QPushButton(centralwidget);
        DrawLineButton->setObjectName(QString::fromUtf8("DrawLineButton"));
        DrawLineButton->setFont(font);

        button_verticalLayout->addWidget(DrawLineButton);

        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setEnabled(true);
        saveButton->setFont(font);

        button_verticalLayout->addWidget(saveButton);

        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setFont(font);

        button_verticalLayout->addWidget(resetButton);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        button_verticalLayout->addItem(verticalSpacer);

        button_verticalLayout->setStretch(0, 1);
        button_verticalLayout->setStretch(1, 3);
        button_verticalLayout->setStretch(2, 3);
        button_verticalLayout->setStretch(3, 3);
        button_verticalLayout->setStretch(6, 3);
        button_verticalLayout->setStretch(7, 3);
        button_verticalLayout->setStretch(8, 1);

        gridLayout->addLayout(button_verticalLayout, 6, 1, 1, 1);

        camera_horizontalLayout = new QHBoxLayout();
        camera_horizontalLayout->setObjectName(QString::fromUtf8("camera_horizontalLayout"));

        gridLayout->addLayout(camera_horizontalLayout, 0, 0, 10, 1);

        gridLayout->setRowStretch(6, 1);
        gridLayout->setColumnStretch(0, 2);
        gridLayout->setColumnStretch(1, 1);

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1062, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        captureButton->setText(QCoreApplication::translate("MainWindow", "Capture", nullptr));
        blendButton->setText(QCoreApplication::translate("MainWindow", "Blend Images", nullptr));
        calculateButton->setText(QCoreApplication::translate("MainWindow", "Calculate Angle", nullptr));
        DrawCircleButton->setText(QCoreApplication::translate("MainWindow", "Draw Circle", nullptr));
        DrawLineButton->setText(QCoreApplication::translate("MainWindow", "Draw Line", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Save Result", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWQAXGZL_H
