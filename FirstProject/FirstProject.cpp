// FirstProject.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


using namespace std;
int main()
{
	cout << "���Ǩ�ƣ�" << endl;
	cout << "hello world" << endl;
	int x = 100;
	int *f, **p;
	f = &x;
	p = &f;
	cout << "x=" << x << ",*f=" << *f << ",**p=" << **p << "." << endl;
	return 0;
}
