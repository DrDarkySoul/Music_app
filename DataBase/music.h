#pragma once
#include "CMySql.h"
#include<vector>
class Cmusic :
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
	Cmusic getMusicAction(int id);
	vector<Cmusic> getMusicsAction(int begin, int end);
	Cmusic();
	~Cmusic();
};

