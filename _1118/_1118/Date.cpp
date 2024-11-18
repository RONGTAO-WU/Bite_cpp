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
	if (_year < x._year)						// �ȱȽ����
	{
		return true;
	}
	else
		if (_year == x._year)
		{
			if (_month < x._month)				// �ٱȽ��·�
			{
				return true;
			}
			else
				if (_month == x._month)
				{
					return _day < x._day;		// ���Ƚ�����
				}
		}

	return false;
}

bool Date::operator<=(Date& x)
{
	return *this < x || *this == x;				// ���� < �� ==
}

bool Date::operator>(Date& x)
{
	return !(*this <= x);						// ���� <=
}

bool Date::operator>=(Date& x)
{
	return !(*this < x);						// ���� <
}

bool Date::operator==(Date& x)
{
	return _year == x._year && _month == x._month && _day == x._day;
}

bool Date::operator!=(Date& x)
{
	return !(*this == x);						// ����==
}



Date& Date::operator+=(int x)
{
	_day += x;									// ��Ҫ��ӵ���ֵ��ԭ�����������
	while (_day > Getmonthday(_year, _month))	// �����뺯�������������бȽϣ����ڵ����·ݽ���ѭ��
	{
		_day -= Getmonthday(_year, _month);		
		_month++;

		if (_month == 13)						// ����12�·������·ݣ���ݼ�1
		{
			_month = 1;
			_year++;
		}
	}

	return *this;								// �������Լ�

}

Date Date::operator+(int x)
{
	Date tmp(*this);							// ��������һ����ͬ��������,�����������������ƣ���ԭ�����಻����֮�ı�

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
//	tmp += x;									// ���ø�ֵ�����
//
//	return tmp;
//}
//
//Date& Date::operator+=(int x)
//{
//	*this = *this + x;							// ����
//	return *this;
//}



Date& Date::operator-=(int x)
{
	_day -= x;

	while (_day <= 0)
	{
		_month--;								// �Ƚ�λ
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

//Date Date::operator-(int x)					// ����
//{
//	Date tmp(*this);
//	tmp = *this - x;
//
//	return tmp;
//}
//
//Date& Date::operator-=(int x)					// ����
//{
//	*this = *this - x;
//	return *this;
//}



Date Date::operator++()
{
	*this += 1;
	return *this ;
}

Date Date::operator++(int)						// ��ʹ�ú�++
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