#include "Playlist.h"


Playlist::Playlist()
{
}

string Playlist:: addMusicToPlayListAction(int user_id, int music_id)
{
	char buf[255];
	itoa(user_id, buf, 10);
	string str_1 = buf;
	itoa(music_id, buf, 10);
	string str_2 = buf;
	return base_add("Playlist(user_id,music_id)", str_1 + "," + str_2);
}

vector<int> Playlist::getSmbPlayListAction(int user_id, int music_begin, int music_end)
{
	char buf[255];
	itoa(user_id, buf, 10);
	string str_1 = buf;
	itoa(music_begin, buf, 10);
	string str_begin = buf;
	itoa(music_end, buf, 10);
	string str_end = buf;
	res = getbasePlaylistAction(str_1, " AND id>=" + str_begin + " AND id<=" + str_end);
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
string Playlist::deleteMusicFromPlayListAction(int user_id, int music_id)
{
	char buf[255];
	itoa(user_id, buf, 10);
	string str_1 = buf;
	itoa(music_id, buf, 10);
	string str_2 = buf;
	return base_complicated_del("Playlist", "(user_id,music_id)=(" + str_1 + "," + str_2 + ")");
}


vector<music> Playlist::getSmbPlayListFullAction(int user_id, int begin, int end)
{
	res = getbaseSmbPlayListFullAction(user_id, begin, end);
	music m;
	vector<music> M;
	if (res->next() == NULL){
		m.id = NULL;
		m.title = "";
		m.artist = "";
		m.album = "";
		m.duration = NULL;
		m.photo = "";
		M.push_back(m);
		return M;
	}
	for (;;){
		m.id = res->getInt(4);
		m.title = res->getString(5);
		m.artist = res->getString(6);
		m.album = res->getString(7);
		m.duration = res->getInt(8);
		m.photo = res->getString(9);
		M.push_back(m);
		if(res->next()==NULL) return M;
	}
}



Playlist::~Playlist()
{
}
