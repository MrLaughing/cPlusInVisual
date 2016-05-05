// FirstProject.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iomanip>
using namespace std;
void test() {
	int x = 100;
	int *f, **p;
	f = &x;
	p = &f;
	cout << "x=" << x << ",*f=" << *f << ",**p=" << **p << "." << endl;
}
/*指针的基本使用*/
void point() {
	int x[6] = { 1,2,3,4,5,6 }, *f;
	f = x;//x代表数组的首地址
	if (*(&x[5]) == x[5]) {
		cout <<setw(15)<<"*(地址) 可引用数组元素"<<endl;
	}
	cout << x<<endl;//x指向的是数组首地址 0018F5F8
	cout << (x + 1) << endl;//0018F5FC (C++里每个存储单元占4字节)
}
/*利用指针对数组元素进行反转*/
void pointToReverse() {
	int m[8] = {1,2,3,4,5,6,7,8};
	int *a = m, *b =m+7, c;
	for (; a < b;a++,b--) {
		c = *a;
		*a = *b;
		*b = c;
	}
	for (int n = 0; n < 8;n++) {
		cout << m[n];
	}
	cout << endl;
}
int main()
{
	pointToReverse();
	//point();
	//test();
	return 0;
}
