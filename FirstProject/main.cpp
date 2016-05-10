// FirstProject.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Rectangle.h"
#include <iomanip>
#include <string>
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
/*test*/
class Clock                   //时钟类声明   
{
public:                       //外部接口   
	Clock(int NewH = 0, int NewM = 0, int NewS = 0);
	void ShowTime();
	Clock& operator ++();     //前置单目运算符重载   
	Clock operator ++(int);   //后置单目运算符重载   
private:                      //私有数据成员   
	int Hour, Minute, Second;
};

Clock::Clock(int NewH, int NewM, int NewS)
{
	if (0 <= NewH && NewH<24 && 0 <= NewM && NewH<60 && 0 <= NewS && NewS<60)
	{
		Hour = NewH;
		Minute = NewM;
		Second = NewS;
	}
	else
		cout << "Tine error!" << endl;
}

void Clock::ShowTime()
{
	cout << Hour << ":" << Minute << ":" << Second << endl;
}

Clock& Clock::operator ++()  //前置单目运算符重载函数   
{
	Second++;
	if (Second >= 60)
	{
		Second = Second - 60;
		Minute++;
		if (Minute >= 60)
		{
			Minute = Minute - 60;
			Hour++;
			Hour = Hour % 24;
		}
	}
	return *this;
}

Clock Clock::operator ++(int)    //后置单目运算符重载   
{
	Clock old = *this;
	++(*this);
	return old;
}
class People
{
public:
	People(char sex);//构造函数
	People(string name, string grade, char sex, int age);
	~People();//析构函数
	void addage(int n);
	int getAge();
	void print();
	void print1();

private:
	string name;
	string grade;
	const char sex;//常成员
	static int age;//静态变量
};
int People::age = 0;
People::People(char sex) :sex(sex) {}

People::People(string name, string grade, char sex, int age) : sex(sex) {
	this->name = name;
	this->grade = grade;
	this->age = age;
}

People::~People()
{
	cout << "执行People析构函数，释放空间" << endl;
}

void People::addage(int n)
{
	age += n;
}

int People::getAge()
{
	return age;
}

void People::print()
{
	cout << "个人信息，姓名：" + name + ",年级：" + grade + ",性别：" << sex << ",年龄：" << age << endl;
}
void People::print1()
{
	cout << "个人信息,性别：" << sex << endl;
}
class Boy:public People//继承People类
{
public:
	Boy();
	Boy(int height);
	~Boy();
	void print1() {
		/*People:print1();*/
		cout << "height为：" << height<<endl;
	}

private:
	int height;//派生类单独的成员
};	
Boy::Boy() : People('M')//常成员这里就要初始化吗？★
{
}
Boy::Boy(int height) : People('M')//常成员这里就要初始化吗？★
{
	this->height = height;
}

Boy::~Boy()
{
	cout << "执行Boy析构函数，释放空间" << endl;
}
int main()
{
	People p1('M'), p2('W'), p3("三号","三班",'M',20);
	p1.print1();
	p2.print1();
	p3.print();
	p1.addage(5);//静态变量属于类，所有对象共享
	cout << p1.getAge();//输出25
	Boy b1(179);
	b1.print1();

	/*Clock myClock(23, 59, 59);
	cout << "First time output:";
	myClock.ShowTime();
	cout << "Show myclock++:";
	(myClock++).ShowTime();
	cout << "Show ++myclock:";
	(++myClock).ShowTime();*/
	/*结果如下：
	First time output:23:59:59
	Show myclock++:23:59:59
	Show ++myclock:0:0:1*/

	/*Rectangle r1(5, 3);
	//Rectangle r2(6, 4);
	Rectangle r2(r1);//复制初始化构造函数
	Rectangle r3;//r3没有初始化
	r1.print(); r1.area(); r1.disp();
	r2.print(); r2.area(); r2.disp();
	r3.addarea(r1,r2);//两矩形面积之和存在了s3中
	r3.disp1();*/
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
