#pragma once
#include "CMySql.h"
#include "Observer.h"
#include<vector>
class music :
	public CMySql,Observer
{
public:
	void Registrate(Subject *mod){ baseRegistrate(mod); }
	void update(pair<int, int> val){
		cout << "music" << endl;
	}
	int id;
	string title;
	string artist;
	string album;
	int duration;
	string photo;

	string addMusic(string title,string artist, string album, int duration, string photo);
	string deleteMusic(int id, Subject * subj);
	music getMusicAction(int id);
	vector<music> getMusicsAction(int begin, int end);
	music();
	~music();
};

