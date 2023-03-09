#include <QApplication>

#include "mainwindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Button redButton(nullptr);
    redButton.setFixedSize(500, 500);
    redButton.show();
    app.exec();
    return 0;
}
