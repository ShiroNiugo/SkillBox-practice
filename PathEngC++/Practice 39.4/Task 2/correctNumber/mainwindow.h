#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "./ui_mainwindow.h"
#include <QRegularExpression>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) , ui(new Ui::MainWindow){
        ui->setupUi(this);
        connect(ui->lineEdit, &QLineEdit::textEdited, [this](QString currentText){
            QRegularExpression exp("^[+]\\d{11}$");
            if(exp.match(currentText).hasMatch()) okLabel();
            else notOkLabel();
        });
    }
    ~MainWindow(){
        delete ui;
    }

private slots:
    void okLabel(){
        ui->label->setText("OK");
        ui->label->setStyleSheet("QLabel {color: green}");
        update();
    }
    void notOkLabel(){
        ui->label->setText("NOT OK");
        ui->label->setStyleSheet("QLabel {color: red}");
        update();
    }

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
