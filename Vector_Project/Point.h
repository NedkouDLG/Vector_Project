#pragma once
#include "Element.h";
class Point:public Element
{
	friend bool operator==(const Point&, const Point&);
public:
	Point();
	Point(double, double, double);
	Point(const Point&);
	Point& operator=(const Point&);
	
	~Point();
	void setX(double);
	void setY(double);
	void setZ(double);
	virtual std::istream& ext(std::istream&);
	virtual std::ostream& ins(std::ostream&) const;
};
bool operator==(const Point&, const Point&);
