#include<iostream>
#include "CMySql.h"
#include "User.h"
#include "music.h"
#include "Location.h"
#include "Friends.h"
#include "Playlist.h"
#include "Location_note.h"
using namespace std;
int main()
{
	Location_note a;
	vector<Location_note> total;
	total = a.getLocationNotesAction(1, 3);
	for (int i = 0; i < total.size(); i++){
		cout << "music=" << total[i].user_id<<total[i].music_id<<total[i].music_id; //<< total[i].album << total[i].artist << total[i].duration << total[i].photo;
	}
	system("pause");
}