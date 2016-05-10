#pragma once
/*创建矩形类*/
class Rectangle
{
private:
	int length;
	int width;
	int s;//面积
	int s1;//两个矩形的面积和
public:
	Rectangle();
	Rectangle(int length1, int width1);
	Rectangle(Rectangle & r);//复制初始化构造函数
	void print();
	void area();
	void addarea(Rectangle r1, Rectangle r2);
	void disp();
	void disp1();
	~Rectangle();
};

