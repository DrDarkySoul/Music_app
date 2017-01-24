#pragma once
#include "CMySql.h"
#include "music.h"
#include "Observer.h"
class Playlist :
	public CMySql,Observer
{
public:
	void Registrate(Subject *mod){ baseRegistrate(mod); }
	void update(pair<int, int> val){
		if (val.second == 0){
			deleteMusic_byUser_id_FromPlayListAction(val.first);
		}
		if (val.second == 1){
			deleteMusic_byMusic_id_FromPlayListAction(val.first);
		}
	}
	int user_id;
	int music_id;
	
	string addMusicToPlayListAction(int user_id, int music_id);
	string deleteMusicFromPlayListAction(int user_id,int music_id);
	string deleteMusic_byUser_id_FromPlayListAction(int user_id);
	string deleteMusic_byMusic_id_FromPlayListAction(int music_id);
	vector<int> getSmbPlayListAction(int user_id, int music_begin=0, int music_end=0);
	vector<music> getSmbPlayListFullAction(int user_id, int begin, int end);
	Playlist();
	~Playlist();
};

