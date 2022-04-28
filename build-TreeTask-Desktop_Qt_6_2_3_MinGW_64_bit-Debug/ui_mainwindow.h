/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *Tree;
    QTableWidget *Vector;
    QPushButton *AddCell;
    QPushButton *Clear;
    QPushButton *AddToTree;
    QTextEdit *textEdit;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpinBox *spinBox;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *Counter;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Tree = new QTableWidget(centralwidget);
        Tree->setObjectName(QString::fromUtf8("Tree"));
        Tree->setGeometry(QRect(30, 20, 281, 361));
        Vector = new QTableWidget(centralwidget);
        Vector->setObjectName(QString::fromUtf8("Vector"));
        Vector->setGeometry(QRect(350, 20, 331, 171));
        AddCell = new QPushButton(centralwidget);
        AddCell->setObjectName(QString::fromUtf8("AddCell"));
        AddCell->setGeometry(QRect(700, 30, 91, 21));
        Clear = new QPushButton(centralwidget);
        Clear->setObjectName(QString::fromUtf8("Clear"));
        Clear->setGeometry(QRect(699, 70, 91, 20));
        AddToTree = new QPushButton(centralwidget);
        AddToTree->setObjectName(QString::fromUtf8("AddToTree"));
        AddToTree->setGeometry(QRect(699, 110, 91, 21));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(350, 210, 251, 171));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(30, 400, 111, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 400, 91, 31));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(490, 400, 111, 31));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(390, 420, 81, 31));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(490, 440, 111, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(640, 270, 91, 21));
        Counter = new QLabel(centralwidget);
        Counter->setObjectName(QString::fromUtf8("Counter"));
        Counter->setGeometry(QRect(650, 300, 61, 16));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        AddCell->setText(QCoreApplication::translate("MainWindow", "add cell", nullptr));
        Clear->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        AddToTree->setText(QCoreApplication::translate("MainWindow", "add to the tree", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "get round", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "delete by key", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "search by key", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Leaves counter :", nullptr));
        Counter->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
