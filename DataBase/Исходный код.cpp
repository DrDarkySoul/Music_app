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
	CLocation_note a;
	vector<CLocation_note>b= a.getSmbLocationNotesAction(1);
	for (int i = 0; i < b.size(); i++){
		cout << b[i].music_id << " ";
	}
	system("pause");
	return 0;
}