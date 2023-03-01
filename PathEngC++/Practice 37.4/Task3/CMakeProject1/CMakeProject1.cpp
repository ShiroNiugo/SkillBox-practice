#include "QApplication"
#include "./ui_formRemoteController.h"
#include "logic.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Logic window(nullptr);
	Ui::MainWindow caller;
	caller.setupUi(&window);
	window.line = caller.textEdit;
	window.show();
	window.showDisplay();
	a.exec();
	return 0;
}
