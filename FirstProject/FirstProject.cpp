// FirstProject.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


using namespace std;
int main()
{
	cout << "完成迁移！" << endl;
	cout << "hello world" << endl;
	int x = 100;
	int *f, **p;
	f = &x;
	p = &f;
	cout << "x=" << x << ",*f=" << *f << ",**p=" << **p << "." << endl;
	return 0;
}
