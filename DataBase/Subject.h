#pragma once
#include "CMySql.h"
//#include "Observer.h"
class Subject
{
	//связь только с базовым классом Observer
	vector < class Observer * > views;
	pair<int,int> value;
public:
	void attach(Observer *obs){ views.push_back(obs); }//регистрация наблюдателей
	void notify();
	void Delid(pair<int, int> val){ value = val; notify(); }//0-User;1-music;2-Location
	pair<int, int> Getval(){ return value; }
	Subject();
	~Subject();
};

