// FirstProject.cpp : �������̨Ӧ�ó������ڵ㡣
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
/*ָ��Ļ���ʹ��*/
void point() {
	int x[6] = { 1,2,3,4,5,6 }, z[6],*f,*m,*n;
	f = m = x;//x����������׵�ַ
	n = z;
	for (int i = 0; i < 6;i++) {
		//*n++ = *f++ + *m++;
		*n = *f + *m;
		f++, m++,n++;//ͬ�������
	}
	n = z;//���½�ָ��nָ������z�׵�ַ
	for (int i = 0; i < 6;i++) {
		cout <<setw(3)<< *n++;
	}
	cout << endl;
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
/*ָ�����ά����*/
void pointToArrays() {
	int m[2][3] = {1,2,3,4,5,6};
	int *f = m[0];//�������ָ�����
	for (int i = 0; i < 6;i++,f++) {
		cout << setw(3)<<*f;
	}
	cout << endl;
	int *a[2] = { m[0],m[1] };//�������ָ������
	for (int i = 0; i < 2;i++) {
		for (int j = 0; j < 3;j++) {
			cout << setw(3)<<*(a[i] + j);//��
		}
	}
	cout << endl;
	int(*b)[3] = m;//���������ָ��
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout <<setw(3)<<b[i][j];//��
		}
	}
	cout << endl;
}
/*�βκ�ʵ��*/
void sort(int *p,int n) {//ʵ�ּ�ѡ������
	int i, j, k, t;
	for (i = 0; i < n-1;i++) {
		k = i;
		for (j = k+1; j < n;j++) {
			if (p[k]>p[j]) {
				k = j;//��¼λ��
			}
		}
		t = p[k];//����
		p[k] = p[i];
		p[i] = t;
	}
}
/*����ģ��*/
template<class T>
T fun(T m,int n) {//�����Ĳ����б�����뺬��������ĺ���ģ���в���������ͬ�Ĳ�����
	return n;
}
/*������*/
//int x = 400, y = 200;
/*�ṹ������������*/
struct date
{
	int year, month, day;

};
/*typeof�����ṹ�壬�������������������*/
typedef struct 
{
	int num;
	char name[20];
	char sex[2];
	date birthday;
	float score;
} ST;
/*��̬�ڴ���� new/delete*/
void dynamic() {
	int *f = new int[5];//��̬�ڴ���䣬�������µı��ʽ��ָ�������С
	for (int i = 0; i < 5;i++) {
		cin >> f[i];
	}
	for (int i = 0; i < 5;i++) {
		cout << f[i]<<setw(3);
	}
	delete[5] f;//��ָ�������ָ��һά�����ڴ�ռ�黹��ϵͳ
}
/*����*/
//���ȶ���һ���ṹ��
typedef struct Node {
	int data;//������
	struct Node *next;//ָ���򣬴����һ�����
} SNode;
/*����������*/
SNode * creat() {//����������
	SNode *head, *p, *q;//pΪ�������,qΪβ���
	int data;
	head = (SNode *)malloc(sizeof(SNode));//Ϊͷ������ռ�
	q = head;
	cin >> data;//����������
	(*head).data = data; //head->data = data;
	while (data !=-1) {
		p = (SNode *)malloc(sizeof(SNode));//Ϊ�½�����ռ�
		(*q).next = p;
		(*p).data = data;
		q = p;
		cin >> data;
	}
	(*q).next = NULL;
	return head;
}
/*��ӡ����*/
void print(SNode *head) {
	SNode *p;
	p = head->next;
	if (p == NULL) {
		cout << "������";
	}
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
	}
}
/*������*/
typedef union un {
	int m;
	char b[2];
} UN;
int main()
{
	Rectangle r1(5, 3);
	//Rectangle r2(6, 4);
	Rectangle r2(r1);//���Ƴ�ʼ�����캯��
	Rectangle r3;//r3û�г�ʼ��
	r1.print(); r1.area(); r1.disp();
	r2.print(); r2.area(); r2.disp();
	r3.addarea(r1,r2);//���������֮�ʹ�����s3��
	r3.disp1();
	/*UN u;
	u.m = 5;
	u.b[0] = 65;
	u.b[1] = 97;
	cout <<u.m << endl;//�����24897
	cout << u.b << endl;//�����Aa*/
	/*SNode *head = creat();
	print(head);*/
	//dynamic();
	/*ST s[3], *f;//�����������������
	struct s1;*/
	/*int x = 100, z = 0;
	z = x + y;
	cout << "��һ�������" << z << endl;
	{
		int x = 200, y = 300;
		z = x + y;
		cout << "�ڶ��������" << z << endl;
	}
	cout << "�����������" << x + y << endl;*/
	//int m = 5;
	//cout<<fun(m,5)<<endl;
	/*int m[8] = { 5,6,2,4,3,1 };
	int n = 6;
	sort(m, 6);//Ӱ��ʵ��
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
