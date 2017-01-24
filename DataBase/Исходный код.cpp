#include<iostream>
#include "CMySql.h"
#include "User.h"
#include "music.h"
#include "Location.h"
#include "Friends.h"
#include "Playlist.h"
#include "Location_note.h"
#include"Observer.h"
using namespace std;
int main()
{
	User u;
	Location l;
	Playlist p;
	Friends f;
	Location_note ln;
	music m;
	Subject subj;
	p.Registrate(&subj);
	ln.Registrate(&subj);
	f.Registrate(&subj);	
	u.deleteUser(4, &subj);
	l.deleteLocation(5, &subj);
	m.deleteMusic(6, &subj);
	system("pause");

}