#include "Location_note.h"


CLocation_note::CLocation_note()
{
}

string CLocation_note::addLocationNoteAction(int user_id, int location_id, int music_id)
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

string CLocation_note::deleteLocationNoteAction(int user_id, int location_id, int music_id)
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

vector<CLocation_note> CLocation_note::getSmbLocationNotesAction(int user_id)
{
	char buf[255];
	itoa(user_id, buf, 10);
	string str_id = buf;
	res = getbaseLocation_noteAction(str_id);
	vector<CLocation_note> Total;
	CLocation_note total;
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

CLocation_note::~CLocation_note()
{
}
