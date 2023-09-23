#pragma once
#include"IncludeMenu.h"

class Player
{
	typedef std::vector<pair<std::string, int>> CARDS_Type;
	typedef std::pair<std::string, int> METHOD_Type;

public:
	//no param construction
	Player();

	//������ұ�ţ��Ƿ�Ϊ����
	Player(int index, bool isfarmer);
	
	//������ұ�ţ��Ƿ�Ϊ����
	void setPlayer(int index, bool isfarmer);

	//�������һ�ſ���
	void getSingleCard(const pair<std::string, int>& card);

	//չʾ��ұ�ţ��Ƿ�Ϊ����
	void displayPlayerInfo();

	//չʾ������п���
	void displayCards();

	//չʾ��ҳ���
	void displayGiveCards();

	//�ж�����Ƿ�ʣ�࿨��
	bool cards_isEmpty();

	//�������ʣ������
	int cards_count();

	void cards_counter(std::vector<pair<pair<std::string, int>, int>>& cards);

	//3people,��ǰ��ҳ���
	//const std::pair<std::string, int>& method ��һ�γ���ʱ�Ĺ���,6-6-6-5-5-5:MULTITHREE,8-8-8-7-7:THREETWO
	//int requireIndex 8-8-8-7-7:CARD_8.second,6-6-6-5-5-5:CARD_6.second,2-A-3-4-5:CARD_5.second,2-2-A-A-K-K:CARD_2.second
	//int& requireCardCount ��һ�γ���ʱ��ҳ�����,6-6-6-5-5-5:6,8-8:2
	pair<pair<string, int>, int> giveCard_3(const std::pair<std::string, int>& method, int requireIndex, int& requireCardCount);

	//4people,��ǰ��ҳ���,����ͬ��
	pair<pair<string, int>, int> giveCard_4(const std::pair<std::string, int>& method, int requireIndex, int& requireCardCount);

private:
	int index; //��ұ��
	bool isfarmer; //�Ƿ�Ϊũ��
	//��������Ƶ����,pair<pair<std::string, int>, int> pair<std::string, int>:�������,int:���д��ſ������� 3��6{ CARD_6, 3 }
	std::vector<pair<pair<std::string, int>, int>> cards = { {CARD_3, 0}, {CARD_4, 0}, {CARD_5, 0}, {CARD_6, 0}, {CARD_7, 0}, {CARD_8, 0}, {CARD_9, 0}, {CARD_10, 0}, {CARD_J, 0}, {CARD_Q, 0}, {CARD_K, 0}, {CARD_A, 0}, {CARD_2, 0}, {CARD_sking, 0}, {CARD_bking, 0} };
	//��ҳ��ƶ�Ӧ����
	std::vector<pair<pair<std::string, int>, int>> givecards = { {CARD_3, 0}, {CARD_4, 0}, {CARD_5, 0}, {CARD_6, 0}, {CARD_7, 0}, {CARD_8, 0}, {CARD_9, 0}, {CARD_10, 0}, {CARD_J, 0}, {CARD_Q, 0}, {CARD_K, 0}, {CARD_A, 0}, {CARD_2, 0}, {CARD_sking, 0}, {CARD_bking, 0} };

	//�ָ��ַ��� Stringsplit("8-8-8",'-',null):res={"8","8","8"}
	void stringSplit(const string& str, const char split, vector<string>& res);

	//�����п��Ƹ�player0
	void fullCards();

	//�ж�givecards�Ƿ����3�˹���
	//vector<int>& vnum givecards={{...,2},{...,3},{...,0},...}:vnum={2,3}
	//pair<pair<string, int>, int> pair<string, int>:method, int:��method�����ȼ�
	pair<pair<string, int>, int> judgeMethod_3(vector<pair<pair<string, int>, int>>& givecards);

	//�ж�givecards�Ƿ����4�˹���
	pair<pair<string, int>, int> judgeMethod_4(vector<pair<pair<string, int>, int>>& givecards);

	//�ж�givecards�Ƿ�ΪAAABBBCD��
	//vector<int>& vnum givecards={{...,2},{...,3},{...,0},...}:vnum={2,3}
	//pair<bool, int> bool:�Ƿ�ΪAAABBBCD��,int:��һ��������µ����ȼ� 3-3-3-4-4-4-8-8-9-9:4
	pair<bool, int> isAeroplane1(vector<pair<pair<string, int>, int>>& givecards, vector<int>& vnum);

	//�ж�givecards�Ƿ�ΪAAABBBCCDD��
	pair<bool, int> isAeroplane2(vector<pair<pair<string, int>, int>>& givecards, vector<int>& vnum);

	//�ж�givecards�Ƿ�ΪAAABBB,AAABBBCCC,AAABBBCCCDDD,...��
	pair<bool, int> isMultithree(vector<pair<pair<string, int>, int>>& givecards, vector<int>& vnum);

	//�ж�givecards�Ƿ�ΪAABBCC,AABBCCDD,...��
	pair<bool, int> isMultiTwo(vector<pair<pair<string, int>, int>>& givecards, vector<int>& vnum);

	//�ж�givecards�Ƿ�ΪABCDE,ABCDEF,ABCDEFG,...��
	pair<bool, int> isMultiOne(vector<pair<pair<string, int>, int>>& givecards, vector<int>& vnum);
};
