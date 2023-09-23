#pragma once
#include"IncludeMenu.h"

class Player
{
	typedef std::vector<pair<std::string, int>> CARDS_Type;
	typedef std::pair<std::string, int> METHOD_Type;

public:
	//no param construction
	Player();

	//设置玩家编号，是否为地主
	Player(int index, bool isfarmer);
	
	//设置玩家编号，是否为地主
	void setPlayer(int index, bool isfarmer);

	//发给玩家一张卡牌
	void getSingleCard(const pair<std::string, int>& card);

	//展示玩家编号，是否为地主
	void displayPlayerInfo();

	//展示玩家所有卡牌
	void displayCards();

	//展示玩家出牌
	void displayGiveCards();

	//判断玩家是否剩余卡牌
	bool cards_isEmpty();

	//返回玩家剩余牌数
	int cards_count();

	void cards_counter(std::vector<pair<pair<std::string, int>, int>>& cards);

	//3people,当前玩家出牌
	//const std::pair<std::string, int>& method 上一次出牌时的规则,6-6-6-5-5-5:MULTITHREE,8-8-8-7-7:THREETWO
	//int requireIndex 8-8-8-7-7:CARD_8.second,6-6-6-5-5-5:CARD_6.second,2-A-3-4-5:CARD_5.second,2-2-A-A-K-K:CARD_2.second
	//int& requireCardCount 上一次出牌时玩家出牌数,6-6-6-5-5-5:6,8-8:2
	pair<pair<string, int>, int> giveCard_3(const std::pair<std::string, int>& method, int requireIndex, int& requireCardCount);

	//4people,当前玩家出牌,参数同上
	pair<pair<string, int>, int> giveCard_4(const std::pair<std::string, int>& method, int requireIndex, int& requireCardCount);

private:
	int index; //玩家编号
	bool isfarmer; //是否为农民
	//玩家手中牌的情况,pair<pair<std::string, int>, int> pair<std::string, int>:卡牌类别,int:手中此张卡牌数量 3张6{ CARD_6, 3 }
	std::vector<pair<pair<std::string, int>, int>> cards = { {CARD_3, 0}, {CARD_4, 0}, {CARD_5, 0}, {CARD_6, 0}, {CARD_7, 0}, {CARD_8, 0}, {CARD_9, 0}, {CARD_10, 0}, {CARD_J, 0}, {CARD_Q, 0}, {CARD_K, 0}, {CARD_A, 0}, {CARD_2, 0}, {CARD_sking, 0}, {CARD_bking, 0} };
	//玩家出牌对应数组
	std::vector<pair<pair<std::string, int>, int>> givecards = { {CARD_3, 0}, {CARD_4, 0}, {CARD_5, 0}, {CARD_6, 0}, {CARD_7, 0}, {CARD_8, 0}, {CARD_9, 0}, {CARD_10, 0}, {CARD_J, 0}, {CARD_Q, 0}, {CARD_K, 0}, {CARD_A, 0}, {CARD_2, 0}, {CARD_sking, 0}, {CARD_bking, 0} };

	//分割字符串 Stringsplit("8-8-8",'-',null):res={"8","8","8"}
	void stringSplit(const string& str, const char split, vector<string>& res);

	//将所有卡牌给player0
	void fullCards();

	//判断givecards是否符合3人规则
	//vector<int>& vnum givecards={{...,2},{...,3},{...,0},...}:vnum={2,3}
	//pair<pair<string, int>, int> pair<string, int>:method, int:此method下优先级
	pair<pair<string, int>, int> judgeMethod_3(vector<pair<pair<string, int>, int>>& givecards);

	//判断givecards是否符合4人规则
	pair<pair<string, int>, int> judgeMethod_4(vector<pair<pair<string, int>, int>>& givecards);

	//判断givecards是否为AAABBBCD型
	//vector<int>& vnum givecards={{...,2},{...,3},{...,0},...}:vnum={2,3}
	//pair<bool, int> bool:是否为AAABBBCD型,int:这一出牌类别下的优先级 3-3-3-4-4-4-8-8-9-9:4
	pair<bool, int> isAeroplane1(vector<pair<pair<string, int>, int>>& givecards, vector<int>& vnum);

	//判断givecards是否为AAABBBCCDD型
	pair<bool, int> isAeroplane2(vector<pair<pair<string, int>, int>>& givecards, vector<int>& vnum);

	//判断givecards是否为AAABBB,AAABBBCCC,AAABBBCCCDDD,...型
	pair<bool, int> isMultithree(vector<pair<pair<string, int>, int>>& givecards, vector<int>& vnum);

	//判断givecards是否为AABBCC,AABBCCDD,...型
	pair<bool, int> isMultiTwo(vector<pair<pair<string, int>, int>>& givecards, vector<int>& vnum);

	//判断givecards是否为ABCDE,ABCDEF,ABCDEFG,...型
	pair<bool, int> isMultiOne(vector<pair<pair<string, int>, int>>& givecards, vector<int>& vnum);
};
