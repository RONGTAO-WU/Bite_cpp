#define _CRT_SECURE_NO_WARNINGS

#include"Date.h"



Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

void Date::Print()
{
	cout << _year << "/";

	if (_month < 10)
		cout << "0" << _month;
	else
		cout << _month;

	cout << "/";

	if (_day < 10)
		cout << "0" << _day << endl;
	else
		cout << _day << endl;
}

bool Date::operator<(Date& x)
{
	if (_year < x._year)						// 先比较年份
	{
		return true;
	}
	else
		if (_year == x._year)
		{
			if (_month < x._month)				// 再比较月份
			{
				return true;
			}
			else
				if (_month == x._month)
				{
					return _day < x._day;		// 最后比较天数
				}
		}

	return false;
}

bool Date::operator<=(Date& x)
{
	return *this < x || *this == x;				// 复用 < 和 ==
}

bool Date::operator>(Date& x)
{
	return !(*this <= x);						// 复用 <=
}

bool Date::operator>=(Date& x)
{
	return !(*this < x);						// 复用 <
}

bool Date::operator==(Date& x)
{
	return _year == x._year && _month == x._month && _day == x._day;
}

bool Date::operator!=(Date& x)
{
	return !(*this == x);						// 复用==
}



Date& Date::operator+=(int x)
{
	_day += x;									// 将要相加的数值与原来的天数相加
	while (_day > Getmonthday(_year, _month))	// 天数与函数返回天数进行比较，大于当月月份进入循环
	{
		_day -= Getmonthday(_year, _month);		
		_month++;

		if (_month == 13)						// 大于12月份重置月份，年份加1
		{
			_month = 1;
			_year++;
		}
	}

	return *this;								// 返回它自己

}

Date Date::operator+(int x)
{
	Date tmp(*this);							// 拷贝构造一个相同的日期类,以下内容与上面相似，但原日期类不会随之改变

	tmp._day += x;								

	while (tmp._day > Getmonthday(tmp._year, tmp._month))
	{
		tmp._day -= Getmonthday(tmp._year, tmp._month);
		tmp._month++;
		if (tmp._month == 13)
		{
			tmp._month = 1;
			tmp._year++;
		}
	}

	return tmp;
}

//Date Date::operator+(int x)
//{
//	Date tmp(*this);
//	tmp += x;									// 复用赋值运算符
//
//	return tmp;
//}
//
//Date& Date::operator+=(int x)
//{
//	*this = *this + x;							// 复用
//	return *this;
//}



Date& Date::operator-=(int x)
{
	_day -= x;

	while (_day <= 0)
	{
		_month--;								// 先借位
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}

		_day += Getmonthday(_year, _month);
	}
	

	return *this;
}

Date Date::operator-(int x)
{
	Date tmp(*this);

	tmp._day -= x;

	while (tmp._day <= 0)
	{
		tmp._month--;
		if (tmp._month == 0)
		{
			tmp._month = 12;
			tmp._year--;
		}

		tmp._day += Getmonthday(tmp._year, tmp._month);
	}

	return tmp;
}

//Date Date::operator-(int x)					// 复用
//{
//	Date tmp(*this);
//	tmp = *this - x;
//
//	return tmp;
//}
//
//Date& Date::operator-=(int x)					// 复用
//{
//	*this = *this - x;
//	return *this;
//}



Date Date::operator++()
{
	*this += 1;
	return *this ;
}

Date Date::operator++(int)						// 先使用后++
{
	Date tmp = *this;
	*this += 1;

	return tmp;
}

Date Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;

	return tmp;
}

int Date::operator-(Date& x)
{
	int flag = 1;
	Date max = *this;
	Date min = x;

	if (*this < x)
	{
		max = x;
		min = *this;
		flag = -1;
	}

	int n = 0;
	while (min != max)
	{
		min++;
		n++;
	}

	return n * flag;

}