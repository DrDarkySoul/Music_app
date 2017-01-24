#pragma once
#include "CMySql.h"
#include "music.h"
#include "Location.h"
class Location_note :
	public CMySql,Observer
{
public:
	void Registrate(Subject *mod){ baseRegistrate(mod); }
	void update(pair<int, int> val){
		if (val.second == 0) deleteLocationNoteActionbyUser_id(val.first);
		if (val.second == 1) deleteLocationNoteActionbyMusic_id(val.first);
		if (val.second == 2) deleteLocationNoteActionbyLocation_id(val.first);
	}
	int user_id;
	int location_id;
	int music_id;
	string deleteLocationNoteActionbyUser_id(int user_id);
	string deleteLocationNoteActionbyMusic_id(int music_id);
	string deleteLocationNoteActionbyLocation_id(int location_id);
	string addLocationNoteAction(int user_id,int location_id,int music_id);
	string deleteLocationNoteAction(int user_id, int location_id,int music_id);
	vector<Location_note> getSmbLocationNotesAction(int user_id);
	pair<vector<music>, vector<Location>> getSmbLocationNotesFullAction(int user_id);
	pair<vector<music>, vector<Location>> getLocationNotesFullAction(int begin, int end);
	vector<Location_note> getLocationNotesAction(int begin, int end);
	Location_note();
	~Location_note();
};

