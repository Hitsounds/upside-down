#include "RomanGUI.h"
#include <string>
#include <QMessageBox>
#include <QFontDatabase>
#include "RomanCalc/NumberClass.h"

RomanGUI::RomanGUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	int id = QFontDatabase::addApplicationFont(":/RomanGUI/Fortnite.otf");
	QString family = QFontDatabase::applicationFontFamilies(id).at(0);
	QFont fortnite(family);
	ui.label->setFont(fortnite);
	//Add action listeners
	QObject::connect(ui.num1, &QLineEdit::textEdited, this, &RomanGUI::on_roman_input_change);
	QObject::connect(ui.num2, &QLineEdit::textEdited, this, &RomanGUI::on_roman_input_change);
	QObject::connect(ui.Submit, &QPushButton::clicked, this, &RomanGUI::submit);
	QObject::connect(ui.Cancel, &QPushButton::clicked, this, &RomanGUI::cancel);
}

void RomanGUI::on_roman_input_change(QString inp) {
	//Updates the inputs representation on bottom of window
	QObject* sender = QObject::sender();
	if (sender == ui.num1) {
		num1 = number(inp.toStdString());
		ui.ArabicNum1->setText(QString::number(num1.get_valAsDouble()));
		ui.RomanNum1->setText(QString::fromStdString(num1.get_rom()));
	}
	else {
		num2 = number(inp.toStdString());
		ui.ArabicNum2->setText(QString::number(num2.get_valAsDouble()));
		ui.RomanNum2->setText(QString::fromStdString(num2.get_rom()));
	}
}

void RomanGUI::submit() {
	result = number();
	ui.ArabicResult->setText("");
	ui.RomanResult->setText("");
	const QLineEdit* inputs[] = { ui.num1, ui.num2 };
	//Validate both input fields
	for (int i = 0; i < 2; i++) {
		try {
			number::validate_roman(inputs[i]->text().toStdString());
		}
		catch (std::string err) {
			QMessageBox error;
			std::string err_msg = "Numeral " + std::to_string(i+1) + " " + err;
			error.setText(QString::fromStdString(err_msg));
			error.exec();
			return;
		}
	}
	//Validate results : not <=0
	if (ui.opSelection->currentText() == "+") {
		result = num1 + num2;
	}
	else {
		try {
			//Negative results will raise an error
			result = num1 - num2;
		}
		catch (const char* err) {
			QMessageBox error;
			error.setText("Result is a negative number and as such can't be represented as a roman numeral.");
			error.exec();
			return;
		}
	}
	//Show error message if result is 0
	if (result.get_valAsDouble() == 0) {
		QMessageBox error;
		error.setText("Result is 0 and as such can't be represented as a roman numeral.");
		error.exec();
		return;
	}
	//Set results fields
	ui.ArabicResult->setText(QString::number(result.get_valAsDouble()));
	ui.RomanResult->setText(QString::fromStdString(result.get_rom()));
}

void RomanGUI::cancel() {
	//Reset all fields and object attributes
	num1 = number();
	num2 = number();
	result = number();
	ui.num1->setText("");
	ui.num2->setText("");
	ui.RomanNum1->setText("");
	ui.ArabicNum1->setText("");
	ui.RomanNum2->setText("");
	ui.ArabicNum2->setText("");
	ui.RomanResult->setText("");
	ui.ArabicResult->setText("");
}