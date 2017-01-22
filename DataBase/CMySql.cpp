#include "CMySql.h"
#include "User.h"
using namespace std;
CMySql::CMySql()
{
	driver = get_driver_instance();
	con = driver->connect("localhost", "root", "7680928160");
	con->setSchema("User");//название бд
	stmt = con->createStatement();
}
string CMySql::base_add(string first,string second)
{
	string query ="INSERT INTO "+first+" Values("+second+")";
	cout << query;
	try{
		stmt->execute(query);
		return "YES";
	}
	catch (sql::SQLException){
		return "NO";
	}
}
string CMySql::base_del(string first, string second)
{
	string query = "Delete From " + first + " Where id=" + second;
	cout << query;
	try{
		stmt->execute(query);
		return "YES";
	}
	catch (sql::SQLException){
		return "NO";
	}
}

string CMySql::base_complicated_del(string first, string second)
{
	string query = "Delete From " + first + " Where " + second;
	cout << query;
	try{
		stmt->execute(query);
		return "YES";
	}
	catch (sql::SQLException){
		return "NO";
	}
}
string CMySql::Login(string login, string password)
{
	pstmt = con->prepareStatement("Select * From User Where(login, password)=(?, ?)");
	pstmt->setString(1, login);
	pstmt->setString(2, password);
	res=pstmt->executeQuery();
	if (res->first() != NULL) return "YES";
	else return "NO";
}
string CMySql::checkFriendAction(int user_id_1, int user_id_2)
{
	pstmt = con->prepareStatement("Select * From Friends Where(user_id_1, user_id_2)=(?, ?)");
	pstmt->setInt(1, user_id_1);
	pstmt->setInt(2, user_id_2);
	res = pstmt->executeQuery();
	if (res->first() != NULL) return "YES";
	else return "NO";
}
sql::ResultSet* CMySql::getBaseAction(string table, string str_id)
{
	string query = "select * from " + table + " where id=" + str_id;
	//cout << query;
	return stmt->executeQuery(query);
}
sql::ResultSet* CMySql::getbaseFriendsAction(string first,string second)
{
	string query = "select * from Friends where user_id_1=" + first+second;
	//cout << query;
	return stmt->executeQuery(query);
}

sql::ResultSet* CMySql::getbasePlaylistAction(string first, string second)
{
	string query = "select * from playlist where user_id=" + first + second;
	//cout << query;
	return stmt->executeQuery(query);
}

sql::ResultSet* CMySql::getbaseLocation_noteAction(string first, string second)
{
	string query = "select * from location_notes where user_id=" + first + second;
	//cout << query;
	return stmt->executeQuery(query);
}

sql::ResultSet* CMySql::getBasesAction(string table, string str_begin, string str_end)
{
	string query = "select * from " + table + " where id>=" + str_begin + " AND id<=" + str_end;
	//cout << query;
	return stmt->executeQuery(query);
}


sql::ResultSet* CMySql::getbaseSmbLocationNotesFullAction(int user_id)
{
	pstmt = con->prepareStatement("SELECT * FROM  location_notes INNER JOIN music ON location_notes.music_id = music.id INNER JOIN location ON location_notes.location_id=location.id WHERE user_id=?");
	pstmt->setInt(1, user_id);
	return pstmt->executeQuery();
}


sql::ResultSet* CMySql::getbaseLocationNotesFullAction(int begin, int end)
{
	pstmt = con->prepareStatement("SELECT * FROM  location_notes INNER JOIN music ON location_notes.music_id = music.id INNER JOIN location ON location_notes.location_id=location.id WHERE location.id BETWEEN ? AND ?");
	pstmt->setInt(1, begin);
	pstmt->setInt(2, end);
	return pstmt->executeQuery();
}


sql::ResultSet* CMySql::getbaseSmbFriendsFullAction(int user_id, int begin, int end)
{
	pstmt = con->prepareStatement("SELECT * FROM friends INNER JOIN user ON friends.user_id_2 = user.id WHERE user_id_1 = ? AND friends.id BETWEEN ? AND ?");
	pstmt->setInt(1, user_id);
	pstmt->setInt(2, begin);
	pstmt->setInt(3, end);
	return pstmt->executeQuery();
}


sql::ResultSet* CMySql::getbaseSmbPlayListFullAction(int user_id, int begin, int end)
{
	pstmt = con->prepareStatement("SELECT * FROM playlist INNER JOIN music ON playlist.music_id=music.id WHERE playlist.user_id=? AND playlist.id BETWEEN ? AND ?");
	pstmt->setInt(1, user_id);
	pstmt->setInt(2, begin);
	pstmt->setInt(3, end);
	return pstmt->executeQuery();
}


CMySql::~CMySql()
{
	/*delete res;
	delete pstmt;
	delete con;
	delete stmt;*/
}
