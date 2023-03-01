#pragma once

#include <string>
#include <exception>
#include <QMainWindow>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

class Caller : public QMainWindow {
	Q_OBJECT

private:
	float result = 0, temp = 0;
	int sing = 0;
public:
	void clear() {
		result = temp = 0;
		sing = 0;
	}
	QLineEdit* lineEdit = nullptr;
	Caller(QWidget* parent = nullptr) : QMainWindow(parent) {}
public slots:
	void add() {
		QPushButton* pushButton = (QPushButton *)sender();
		if (lineEdit->text() == "0" || lineEdit->text() == "division by zero is not possible") 
			lineEdit->setText("");
		if (lineEdit->text().count(".") < 1 && pushButton->text() == ".")
			lineEdit->setText(lineEdit->text() + pushButton->text());
		else if (pushButton->text() != ".")
			lineEdit->setText(lineEdit->text() + pushButton->text());
	}
	void action() {
		QPushButton* pushButton = (QPushButton*)sender();
		if(pushButton->text() == "Clear")
			lineEdit->setText("0");
		else if (pushButton->text() == "All clear"){
			lineEdit->setText("0");
			clear();
		}
		else if (pushButton->text() == "+") { 
			sing = 1;
			if (result == 0) result = lineEdit->text().toFloat();
			else result += lineEdit->text().toFloat();
		}
		else if (pushButton->text() == "-") {
			sing = 2;
			if (result == 0) result = lineEdit->text().toFloat();
			else result -= lineEdit->text().toFloat();
		}
		else if (pushButton->text() == "/") {
			sing = 3;
			if (result == 0) result = lineEdit->text().toFloat();
			else result /= lineEdit->text().toFloat();
		}
		else if (pushButton->text() == "*") {
			sing = 4;
			if(result == 0) result = lineEdit->text().toFloat();
			else result *= lineEdit->text().toFloat();
		}
		else if(pushButton->text() == "="){
			temp = lineEdit->text().toFloat();
			
			try {
				switch (sing)
				{
				case 1: result += temp; break;
				case 2: result -= temp; break;
				case 3: {
					if (temp == 0 && sing == 3) throw std::invalid_argument("division by zero is not possible");
					else result /= temp;
					break;
				}
				case 4: result *= temp; break;
				}
				lineEdit->setText(QString().setNum(result));
			}catch (const std::invalid_argument e) {
				lineEdit->setText(e.what());
				clear();
			}
		}
		if (pushButton->text() != "=") lineEdit->setText("0");
	}
};