#include "music.h"
string music::addMusic(string title, string artist, string album, int duration, string photo)
{
	char*buf = new char[255];
	itoa(duration,buf,10);
	string str_dur = buf;
	delete buf;
	return base_add("music(title,artist,album,duration,photo)", "\"" + title + "\",\"" + artist + "\",\"" + album + "\"," + str_dur + ",\"" + photo + "\"");
}
string music::deleteMusic(int id)
{
	char buf[255];
	itoa(id, buf, 10);
	string str_id = buf;
	return base_del("music", str_id);
}
music music::getMusicAction(int id)
{
	char buf[255];
	itoa(id, buf, 10);
	string str_id = buf;
	res = getBaseAction("music", str_id);
	music total;
	if (res->next() == NULL){
		total.id = NULL;
		total.title = "";
		total.artist = "";
		total.album = "";
		total.duration = NULL;
		total.photo = "";
		return total;
	}
	total.id = res->getInt(1);
	total.title = res->getString(2);
	total.artist = res->getString(3);
	total.album = res->getString(4);
	total.duration = res->getInt(5);
	total.photo = res->getString(6);
	return total;
}
vector<music> music::getMusicsAction(int begin, int end)
{
	char buf[255];
	itoa(begin, buf, 10);
	string str_begin = buf;
	itoa(end, buf, 10);
	string str_end = buf;
	res = getBasesAction("music", str_begin, str_end);
	vector<music> Total;
	music total;
	if (res->next() == NULL){
		total.id = NULL;
		total.title = "";
		total.artist = "";
		total.album = "";
		total.duration = NULL;
		total.photo = "";
		Total.push_back(total);
		return Total;
	}
	for (;;){
		total.id = res->getInt(1);
		total.title = res->getString(2);
		total.artist = res->getString(3);
		total.album = res->getString(4);
		total.duration = res->getInt(5);
		total.photo = res->getString(6);
		Total.push_back(total);
		if (res->next() == NULL) return Total;
	}
}
music::music()
{
}


music::~music()
{
}
