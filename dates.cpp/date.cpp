#include"date.h"

Date Date::operator+(uint delay) const 
{
	Date res = *this;
	uint tmp;
	int numy = delay / 365;
	int numd = delay % 365;
	int flag = 0;
	if (res.m_month > 2)
	{
		flag = 1;
	}
	int leapnum = GetLeapNum(res.m_year+flag, res.m_year + numy);
	while(numd < leapnum)
	{
		numy--;
		leapnum = GetLeapNum(res.m_year+flag, res.m_year + numy);
		numd += 365;
	}
	numd -= leapnum;
	res.m_year += numy;
	delay = numd;
	tmp = GetMonthDay(res.m_year, res.m_month);
	while (delay >= tmp)
	{
		delay -= tmp;
		res.m_month++;
		if (res.m_month > 12)
		{
			res.m_month = 1;
			res.m_year++;
		}
		tmp = GetMonthDay(res.m_year, res.m_month);
	}
	res.m_day += delay;
	if (res.m_day > GetMonthDay(res.m_year, res.m_month))
	{
		res.m_day -= GetMonthDay(res.m_year, res.m_month);
		res.m_month++;
		if (res.m_month > 12)
		{
			res.m_month = 1;
			res.m_year++;
		}
	}
	return res;
}

Date Date::operator-(uint delay) const
{
	Date res = *this;
	uint tmp;
	tmp = GetMonthDay(res.m_year, res.m_month);
	while (delay > tmp)
	{
		delay -= tmp;
		res.m_month--;
		if (0 == res.m_month)
		{
			res.m_month = 12;
			res.m_year--;
		}
		tmp = GetMonthDay(res.m_year, res.m_month);
	}
	int count = res.m_day - delay;
	if (count < 1)
	{
		if (0 == res.m_month)
		{
			res.m_month = 12;
			res.m_year--;
		}
		delay -= res.m_day;
		res.m_day = GetMonthDay(res.m_year, res.m_month);
		res.m_day -= delay;
		res.m_month--;
	}
	else
	{
		res.m_day -= delay;
	}
	return res;
}

int GetLeapNum(int startyear, int endyear)
{
	int tmp = startyear % 4;
	if (tmp)
	{
		startyear += (4 - tmp);
	}
	int ret1 = (endyear - startyear)/400;
	int ret2 = (endyear - startyear) / 4 + 1 - (endyear - startyear) / 100;
	return ret1 + ret2;
}

static uint GetMonthDay(int y, uint m)
{
	if (m > 12 || m == 0)
	{
		return 0;
	}
	if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		return 30;
	}
	else if (m == 2)
	{
		return 28 + ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0));
	}
	else
	{
		return 31;
	}
}

ostream & operator <<(ostream& os, Date &d)
{
	os << d.m_year << "-" << d.m_month << "-" << d.m_day;
	return os;
}

void test()
{
	Date test1(2019, 10, 7);
	cout << test1 << endl;
	test1 =  test1 + 100000;
	cout << test1 << endl;

}

bool Date::operator < (const Date & d)const
{
	if (m_year < d.m_year)
	{
		return true;
	}
	else if (m_year == d.m_year)
	{
		if (m_month < d.m_month)
		{
			return true;
		}
		else if (m_month == d.m_month)
		{
			if (m_day < d.m_day)
			{
				return true;
			}
		}
	}
	return false;
}
bool Date::operator > (const Date & d)const
{
	if (m_year > d.m_year)
	{
		return true;
	}
	else if (m_year == d.m_year)
	{
		if (m_month > d.m_month)
		{
			return true;
		}
		else if (m_month == d.m_month)
		{
			if (m_day > d.m_day)
			{
				return true;
			}
		}
	}
	return false;
}
bool Date::operator <= (const Date & d)const
{
	return !(*this > d);
}
bool Date::operator >= (const Date & d)const
{
	return !(*this < d);
}
bool Date::operator == (const Date & d)const
{
	if (m_year == d.m_year&&
		m_month == d.m_month&&
		m_day == d.m_day)
	{
		return true;
	}
	return false;
}
bool Date::operator != (const Date & d)const
{
	return (*this < d) || (*this > d);
}
