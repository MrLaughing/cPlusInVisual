// LearnClass.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;
class People
{
public:
	People(char sex);//构造函数
	People(char *name,char *grade,char sex,int age);
	~People();//析构函数
	void print();

private:
	char *name;
	char *grade;
	const char sex;//常成员
	int age;
};
People::People(char sex):sex(sex){}

People::People(char * name, char * grade, char sex, int age): sex(sex){
	this->name = name;
	this->grade = grade;
	this->age = age;
}

People::~People()
{
	cout << "执行析构函数，释放空间" << endl;
}

void People::print()
{
	cout << "个人信息，姓名：" << name << ",年级：" << grade << ",性别：" << sex << ",年龄：" << age << endl;
}

int main()
{
	People p1('男'), p2('女'), p3('男');
	p1.print();
	p2.print();
	p3.print();
	return 0;
}

