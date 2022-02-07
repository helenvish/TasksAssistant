#include "BurgerMenu.h"
#include "MenuButton.h"
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QAction>
#include <QString>
#include <QStyleOption>
#include <QPainter>
#include <QPropertyAnimation>
#include <QDebug>

BurgerMenu::BurgerMenu(QWidget* parent)
	: QWidget(parent)
	, m_actionGroup(new QActionGroup(this))
	, m_mainButton(new QPushButton(this))
	, m_width(100)
{
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
	m_mainButton->setFlat(true);
	m_mainButton->setIconSize(QSize(48, 48));
	m_mainButton->setFixedSize(48, 48);
	m_mainButton->setCheckable(true);
	m_mainButton->setIcon(QIcon(":/images/burger.png"));
	//m_mainButton->setCursor(Qt::PointingHandCursor);
	//mActions->setExclusive(true);

	auto lay = new QVBoxLayout();
	setLayout(lay);
	lay->setContentsMargins(0, 0, 0, 0);
	lay->setSpacing(0);

	lay->addWidget(m_mainButton);
	lay->addStretch();
	setFixedWidth(48);

	connect(m_mainButton, &QPushButton::toggled, this, &BurgerMenu::setExpansion);
}

void BurgerMenu::addAction(const QIcon& icon, const QString& label)
{
	auto action = m_actionGroup->addAction(icon, label);
	QVBoxLayout* lay = static_cast<QVBoxLayout*>(layout());
	MenuButton* btn = new MenuButton(action);
	lay->addWidget(btn);
}

void BurgerMenu::addAction(QAction* action)
{
	QVBoxLayout* lay = static_cast<QVBoxLayout*>(layout());
	MenuButton* btn = new MenuButton(action, this);
	btn->setIconSize(m_mainButton->iconSize());
	lay->insertWidget(lay->count() - 1, btn);
}

void BurgerMenu::setExpansion(bool expanded)
{
		auto anim = new QPropertyAnimation(this, "minimumWidth", this);
		anim->setDuration(250);
		anim->setStartValue(m_mainButton->width());
		anim->setEndValue(m_mainButton->width() + m_width);
		anim->setDirection(expanded ? QAbstractAnimation::Forward : QAbstractAnimation::Backward);
		anim->setEasingCurve(expanded ? QEasingCurve::OutCubic : QEasingCurve::InCubic);
		anim->start(QAbstractAnimation::DeleteWhenStopped);
}


