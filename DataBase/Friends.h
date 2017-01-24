#pragma once
#include "CMySql.h"
#include "User.h"
class Friends :
	public CMySql,Observer
{
public:
	void Registrate(Subject *mod){ baseRegistrate(mod); }
	void update(pair<int, int> val){
		if (val.second == 0){
			deleteFriendActionbyUser_id(val.first);
		}
	}
	int user_id_1;
	int user_id_2;
	string deleteFriendActionbyUser_id(int user_id);
	string addFriendAction(int user_id_1,int user_id_2);
	string deleteFriendAction(int user_id_1, int user_id_2);
	vector<int> getSmbFriendsFullAction(int id);
	vector<int> getSmbFriendsAction(int id, int begin, int end);
	vector<User> getSmbFriendsFullAction(int user_id, int begin, int end);
	Friends();
	~Friends();
};

