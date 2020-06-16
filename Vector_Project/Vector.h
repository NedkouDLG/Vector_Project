#pragma once
#include "Point.h"
#include "VectorLengthException.h"
class Vector:public Point
{
public:
	// Големите 5 + още един контруктор са параметри
	Vector();
	Vector(const double&, const double&, const double&);
	Vector(const Point&, const Point&);
	Vector(const Vector&);
	Vector& operator =(const Vector&);
	~Vector();

	//Скаларно произведение на вектор
	double operator ()(const Vector&, const Vector&);
	//Дължина на вектора
	double getLength() const;
	//Вирутална функция за посока на вектора, тъй като в наследяващия клас Line
	//също се иска посока, но на правата и функцията отново връща вектор
	virtual Vector getDirection();

	bool isZero() const;
	bool isParallel(const Vector&);
	bool isPerpendicular(const Vector&);

	//Предифиниране на операциите за въвеждане и извеждане за класа Vector
	virtual std::istream& ext(std::istream&);
	virtual std::ostream& ins(std::ostream&) const;
};

Vector operator +(const Vector&, const Vector&);
Vector operator -(const Vector&, const Vector&);
Vector operator ^(const Vector&, const Vector&);
Vector operator *(const double&, const Vector&);
double operator *(const Vector&, const Vector&);