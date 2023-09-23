#pragma once
//pair<string, int> string:规则名,int:优先级
#define KING_BOOM {"kb", 1} //3player:bking-sking 4player:bking-bking-sking-sking
#define BOOM_8 {"b8", 2} //3player:none 4player:8-8-8-8-8-8-8-8
#define BOOM_7 {"b7", 3} //3player:none 4player:8-8-8-8-8-8-8
#define BOOM_6 {"b6", 4} //3player:none 4player:8-8-8-8-8-8
#define BOOM_5 {"b5", 5} //3player:none 4player:8-8-8-8-8
#define BOOM_4 {"b4", 6} //3player,4player:8-8-8-8
#define AEROPLANE1 {"a3311", 7} //3player:9-9-9-8-8-8-3-5 4player:none
#define AEROPLANE2 {"a3322", 7} //3player,4player:9-9-9-8-8-8-3-3-5-5
#define MULTITHREE {"m3", 7} //3player,4player:9-9-9-8-8-8-7-7-7
#define MULTITWO {"m2", 7} //3player,4player:9-9-9-8-8-8
#define MULTIONE {"m1", 7} //3player,4player:9-8-7-6-5
#define FOURONEONE {"c411", 7} //3player:8-8-8-8-3-5 4player:none
#define FOURTWOTWO {"c422", 7} //3player:8-8-8-8-3-3-5-5 4player:none
#define THREE {"c3", 7} //3player,4player:9-9-9
#define THREEONE {"c31", 7} //3player:9-9-9-8 4player:none
#define THREETWO {"c32", 7} //3player,4player:9-9-9-8-8
#define TWO {"c2", 7} //3player,4player:9-9
#define ONE {"c1", 7} //3player,4player:9
#define ALL {"all", 8} //3player,4player:all vaild method
#define NONE {"none", 8} //3player,4player:no vaild method
//3人所有出牌规则
const vector<pair<string, int>> METHODS_TYPE_3 = { KING_BOOM, BOOM_4, AEROPLANE1, AEROPLANE2, MULTITHREE, MULTITWO, MULTIONE, FOURONEONE, FOURTWOTWO, THREE, THREEONE, THREETWO, TWO, ONE, ALL, NONE };
const vector<string> METHODS_TYPE_3_EXAMPLE = { "bking-sking", "5-5-5-5", "9-9-9-8-8-8-4-5", "7-7-7-6-6-6-9-9-J-J", "K-K-K-Q-Q-Q", "10-10-9-9-8-8", "A-K-Q-J-10", "6-6-6-6-10-9", "A-A-A-A-6-6-4-4", "2-2-2", "Q-Q-Q-3", "K-K-K-6-6", "10-10", "A", "all valid methods", "no valid methods" };
//4人所有出牌规则
const vector<pair<string, int>> METHODS_TYPE_4 = { KING_BOOM, BOOM_8, BOOM_7, BOOM_6, BOOM_5, BOOM_4, AEROPLANE2, MULTITHREE, MULTITWO, MULTIONE, THREE, THREETWO, TWO, ONE, ALL, NONE };
const vector<string> METHODS_TYPE_4_EXAMPLE = { "bking-bking-sking-sking", "9-9-9-9-9-9-9-9", "7-7-7-7-7-7-7", "3-3-3-3-3-3", "Q-Q-Q-Q-Q", "5-5-5-5", "7-7-7-6-6-6-9-9-J-J", "K-K-K-Q-Q-Q", "10-10-9-9-8-8", "A-K-Q-J-10", "2-2-2", "K-K-K-6-6", "10-10", "A", "all valid methods", "no valid methods"};