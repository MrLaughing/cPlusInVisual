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
int main()
{
	pointToArrays();
	//pointToReverse();
	//();
	//test();
	return 0;
}
