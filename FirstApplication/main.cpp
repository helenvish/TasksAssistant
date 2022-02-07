#include "FirstApplication.h"
#include <QtWidgets/QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //qApp->setStyle(QStyleFactory::create("Fusion"));
	QPalette p;
	p = qApp->palette();
	p.setColor(QPalette::Window, QColor(53, 53, 53));
	p.setColor(QPalette::Button, QColor(53, 53, 53));
	p.setColor(QPalette::Highlight, QColor(142, 45, 197));
	p.setColor(QPalette::ButtonText, QColor(255, 255, 255));
	p.setColor(QPalette::WindowText, QColor(255, 255, 255));
	qApp->setPalette(p);
    FirstApplication w;
	w.setMinimumSize(500, 400);
    w.show();
    return a.exec();
}
