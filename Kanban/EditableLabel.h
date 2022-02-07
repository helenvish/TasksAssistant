#pragma once
#include <QLabel>

class QLabel;
class QLineEdit;

class KeyPressHandler: public QObject {
	Q_OBJECT
public:
	KeyPressHandler();
	~KeyPressHandler(){}
signals:
	void escapeKeyPressed(bool);
	void returnKeyPressed(bool);

protected:
	bool eventFilter(QObject* obj, QEvent* event) override;
};

class EditableLabel :public QWidget
{
	Q_OBJECT
public:
	EditableLabel(QWidget* parent = nullptr);
	~EditableLabel(){}

signals:
	void textChanged(const QString& str);

public slots:
	void setLabelText();
	void escapeEdit();
protected:
	void mouseDoubleClickEvent(QMouseEvent* ev) override;

private:
	QLabel* m_label;
	QLineEdit* m_lineEdit;
	KeyPressHandler* m_handler;
};

