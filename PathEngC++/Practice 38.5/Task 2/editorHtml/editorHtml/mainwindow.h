#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QWebEngineView>
#include <QPlainTextEdit>

#include "./ui_formEditor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void showHtml(){
        ui->webEngineView->setHtml(ui->plainTextEdit->document()->toPlainText());
        update();
    }

public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent), ui(new Ui::MainWindow){
        ui->setupUi(this);
    }

    ~MainWindow(){
        delete ui;
    }
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
