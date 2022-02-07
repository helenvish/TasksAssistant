#include "EditableLabel.h"
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QDebug>

KeyPressHandler::KeyPressHandler()
	:QObject()
{

}

bool KeyPressHandler::eventFilter(QObject* obj, QEvent* event)
{
	if (event->type() == QEvent::KeyPress) {
		QKeyEvent* event_key = static_cast<QKeyEvent*>(event);
		if (event_key->key() == Qt::Key_Escape) {
			emit escapeKeyPressed(true);
			return true;
		}
		if (event_key->key() == Qt::Key_Return || event_key->key() == Qt::Key_Enter) {
			emit returnKeyPressed(true);
			return true;
		}
	}
	return QObject::eventFilter(obj, event);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
EditableLabel::EditableLabel(QWidget* parent)
	:QWidget(parent)
	, m_handler(new KeyPressHandler())
{
	QHBoxLayout* lay = new QHBoxLayout(this);
	lay->setContentsMargins(0, 0, 0, 0);
	lay->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
	m_label = new QLabel(this);
	m_label->setText("default name");
	lay->addWidget(m_label);
	m_label->setFixedWidth(150);
	m_label->setAlignment(Qt::AlignHCenter);
	m_label->setWordWrap(true);
	m_label->setStyleSheet("QLabel {font: 75 12pt; color: rgb(0, 0, 0)}");

	m_lineEdit = new QLineEdit(this);
	m_lineEdit->setFixedWidth(150);
	lay->addWidget(m_lineEdit);
	m_lineEdit->setStyleSheet("QLineEdit {font: 75 12pt; color: rgb(0, 0, 0)}");
	m_lineEdit->setHidden(true);
	m_lineEdit->installEventFilter(m_handler);
		
	connect(m_handler, &KeyPressHandler::escapeKeyPressed, this, &EditableLabel::escapeEdit);
	connect(m_handler, &KeyPressHandler::returnKeyPressed, this, &EditableLabel::setLabelText);
	connect(m_lineEdit, &QLineEdit::editingFinished, this, &EditableLabel::setLabelText);
}

void EditableLabel::setLabelText()
{
	QString text = m_lineEdit->text();

	if (text != m_label->text()) {
		m_label->setText(text);
		m_label->setWordWrap(true);
		emit textChanged(text);
	}
	m_label->setHidden(false);
	m_lineEdit->setHidden(true);
	m_lineEdit->blockSignals(true);
	m_label->blockSignals(false);	
}

void EditableLabel::escapeEdit()
{
	m_label->setHidden(false);
	m_lineEdit->setHidden(true);
	m_lineEdit->blockSignals(true);
	m_label->blockSignals(false);
}

void EditableLabel::mouseDoubleClickEvent(QMouseEvent* event)
{
	if (event->button() == Qt::MouseButton::LeftButton) {
		m_label->setHidden(true);
		m_label->blockSignals(true);
		m_lineEdit->setHidden(false);
		m_lineEdit->setText(m_label->text());
		m_lineEdit->blockSignals(false);
		m_lineEdit->setFocus(Qt::MouseFocusReason);
		//m_lineEdit->selectAll();
	}
}