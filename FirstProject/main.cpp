// FirstProject.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Rectangle.h"
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
//int x = 400, y = 200;
/*结构体声明和引用*/
struct date
{
	int year, month, day;

};
/*typeof声明结构体，再用新类型名定义变量*/
typedef struct 
{
	int num;
	char name[20];
	char sex[2];
	date birthday;
	float score;
} ST;
/*动态内存分配 new/delete*/
void dynamic() {
	int *f = new int[5];//动态内存分配，必须在新的表达式中指定数组大小
	for (int i = 0; i < 5;i++) {
		cin >> f[i];
	}
	for (int i = 0; i < 5;i++) {
		cout << f[i]<<setw(3);
	}
	delete[5] f;//将指针变量所指的一维数组内存空间归还给系统
}
/*链表*/
//首先定义一个结构体
typedef struct Node {
	int data;//数据域
	struct Node *next;//指针域，存放下一个结点
} SNode;
/*建立单链表*/
SNode * creat() {//创建单链表
	SNode *head, *p, *q;//p为新增结点,q为尾结点
	int data;
	head = (SNode *)malloc(sizeof(SNode));//为头结点分配空间
	q = head;
	cin >> data;//输入结点数据
	(*head).data = data; //head->data = data;
	while (data !=-1) {
		p = (SNode *)malloc(sizeof(SNode));//为新结点分配空间
		(*q).next = p;
		(*p).data = data;
		q = p;
		cin >> data;
	}
	(*q).next = NULL;
	return head;
}
/*打印链表*/
void print(SNode *head) {
	SNode *p;
	p = head->next;
	if (p == NULL) {
		cout << "空链表";
	}
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
	}
}
/*共用体*/
typedef union un {
	int m;
	char b[2];
} UN;
int main()
{
	Rectangle r1(5, 3);
	//Rectangle r2(6, 4);
	Rectangle r2(r1);//复制初始化构造函数
	Rectangle r3;//r3没有初始化
	r1.print(); r1.area(); r1.disp();
	r2.print(); r2.area(); r2.disp();
	r3.addarea(r1,r2);//两矩形面积之和存在了s3中
	r3.disp1();
	/*UN u;
	u.m = 5;
	u.b[0] = 65;
	u.b[1] = 97;
	cout <<u.m << endl;//结果是24897
	cout << u.b << endl;//结果是Aa*/
	/*SNode *head = creat();
	print(head);*/
	//dynamic();
	/*ST s[3], *f;//用新类型名定义变量
	struct s1;*/
	/*int x = 100, z = 0;
	z = x + y;
	cout << "第一次输出：" << z << endl;
	{
		int x = 200, y = 300;
		z = x + y;
		cout << "第二次输出：" << z << endl;
	}
	cout << "第三次输出：" << x + y << endl;*/
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
