// FirstProject.cpp : �������̨Ӧ�ó������ڵ㡣
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
/*ָ��Ļ���ʹ��*/
void point() {
	int x[6] = { 1,2,3,4,5,6 }, *f;
	f = x;//x����������׵�ַ
	if (*(&x[5]) == x[5]) {
		cout <<setw(15)<<"*(��ַ) ����������Ԫ��"<<endl;
	}
	cout << x<<endl;//xָ����������׵�ַ 0018F5F8
	cout << (x + 1) << endl;//0018F5FC (C++��ÿ���洢��Ԫռ4�ֽ�)
}
/*����ָ�������Ԫ�ؽ��з�ת*/
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
