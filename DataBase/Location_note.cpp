#include "Location_note.h"


Location_note::Location_note()
{
}

string Location_note::addLocationNoteAction(int user_id, int location_id, int music_id)
{
	char buf[255];
	itoa(user_id, buf, 10);
	string str_1 = buf;
	itoa(location_id, buf, 10);
	string str_2 = buf;
	itoa(music_id, buf, 10);
	string str_3 = buf;
	return base_add("Location_notes(user_id,location_id,music_id)", str_1 + "," + str_2+","+str_3);
}

string Location_note::deleteLocationNoteAction(int user_id, int location_id, int music_id)
{
	char buf[255];
	itoa(user_id, buf, 10);
	string str_1 = buf;
	itoa(location_id, buf, 10);
	string str_2 = buf;
	itoa(music_id, buf, 10);
	string str_3 = buf;
	return base_complicated_del("Location_notes", "(user_id,location_id,music_id)=(" + str_1 + "," + str_2 + ","+str_3 + ")");
}

string Location_note::deleteLocationNoteActionbyUser_id(int user_id)
{
	char buf[255];
	itoa(user_id, buf, 10);
	string str_1 = buf;
	return base_complicated_del("Location_notes", "user_id=" + str_1);
}
string Location_note::deleteLocationNoteActionbyMusic_id(int music_id)
{
	char buf[255];
	itoa(music_id, buf, 10);
	string str_1 = buf;
	return base_complicated_del("Location_notes", "music_id=" + str_1);
}
string Location_note::deleteLocationNoteActionbyLocation_id(int location_id)
{
	char buf[255];
	itoa(location_id, buf, 10);
	string str_1 = buf;
	return base_complicated_del("Location_notes", "location_id=" + str_1);
}
vector<Location_note> Location_note::getSmbLocationNotesAction(int user_id)
{
	char buf[255];
	itoa(user_id, buf, 10);
	string str_id = buf;
	res = getbaseLocation_noteAction(str_id);
	vector<Location_note> Total;
	Location_note total;
	if (res->next() == NULL){
		total.user_id = NULL;
		total.music_id = NULL;
		total.location_id = NULL;
		Total.push_back(total);
		return Total;
	}
	for (;;){
		total.user_id = res->getInt(1);
		total.location_id = res->getInt(2);
		total.music_id = res->getInt(3);
		Total.push_back(total);
		if (res->next() == NULL) return Total;
	}
}


std::pair<vector<music>, vector<Location>> Location_note::getSmbLocationNotesFullAction(int user_id)
{
	res = getbaseSmbLocationNotesFullAction(user_id);
	music m;
	Location l;
	vector<music> M;
	vector<Location> L;
	if (res->next() == NULL){
		m.id = NULL;
		m.title = "";
		m.artist = "";
		m.album = "";
		m.duration = NULL;
		m.photo = "";
		l.id = NULL;
		l.latitude = NULL;
		l.longitude = NULL;
		l.title = "";
		l.photo = "";
		M.push_back(m);
		L.push_back(l);
		return std::make_pair(M,L);
	}
	for (;;){
		m.id = res->getInt(4);
		m.title = res->getString(5);
		m.artist = res->getString(6);
		m.album = res->getString(7);
		m.duration = res->getInt(8);
		m.photo = res->getString(9);
		l.id = res->getInt(10);
		l.latitude = res->getDouble(11);
		l.longitude = res->getDouble(12);
		l.title = res->getString(13);
		l.photo = res->getString(14);
		M.push_back(m);
		L.push_back(l);
		if (res->next() == NULL) return std::make_pair(M, L);
	}
}


pair<vector<music>, vector<Location>> Location_note::getLocationNotesFullAction(int begin, int end)
{
	res = getbaseLocationNotesFullAction(begin, end);
	music m;
	Location l;
	vector<music> M;
	vector<Location> L;
	if (res->next() == NULL){
		m.id = NULL;
		m.title = "";
		m.artist = "";
		m.album = "";
		m.duration = NULL;
		m.photo = "";
		l.id = NULL;
		l.latitude = NULL;
		l.longitude = NULL;
		l.title = "";
		l.photo = "";
		M.push_back(m);
		L.push_back(l);
		return std::make_pair(M, L);
	}
	for (;;){
		m.id = res->getInt(4);
		m.title = res->getString(5);
		m.artist = res->getString(6);
		m.album = res->getString(7);
		m.duration = res->getInt(8);
		m.photo = res->getString(9);
		l.id = res->getInt(10);
		l.latitude = res->getDouble(11);
		l.longitude = res->getDouble(12);
		l.title = res->getString(13);
		l.photo = res->getString(14);
		M.push_back(m);
		L.push_back(l);
		if (res->next() == NULL) return std::make_pair(M, L);
	}
}
vector<Location_note> Location_note::getLocationNotesAction(int begin, int end)
{
	char buf[255];
	itoa(user_id, buf, 10);
	string str_b = buf;
	itoa(user_id, buf, 10);
	string str_end = buf;
	res = getBasesAction("location_notes",str_b,str_end);
	vector<Location_note> Total;
	Location_note total;
	if (res->next() == NULL){
		total.user_id = NULL;
		total.music_id = NULL;
		total.location_id = NULL;
		Total.push_back(total);
		return Total;
	}
	for (;;){
		total.user_id = res->getInt(1);
		total.location_id = res->getInt(2);
		total.music_id = res->getInt(3);
		Total.push_back(total);
		if (res->next() == NULL) return Total;
	}
}



Location_note::~Location_note()
{
}
