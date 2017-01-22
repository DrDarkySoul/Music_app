#pragma once
#include "CMySql.h"
class Location :
	public CMySql
{
public:
	int id;
	double latitude;
	double longitude;
	string title;
	string photo;
	string addLocation(double latitude, double longitude, string title, string photo);// уникальность третья позиция?
	string deleteLocation(int id);
	Location getLocationAction(int id);
	Location();
	~Location();
};

