#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

enum {
	SPADES,
	HEARTS,
	CLUBS,
	DIAMONDS,
	JOKER
};

class Poker
{
	char m_type;
	int m_point;
public:
	void MakePoker(char type, int point)
	{
		m_type = type;
		m_point = point;
		if (m_type == JOKER)
		{
			m_point += 13;
		}
	}
	void OutputPoker()
	{
		const char *type[5] = { "黑桃","红桃","梅花","方片","" };
		const char *point[16] = { "","A","2","3","4","5","6","7","8","9","10","J","Q","K","大王","小王" };
		printf("%s%s", type[m_type], point[m_point]);
	}
	bool cmmppoker(Poker tmp)
	{
		return (m_point < tmp.m_point) ||
			(m_point == tmp.m_point && m_type > tmp.m_type);
	}
	bool isEff()
	{
		if (m_type == JOKER && m_point == 15 || m_point == 14)
		{
			return true;
		}
		if ((unsigned char)m_type > 3 || (unsigned char)m_point - 1 > 13)
		{
			return false;
		}
		return true;
	}
};

class Player
{
	Poker m_HandCard[18];
	int m_size;
public:
	Player() : m_size(0) {}; 
	void GetCard(Poker newCard)
	{
		int i;
		for (i = m_size; i > 0 && m_HandCard[i - 1].cmmppoker(newCard); i--)
		{
			m_HandCard[i] = m_HandCard[i - 1];
		}
		m_HandCard[i] = newCard;
		m_size++;
	}

	void ShowCard()
	{
		for (auto &i : m_HandCard)
		{
			i.OutputPoker();
			putchar(' ');
		}
		putchar('\n');
	}
};

int randnum(Poker *cardHeap)
{
	int tmp = rand() % 54;
	while (1)
	{
		if (cardHeap[tmp].isEff())
		{
			return tmp;
		}
		else
		{
			tmp++;
			if (tmp == 54)
			{
				tmp = 0;
			}
		}
	}
}

int main()
{
	Poker tmp[54];
	int j = 0;
	Player p1;
	Player p2;
	Player p3;
	for (auto &i : tmp)
	{
		i.MakePoker(j / 13, j % 13 + 1);
		j++;
	}
	srand((unsigned)time(NULL));
	int delcard;
	int i = 0;
	for (i = 0; i < 18; i++)
	{
		delcard = randnum(tmp);
		p1.GetCard(tmp[delcard]);
		tmp[delcard].MakePoker(-1, -1);

		delcard = randnum(tmp);
		p2.GetCard(tmp[delcard]);
		tmp[delcard].MakePoker(-1, -1);

		delcard = randnum(tmp);
		p3.GetCard(tmp[delcard]);
		tmp[delcard].MakePoker(-1, -1);
	}
	p1.ShowCard();
	p2.ShowCard();
	p3.ShowCard();
	system("pause");
	return 0;
}
