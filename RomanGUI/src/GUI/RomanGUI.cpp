#include "RomanGUI.h"
#include <string>

RomanGUI::RomanGUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.num1, &QLineEdit::textEdited, this, &RomanGUI::on_roman_input_change);
	QObject::connect(ui.num2, &QLineEdit::textEdited, this, &RomanGUI::on_roman_input_change);
	QObject::connect(ui.Submit, &QPushButton::clicked, this, &RomanGUI::submit);
}

void RomanGUI::on_roman_input_change(QString inp) {
	QObject* sender = QObject::sender();
	if (sender == ui.num1) {
		num1 = number(inp.toStdString());
		ui.ArabicNum1->setText(QString::number(num1.get_valAsDouble()));
		ui.RomanNum1->setText(QString::fromStdString(num1.get_rom()));
	}
	else {
		num2 = number(inp.toStdString());
		ui.ArabicNum2->setText(QString::number(num2.get_valAsDouble()));
		ui.RomanNum2->setText(QString::fromStdString(num1.get_rom()));
	}
}

void RomanGUI::submit() {
	result = num1 + num2;
	ui.ArabicResult->setText(QString::number(result.get_valAsDouble()));
	ui.RomanResult->setText(QString::fromStdString(result.get_rom()));
}