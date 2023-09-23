#pragma once
#include"IncludeMenu.h"
#include"Player.h"

class Game
{
public:
	//启动
	void play();

private:
	vector<pair<string, int>> all_cards; //所有卡牌的数组
	std::vector<pair<pair<std::string, int>, int>> leftCards = { {CARD_3, 0}, {CARD_4, 0}, {CARD_5, 0}, {CARD_6, 0}, {CARD_7, 0}, {CARD_8, 0}, {CARD_9, 0}, {CARD_10, 0}, {CARD_J, 0}, {CARD_Q, 0}, {CARD_K, 0}, {CARD_A, 0}, {CARD_2, 0}, {CARD_sking, 0}, {CARD_bking, 0} }; //目前所有玩家手中卡牌
	Player player_Arr[PLAYER_COUNT]; //玩家数组
	int player_cycle[PLAYER_COUNT]; //玩家出牌顺序
	int landlordIndex; //地主的玩家编号

	//提供帮助
	void instruction();

	//初始化所有卡牌并打乱
	void InitAllCards();

	//初始化玩家卡牌，3people:一人17张,4people:一人25张
	void InitPlayersCards();

	//展示地主牌
	//void displayLandlordCards();

	//选择地主
	int selectLandlord();

	//设置玩家编号，是否为地主
	void InitPlayers();

	//给地主发额外卡牌,3player:3,4player:8
	void giveLandlordCards();

	//展示所有玩家卡牌情况
	void displayPlayersCards();

	//出牌前提示
	void mentionInfo();

	//开始出牌
	void start();
};