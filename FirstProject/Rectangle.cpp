#include "stdafx.h"
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(int length1,int width1) {
	length = length1;
	width = width1;
}
Rectangle::Rectangle(Rectangle &r) {
	length = r.length;
	width = r.width;
}
Rectangle::~Rectangle()
{
}

void Rectangle::print()
{
	cout << "���γ���" << length << "�����ο�" << width<<endl;
}
void Rectangle::area() {
	s = length*width;
}
void Rectangle:: addarea( Rectangle r1,Rectangle r2) {
	s1 = r1.s + r2.s;
}
void Rectangle::disp() {
	cout << "���������" << s<<endl;
}
void Rectangle::disp1() {
	cout << "������������ͣ�" << s1<<endl;
}
