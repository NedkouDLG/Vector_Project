#pragma once
#include "Element.h";
class Point:public Element
{
public:
	Point();
	Point(int, int, int);
	Point(const Point&);
	Point& operator=(const Point&);
	bool operator==(const Point&);
	~Point();
};

