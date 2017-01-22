#pragma once
#include "CMySql.h"
#include "User.h"
class Friends :
	public CMySql
{
public:
	int user_id_1;
	int user_id_2;

	string addFriendAction(int user_id_1,int user_id_2);
	string deleteFriendAction(int user_id_1, int user_id_2);
	vector<int> getSmbFriendsFullAction(int id);
	vector<int> getSmbFriendsAction(int id, int begin, int end);
	vector<User> getSmbFriendsFullAction(int user_id, int begin, int end);
	Friends();
	~Friends();
};

