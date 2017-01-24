#pragma once
#include "CMySql.h"
#include "Observer.h"
class Location :
	public CMySql,Observer
{
public:
	void Registrate(Subject *mod){ baseRegistrate(mod); }
	void update(pair<int, int> val){
		cout << "Location" << endl;
	}
	int id;
	double latitude;
	double longitude;
	string title;
	string photo;
	string addLocation(double latitude, double longitude, string title, string photo);// уникальность третья позиция?
	string deleteLocation(int id,Subject * subj);
	Location getLocationAction(int id);
	Location();
	~Location();
};

