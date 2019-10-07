# pragma once
#include<iostream>
using namespace std;
#include<stdio.h>

typedef unsigned int uint;

class Date
{
	int m_year;
	uint m_month;
	uint m_day;

public:
	Date(int year, uint month, uint day)
		:m_year(year)
		, m_month(month)
		, m_day(day)
	{}
	Date()
	{}
	Date operator+(uint delay) const;
	Date operator-(uint delay) const;

	bool operator < (const Date & d)const;
	bool operator > (const Date & d)const;
	bool operator <= (const Date & d)const;
	bool operator >= (const Date & d)const;
	bool operator == (const Date & d)const;
	bool operator != (const Date & d)const;

	friend ostream & operator <<(ostream & os, Date & d);

};

static uint GetMonthDay(int y, uint m);
int GetLeapNum(int startyear, int endyear)
void test();