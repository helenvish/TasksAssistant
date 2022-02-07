#pragma once
#include <QWidget>

class QListView;
class KanbanList;

class KanbanBoard: public QWidget
{
    Q_OBJECT
public:
    KanbanBoard(QWidget* parent = nullptr);

    void createList(const QString& name);
private:
    QList<KanbanList*> m_views;
};
