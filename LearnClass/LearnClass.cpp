// LearnClass.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
using namespace std;
class People
{
public:
	People(char sex);//���캯��
	People(char *name,char *grade,char sex,int age);
	~People();//��������
	void print();

private:
	char *name;
	char *grade;
	const char sex;//����Ա
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
	cout << "ִ�������������ͷſռ�" << endl;
}

void People::print()
{
	cout << "������Ϣ��������" << name << ",�꼶��" << grade << ",�Ա�" << sex << ",���䣺" << age << endl;
}

int main()
{
	People p1('��'), p2('Ů'), p3('��');
	p1.print();
	p2.print();
	p3.print();
	return 0;
}

