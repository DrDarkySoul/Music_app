#pragma once
#include "CMySql.h"
#include "music.h"
#include "Location.h"
class Location_note :
	public CMySql
{
public:
	int user_id;
	int location_id;
	int music_id;

	string addLocationNoteAction(int user_id,int location_id,int music_id);
	string deleteLocationNoteAction(int user_id, int location_id,int music_id);
	vector<Location_note> getSmbLocationNotesAction(int user_id);
	pair<vector<music>, vector<Location>> getSmbLocationNotesFullAction(int user_id);
	pair<vector<music>, vector<Location>> getLocationNotesFullAction(int begin, int end);
	vector<Location_note> getLocationNotesAction(int begin, int end);
	Location_note();
	~Location_note();
};

