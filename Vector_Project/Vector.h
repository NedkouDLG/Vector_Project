#pragma once
#include "Point.h"
class Vector:public Point
{
private:
	double baseX;
	double baseY;
	double baseZ;
public:
	Vector();
	Vector(double, double, double);
	Vector(Point, Point);
	Vector(const Vector&);
	Vector& operator =(const Vector&);
	~Vector();

	Vector operator +(const Vector&);
	Vector operator -(const Vector&);
	Vector operator ^(const Vector&);
	Vector operator *(const double&);
	double operator *(const Vector&);
	double operator ()(const Vector&, const Vector&);

	double getBaseX() const;
	double getBaseY() const;
	double getBaseZ() const;
	double getLength() const;

	void setBaseX(double);
	void setBaseY(double);
	void setBaseZ(double);

	bool isZero() const;
	bool isParallel(const Vector&) const;
	bool isPerpendicular(const Vector&) const;
};

