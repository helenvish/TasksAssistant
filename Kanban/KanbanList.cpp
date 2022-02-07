#include "KanbanList.h"
#include "ui_KanbanList.h"
#include "EditableLabel.h"

KanbanList::KanbanList(QWidget* parent /*= nullptr*/)
	: QWidget(parent)
	, ui(new Ui::KanbanList())
{
	ui->setupUi(this);
	EditableLabel* label = new EditableLabel();
	ui->horizontalLayout->insertWidget(1, label);
}

KanbanList::~KanbanList()
{
	delete ui;
}
