#include "QApplication"
#include "./ui_formCalc.h"
#include "caller.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Caller window(nullptr);
	Ui::MainWindow caller;
	caller.setupUi(&window);
	window.lineEdit = caller.lineEdit;
	window.show();
	return a.exec();
}
