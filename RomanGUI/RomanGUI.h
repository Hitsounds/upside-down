#pragma once

#include <QtWidgets/QWidget>
#include "ui_RomanGUI.h"
#include "RomanCalc/NumberClass.h"

class RomanGUI : public QWidget
{
	Q_OBJECT

public:
	RomanGUI(QWidget *parent = Q_NULLPTR);
	number num1;
	number num2;
	number result;

public slots:
	void on_roman_input_change(QString);
	void submit();

private:
	Ui::RomanGUIClass ui;
};
