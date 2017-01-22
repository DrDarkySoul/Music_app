<<<<<<< Updated upstream
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
=======
/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

/*
Include directly the different
headers from cppconn/ and mysql_driver.h + mysql_util.h
(and mysql_connection.h). This will reduce your build time!
*/

#include "mysql_connection.h"
#include "mysql_driver.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include <vector>

using namespace std;

class Location
{
	Location(){};
	~Location() {};

public:

	string addLocation(string id, string latitude, string lotitude, string title, string photo);
	string deleteLocation(string id);

	string id;
	string latitude;
	string longitude;
	string title;
	string photo;
};

string Location::addLocation(string id, string latitude, string longitude, string title, string photo)
{
	string query = "INSERT INTO User(id,title,latitude, lotitude, title, photo) VALUES(";
	query += id + ",";
	query += "\"";
	query += title;
	query += "\"";
	query += ",";
	query += "\"";
	query += latitude + "\"" + "," + "\"" + lotitude + "\"" + ",\"" + title + "\",\"" + photo + "\")";
	sql::mysql::MySQL_Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect("localhost", "root", "7680928160");
	con->setSchema("Friends");
	stmt = con->createStatement();
	//cout << query << endl;
	try{
		stmt->execute(query);
		delete con;
		delete stmt;
		return "YES";
	}
	catch (sql::SQLException){
		delete con;
		delete stmt;
		return "NO";
	}
}
string Location::deleteLocation(string id)
{
	string query = "DELETE FROM Location WHERE id=";
	query += id;
	sql::mysql::MySQL_Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect("localhost", "root", "7680928160");
	con->setSchema("Location");
	stmt = con->createStatement();
	//cout << query << endl;
	try{
		stmt->execute(query);
		delete con;
		delete stmt;
		return "YES";
	}
	catch (sql::SQLException){
		delete con;
		delete stmt;
		return "NO";
	}
}
class Location_notes
{
	Location_notes() {};
	~Location_notes() {};
public:
	string user_id;
	string location_id;
	string music_id;
};
class Music
{
	Music(){};
	~Music(){};
public:
	string addMusic(string id, string title, string artist, string album, string duration, string photo);
	string id;
	string title;
	string artist;
	string album;
	string duration;
	string photo;
};
string Music::addMusic(string id, string title, string artist, string album, string duration, string photo)
{
	string query = "INSERT INTO User(id,title,artist, album, duration, photo) VALUES(";
	query += id + ",";
	query += "\"";
	query += title;
	query += "\"";
	query += ",";
	query += "\"";
	query += artist + "\"" + "," + "\"" + album + "\""+ ",\"" + duration + "\",\"" + photo + "\")";
	sql::mysql::MySQL_Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect("localhost", "root", "7680928160");
	con->setSchema("Music");
	stmt = con->createStatement();
	//cout << query << endl;
	try{
		stmt->execute(query);
		delete con;
		delete stmt;
		return "YES";
	}
	catch (sql::SQLException){
		delete con;
		delete stmt;
		return "NO";
	}
}
class Playlist
{
	Playlist() {};
	~Playlist() {};
public:
	string addMusicToPlaylist(string user_id,string music_id);
	string deleteMusicToPlaylist(string user_id);
	string user_id;
	string music_id;
};
string Playlist::deleteMusicToPlaylist(string user_id)
{
	string query = "DELETE FROM Location WHERE id=";
	query += user_id;
	sql::mysql::MySQL_Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect("localhost", "root", "7680928160");
	con->setSchema("PLaylist");
	stmt = con->createStatement();
	//cout << query << endl;
	try{
		stmt->execute(query);
		delete con;
		delete stmt;
		return "YES";
	}
	catch (sql::SQLException){
		delete con;
		delete stmt;
		return "NO";
	}
}
string addMusicToPlaylist(string user_id, string music_id)
{
	string query = "INSERT INTO User(user_id,music_id) VALUES(";
	query += user_id + ",";
	query += music_id;
	query += ")";
	sql::mysql::MySQL_Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect("localhost", "root", "7680928160");
	con->setSchema("Friends");
	stmt = con->createStatement();
	//cout << query << endl;
	try{
		stmt->execute(query);
		delete con;
		delete stmt;
		return "YES";
	}
	catch (sql::SQLException){
		delete con;
		delete stmt;
		return "NO";
>>>>>>> Stashed changes
	}
	system("pause");
}