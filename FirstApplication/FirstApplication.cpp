#include "FirstApplication.h"
#include "BurgerMenu.h"
#include "ui_FirstApplication.h"
#include "KanbanBoard.h"
#include <QHBoxLayout>
#include <QDebug>
#include <QStyleFactory>
#include <QColor>

FirstApplication::FirstApplication(QWidget *parent)
    : QMainWindow(parent)
	, ui(new Ui::FirstApplicationClass)
	, m_widget(new QWidget())
{
	ui->setupUi(this);
	setMinimumSize(500, 400);
	QHBoxLayout* layout = new QHBoxLayout();
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);
	BurgerMenu* bm = new BurgerMenu();
	QPalette pal = QPalette();
	pal.setColor(QPalette::Window, QColor(88, 88, 88));
	//pal.setColor(QPalette::WindowText, textColor);
	m_widget->setAutoFillBackground(true);
	m_widget->setPalette(pal);

	QAction* kanban = new QAction(QIcon(":/images/board.png"), "Kanban");
	bm->addAction(kanban);
	connect(kanban, &QAction::triggered, this, &FirstApplication::openKanbanSpace);

	layout->addWidget(bm);
	layout->addWidget(m_widget);
	ui->centralWidget->setLayout(layout);
}

FirstApplication::~FirstApplication()
{
	delete ui;
}

void FirstApplication::openKanbanSpace()
{
	KanbanBoard* board = new KanbanBoard();
	QHBoxLayout* layout = new QHBoxLayout();
	layout->addWidget(board);
	m_widget->setLayout(layout);
	//QHBoxLayout* layout = static_cast<QHBoxLayout*>(ui->centralWidget->layout());
	//layout->replaceWidget(m_widget, board);
	m_widget->setLayout(layout);
	//delete m_widget;
}
