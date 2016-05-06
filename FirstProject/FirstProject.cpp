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
	int x[6] = { 1,2,3,4,5,6 }, z[6],*f,*m,*n;
	f = m = x;//x代表数组的首地址
	n = z;
	for (int i = 0; i < 6;i++) {
		//*n++ = *f++ + *m++;
		*n = *f + *m;
		f++, m++,n++;//同上面代码
	}
	n = z;//重新将指针n指向数组z首地址
	for (int i = 0; i < 6;i++) {
		cout <<setw(3)<< *n++;
	}
	cout << endl;
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
/*指针与二维数组*/
void pointToArrays() {
	int m[2][3] = {1,2,3,4,5,6};
	int *f = m[0];//定义的是指针变量
	for (int i = 0; i < 6;i++,f++) {
		cout << setw(3)<<*f;
	}
	cout << endl;
	int *a[2] = { m[0],m[1] };//定义的是指针数组
	for (int i = 0; i < 2;i++) {
		for (int j = 0; j < 3;j++) {
			cout << setw(3)<<*(a[i] + j);//★
		}
	}
	cout << endl;
	int(*b)[3] = m;//定义的是行指针
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout <<setw(3)<<b[i][j];//★
		}
	}
	cout << endl;
}
/*形参和实参*/
void sort(int *p,int n) {//实现简单选择排序
	int i, j, k, t;
	for (i = 0; i < n-1;i++) {
		k = i;
		for (j = k+1; j < n;j++) {
			if (p[k]>p[j]) {
				k = j;//记录位置
			}
		}
		t = p[k];//交换
		p[k] = p[i];
		p[i] = t;
	}
}
/*函数模板*/
template<class T>
T fun(T m,int n) {//函数的参数列表里必须含有与给定的函数模板中参数类型相同的参数。
	return n;
}
/*作用域*/
int x = 400, y = 200;
int main()
{
	int x = 100, z = 0;
	z = x + y;
	cout << "第一次输出：" << z << endl;
	{
		int x = 200, y = 300;
		z = x + y;
		cout << "第二次输出：" << z << endl;
	}
	cout << "第三次输出：" << x + y << endl;
	//int m = 5;
	//cout<<fun(m,5)<<endl;
	/*int m[8] = { 5,6,2,4,3,1 };
	int n = 6;
	sort(m, 6);//影响实参
	for (int i = 0; i < 6;i++) {
		cout <<setw(3)<<m[i];
	}
	cout << endl;*/
	//pointToArrays();
	//pointToReverse();
	//();
	//test();
	return 0;
}
