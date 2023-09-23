#pragma once
#include"IncludeMenu.h"
#include"Player.h"

class Game
{
public:
	//����
	void play();

private:
	vector<pair<string, int>> all_cards; //���п��Ƶ�����
	std::vector<pair<pair<std::string, int>, int>> leftCards = { {CARD_3, 0}, {CARD_4, 0}, {CARD_5, 0}, {CARD_6, 0}, {CARD_7, 0}, {CARD_8, 0}, {CARD_9, 0}, {CARD_10, 0}, {CARD_J, 0}, {CARD_Q, 0}, {CARD_K, 0}, {CARD_A, 0}, {CARD_2, 0}, {CARD_sking, 0}, {CARD_bking, 0} }; //Ŀǰ����������п���
	Player player_Arr[PLAYER_COUNT]; //�������
	int player_cycle[PLAYER_COUNT]; //��ҳ���˳��
	int landlordIndex; //��������ұ��

	//�ṩ����
	void instruction();

	//��ʼ�����п��Ʋ�����
	void InitAllCards();

	//��ʼ����ҿ��ƣ�3people:һ��17��,4people:һ��25��
	void InitPlayersCards();

	//չʾ������
	//void displayLandlordCards();

	//ѡ�����
	int selectLandlord();

	//������ұ�ţ��Ƿ�Ϊ����
	void InitPlayers();

	//�����������⿨��,3player:3,4player:8
	void giveLandlordCards();

	//չʾ������ҿ������
	void displayPlayersCards();

	//����ǰ��ʾ
	void mentionInfo();

	//��ʼ����
	void start();
};