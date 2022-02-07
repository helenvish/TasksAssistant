#pragma once

#include <QPushButton>

class QAction;

class MenuButton : public QPushButton
{
	Q_OBJECT
public:
	MenuButton(const QIcon& icon, const QString& label, QWidget* parent = nullptr);
	MenuButton(QAction* action, QWidget* parent = nullptr);
	QAction* action() const { return mAction; }
	void setIconSize(const QSize& size) { mIconSize = size; setFixedHeight(mIconSize.height()); update(); }
protected:
	void paintEvent(QPaintEvent*) override;

private:
	void init();

	QSize mIconSize;
	QAction* mAction;
};