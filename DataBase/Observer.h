#pragma once
#include"Subject.h"
//"���������" ����������������
class Observer
{
	class Subject * model;
public:
	void baseRegistrate(class Subject * mod)
	{
		model = mod;
		mod->attach(this);//����������� ��������������
	};
	Observer();
	virtual void update(pair<int,int> val) = 0;
protected:
	//Subject *getSubject() {
	//	return model;
	//}
	~Observer();
};

