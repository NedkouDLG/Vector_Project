#pragma once
#include "Element.h";
class Point:public Element
{
public:
	//�������� 5
	Point();
	Point(double, double, double);
	Point(const Point&);
	Point& operator=(const Point&);
	~Point();

	//������������� �� ���������� �� ��������� � ��������� �� ����� Point
	virtual std::istream& ext(std::istream&);
	virtual std::ostream& ins(std::ostream&) const;
};
//������������� �� �������� ==
bool operator==(const Point&, const Point&);
