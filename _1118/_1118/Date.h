#pragma once

#include<iostream>
using namespace std;

#include<assert.h>
#include<stdbool.h>


class Date {																				// ������

public:
	Date(int year = 1, int month = 1, int day = 1);											// ���캯������
	void Print();																			// ��ӡ����



	int Getmonthday(int _year, int _month)
	{
		assert(_month > 0 && _month < 13);

		int monthdayarray[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		
		if (_month == 2 && ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0))		// �ж�����

			return 29;																		// 2�£����귵������29
		else
			return monthdayarray[_month];													// �������������������
	}



	bool operator < (Date& x);																// �������������
	bool operator <=(Date& x);
	bool operator > (Date& x);
	bool operator >=(Date& x);
	bool operator ==(Date& x);
	bool operator !=(Date& x);



	Date& operator+=(int x);																// �й�����������
	Date operator+(int x);

	Date& operator-=(int x);
	Date operator-(int x);



	int operator-(Date& x);																	// һ�����һ���෵���������



	Date operator++();																		// ����++��ǰ��++������
	Date operator++(int);

	Date operator--();
	Date operator--(int);


private:

	int _year;
	int _month;
	int _day;

};