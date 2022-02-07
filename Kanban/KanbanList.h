#pragma once
#include <QWidget>

namespace Ui {
	class KanbanList;
}

class KanbanList : public QWidget {

	Q_OBJECT
public:
	KanbanList(QWidget* parent = nullptr);
	~KanbanList();
private:
	Ui::KanbanList* ui;
};
