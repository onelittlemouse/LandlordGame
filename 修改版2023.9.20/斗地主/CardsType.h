#pragma once
//定义3-10,J-2,small king,big king
//pair<string, int> string:卡牌名称,int:卡牌大小
#define CARD_3 {"3", 0}
#define CARD_4 {"4", 1}
#define CARD_5 {"5", 2}
#define CARD_6 {"6", 3}
#define CARD_7 {"7", 4}
#define CARD_8 {"8", 5}
#define CARD_9 {"9", 6}
#define CARD_10 {"10", 7}
#define CARD_J {"J", 8}
#define CARD_Q {"Q", 9}
#define CARD_K {"K", 10}
#define CARD_A {"A", 11}
#define CARD_2 {"2", 12}
#define CARD_sking {"sking", 13}
#define CARD_bking {"bking", 14}
//共15种卡牌
#define CARDS_SIZE 15
//定义玩家人数，仅支持3和4
#define PLAYER_COUNT 4
//定义卡牌套数，3人1副，4人2副
#define CARDS_COUNT int(PLAYER_COUNT) / 2
//卡牌种类数组
const std::vector<std::pair<std::string, int>> CARDS_TYPE = { CARD_3, CARD_4, CARD_5, CARD_6, CARD_7, CARD_8, CARD_9, CARD_10, CARD_J, CARD_Q, CARD_K, CARD_A, CARD_2, CARD_sking, CARD_bking };