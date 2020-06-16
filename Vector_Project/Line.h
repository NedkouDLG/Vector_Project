#pragma once
#include "Vector.h"
class Line:public Vector
{
private:
	Point begin;
	Vector direction;
public:
	Line();
	Line(const Point&, const Point&);
	Line(const Point&, const Vector&);
	Line(const Line&);
	~Line();
	Line& operator=(const Line&);
	
	virtual double getX() const;
	virtual double getY() const;
	virtual double getZ() const;

	double getPointX() const;
	double getPointY() const;
	double getPointZ() const;

	virtual Vector getDirection();
	Vector* getPerpendicularOfLine();
	double angle(Line&);

	virtual std::istream& ext(std::istream&);
	virtual std::ostream& ins(std::ostream&) const;
};
bool operator||(Line&, Line&);
bool operator==(const Line&, const Line&);
bool operator|(Line&, Line&);
bool operator+(const Point&, Line&);
