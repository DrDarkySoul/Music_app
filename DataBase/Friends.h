#pragma once
#include "CMySql.h"
class CFriends :
	public CMySql
{
public:
	int user_id_1;
	int user_id_2;

	string addFriendAction(int user_id_1,int user_id_2);
	string deleteFriendAction(int user_id_1, int user_id_2);
	vector<int> getSmbFriendsFullAction(int id);
	vector<int> getSmbFriendsAction(int id, int begin, int end);

	CFriends();
	~CFriends();
};

