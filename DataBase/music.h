#pragma once
#include "CMySql.h"
#include<vector>
class music :
	public CMySql
{
public:
	int id;
	string title;
	string artist;
	string album;
	int duration;
	string photo;

	string addMusic(string title,string artist, string album, int duration, string photo);
	string deleteMusic(int id);
	music getMusicAction(int id);
	vector<music> getMusicsAction(int begin, int end);
	music();
	~music();
};

