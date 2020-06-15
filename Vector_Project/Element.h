#pragma once
#include<iostream>
class Element
{
protected:
	double x;
	double y;
	double z;
public:
	virtual void setX(double) = 0;
	virtual void setY(double) = 0;
	virtual void setZ(double) = 0;
	virtual double getX() const;
	virtual double getY() const;
	virtual double getZ() const;

	virtual std::ostream& ins(std::ostream&) const;
	virtual std::istream& ext(std::istream&);
};
std::ostream& operator<<(std::ostream&, const Element&);
std::istream& operator>>(std::istream&, Element&);
