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
#include<vector>
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
	string lotitude;
	string title;
	string photo;
};
string Location::addLocation(string id, string latitude, string lotitude, string title, string photo)
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
	}
}
class User{
public:
	string id;
	string login;
	string password;
	string email;
	string nickname;
	string photo;
	string add(string id,string user_login, string user_password, string user_email, string user_nickname, string user_photo);
	string Login(string user_login,string user_password);
	vector<User> getUsers();
	void del_id_log(string key);

	User(){};
	~User(){};

};
class Friends
{
	Friends() {};
	~Friends() {};
public:
	string addFriends(string user_id_1, string user_id_2);
	string user_id_1;
	string user_id_2;
	vector<User> getsmbFriends(string id);
};
string Friends::addFriends(string user_id_1, string user_id_2)
{
	string query = "INSERT INTO User(user_id_1,user_id_2) VALUES(";
	query += user_id_1 + ",";
	query += user_id_2;
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
	}
}
vector<User> Friends::getsmbFriends(string id)
{
	/*vector<string> all_id;
	vector<User> result;
	string query = "SELECT * FROM Friends where user_id_1=";
	query += id+" OR "+"user_id_2="+id;

	sql::mysql::MySQL_Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet  *res;
	sql::ResultSet  *res_user;
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect("localhost", "root", "7680928160");
	con->setSchema("Friends");
	stmt = con->createStatement();
	res = stmt->executeQuery(query);
	delete con;
	delete stmt;
	while (res->next()){
		User a;
		int id_1 = res->getInt(1);
		int id_2 = res->getInt(2);
		int res_id;
		int int_id = atoi(id.c_str());
		if (id_1 != int_id) res_id = id_1;
		else res_id = id_2;
		con = driver->connect("localhost", "root", "7680928160");
		con->setSchema("User");
		query = "SELECT * FROM User WHERE id="+res_id;
		stmt = con->createStatement();
		res_user = stmt->executeQuery(query);
		a.id = res_user->getInt(1);
		a.login = res_user->getString("login");
		a.password = res_user->getString("password");
		a.email = res_user->getString("email");
		a.photo = res_user->getString("photo");
		a.nickname = res_user->getString("nickname");
		result.push_back(a);
	}
	delete res;
	delete con;
	delete stmt;
	return result;*/
}
vector<User> User::getUsers()
{
	vector<User> result;
	string query = "Select * FROM User ";
	sql::mysql::MySQL_Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet  *res;
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect("localhost", "root", "7680928160");
	con->setSchema("User");
	stmt = con->createStatement();
	res=stmt->executeQuery(query);
	while (res->next()){
		User a;
		a.id = res->getInt(1);
		a.login = res->getString("login");
		a.password=res->getString("password");
		a.email=res->getString("email");
		a.photo=res->getString("photo");
		a.nickname=res->getString("nickname");
		result.push_back(a);
	}
	delete res;
	delete con;
	delete stmt;
	return result;
}
void User::del_id_log(string key)//предполагается что он есть?
{
	string query = "DELETE FROM User WHERE id=";
	query += key;
	sql::mysql::MySQL_Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect("localhost", "root", "7680928160");
	con->setSchema("User");
	stmt = con->createStatement();
	//cout << query << endl;
	try{
		stmt->execute(query);
	}
	catch (sql::SQLException){
		query = "DELETE FROM User WHERE login=\"";
		query += key+"\"";
		stmt->execute(query);
		delete con;
		delete stmt;
		return;
	}
	query = "DELETE FROM User WHERE login=\"";//для цифрового логина
	query += key + "\"";
	stmt->execute(query);
	delete con;
	delete stmt;
	return;
	//может удалить двух пользователей если цифровой логин и ест такой же id
}
string User::Login(string user_login, string user_password)
{
	sql::mysql::MySQL_Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet  *res;
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect("localhost", "root", "7680928160");
	con->setSchema("User");//название базы
	stmt = con->createStatement();
	string query ="SELECT id FROM User WHERE login=\"";
	query += user_login+"\"";
	query += " AND password=\"";
	query += user_password+"\"";
	//cout << query;
	res = stmt->executeQuery(query);
	//cout << endl << res;
	//cout <<"ds"<<res->first();
	if (res->first() != NULL) return "YES";
	else return "NO";
	
	delete res;
	delete stmt;
	delete con;
}
string User::add(string id,string user_login, string user_password, string user_email, string user_nickname, string user_photo)
{
	string query = "INSERT INTO User(id,login,password, email, photo, nickname) VALUES(";
	query += id + ",";
	query += "\"";
	query += user_login;
	query += "\"";
	query += ",";
	query += "\"";
	query += user_password + "\"" + "," + "\"" + user_email + "\""+ ",\"" + user_nickname + "\",\"" + user_photo + "\")";
	sql::mysql::MySQL_Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect("localhost", "root", "7680928160");
	con->setSchema("User");
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
int main(void)
{
	User u;
	//cout<<u.add("34", "1234", "jkkddhd4sa45s", "65ddsdhs7@maail.ru", "d17dsdsja234", "wdadwswds7h.sd");
	system("pause");
	return 0;
}