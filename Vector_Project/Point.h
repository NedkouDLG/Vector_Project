#pragma once
#include "Element.h";
class Point:public Element
{
public:
	Point();
	Point(double, double, double);
	Point(const Point&);
	Point& operator=(const Point&);
	bool operator==(const Point&);
	~Point();
};

