#include "MenuButton.h"
#include <QAction>
#include <QPainter>
#include <QStyleOptionButton>

MenuButton::MenuButton(const QIcon& icon, const QString& label, QWidget* parent)
	: QPushButton(parent)
	, mIconSize(QSize(64, 64))
	, mAction(new QAction(icon, label))
{
	init();
}

MenuButton::MenuButton(QAction* action, QWidget* parent /*= nullptr*/)
	: QPushButton(parent)
	, mIconSize(QSize(64, 64))
	, mAction(action)
{
	init();
}

void MenuButton::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	QStyleOptionButton opt;
	opt.initFrom(this);
	opt.state |= (mAction->isChecked() ? QStyle::State_On : QStyle::State_Off);

	style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
	const QRect contentsRect = style()->subElementRect(QStyle::SE_PushButtonContents, &opt, this);
	if (!mAction->icon().isNull())
	{
		QIcon::Mode mode = ((opt.state & QStyle::State_MouseOver) == 0) ? QIcon::Normal : QIcon::Active;
		if (!isEnabled())
			mode = QIcon::Disabled;
		QIcon::State state = mAction->isChecked() ? QIcon::On : QIcon::Off;
		painter.drawPixmap(QRect(contentsRect.topLeft(), mIconSize), mAction->icon().pixmap(mIconSize, mode, state));
	}

	opt.rect = contentsRect.adjusted(mIconSize.width() + 1, 0, 0, 0);
	opt.text = fontMetrics().elidedText(mAction->iconText(), Qt::ElideRight, opt.rect.width(), Qt::TextShowMnemonic);
	
	style()->drawControl(QStyle::CE_CheckBoxLabel, &opt, &painter, this);
}

void MenuButton::init()
{
	connect(mAction, &QAction::destroyed, this, &MenuButton::deleteLater);
	setCursor(Qt::PointingHandCursor);

	connect(mAction, SIGNAL(changed()), this, SLOT(update()));
	connect(this, &MenuButton::clicked, [&] {
		if (mAction->isCheckable() && !mAction->isChecked())
			mAction->toggle();

		mAction->trigger();
		});
}

