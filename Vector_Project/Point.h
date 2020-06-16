#pragma once
#include "Element.h";
class Point:public Element
{
public:
	//Големите 5
	Point();
	Point(double, double, double);
	Point(const Point&);
	Point& operator=(const Point&);
	~Point();

	//Предифиниране на операциите за въвеждане и извеждане за класа Point
	virtual std::istream& ext(std::istream&);
	virtual std::ostream& ins(std::ostream&) const;
};
//Предифиниране на оператор ==
bool operator==(const Point&, const Point&);
