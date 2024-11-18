#pragma once

#include<iostream>
using namespace std;

#include<assert.h>
#include<stdbool.h>


class Date {																				// 类声明

public:
	Date(int year = 1, int month = 1, int day = 1);											// 构造函数声明
	void Print();																			// 打印声明



	int Getmonthday(int _year, int _month)
	{
		assert(_month > 0 && _month < 13);

		int monthdayarray[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		
		if (_month == 2 && ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0))		// 判断闰年

			return 29;																		// 2月，闰年返回天数29
		else
			return monthdayarray[_month];													// 其他情况正常返回天数
	}



	bool operator < (Date& x);																// 运算符重载声明
	bool operator <=(Date& x);
	bool operator > (Date& x);
	bool operator >=(Date& x);
	bool operator ==(Date& x);
	bool operator !=(Date& x);



	Date& operator+=(int x);																// 有关天数的运算
	Date operator+(int x);

	Date& operator-=(int x);
	Date operator-(int x);



	int operator-(Date& x);																	// 一个类减一个类返回相差天数



	Date operator++();																		// 后置++和前置++的区别
	Date operator++(int);

	Date operator--();
	Date operator--(int);


private:

	int _year;
	int _month;
	int _day;

};