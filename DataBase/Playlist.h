#pragma once
#include "CMySql.h"
#include "music.h"
class Playlist :
	public CMySql
{
public:
	int user_id;
	int music_id;
	
	string addMusicToPlayListAction(int user_id, int music_id);
	string deleteMusicFromPlayListAction(int user_id,int music_id);
	vector<int> getSmbPlayListAction(int user_id, int music_begin, int music_end);
	vector<music> getSmbPlayListFullAction(int user_id, int begin, int end);
	Playlist();
	~Playlist();
};

