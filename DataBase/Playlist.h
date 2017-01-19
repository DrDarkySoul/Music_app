#pragma once
#include "CMySql.h"
class CPlaylist :
	public CMySql
{
public:
	int user_id;
	int music_id;
	
	string addMusicToPlayListAction(int user_id, int music_id);
	string deleteMusicFromPlayListAction(int user_id,int music_id);
	vector<int> getSmbPlayListAction(int user_id, int music_begin, int music_end);
	
	CPlaylist();
	~CPlaylist();
};

