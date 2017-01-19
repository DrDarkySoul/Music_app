#include "Friends.h"


CFriends::CFriends()
{
}
string CFriends::addFriendAction(int user_id_1, int user_id_2)
{
	if (checkFriendAction(user_id_1, user_id_2) == "YES") return "NO"; 	
	char buf[255];
	itoa(user_id_1, buf, 10);
	string str_1 = buf;
	itoa(user_id_2, buf, 10);
	string str_2 = buf;
	base_add("Friends(user_id_1,user_id_2)", str_2 + "," + str_1);
	return base_add("Friends(user_id_1,user_id_2)", str_1 +"," + str_2);
}

vector<int> CFriends::getSmbFriendsFullAction(int id)
{
	char buf[255];
	itoa(id, buf, 10);
	string str_1 = buf;
	res = getbaseFriendsAction(str_1);
	vector<int> Total;
	if (res->next() == NULL){
		Total.push_back(NULL);
		return Total;
	}
	for (;;){
		Total.push_back(res->getInt(2));
		if (res->next() == NULL) return Total;
	}
}

vector<int> CFriends::getSmbFriendsAction(int id,int begin, int end)
{
	char buf[255];
	itoa(id, buf, 10);
	string str_1 = buf;
	itoa(begin, buf, 10);
	string str_begin = buf;
	itoa(end, buf, 10);
	string str_end = buf;
	res = getbaseFriendsAction(str_1," AND user_id_2>="+ str_begin + " AND user_id_2<=" + str_end);
	vector<int> Total;
	if (res->next() == NULL){
		Total.push_back(NULL);
		return Total;
	}
	for (;;){
		Total.push_back(res->getInt(2));
		if (res->next() == NULL) return Total;
	}
}

string CFriends::deleteFriendAction(int user_id_1, int user_id_2)
{
	char buf[255];
	itoa(user_id_1, buf, 10);
	string str_1 = buf;
	itoa(user_id_2, buf, 10);
	string str_2 = buf;
	base_complicated_del("Friends", "(user_id_1,user_id_2)=(" + str_2 + "," + str_1 + ")");
	return base_complicated_del("Friends", "(user_id_1,user_id_2)=(" + str_1 + "," + str_2 + ")");
}

CFriends::~CFriends()
{
}
