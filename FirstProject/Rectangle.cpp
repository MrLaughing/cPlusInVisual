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
	cout << "矩形长：" << length << "，矩形宽：" << width<<endl;
}
void Rectangle::area() {
	s = length*width;
}
void Rectangle:: addarea( Rectangle r1,Rectangle r2) {
	s1 = r1.s + r2.s;
}
void Rectangle::disp() {
	cout << "矩形面积：" << s<<endl;
}
void Rectangle::disp1() {
	cout << "两个矩形面积和：" << s1<<endl;
}
