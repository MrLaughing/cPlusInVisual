#include "stdafx.h"
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(int length1,int width1) {
	cout << "���캯��" << endl;
	length = length1;
	width = width1;
}
Rectangle::Rectangle(Rectangle &r) {
	cout << "���ƹ��캯��"<<endl;
	length = r.length;
	width = r.width;
}
Rectangle::~Rectangle()
{
	cout << "�˴�Ϊ�����������ͷ���Դ" << endl;
}

void Rectangle::print()
{
	cout << "���γ���" << length << "�����ο�" << width<<endl;
}
void Rectangle::area() {
	s = length*width;
}
void Rectangle:: addarea( Rectangle r1,Rectangle r2) {
	s1 = r1.length*r1.width+ r2.length*r2.width;
}
void Rectangle::disp() {
	cout << "���������" << s<<endl;
}
void Rectangle::disp1() {
	cout << "������������ͣ�" << s1<<endl;
}
