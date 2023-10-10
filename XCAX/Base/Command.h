#pragma once
#include <QtCore/QObject>
#include <QAction> 
#include <App.h>


class Command : public QObject
{
	Q_OBJECT
public:
	Command(AppPtr app);
	virtual ~Command() = default;

	virtual void Execute() = 0;

	QAction* Action() const { return m_action; };
	App* GetApp() const { return m_app.get(); };

protected:
	void SetAction(QAction* action);

private:
	AppPtr m_app = nullptr;
	QAction* m_action = nullptr;
};

