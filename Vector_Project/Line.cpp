#include "Line.h"
#include <iostream>
#include <cmath>
Line::Line()
{
	//std::cout << this->baseX << std::endl;
}

Line::Line(const Point& a, const Point& b)
{
	Vector vector(a, b);
	this->begin = a;
	this->direction = vector;
	this->x = direction.getX();
	this->y = direction.getY();
	this->z = direction.getZ();
}

Line::Line(const Point& a, const Vector& vector)
{
	this->begin = a;
	this->direction  = vector;
	this->x = direction.getX();
	this->y = direction.getY();
	this->z = direction.getZ();
}

Line::Line(const Line& rhs)
{
	this->begin = rhs.begin;
	this->direction = rhs.direction;
	this->x = direction.getX();
	this->y = direction.getY();
	this->z = direction.getZ();
}

Line::~Line()
{

}

Line& Line::operator=(const Line& rhs)
{
	if (this != &rhs) {
		this->begin = rhs.begin;
		this->direction = rhs.direction;
		this->x = direction.getX();
		this->y = direction.getY();
		this->z = direction.getZ();
	}
	return *this;
}

void Line::setX(double _x)
{
	this->x = _x;
}

void Line::setY(double _y)
{
	this->y = _y;
}

void Line::setZ(double _z)
{
	this->z = _z;
}

double Line::getX() const
{
	return direction.getX();
}

double Line::getY() const
{
	return direction.getY();
}

double Line::getZ() const
{
	return direction.getZ();
}

double Line::getPointX() const
{
	return begin.getX();
}

double Line::getPointY() const
{
	return begin.getY();
}

double Line::getPointZ() const
{
	return begin.getZ();
}

Vector Line::getDirection()
{
	Vector vector(direction.getX(), direction.getY(), direction.getZ());
	return vector;
}

Vector* Line::getPerpendicularOfLine()
{
	
	double z = (-direction.getY() - direction.getX()) / direction.getZ();
	Vector* v = new Vector(1, 1, z);
	return v;
}

double Line::angle(Line& rhs)
{
	double dot = (this->direction) * (rhs.getDirection());
	double aMag = this->direction.getLength();
	double bMag = rhs.direction.getLength();
	double sum = dot / (aMag * bMag);
	
	return acos(sum);
}

std::istream& Line::ext(std::istream& in)
{
	std::cout << "Please enter first point" << std::endl;
	Point* point1 = new Point();
	std::cin >> *point1;
	std::cout << "Please enter second point" << std::endl;
	Point* point2 = new Point();
	std::cin >> *point2;

	Vector vector(*point1, *point2);
	this->begin = *point1;
	this->direction = vector;
	this->x = direction.getX();
	this->y = direction.getY();
	this->z = direction.getZ();

	delete point1;
	delete point2;
	return in;
}

std::ostream& Line::ins(std::ostream& out) const
{

	return out;
}

bool operator||(Line& lhs, Line& rhs)
{
	return lhs.getDirection().isParallel(rhs.getDirection());
}

bool operator==(const Line& lhs, const Line& rhs)
{
	if (lhs.getPointX() == rhs.getPointX() && lhs.getPointY() == rhs.getPointY() && lhs.getPointZ() == rhs.getPointZ()) {
		if (lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY() && lhs.getZ() == rhs.getZ()) return true;
	}
	return false;
}

bool operator|(Line& lhs, Line& rhs)
{
	return lhs.getDirection().isPerpendicular(rhs.getDirection());
	return false;
}

bool operator+(const Point& lhs, Line& rhs)
{
	double t = (lhs.getX() - rhs.getPointX()) / rhs.getDirection().getX();
	double _y = rhs.getPointY() + rhs.getDirection().getY() * t;
	double _z = rhs.getPointZ() + rhs.getDirection().getZ() * t;
	if (lhs.getY() == _y && lhs.getZ() == _z) return true;
	return false;
}
