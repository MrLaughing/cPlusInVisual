#pragma once
/*����������*/
class Rectangle
{
private:
	int length;
	int width;
	int s;//���
	int s1;//�������ε������
public:
	Rectangle();
	Rectangle(int length1, int width1);
	Rectangle(Rectangle & r);//���Ƴ�ʼ�����캯��
	void print();
	void area();
	void addarea(Rectangle r1, Rectangle r2);
	void disp();
	void disp1();
	~Rectangle();
};

