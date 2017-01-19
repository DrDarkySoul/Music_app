#pragma once
#include "CMySql.h"
class CLocation_note :
	public CMySql
{
public:
	int user_id;
	int location_id;
	int music_id;

	string addLocationNoteAction(int user_id,int location_id,int music_id);
	string deleteLocationNoteAction(int user_id, int location_id,int music_id);
	vector<CLocation_note> getSmbLocationNotesAction(int user_id);

	CLocation_note();
	~CLocation_note();
};

