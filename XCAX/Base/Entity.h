#ifndef ENTITY_H
#define ENTITY_H

#include <QString>
#include <QList>
#include <QStringList>
#include <QObject>

class Entity
{
public:
	Entity() = default;
	~Entity() = default;

	virtual void setIdentify(int id);//设置标识
	int getIdentify();//获取标识
	virtual void setName(const QString &name);
	QString getName();


private:
	int m_id = -1;
	QString m_name;
};


#endif // !ENTITY_H
