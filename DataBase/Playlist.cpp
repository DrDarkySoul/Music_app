#include "Playlist.h"


CPlaylist::CPlaylist()
{
}

string CPlaylist:: addMusicToPlayListAction(int user_id, int music_id)
{
	char buf[255];
	itoa(user_id, buf, 10);
	string str_1 = buf;
	itoa(music_id, buf, 10);
	string str_2 = buf;
	return base_add("Playlist(user_id,music_id)", str_1 + "," + str_2);
}

vector<int> CPlaylist::getSmbPlayListAction(int user_id, int music_begin, int music_end)
{
	char buf[255];
	itoa(user_id, buf, 10);
	string str_1 = buf;
	itoa(music_begin, buf, 10);
	string str_begin = buf;
	itoa(music_end, buf, 10);
	string str_end = buf;
	res = getbasePlaylistAction(str_1, " AND music_id>=" + str_begin + " AND music_id<=" + str_end);
	vector<int> Total;
	if (res->next() == NULL){
		Total.push_back(NULL);
		return Total;
	}
	for (;;){
		Total.push_back(res->getInt(2));
		if (res->next() == NULL) return Total;
	}
}
string CPlaylist::deleteMusicFromPlayListAction(int user_id, int music_id)
{
	char buf[255];
	itoa(user_id, buf, 10);
	string str_1 = buf;
	itoa(music_id, buf, 10);
	string str_2 = buf;
	return base_complicated_del("Playlist", "(user_id,music_id)=(" + str_1 + "," + str_2 + ")");
}

CPlaylist::~CPlaylist()
{
}
