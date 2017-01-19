#pragma once
#include<iostream>
#include <stdlib.h>
#include "mysql_connection.h"
#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include<vector>
#include<string>
using namespace std;
class CMySql
{
public:
	sql::ResultSet  *res;
	sql::PreparedStatement *pstmt;
	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;

	string base_add(string first, string second);
	string Login(string login, string password);
	string base_complicated_del(string first,string second);
	string base_del(string first, string second);
	string checkFriendAction(int user_id_1, int user_id_2);
	sql::ResultSet* getbaseFriendsAction(string first, string second="");
	sql::ResultSet* getBaseAction(string table,string str_id);
	sql::ResultSet* getBasesAction(string table, string str_begin, string str_end);
	sql::ResultSet* CMySql::getbasePlaylistAction(string first, string second = "");
	sql::ResultSet* CMySql::getbaseLocation_noteAction(string first, string second="");
	
	CMySql();
	~CMySql();
};

