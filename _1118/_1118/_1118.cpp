#define _CRT_SECURE_NO_WARNINGS

#include"Date.h"




void TestDate1()
{
	Date d1(2024, 11, 18);
	Date d2 = d1 + 50;					// 运算符+

	d1.Print();
	d2.Print();

	Date d3(2024, 11, 18);
	d3 += 50;							// 运算符+=
	d3.Print();

	Date d4(2024, 11, 18);
	d4 += 50000;						// 大数值测试
	d4.Print();

}

void TestDate2()
{
	Date d1(2024, 11, 18);
	Date d2 = d1 - 50;

	d1.Print();
	d2.Print();

	Date d3(2024, 11, 18);
	d3 -= 50;
	d3.Print();

	Date d4(2024, 11, 18);
	d4 -= 50000;
	d4.Print();

}

void TestDate3()						// 
{
	Date d1(2024, 11, 18);
	Date d2(2024, 1, 1);
	Date d3(2025, 1, 1);

	cout << (d1 > d2) << endl;			// << 的优先级高于 <
	cout << (d1 < d2) << endl;
	cout << (d1 == d2) << endl;

	cout << (d1 >= d3) << endl;
	cout << (d1 <= d3) << endl;
	cout << (d1 != d3) << endl;
}

void TestDate4()
{
	Date d1(2024, 11, 18);
	Date d2 = d1++;						// d2.operator++()
	Date d3 = ++d1;						// d2.operator++(0)

	d1.Print();
	d2.Print();
	d3.Print();

	Date d4 = d1--;
	Date d5 = --d1;

	d1.Print();
	d4.Print();
	d5.Print();
}

void TestDate5()
{
	Date d1(2024, 11, 18);
	Date d2(2000, 1, 1);

	cout << (d1 - d2) << endl;
}

int main()
{

	TestDate1();
	TestDate2();
	TestDate3();
	TestDate4();
	TestDate5();

	return 0;
}