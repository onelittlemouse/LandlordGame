#include"Game.h"

void Game::play()
{
	srand((unsigned int)time(NULL));
	instruction();
	InitAllCards();
	//cout << "初始卡牌" << endl;
	InitPlayersCards();
	this->landlordIndex = selectLandlord();
	InitPlayers();
	giveLandlordCards();
	//cout << "初始卡牌：" << endl;
	//displayPlayersCards();
	start();
}

void Game::instruction()
{
	cout << "当前玩家数量：" << PLAYER_COUNT << ",共" << CARDS_COUNT << "副牌" << endl;
	cout << "help?";
	char c;
	cin >> c;
	if (c != 'y')
	{
		system("cls");
		return;
	}
	system("cls");
	cout << "出牌规则：" << endl;
	cout << "method\tpriority\t\texample\t" << endl;
	if (PLAYER_COUNT == 3)
	{
		int methods_size = METHODS_TYPE_3.size();
		for (int i = 0; i < methods_size; ++i)
		{
			cout << METHODS_TYPE_3[i].first << "\t" << METHODS_TYPE_3[i].second << "\t\t" << METHODS_TYPE_3_EXAMPLE[i] << endl;
		}
	}
	else if (PLAYER_COUNT == 4)
	{
		int methods_size = METHODS_TYPE_4.size();
		for (int i = 0; i < methods_size; ++i)
		{
			cout << METHODS_TYPE_4[i].first << "\t" << METHODS_TYPE_4[i].second << "\t\t" << METHODS_TYPE_4_EXAMPLE[i] << endl;
		}
	}
	system("pause");
	system("cls");
	if (PLAYER_COUNT == 3)
	{
		Player p(-1, false);
		/*p.displayPlayerInfo();
		p.displayCards();*/
		int t = -1;
		while (1)
		{
			p.displayPlayerInfo();
			p.displayCards();
			cout << "Player0出牌：(" << pair<string, int>(ALL).first << ",-1,-1)  ";
			auto x = p.giveCard_3(ALL, -1, t);
			if (t == 0)
			{
				break;
			}
			cout << "(" << x.first.first << "," << CARDS_TYPE[x.second].first << "," << t << ")" << endl;
			t = -1;
			system("pause");
			system("cls");
		}
	}
	else if (PLAYER_COUNT == 4)
	{
		Player p(-1, false);
		//p.displayPlayerInfo();
		//p.displayCards();
		int t = -1;
		while (1)
		{
			p.displayPlayerInfo();
			p.displayCards();
			cout << "Player0出牌：(" << pair<string, int>(ALL).first << ",-1,-1)  ";
			auto x = p.giveCard_4(ALL, -1, t);
			if (t == 0)
			{
				break;
			}
			cout << "(" << x.first.first << "," << CARDS_TYPE[x.second].first << "," << t << ")" << endl;
			t = -1;
			system("pause");
			system("cls");
		}
	}
	system("pause");
	system("cls");
}

void Game::InitAllCards()
{
	for (int i = 0; i < CARDS_COUNT; ++i)
	{
		for (int j = 0; j < 13; ++j)
		{
			all_cards.emplace_back(CARDS_TYPE[j]);
			all_cards.emplace_back(CARDS_TYPE[j]);
			all_cards.emplace_back(CARDS_TYPE[j]);
			all_cards.emplace_back(CARDS_TYPE[j]);
		}
		all_cards.emplace_back(CARDS_TYPE[13]);
		all_cards.emplace_back(CARDS_TYPE[14]);
	}
	random_shuffle(all_cards.begin(), all_cards.end());
	cout << "初始卡牌完成！" << endl;
}

void Game::InitPlayersCards()
{
	if (PLAYER_COUNT == 3)//4*13+2=54
	{
		for (int i = 0; i < PLAYER_COUNT; ++i)
		{
			for (int j = 0; j < 17; ++j)
			{
				player_Arr[i].getSingleCard(all_cards[i * 17 + j]);
			}
			//cout << "Player" << i + 1 << ":";
			//player_Arr[i].displayCards();
		}
	}
	else if (PLAYER_COUNT == 4)//54*2
	{
		for (int i = 0; i < PLAYER_COUNT; ++i)
		{
			for (int j = 0; j < 25; ++j)
			{
				player_Arr[i].getSingleCard(all_cards[i * 25 + j]);
			}
			//cout << "Player" << i + 1 << ":";
			//player_Arr[i].displayCards();
		}
	}
}

//void Game::displayLandlordCards()
//{
//	cout << "地主牌：";
//	if (PLAYER_COUNT == 3)
//	{
//		cout << all_cards[51].first << " " << all_cards[52].first << " " << all_cards[53].first << endl;
//	}
//	else if (PLAYER_COUNT == 4)
//	{
//		cout << all_cards[100].first << " " << all_cards[101].first << " " << all_cards[102].first << " " << all_cards[103].first << " " << all_cards[104].first << " " << all_cards[105].first << " " << all_cards[106].first << " " << all_cards[107].first << endl;
//	}
//}

int Game::selectLandlord()
{
	cout << "下面启动抢地主环节！" << endl;
	//displayLandlordCards();
	system("pause");
	system("cls");
	vector<int> wantgetlandlord;
	for (int i = 0; i < PLAYER_COUNT; ++i)
	{
		cout << "Player" << i + 1 << ":";
		player_Arr[i].displayCards();
		//displayLandlordCards();
		cout << "Player" << i + 1 << "是否抢地主：";
		char c;
		cin >> c;
		if (c == 'y')
		{
			wantgetlandlord.push_back(i);
		}
		system("cls");
	}
	int landlordIndex = -1;
	if (wantgetlandlord.size() == 0)
	{
		landlordIndex = rand() % PLAYER_COUNT;
	}
	else
	{
		landlordIndex = wantgetlandlord[rand() % (wantgetlandlord.size())];
	}
	system("cls");
	cout << "地主：player" << landlordIndex + 1 << endl;
	system("pause");
	system("cls");
	return landlordIndex;
}

void Game::InitPlayers()
{
	for (int i = 0; i < PLAYER_COUNT; ++i)
	{
		if (this->landlordIndex == i)
		{
			player_Arr[i].setPlayer(i, false);
		}
		else
		{
			player_Arr[i].setPlayer(i, true);
		}
	}
}

void Game::giveLandlordCards()
{
	if (PLAYER_COUNT == 3)
	{
		player_Arr[landlordIndex].getSingleCard(all_cards[51]);
		player_Arr[landlordIndex].getSingleCard(all_cards[52]);
		player_Arr[landlordIndex].getSingleCard(all_cards[53]);
	}
	else if (PLAYER_COUNT == 4)
	{
		player_Arr[landlordIndex].getSingleCard(all_cards[100]);
		player_Arr[landlordIndex].getSingleCard(all_cards[101]);
		player_Arr[landlordIndex].getSingleCard(all_cards[102]);
		player_Arr[landlordIndex].getSingleCard(all_cards[103]);
		player_Arr[landlordIndex].getSingleCard(all_cards[104]);
		player_Arr[landlordIndex].getSingleCard(all_cards[105]);
		player_Arr[landlordIndex].getSingleCard(all_cards[106]);
		player_Arr[landlordIndex].getSingleCard(all_cards[107]);
	}
}

void Game::displayPlayersCards()
{
	for (int i = 0; i < PLAYER_COUNT; ++i)
	{
		player_Arr[i].displayPlayerInfo();
		player_Arr[i].displayCards();
	}
	endl(cout);
}

void Game::mentionInfo()
{
	cout << "地主牌：";
	if (PLAYER_COUNT == 3)
	{
		cout << all_cards[51].first << " " << all_cards[52].first << " " << all_cards[53].first << endl;
	}
	else if (PLAYER_COUNT == 4)
	{
		cout << all_cards[100].first << " " << all_cards[101].first << " " << all_cards[102].first << " " << all_cards[103].first << " " << all_cards[104].first << " " << all_cards[105].first << " " << all_cards[106].first << " " << all_cards[107].first << endl;
	}
	cout << "上一轮出牌：" << endl;
	for (const int i : player_cycle)
	{
		player_Arr[i].displayPlayerInfo();
		player_Arr[i].displayGiveCards();
	}
	cout << "剩余牌数：" << endl;
	for (const int i : player_cycle)
	{
		player_Arr[i].displayPlayerInfo();
		cout << player_Arr[i].cards_count() << endl;
	}
	cout << "记牌器：" << endl;
	for (const auto& i : player_cycle)
	{
		player_Arr[i].cards_counter(leftCards);
	}
	for (int i = CARDS_SIZE - 1; i >= 0; --i)
	{
		cout << leftCards[i].first.first << "-" << leftCards[i].second << " ";
		leftCards[i].second = 0;
	}
	endl(cout);
}

void Game::start()
{
	cout << "Game start!" << endl;
	system("pause");
	system("cls");
	if (PLAYER_COUNT == 3)
	{
		//vector<vector<int>> player_cycles = { { 0, 1, 2 }, { 1, 2, 0 }, { 2, 0, 1 } };
		//vector<int> player_cycle = player_cycles[landlordIndex];
		for (int i = 0; i < PLAYER_COUNT; ++i)
		{
			this->player_cycle[i] = (landlordIndex + i) % PLAYER_COUNT;
		}
		pair<pair<string, int>, int> method_index = { ALL, 0 };
		int requirecardcount = 0;
		int lastgivecardplayer = -1;
		bool landlordwin = true;
		while (1)
		{
			//cout << "-------------------------------------------------------------------" << endl;
			bool isEnd = false;
			for (const int i : player_cycle)
			{
				/*cout << "上一轮出牌：" << endl;
				for (const int i : player_cycle)
				{
					player_Arr[i].displayPlayerInfo();
					player_Arr[i].displayGiveCards();
				}
				cout << "剩余牌数：" << endl;
				for (const int i : player_cycle)
				{
					player_Arr[i].displayPlayerInfo();
					cout << player_Arr[i].cards_count() << endl;
				}
				cout << "记牌器：" << endl;
				for (const auto& i : player_cycle)
				{
					player_Arr[i].cards_counter(leftCards);
				}
				for (int i = CARDS_SIZE - 1; i >= 0; --i)
				{
					cout << leftCards[i].first.first << "-" << leftCards[i].second << " ";
					leftCards[i].second = 0;
				}
				endl(cout);*/
				this->mentionInfo();
				cout << "-------------------------------------------------------------------" << endl;
				player_Arr[i].displayPlayerInfo();
				player_Arr[i].displayCards();
				if (i == lastgivecardplayer)
				{
					method_index = { ALL, 0 };
				}
				if (method_index.first == pair<string, int>(ALL))
				{
					cout << "Player" << i + 1 << "出牌：(" << pair<string, int>(ALL).first << ",-1,-1)  ";
				}
				else
				{
					cout << "Player" << i + 1 << "出牌：(" << method_index.first.first << "," << CARDS_TYPE[method_index.second].first << "," << requirecardcount << ")  ";
				}
				int pre_requirecardcount = requirecardcount;
				pair<pair<string, int>, int> temp = player_Arr[i].giveCard_3(method_index.first, method_index.second, requirecardcount);
				system("pause");
				system("cls");
				if (temp.second > 100)
				{
					landlordwin = (i == landlordIndex);
					isEnd = true;
					break;
				}
				if (requirecardcount == 0)
				{
					if (method_index.first == pair<string, int>(ALL))
					{
						landlordwin = (i != landlordIndex);
						isEnd = true;
						break;
					}
					requirecardcount = pre_requirecardcount;
					continue;
				}
				else
				{
					lastgivecardplayer = i;
					method_index = temp;
				}
			}
			if (isEnd == true)
			{
				if (landlordwin == true)
				{
					cout << "landlordwin!" << endl;
				}
				else
				{
					cout << "landlordloss!" << endl;
				}
				break;
			}
			//cout << "-------------------------------------------------------------------" << endl;
		}
	}
	else if (PLAYER_COUNT == 4)
	{
		//vector<vector<int>> player_cycles = { { 0, 1, 2, 3 }, { 1, 2, 3, 0 }, { 2, 3, 0, 1 }, { 3, 0, 1, 2} };
		//vector<int> player_cycle = player_cycles[landlordIndex];
		for (int i = 0; i < PLAYER_COUNT; ++i)
		{
			this->player_cycle[i] = (landlordIndex + i) % PLAYER_COUNT;
		}
		pair<pair<string, int>, int> method_index = { ALL, 0 };
		int requirecardcount = 0;
		int lastgivecardplayer = -1;
		bool landlordwin = true;
		while (1)
		{
			//cout << "-------------------------------------------------------------------" << endl;
			bool isEnd = false;
			for (const int i : player_cycle)
			{
				this->mentionInfo();
				cout << "-------------------------------------------------------------------" << endl;
				player_Arr[i].displayPlayerInfo();
				player_Arr[i].displayCards();

				if (i == lastgivecardplayer)
				{
					method_index = { ALL, 0 };
				}
				if (method_index.first == pair<string, int>(ALL))
				{
					cout << "Player" << i + 1 << "出牌：(" << pair<string, int>(ALL).first << ",-1,-1)  ";
				}
				else
				{
					cout << "Player" << i + 1 << "出牌：(" << method_index.first.first << "," << CARDS_TYPE[method_index.second].first << "," << requirecardcount << ")  ";
				}				
				int pre_requirecardcount = requirecardcount;
				pair<pair<string, int>, int> temp = player_Arr[i].giveCard_4(method_index.first, method_index.second, requirecardcount);
				system("pause");
				system("cls");
				if (temp.second > 100)
				{
					landlordwin = (i == landlordIndex);
					isEnd = true;
					break;
				}
				if (requirecardcount == 0)
				{
					if (method_index.first == pair<string, int>(ALL))
					{
						landlordwin = (i != landlordIndex);
						isEnd = true;
						break;
					}
					requirecardcount = pre_requirecardcount;
					continue;
				}
				else
				{
					lastgivecardplayer = i;
					method_index = temp;
				}
			}
			if (isEnd == true)
			{
				if (landlordwin == true)
				{
					cout << "landlordwin!" << endl;
				}
				else
				{
					cout << "landlordloss!" << endl;
				}
				break;
			}
			//cout << "-------------------------------------------------------------------" << endl;
		}
	}
}