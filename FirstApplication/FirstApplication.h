#pragma once

#include <QtWidgets/QMainWindow>

namespace Ui {
    class FirstApplicationClass;
}
class FirstApplication : public QMainWindow
{
    Q_OBJECT

public:
    FirstApplication(QWidget *parent = Q_NULLPTR);
    ~FirstApplication();
private slots:
    void openKanbanSpace();

private:
    Ui::FirstApplicationClass* ui;

    QWidget* m_widget;
};
