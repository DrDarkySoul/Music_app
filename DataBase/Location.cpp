#include "Location.h"

string Location::addLocation(double latitude, double longitude, string title, string photo)
{
	char buf[255];
	gcvt(latitude,10,buf);
	string str_lat = buf;
	gcvt(longitude, 10, buf);
	string str_lon = buf;
	return base_add("location(latitude,longitude,title,photo)", str_lat + "," + str_lon + ",\"" + title + "\",\"" + photo + "\"");
}
Location Location::getLocationAction(int id)
{
	char buf[255];
	itoa(id, buf, 10);
	string str_id = buf;
	res = getBaseAction("Location", str_id);
	Location total;
	if (res->next() == NULL){
		total.id = NULL;
		total.latitude = NULL;
		total.longitude = NULL;
		total.title = "";
		total.photo = "";
		return total;
	}
	total.id = res->getInt(1);
	total.latitude = res->getDouble(2);
	total.longitude = res->getDouble(3);
	total.title = res->getString(4);
	total.photo = res->getString(5);
	return total;
}
string Location::deleteLocation(int id, Subject * subj)
{
	char buf[255];
	itoa(id, buf, 10);
	string str_id = buf;
	string result = base_del("location", str_id);
	if (result == "YES"){
		subj->Delid(make_pair(id, 2));
	}
	return result;
}
Location::Location()
{
}


Location::~Location()
{
}
