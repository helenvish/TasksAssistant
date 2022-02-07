#pragma once
#include <QWidget>
#include <QActionGroup>
#include <QString>

class QPushButton;

class BurgerMenu: public QWidget
{
	Q_OBJECT
public:
	BurgerMenu(QWidget* parent = nullptr);
	~BurgerMenu() {}

	void addAction(const QIcon& icon, const QString& label);
	void addAction(QAction* action);
private slots:
	void setExpansion(bool expanded);
private:
	QActionGroup* m_actionGroup;
	QPushButton* m_mainButton;
	int m_width;
};

