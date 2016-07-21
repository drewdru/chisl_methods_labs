/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
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
#include <QtWidgets/QFormLayout>
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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QSpinBox *spinBox_2;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_7;
    QSpacerItem *verticalSpacer;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 110));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);


        gridLayout->addLayout(formLayout, 0, 0, 1, 7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout_2->addWidget(lineEdit_3);


        gridLayout->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(10);

        horizontalLayout_4->addWidget(spinBox);


        gridLayout->addLayout(horizontalLayout_4, 1, 5, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        horizontalLayout_3->addWidget(lineEdit_4);


        gridLayout->addLayout(horizontalLayout_3, 1, 2, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        doubleSpinBox = new QDoubleSpinBox(groupBox);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setMinimum(0.01);
        doubleSpinBox->setValue(0.1);

        horizontalLayout_5->addWidget(doubleSpinBox);


        gridLayout->addLayout(horizontalLayout_5, 1, 3, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_6->addWidget(label_7);

        spinBox_2 = new QSpinBox(groupBox);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMinimum(10000);
        spinBox_2->setMaximum(10000000);

        horizontalLayout_6->addWidget(spinBox_2);


        gridLayout->addLayout(horizontalLayout_6, 1, 4, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 2);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(133, 30));

        gridLayout_3->addWidget(pushButton_2, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        graphicsView = new QGraphicsView(groupBox_2);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setMinimumSize(QSize(0, 0));

        gridLayout_2->addWidget(graphicsView, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 1, 7, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_3->addWidget(pushButton, 2, 0, 1, 1);

        lineEdit_6 = new QLineEdit(centralWidget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setMaximumSize(QSize(133, 30));
        lineEdit_6->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit_6, 4, 0, 1, 1);

        lineEdit_5 = new QLineEdit(centralWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setMaximumSize(QSize(133, 30));

        gridLayout_3->addWidget(lineEdit_5, 5, 0, 1, 1);

        lineEdit_7 = new QLineEdit(centralWidget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setMaximumSize(QSize(133, 30));

        gridLayout_3->addWidget(lineEdit_7, 6, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 229, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 7, 0, 1, 1);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setMinimumSize(QSize(0, 0));
        textEdit->setMaximumSize(QSize(133, 16777215));

        gridLayout_3->addWidget(textEdit, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 24));
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
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264\320\275\321\213\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217:", 0));
        label->setText(QApplication::translate("MainWindow", "\321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265: y=", 0));
        lineEdit->setText(QApplication::translate("MainWindow", "2-log(x)-x", 0));
        label_2->setText(QApplication::translate("MainWindow", "a=", 0));
        lineEdit_2->setInputMask(QString());
        lineEdit_2->setText(QApplication::translate("MainWindow", "2", 0));
        label_3->setText(QApplication::translate("MainWindow", "b=", 0));
        lineEdit_3->setText(QApplication::translate("MainWindow", "10", 0));
        label_5->setText(QApplication::translate("MainWindow", "zoom:", 0));
        label_4->setText(QApplication::translate("MainWindow", "eps=", 0));
        lineEdit_4->setText(QApplication::translate("MainWindow", "0.001", 0));
        label_6->setText(QApplication::translate("MainWindow", "\321\210\320\260\320\263", 0));
        label_7->setText(QApplication::translate("MainWindow", "Max itr", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\263\321\200\320\260\321\204\320\270\320\272", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272:", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Help", 0));
        lineEdit_6->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202: ", 0));
        lineEdit_5->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273. \320\270\321\202\320\265\321\200\320\260\321\206\320\270\320\271", 0));
        lineEdit_7->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217(\320\274\320\270\320\273.\321\201\320\265\320\272.)", 0));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\236\321\202\320\262\320\265\321\202: </p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
