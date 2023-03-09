#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsScene>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>

#include <QPixmap>
#include <QPainter>
#include <QFileDialog>

#include "./ui_formBlur.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QImage bluredImage(QImage sourceImage, int blurRadius) {
        if (sourceImage.isNull()) return QImage();
        QGraphicsScene scene;
        QGraphicsPixmapItem item;
        item.setPixmap(QPixmap::fromImage(sourceImage));

        auto* blur = new QGraphicsBlurEffect;
        blur->setBlurRadius(blurRadius);
        item.setGraphicsEffect(blur);
        scene.addItem(&item);
        QImage result(sourceImage.size(), QImage::Format_ARGB32);
        result.fill(Qt::transparent);
        QPainter painter(&result);
        scene.render(&painter, QRectF(), QRectF(0, 0, sourceImage.width(), sourceImage.height()));
        return result;
    }

    void proccessSingleImage() {
        ui->label->setPixmap(QPixmap::fromImage(bluredImage(QImage(source), ui->horizontalSlider->value()).scaled(ui->label->width(), ui->label->height(), Qt::KeepAspectRatio)));
        //ui->label->setScaledContents(1);
    }

    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent), ui(new Ui::MainWindow){
        ui->setupUi(this);
    }
    ~MainWindow(){
        delete ui;
    }
public slots:
    void add() {
        source = QFileDialog::getOpenFileName(nullptr, "Open jpg file", "../image/", "JPG files (*.jpg)");
        proccessSingleImage();
        update();
    }
    void move() {
        proccessSingleImage();
        update();
    }
private:
    Ui::MainWindow *ui;
    QString source;
};
#endif // MAINWINDOW_H
