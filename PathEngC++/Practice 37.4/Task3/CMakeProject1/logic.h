#pragma once

#include <string>
#include <QMainWindow>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>

class Logic : public QMainWindow {
	Q_OBJECT
private:
	int channel = 0, volume = 0;
public:
	QTextEdit* line = nullptr;

	void showDisplay(bool t = 0) {
		line->setText("Channel: " + (QString)std::to_string(channel).c_str() + 
					  "\nVolume: " + (QString)std::to_string(volume).c_str()+"%");
	}

	Logic(QWidget* parent = nullptr) : QMainWindow(parent) {}
private slots:
	void add() {
		QPushButton* button = (QPushButton*)sender();
		channel = button->text().toInt();
		showDisplay();
	}
	void channels() {
		QPushButton* button = (QPushButton*)sender();
		if (button->text() == "+" && channel < 9) channel += 1;
		else if (button->text() == "-" && channel > 0) channel -= 1;
		showDisplay();
	}
	void volumes() {
		QPushButton* button = (QPushButton*)sender();
		if (button->text() == "+") volume += (volume<100)? 10:0;
		else if (button->text() == "-") volume -= (volume > 0) ? 10 : 0;
		showDisplay();
	}
};