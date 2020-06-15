#include "Vector.h"
#include <cmath>
Vector::Vector()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector::Vector(const double& x, const double& y, const double& z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector::Vector(const Point& a, const Point& b)
{
	this->x = b.getX() - a.getX();
	this->y = b.getY() - a.getY();
	this->z = b.getZ() - a.getZ();
}

Vector::Vector(const Vector& rhs)
{
	this->x = rhs.getX();
	this->y = rhs.getY();
	this->z = rhs.getZ();
}

Vector& Vector::operator=(const Vector& rhs)
{
	if (this != &rhs) {
		this->x = rhs.getX();
		this->y = rhs.getY();
		this->z = rhs.getZ();
	}
	return *this;
}

Vector::~Vector()
{
}

Vector operator+(const Vector& lhs, const Vector& rhs)
{
	Vector newVector;
	newVector.setX(lhs.getX() + rhs.getX());
	newVector.setY(lhs.getY() + rhs.getY());
	newVector.setZ(lhs.getZ() + rhs.getZ());
	return newVector;
}

Vector operator-(const Vector& lhs, const Vector& rhs)
{
	Vector newVector;
	newVector.setX(lhs.getX() - rhs.getX());
	newVector.setY(lhs.getY() - rhs.getY());
	newVector.setZ(lhs.getZ() - rhs.getZ());
	return newVector;
}

Vector operator^(const Vector& lhs, const Vector& rhs)
{
	Vector newVector;
	newVector.setX(lhs.getY()*rhs.getZ() - lhs.getZ()*rhs.getY());
	newVector.setY(lhs.getZ()*rhs.getX() - lhs.getX()*rhs.getZ());
	newVector.setZ(lhs.getX()*rhs.getY() - lhs.getY()*rhs.getX());
	return newVector;
}

Vector operator*(const double& r, const Vector& rhs)
{
	Vector newVector;
	newVector.setX(rhs.getX() * r);
	newVector.setY(rhs.getY() * r);
	newVector.setZ(rhs.getZ() * r);
	return newVector;
}

double operator*(const Vector& lhs, const Vector& rhs)
{
	double sum = lhs.getX() * rhs.getX() + lhs.getY() * rhs.getY() + lhs.getZ() * rhs.getZ();
	return sum;
}

double Vector::operator()(const Vector& lhs, const Vector& rhs)
{
	Vector uv = *this ^ lhs;
	double sum = uv * rhs;
	return sum;
}


double Vector::getLength() const
{
	double len = (double)sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	return len;
}

Vector Vector::getDirection()//return&
{
	if (this->getLength() == 0) {
		throw VectorLengthException();
		exit(1);
	}
	Vector newVector;
	newVector.setX(this->x / this->getLength());
	newVector.setY(this->y / this->getLength());
	newVector.setZ(this->z / this->getLength());
	return newVector;
}

void Vector::setX(double _x)
{
	this->x = _x;
}

void Vector::setY(double _y)
{
	this->y = _y;
}

void Vector::setZ(double _z)
{
	this->z = _z;
}



bool Vector::isZero() const
{
	if (x == y == z == 0)
		return true;
	else
		return false;
}

bool Vector::isParallel(const Vector& rhs)
{
	if (this->getLength() == 0 || rhs.getLength() == 0) {
		throw VectorLengthException();
		exit(1);
	}
	double check1 = this->x / rhs.getX();
	double check2 = this->y / rhs.getY();
	double check3 = this->z / rhs.getZ();
	if (check1 == check2 == check3) return true;
	else return false;
}

bool Vector::isPerpendicular(const Vector& rhs)
{
	if (this->getLength() == 0 || rhs.getLength() == 0) {
		throw VectorLengthException();
		exit(1);
	}
	double check1 = this->x * rhs.getX();
	double check2 = this->y * rhs.getY();
	double check3 = this->z * rhs.getZ();
	double sum = check1 + check2 + check3;
	if (sum == 0) return true;
	else return false;
}

std::istream& Vector::ext(std::istream& in)
{
	std::cout << "Please enter value x of vector: ";
	in >> this->x;
	std::cout << "Please enter value y of vector: ";
	in >> this->y;
	std::cout << "Please enter value z of vector: ";
	in >> this->z;
	return in;
}

std::ostream& Vector::ins(std::ostream& out) const
{
	out << "(" << this->x << ", " << this->y << ", " << this->z << ")";
	return out;
}
