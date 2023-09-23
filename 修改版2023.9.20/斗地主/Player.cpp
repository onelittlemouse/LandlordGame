#include"Player.h"

Player::Player()
{

}

Player::Player(int index, bool isfarmer)
{
	if (index == -1)
	{
		fullCards();
	}
	this->index = index;
	this->isfarmer = isfarmer;
}

void Player::setPlayer(int index, bool isfarmer)
{
	if (index == -1)
	{
		fullCards();
	}
	this->index = index;
	this->isfarmer = isfarmer;
}

void Player::getSingleCard(const pair<std::string, int>& card)
{
	++(((this->cards)[card.second]).second);
}

void Player::displayPlayerInfo()
{
	if (this->isfarmer == false)
	{
		cout << "Player" << index + 1 << "(landlord):";
	}
	else
	{
		cout << "Player" << index + 1 << "(farmer):";
	}
}

void Player::displayCards()
{
	int cards_size = this->cards.size();
	for (int i = cards_size - 1; i >= 0; --i)
	{
		for (int j = 0; j < cards[i].second; ++j)
		{
			cout << cards[i].first.first << " ";
		}
	}
	endl(cout);
}

void Player::displayGiveCards()
{
	int givecards_size = this->givecards.size();
	int count = 0;
	for (int i = givecards_size - 1; i >= 0; --i)
	{
		for (int j = 0; j < givecards[i].second; ++j)
		{
			++count;
			cout << givecards[i].first.first << " ";
		}
	}
	if (count == 0)
	{
		cout << PASS;
	}
	endl(cout);
}

bool Player::cards_isEmpty()
{
	for (const auto& i : this->cards)
	{
		if (i.second > 0)
		{
			return false;
		}
	}
	return true;
}

int Player::cards_count()
{
	int count = 0;
	for (const auto& card : cards)
	{
		count += card.second;
	}
	return count;
}

void Player::cards_counter(std::vector<pair<pair<std::string, int>, int>>& cards)
{
	for (int i = 0; i < CARDS_SIZE; ++i)
	{
		cards[i].second += this->cards[i].second;
	}
}

pair<pair<string, int>, int> Player::giveCard_3(const std::pair<std::string, int>& method, int requireIndex, int& requireCardCount)
{
	pair<pair<string, int>, int> null;
	if (method == METHOD_Type(KING_BOOM))
	{
		cout << PASS << endl;
		requireCardCount = 0;
		return null;
	}
	const int giveTime = 10;
	for (int i = 0; i < giveTime; ++i)
	{
		int n = this->cards.size();
		//std::vector<pair<pair<std::string, int>, int>> givecards = { {CARD_3, 0}, {CARD_4, 0}, {CARD_5, 0}, {CARD_6, 0}, {CARD_7, 0}, {CARD_8, 0}, {CARD_9, 0}, {CARD_10, 0}, {CARD_J, 0}, {CARD_Q, 0}, {CARD_K, 0}, {CARD_A, 0}, {CARD_2, 0}, {CARD_sking, 0}, {CARD_bking, 0} };
		for (auto& givecard : givecards)
		{
			givecard.second = 0;
		}
		string s;
		cin >> s;
		if (s == "pass")
		{
			requireCardCount = 0;
			return null;
		}
		vector<string> input_cards;
		this->stringSplit(s, '-', input_cards);
		int givecardcount = 0;
		for (const auto& i : input_cards)
		{
			for (auto& j : givecards)
			{
				if (i == j.first.first)
				{
					++j.second;
					++givecardcount;
					break;
				}
			}
		}
		if (givecardcount != input_cards.size())
		{
			cout << INVALID << endl;
			continue;
		}
		bool flag = true;
		for (int i = 0; i < 15; ++i)
		{
			if (givecards[i].second > this->cards[i].second)
			{
				flag = false;
			}
		}
		if (flag == false)
		{
			cout << INVALID << endl;
			continue;
		}
		pair<pair<string, int>, int> method_index = judgeMethod_3(givecards);
		if (method_index.second == -1)
		{
			cout << INVALID << endl;
			continue;
		}
		if (method == METHOD_Type(ALL) || method_index.first.second < method.second || (method_index.first.first == method.first && requireIndex < method_index.second && givecardcount == requireCardCount))
		{
			for (int i = 0; i < 15; ++i)
			{
				this->cards[i].second -= givecards[i].second;
			}
			bool success = this->cards_isEmpty();
			if (success == true)
			{
				requireCardCount = 0;
				return { { "", -1 }, 1000 };
			}
			requireCardCount = givecardcount;
			return method_index;
		}
		else
		{
			cout << INVALID << endl;
			continue;
		}
	}
	cout << PASS << endl;
	requireCardCount = 0;
	return null;
}

pair<pair<string, int>, int> Player::giveCard_4(const std::pair<std::string, int>& method, int requireIndex, int& requireCardCount)
{
	pair<pair<string, int>, int> null;
	if (method == METHOD_Type(KING_BOOM))
	{
		cout << PASS << endl;
		requireCardCount = 0;
		return null;
	}
	const int giveTime = 10;
	for (int i = 0; i < giveTime; ++i)
	{
		int n = this->cards.size();
		//std::vector<pair<pair<std::string, int>, int>> givecards = { {CARD_3, 0}, {CARD_4, 0}, {CARD_5, 0}, {CARD_6, 0}, {CARD_7, 0}, {CARD_8, 0}, {CARD_9, 0}, {CARD_10, 0}, {CARD_J, 0}, {CARD_Q, 0}, {CARD_K, 0}, {CARD_A, 0}, {CARD_2, 0}, {CARD_sking, 0}, {CARD_bking, 0} };
		for (auto& givecard : givecards)
		{
			givecard.second = 0;
		}
		string s;
		cin >> s;
		if (s == "pass")
		{
			requireCardCount = 0;
			return null;
		}
		vector<string> input_cards;
		this->stringSplit(s, '-', input_cards);
		int givecardcount = 0;
		for (const auto& i : input_cards)
		{
			for (auto& j : givecards)
			{
				if (i == j.first.first)
				{
					++j.second;
					++givecardcount;
					break;
				}
			}
		}
		if (givecardcount != input_cards.size())
		{
			cout << INVALID << endl;
			continue;
		}
		bool flag = true;
		for (int i = 0; i < 15; ++i)
		{
			if (givecards[i].second > this->cards[i].second)
			{
				flag = false;
			}
		}
		if (flag == false)
		{
			cout << INVALID << endl;
			continue;
		}
		pair<pair<string, int>, int> method_index = judgeMethod_4(givecards);
		if (method_index.second == -1)
		{
			cout << INVALID << endl;
			continue;
		}
		if (method == METHOD_Type(ALL) || method_index.first.second < method.second || (method_index.first.first == method.first && requireIndex < method_index.second && givecardcount == requireCardCount))
		{
			for (int i = 0; i < 15; ++i)
			{
				this->cards[i].second -= givecards[i].second;
			}
			bool success = this->cards_isEmpty();
			if (success == true)
			{
				requireCardCount = 0;
				return { { "", -1 }, 1000 };
			}
			requireCardCount = givecardcount;
			return method_index;
		}
		else
		{
			cout << INVALID << endl;
			continue;
		}
	}
	cout << PASS << endl;
	requireCardCount = 0;
	return null;
}

void Player::stringSplit(const string& str, const char split, vector<string>& res)
{
	if (str == "")		return;
	string strs = str + split;
	int pos = strs.find(split);

	while (pos != strs.npos)
	{
		string temp = strs.substr(0, pos);
		res.push_back(temp);
		strs = strs.substr(pos + 1, strs.size());
		pos = strs.find(split);
	}
}

void Player::fullCards()
{
	for (int i = 0; i < 13; ++i)
	{
		cards[i].second = 4 * int(CARDS_COUNT);
	}
	cards[13].second = int(CARDS_COUNT);
	cards[14].second = int(CARDS_COUNT);
}

pair<pair<string, int>, int> Player::judgeMethod_3(vector<pair<pair<string, int>, int>>& givecards)
{
	vector<int> vnum;
	for (const auto& i : givecards)
	{
		if (i.second >= 1)
		{
			vnum.push_back(i.second);
		}
	}
	sort(vnum.begin(), vnum.end());
	int vnum_size = vnum.size();
	if (vnum_size == 0)
	{
		return pair<pair<string, int>, int>(pair<string, int>(), -1);
	}
	else if (vnum_size == 1)
	{
		for (const auto& i : givecards)
		{
			if (i.second == 1)
			{
				return { ONE, i.first.second };
			}
			else if (i.second == 2)
			{
				return { TWO, i.first.second };
			}
			else if (i.second == 3)
			{
				return { THREE, i.first.second };
			}
			else if (i.second == 4)
			{
				return { BOOM_4, i.first.second };
			}
		}
	}
	else if (vnum_size == 2)
	{
		if (vnum[0] == 1 && vnum[1] == 1)
		{
			if (givecards[13].second == 1 && givecards[14].second == 1)
			{
				return { KING_BOOM , 14 };
			}
		}
		if (vnum[1] == 4 && vnum[0] == 2)
		{
			for (const auto& i : givecards)
			{
				if (i.second == 4)
				{
					return { FOURONEONE, i.first.second };
				}
			}
		}
		if (vnum[1] == 3)
		{
			if (vnum[0] == 3)
			{
				if (givecards[0].second == 3 && givecards[12].second == 3)
				{
					return { MULTITHREE, 0 };
				}
				for (int i = 12; i >= 1; --i)
				{
					if (givecards[i].second == 3 && givecards[i - 1].second == 3)
					{
						return { MULTITHREE, givecards[i].first.second };
					}
				}
			}
			for (const auto& i : givecards)
			{
				if (i.second == 3)
				{
					if (vnum[0] == 1)
					{
						return { THREEONE, i.first.second };
					}
					else if (vnum[0] == 2)
					{
						return { THREETWO, i.first.second };
					}
				}
			}
		}
	}
	else
	{
		if (vnum_size == 3 && vnum[2] == 4)
		{
			if (vnum[0] == 1 && vnum[1] == 1)
			{
				for (const auto& i : givecards)
				{
					if (i.second == 4)
					{
						return { FOURONEONE, i.first.second };
					}
				}
			}
			else if (vnum[0] == 2 && vnum[1] == 2)
			{
				for (const auto& i : givecards)
				{
					if (i.second == 4)
					{
						return { FOURTWOTWO, i.first.second };
					}
				}
			}
		}
		pair<bool, int> p1 = isAeroplane1(givecards, vnum);
		if (p1.first == true)
		{
			return { AEROPLANE1, p1.second };
		}
		pair<bool, int> p2 = isAeroplane2(givecards, vnum);
		if (p2.first == true)
		{
			return { AEROPLANE2, p2.second };
		}
		pair<bool, int> p3 = isMultithree(givecards, vnum);
		if (p3.first == true)
		{
			return { MULTITHREE, p3.second };
		}
		pair<bool, int> p4 = isMultiTwo(givecards, vnum);
		if (p4.first == true)
		{
			return { MULTITWO, p4.second };
		}
		pair<bool, int> p5 = isMultiOne(givecards, vnum);
		if (p5.first == true)
		{
			return { MULTIONE, p5.second };
		}
	}
	return pair<pair<string, int>, int>(pair<string, int>(), -1);
}

pair<pair<string, int>, int> Player::judgeMethod_4(vector<pair<pair<string, int>, int>>& givecards)
{
	vector<int> vnum;
	for (const auto& i : givecards)
	{
		if (i.second >= 1)
		{
			vnum.push_back(i.second);
		}
	}
	sort(vnum.begin(), vnum.end());
	int vnum_size = vnum.size();
	if (vnum_size == 0)
	{
		return pair<pair<string, int>, int>(pair<string, int>(), -1);
	}
	else if (vnum_size == 1)
	{
		for (const auto& i : givecards)
		{
			if (i.second == 1)
			{
				return { ONE, i.first.second };
			}
			else if (i.second == 2)
			{
				return { TWO, i.first.second };
			}
			else if (i.second == 3)
			{
				return { THREE, i.first.second };
			}
			else if (i.second == 4)
			{
				return { BOOM_4, i.first.second };
			}
			else if (i.second == 5)
			{
				return { BOOM_5, i.first.second };
			}
			else if (i.second == 6)
			{
				return { BOOM_6, i.first.second };
			}
			else if (i.second == 7)
			{
				return { BOOM_7, i.first.second };
			}
			else if (i.second == 8)
			{
				return { BOOM_8, i.first.second };
			}
		}
	}
	else if (vnum_size == 2)
	{
		if (vnum[0] == 2 && vnum[1] == 2)
		{
			if (givecards[13].second == 2 && givecards[14].second == 2)
			{
				return { KING_BOOM , 14 };
			}
		}
		if (vnum[1] == 3)
		{
			if (vnum[0] == 3)
			{
				if (givecards[0].second == 3 && givecards[12].second == 3)
				{
					return { MULTITHREE, 0 };
				}
				for (int i = 12; i >= 1; --i)
				{
					if (givecards[i].second == 3 && givecards[i - 1].second == 3)
					{
						return { MULTITHREE, givecards[i].first.second };
					}
				}
			}
			for (const auto& i : givecards)
			{
				if (i.second == 3)
				{
					if (vnum[0] == 2)
					{
						return { THREETWO, i.first.second };
					}
				}
			}
		}
	}
	else
	{
		//pair<bool, int> p1 = isAeroplane1(givecards, vnum);
		//if (p1.first == true)
		//{
		//	return { AEROPLANE1, p1.second };
		//}
		pair<bool, int> p2 = isAeroplane2(givecards, vnum);
		if (p2.first == true)
		{
			return { AEROPLANE2, p2.second };
		}
		pair<bool, int> p3 = isMultithree(givecards, vnum);
		if (p3.first == true)
		{
			return { MULTITHREE, p3.second };
		}
		pair<bool, int> p4 = isMultiTwo(givecards, vnum);
		if (p4.first == true)
		{
			return { MULTITWO, p4.second };
		}
		pair<bool, int> p5 = isMultiOne(givecards, vnum);
		if (p5.first == true)
		{
			return { MULTIONE, p5.second };
		}
	}
	return pair<pair<string, int>, int>(pair<string, int>(), -1);
}

pair<bool, int> Player::isAeroplane1(vector<pair<pair<string, int>, int>>& givecards, vector<int>& vnum)
{
	int n = vnum.size();
	if (n < 4 || n % 2 == 1 || n > 14)
	{
		return { false, -1 };
	}
	int count_3 = 0;
	for (int i = 0; i < n; ++i)
	{
		if (vnum[i] == 3)
		{
			++count_3;
		}
		else if (vnum[i] != 1)
		{
			return { false, -1 };
		}
	}
	if (count_3 * 2 != n)
	{
		return { false, -1 };
	}
	if (givecards[12].second == 3 && givecards[11].second == 3 && givecards[10].second == 3)
	{
		return { false, -1 };
	}
	if (givecards[12].second != 3)
	{
		for (int i = 11; i >= 0; --i)
		{
			if (givecards[i].second == 3)
			{
				for (int j = i - 1; j > i - count_3; --j)
				{
					if (j < 0 || givecards[j].second != 3)
					{
						return { false, -1 };
					}
				}
				return { true, i };
			}
		}
	}
	else if (givecards[12].second == 3 && givecards[0].second != 3)
	{
		for (int i = 11; i > 12 - count_3; --i)
		{
			if (givecards[i].second != 3)
			{
				return { false, -1 };
			}
		}
		return { true, 12 };
	}
	else
	{
		if (givecards[11].second == 3)
		{
			if (givecards[0].second != 3)
			{
				return count_3 == 2 ? pair<bool, int>{ true, 12 } : pair<bool, int>{ false, -1 };
			}
			else
			{
				for (int i = 0; i < count_3 - 2; ++i)
				{
					if (givecards[i].second != 3)
					{
						return { false, -1 };
					}
				}
				return { true, count_3 - 3 };
			}
		}
		else
		{
			if (givecards[0].second != 3)
			{
				return { false, -1 };
			}
			else
			{
				for (int i = 0; i < count_3 - 1; ++i)
				{
					if (givecards[i].second != 3)
					{
						return { false, -1 };
					}
				}
				return { true, count_3 - 2 };
			}
		}
	}
}

pair<bool, int> Player::isAeroplane2(vector<pair<pair<string, int>, int>>& givecards, vector<int>& vnum)
{
	int n = vnum.size();
	if (n < 4 || n % 2 == 1 || n > 14)
	{
		return { false, -1 };
	}
	int count_3 = 0;
	for (int i = 0; i < n; ++i)
	{
		if (vnum[i] == 3)
		{
			++count_3;
		}
		else if (vnum[i] != 2)
		{
			return { false, -1 };
		}
	}
	if (count_3 * 2 != n)
	{
		return { false, -1 };
	}
	if (givecards[12].second == 3 && givecards[11].second == 3 && givecards[10].second == 3)
	{
		return { false, -1 };
	}
	if (givecards[12].second != 3)
	{
		for (int i = 11; i >= 0; --i)
		{
			if (givecards[i].second == 3)
			{
				for (int j = i - 1; j > i - count_3; --j)
				{
					if (j < 0 || givecards[j].second != 3)
					{
						return { false, -1 };
					}
				}
				return { true, i };
			}
		}
	}
	else if (givecards[12].second == 3 && givecards[0].second != 3)
	{
		for (int i = 11; i > 12 - count_3; --i)
		{
			if (givecards[i].second != 3)
			{
				return { false, -1 };
			}
		}
		return { true, 12 };
	}
	else
	{
		if (givecards[11].second == 3)
		{
			if (givecards[0].second != 3)
			{
				return count_3 == 2 ? pair<bool, int>{ true, 12 } : pair<bool, int>{ false, -1 };
			}
			else
			{
				for (int i = 0; i < count_3 - 2; ++i)
				{
					if (givecards[i].second != 3)
					{
						return { false, -1 };
					}
				}
				return { true, count_3 - 3 };
			}
		}
		else
		{
			if (givecards[0].second != 3)
			{
				return { false, -1 };
			}
			else
			{
				for (int i = 0; i < count_3 - 1; ++i)
				{
					if (givecards[i].second != 3)
					{
						return { false, -1 };
					}
				}
				return { true, count_3 - 2 };
			}
		}
	}
}

pair<bool, int> Player::isMultithree(vector<pair<pair<string, int>, int>>& givecards, vector<int>& vnum)
{
	int n = vnum.size();
	if (n < 2 || n > 13 || givecards[13].second != 0 || givecards[14].second != 0)
	{
		return { false, -1 };
	}
	int count_3 = 0;
	for (int i = 0; i < n; ++i)
	{
		if (vnum[i] == 3)
		{
			++count_3;
		}
		else
		{
			return { false, -1 };
		}
	}
	if (count_3 != n)
	{
		return { false, -1 };
	}
	if (givecards[12].second == 3 && givecards[11].second == 3 && givecards[10].second == 3)
	{
		return { false, -1 };
	}
	if (givecards[12].second != 3)
	{
		for (int i = 11; i >= 0; --i)
		{
			if (givecards[i].second == 3)
			{
				for (int j = i - 1; j > i - count_3; --j)
				{
					if (j < 0 || givecards[j].second != 3)
					{
						return { false, -1 };
					}
				}
				return { true, i };
			}
		}
	}
	else if (givecards[12].second == 3 && givecards[0].second != 3)
	{
		for (int i = 11; i > 12 - count_3; --i)
		{
			if (givecards[i].second != 3)
			{
				return { false, -1 };
			}
		}
		return { true, 12 };
	}
	else
	{
		if (givecards[11].second == 3)
		{
			if (givecards[0].second != 3)
			{
				return count_3 == 2 ? pair<bool, int>{ true, 12 } : pair<bool, int>{ false, -1 };
			}
			else
			{
				for (int i = 0; i < count_3 - 2; ++i)
				{
					if (givecards[i].second != 3)
					{
						return { false, -1 };
					}
				}
				return { true, count_3 - 3 };
			}
		}
		else
		{
			if (givecards[0].second != 3)
			{
				return { false, -1 };
			}
			else
			{
				for (int i = 0; i < count_3 - 1; ++i)
				{
					if (givecards[i].second != 3)
					{
						return { false, -1 };
					}
				}
				return { true, count_3 - 2 };
			}
		}
	}
}

pair<bool, int> Player::isMultiTwo(vector<pair<pair<string, int>, int>>& givecards, vector<int>& vnum)
{
	int n = vnum.size();
	if (n < 3 || n > 13 || givecards[13].second != 0 || givecards[14].second != 0)
	{
		return { false, -1 };
	}
	int count_2 = 0;
	for (int i = 0; i < n; ++i)
	{
		if (vnum[i] == 2)
		{
			++count_2;
		}
		else
		{
			return { false, -1 };
		}
	}
	if (count_2 != n)
	{
		return { false, -1 };
	}
	if (givecards[12].second == 2 && givecards[11].second == 2 && givecards[10].second == 2)
	{
		return { false, -1 };
	}
	if (givecards[12].second != 2)
	{
		for (int i = 11; i >= 0; --i)
		{
			if (givecards[i].second == 2)
			{
				for (int j = i - 1; j > i - count_2; --j)
				{
					if (j < 0 || givecards[j].second != 2)
					{
						return { false, -1 };
					}
				}
				return { true, i };
			}
		}
	}
	else if (givecards[12].second == 2 && givecards[0].second != 2)
	{
		for (int i = 11; i > 12 - count_2; --i)
		{
			if (givecards[i].second != 2)
			{
				return { false, -1 };
			}
		}
		return { true, 12 };
	}
	else
	{
		if (givecards[11].second == 2)
		{
			if (givecards[0].second != 2)
			{
				return { false, -1 };
			}
			else
			{
				for (int i = 0; i < count_2 - 2; ++i)
				{
					if (givecards[i].second != 2)
					{
						return { false, -1 };
					}
				}
				return { true, count_2 - 3 };
			}
		}
		else
		{
			if (givecards[0].second != 2)
			{
				return { false, -1 };
			}
			else
			{
				for (int i = 0; i < count_2 - 1; ++i)
				{
					if (givecards[i].second != 2)
					{
						return { false, -1 };
					}
				}
				return { true, count_2 - 2 };
			}
		}
	}
}

pair<bool, int> Player::isMultiOne(vector<pair<pair<string, int>, int>>& givecards, vector<int>& vnum)
{
	int n = vnum.size();//2,3,4,5,6  12,0,1,2,3
	if (n < 5 || n > 13 || givecards[13].second != 0 || givecards[14].second != 0)
	{
		return { false, -1 };
	}
	int count_1 = 0;
	for (int i = 0; i < n; ++i)
	{
		if (vnum[i] == 1)
		{
			++count_1;
		}
		else
		{
			return { false, -1 };
		}
	}
	if (count_1 != n)
	{
		return { false, -1 };
	}
	if (givecards[12].second == 1 && givecards[11].second == 1 && givecards[10].second == 1)
	{
		return { false, -1 };
	}
	if (givecards[12].second != 1)
	{
		for (int i = 11; i >= 0; --i)
		{
			if (givecards[i].second == 1)
			{
				for (int j = i - 1; j > i - count_1; --j)
				{
					if (j < 0 || givecards[j].second != 1)
					{
						return { false, -1 };
					}
				}
				return { true, i };
			}
		}
	}
	else if (givecards[12].second == 1 && givecards[0].second != 1)
	{
		for (int i = 11; i > 12 - count_1; --i)
		{
			if (givecards[i].second != 1)
			{
				return { false, -1 };
			}
		}
		return { true, 12 };
	}
	else
	{
		if (givecards[11].second == 1)
		{
			if (givecards[0].second != 1)
			{
				return { false, -1 };
			}
			else
			{
				for (int i = 0; i < count_1 - 2; ++i)
				{
					if (givecards[i].second != 1)
					{
						return { false, -1 };
					}
				}
				return { true, count_1 - 3 };
			}
		}
		else
		{
			if (givecards[0].second != 1)
			{
				return { false, -1 };
			}
			else
			{
				for (int i = 0; i < count_1 - 1; ++i)
				{
					if (givecards[i].second != 1)
					{
						return { false, -1 };
					}
				}
				return { true, count_1 - 2 };
			}
		}
	}
}