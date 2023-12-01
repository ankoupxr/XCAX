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

signals:
	void Draw(TopoDS_Shape*);
	void Remove(TopoDS_Shape*);

protected:
	void SetAction(QAction* action);
	DocPtr m_doc = nullptr;
	AppPtr m_app = nullptr;
	TopoDS_Shape* m_resultShape = nullptr;
private:
	QAction* m_action = nullptr;
};

