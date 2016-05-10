#include "stdafx.h"
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(int length1,int width1) {
	cout << "构造函数" << endl;
	length = length1;
	width = width1;
}
Rectangle::Rectangle(Rectangle &r) {
	cout << "复制构造函数"<<endl;
	length = r.length;
	width = r.width;
}
Rectangle::~Rectangle()
{
	cout << "此处为析构函数，释放资源" << endl;
}

void Rectangle::print()
{
	cout << "矩形长：" << length << "，矩形宽：" << width<<endl;
}
void Rectangle::area() {
	s = length*width;
}
void Rectangle:: addarea( Rectangle r1,Rectangle r2) {
	s1 = r1.length*r1.width+ r2.length*r2.width;
}
void Rectangle::disp() {
	cout << "矩形面积：" << s<<endl;
}
void Rectangle::disp1() {
	cout << "两个矩形面积和：" << s1<<endl;
}
