#include "KanbanBoard.h"
#include "KanbanList.h"
#include <QListView>
#include <QHBoxLayout>

KanbanBoard::KanbanBoard(QWidget* parent /*= nullptr*/)
	:QWidget(parent)
{
	QVBoxLayout* vLay = new QVBoxLayout();
	setLayout(vLay);
	QHBoxLayout* lay = new QHBoxLayout();
	//setLayout(lay);
	vLay->addLayout(lay);

	createList("Test");

	QSpacerItem* horizontalSpacer = new QSpacerItem(300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	lay->addItem(horizontalSpacer);

	QSpacerItem* verticalSpacer = new QSpacerItem(20, 300, QSizePolicy::Minimum, QSizePolicy::Expanding);
	vLay->addItem(verticalSpacer);

	setFocusPolicy(Qt::StrongFocus);
}

void KanbanBoard::createList(const QString& name)
{
	KanbanList* list = new KanbanList();
	QVBoxLayout* lay = static_cast<QVBoxLayout*>(layout());
	lay->addWidget(list);
}
