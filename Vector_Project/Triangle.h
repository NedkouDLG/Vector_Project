#pragma once
#include "EqualPointException.h"
#include "Point.h"
class Triangle:public Point
{
	//Направени са функциите приятлески за да може да се достъпват private елементите на класа
	friend bool operator<(const Point&, Triangle&);
	friend bool operator>(const Point&, Triangle&);
	friend bool operator==(const Point&, Triangle&);
private:
	Point a, b, c;
	bool isInPlane(const Point&);
public:
	Triangle();
	Triangle(Point, Point, Point);
	Triangle(const Triangle&);
	~Triangle();
	Triangle& operator=(const Triangle&);
	double getPerimeter() const;
	Point getMedicenter() const;
	double getAreaOfTriangle() const;

	void coutType()const;
	virtual std::istream& ext(std::istream&);
	virtual std::ostream& ins(std::ostream&) const;
};
bool operator<(const Point&, Triangle&);
bool operator>(const Point&, Triangle&);
bool operator==(const Point&, Triangle&);