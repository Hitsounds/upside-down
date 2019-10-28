#include "RomanGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RomanGUI w;
	w.show();
	return a.exec();
}
