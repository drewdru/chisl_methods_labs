/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QSpinBox *spinBox_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_5;
    QSpinBox *spinBox;
    QDoubleSpinBox *doubleSpinBox_5;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1231, 502);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(150, 16777215));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 1, 1, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 120));
        groupBox->setMaximumSize(QSize(16777215, 120));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_9->addWidget(label_8);

        spinBox_3 = new QSpinBox(groupBox);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setReadOnly(true);
        spinBox_3->setMinimum(1);
        spinBox_3->setValue(2);

        horizontalLayout_9->addWidget(spinBox_3);


        gridLayout_2->addLayout(horizontalLayout_9, 0, 10, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(0, 0));

        gridLayout_2->addWidget(label_4, 0, 8, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_8->addWidget(label_6);

        doubleSpinBox_4 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setReadOnly(true);
        doubleSpinBox_4->setDecimals(10);
        doubleSpinBox_4->setMinimum(1e-06);
        doubleSpinBox_4->setMaximum(10);
        doubleSpinBox_4->setSingleStep(0.005);
        doubleSpinBox_4->setValue(0.001);

        horizontalLayout_8->addWidget(doubleSpinBox_4);


        gridLayout_2->addLayout(horizontalLayout_8, 0, 6, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_3->addWidget(label_7);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEdit);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 14);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_6->addWidget(label_2);

        doubleSpinBox_2 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setReadOnly(true);
        doubleSpinBox_2->setMinimum(-100);
        doubleSpinBox_2->setMaximum(100);
        doubleSpinBox_2->setValue(10);

        horizontalLayout_6->addWidget(doubleSpinBox_2);


        gridLayout_2->addLayout(horizontalLayout_6, 0, 5, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 0, 11, 1, 1);

        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(999);
        spinBox->setValue(30);

        gridLayout_2->addWidget(spinBox, 0, 9, 1, 1);

        doubleSpinBox_5 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        doubleSpinBox_5->setReadOnly(true);
        doubleSpinBox_5->setValue(0.1);

        gridLayout_2->addWidget(doubleSpinBox_5, 0, 12, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(groupBox);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setReadOnly(true);
        doubleSpinBox->setDecimals(10);
        doubleSpinBox->setMinimum(-100);
        doubleSpinBox->setMaximum(100);
        doubleSpinBox->setSingleStep(0.05);
        doubleSpinBox->setValue(7.7);

        gridLayout_2->addWidget(doubleSpinBox, 0, 2, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        doubleSpinBox_3 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setReadOnly(true);
        doubleSpinBox_3->setMinimum(-100);
        doubleSpinBox_3->setMaximum(100);
        doubleSpinBox_3->setValue(0.05);

        horizontalLayout_5->addWidget(doubleSpinBox_3);


        gridLayout_2->addLayout(horizontalLayout_5, 0, 3, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_7->addWidget(label_9);

        doubleSpinBox_6 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        doubleSpinBox_6->setReadOnly(true);
        doubleSpinBox_6->setMinimum(-100);
        doubleSpinBox_6->setMaximum(100);
        doubleSpinBox_6->setValue(-10);

        horizontalLayout_7->addWidget(doubleSpinBox_6);


        gridLayout_2->addLayout(horizontalLayout_7, 0, 4, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1231, 24));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "GroupBox", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \320\255\320\271\320\273\320\265\321\200\320\260", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264\n"
"\320\240\321\203\320\275\320\263\320\265-\320\232\321\203\321\202\321\202\320\260", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\244\321\203\320\275\320\272\321\206\320\270\321\217", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "GroupBox", 0));
        label_8->setText(QApplication::translate("MainWindow", "ZUM", 0));
        label_4->setText(QApplication::translate("MainWindow", "\321\210\320\260\320\263 \321\201\320\265\321\202\320\272\320\270", 0));
        label_6->setText(QApplication::translate("MainWindow", "eps=", 0));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600;\">y`=</span></p></body></html>", 0));
        lineEdit->setText(QApplication::translate("MainWindow", "1/(x-y*y)", 0));
        label_2->setText(QApplication::translate("MainWindow", "b=", 0));
        label_5->setText(QApplication::translate("MainWindow", "\321\210\320\260\320\263 \320\263\321\200\320\260\321\204\320\270\320\272\320\260", 0));
        label->setText(QApplication::translate("MainWindow", "x0 =", 0));
        label_3->setText(QApplication::translate("MainWindow", "y0=", 0));
        label_9->setText(QApplication::translate("MainWindow", "a=", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
