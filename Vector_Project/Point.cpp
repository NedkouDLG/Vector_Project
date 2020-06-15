#include "Point.h"

Point::Point()
{
	this->setX(0);
	this->setY(0);
	this->setZ(0);
}

Point::Point(double x, double y, double z)
{
	this->setX(x);
	this->setY(y);
	this->setZ(z);
}

Point::Point(const Point& rhs)
{
	this->setX(rhs.getX());
	this->setY(rhs.getY());
	this->setZ(rhs.getZ());
}

Point& Point::operator=(const Point& rhs)
{
	if (this != &rhs) {
		this->setX(rhs.getX());
		this->setY(rhs.getY());
		this->setZ(rhs.getZ());
	}
	return *this;
}

bool operator==(const Point& lhs, const Point& rhs)
{
	if (lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY() && lhs.getZ() == rhs.getZ()) {
		return true;
	}else 
		return false;
}

Point::~Point()
{

}

void Point::setX(double _x)
{
	this->x = _x;
}

void Point::setY(double _y)
{
	this->y = _y;
}

void Point::setZ(double _z)
{
	this->z = _z;
}

std::istream& Point::ext(std::istream& in)
{
	std::cout << "Please enter value x of point: ";
	in >> this->x;
	std::cout << "Please enter value y of point: ";
	in >> this->y;						  
	std::cout << "Please enter value z of point: ";
	in >> this->z;
	return in;
}

std::ostream& Point::ins(std::ostream& out) const
{
	out << "(" << this->x << ", " << this->y << ", " << this->z << ")";
	return out;
}
