#include "Vector.h"
#include <cmath>
Vector::Vector():baseX(0),baseY(0),baseZ(0)
{
}

Vector::Vector(double x, double y, double z)
{
	this->baseX = x;
	this->baseY = y;
	this->baseZ = z;
}

Vector::Vector(Point a, Point b)
{
	this->baseX = b.getX() - a.getX();
	this->baseY = b.getY() - a.getY();
	this->baseZ = b.getZ() - a.getZ();
}

Vector::Vector(const Vector& rhs)
{
	this->baseX = rhs.getBaseX();
	this->baseY = rhs.getBaseY();
	this->baseZ = rhs.getBaseZ();
}

Vector& Vector::operator=(const Vector& rhs)
{
	if (this != &rhs) {
		this->baseX = rhs.getBaseX();
		this->baseY = rhs.getBaseY();
		this->baseZ = rhs.getBaseZ();
	}
	return *this;
}

Vector::~Vector()
{
}

Vector Vector::operator+(const Vector& rhs)
{
	Vector newVector;
	newVector.setBaseX(this->getBaseX() + rhs.getBaseX());
	newVector.setBaseY(this->getBaseY() + rhs.getBaseY());
	newVector.setBaseZ(this->getBaseZ() + rhs.getBaseZ());
	return newVector;
}

Vector Vector::operator-(const Vector& rhs)
{
	Vector newVector;
	newVector.setBaseX(this->getBaseX() - rhs.getBaseX());
	newVector.setBaseY(this->getBaseY() - rhs.getBaseY());
	newVector.setBaseZ(this->getBaseZ() - rhs.getBaseZ());
	return newVector;
}

Vector Vector::operator^(const Vector& rhs)
{
	Vector newVector;
	newVector.setBaseX(this->getBaseY()*rhs.getBaseZ() - this->getBaseZ()*rhs.getBaseY());
	newVector.setBaseY(this->getBaseZ()*rhs.getBaseX() - this->getBaseX()*rhs.getBaseZ());
	newVector.setBaseZ(this->getBaseX()*rhs.getBaseY() - this->getBaseY()*rhs.getBaseX());
	return newVector;
}

Vector Vector::operator*(const double& r)
{
	Vector newVector;
	newVector.setBaseX(this->getBaseX() * r);
	newVector.setBaseY(this->getBaseY() * r);
	newVector.setBaseZ(this->getBaseZ() * r);
	return newVector;
}

double Vector::operator*(const Vector& rhs)
{
	double sum = this->getBaseX() * rhs.getBaseX() + this->getBaseY() * rhs.getBaseY() + this->getBaseZ() * rhs.getBaseZ();
	return sum;
}

double Vector::operator()(const Vector& lhs, const Vector& rhs)
{
	Vector uv = *this ^ lhs;
	double sum = uv * rhs;
	return sum;
}

double Vector::getBaseX() const
{
	return baseX;
}

double Vector::getBaseY() const
{
	return baseY;
}

double Vector::getBaseZ() const
{
	return baseZ;
}

double Vector::getLength() const
{
	double len = (double)sqrt(pow(baseX, 2) + pow(baseY, 2) + pow(baseZ, 2));
	return len;
}

void Vector::setBaseX(double x)
{
	this->baseX = x;
}

void Vector::setBaseY(double y)
{
	this->baseY = y;
}

void Vector::setBaseZ(double z)
{
	this->baseZ = z;
}

bool Vector::isZero() const
{
	if (baseX == baseY == baseZ == 0)
		return true;
	else
		return false;
}

bool Vector::isParallel(const Vector& rhs) const
{
	double check1 = this->baseX / rhs.getBaseX();
	double check2 = this->baseY / rhs.getBaseY();
	double check3 = this->baseZ / rhs.getBaseZ();
	if (check1 == check2 == check3) return true;
	else return false;
}

bool Vector::isPerpendicular(const Vector& rhs) const
{
	double check1 = this->baseX * rhs.getBaseX();
	double check2 = this->baseY * rhs.getBaseY();
	double check3 = this->baseZ * rhs.getBaseZ();
	double sum = check1 + check2 + check3;
	if (sum == 0) return true;
	else return false;
}
