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

bool Point::operator==(const Point& rhs)
{
	if (this->getX() == rhs.getX() && this->getY() == rhs.getY() && this->getZ() == rhs.getZ()) {
		return true;
	}else 
		return false;
}

Point::~Point()
{

}
