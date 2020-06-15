#include "Triangle.h"
#include <iostream>
#include <cmath>
#include "Vector.h"
bool Triangle::isInPlane(const Point& rhs)
{
	Vector ab(a, b);
	Vector ac(a, c);
	Vector n = ab ^ ac;
	double d = n.getX() * a.getX() + n.getY() * a.getY() + n.getZ() * a.getZ();
	double checker = n.getX() * rhs.getX() + n.getY() * rhs.getY() + n.getZ() * rhs.getZ();
	if (checker == d)return true;
	return false;
}
Triangle::Triangle()
{
}

Triangle::Triangle(Point _a, Point _b, Point _c)
{
	if (_a == _b) {
		throw EqualPointException("Points A and B");
	}
	if (_a == _c) {
		throw EqualPointException("Points A and C");
	}if (_b == _c) {
		throw EqualPointException("Points B and C");
	}
	this->a = _a;
	this->b = _b;
	this->c = _c;
	x = _c.getX();
	y = _c.getY();
	z = _c.getZ();
}

Triangle::Triangle(const Triangle& rhs)
{
	this->a = rhs.a;
	this->b = rhs.b;
	this->c = rhs.c;
	x = rhs.c.getX();
	y = rhs.c.getY();
	z = rhs.c.getZ();
}

Triangle::~Triangle()
{
}

Triangle& Triangle::operator=(const Triangle& rhs)
{
	if (this != &rhs) {
		this->a = rhs.a;
		this->b = rhs.b;
		this->c = rhs.c;
		x = rhs.c.getX();
		y = rhs.c.getY();
		z = rhs.c.getZ();
	}
	return *this;
}

double Triangle::getPerimeter()const
{
	double ab = sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2) + pow(b.getZ() - a.getZ(), 2));
	double bc = sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2) + pow(c.getZ() - b.getZ(), 2));
	double ac = sqrt(pow(c.getX() - a.getX(), 2) + pow(c.getY() - a.getY(), 2) + pow(c.getZ() - a.getZ(), 2));
	return ab+bc+ac;
}

Point Triangle::getMedicenter()const
{
	double _x = (a.getX() + b.getX() + c.getX()) / 3;
	double _y = (a.getY() + b.getY() + c.getY()) / 3;
	double _z = (a.getZ() + b.getZ() + c.getY()) / 3;
	Point m(_x, _y, _z);
	return m;
}

double Triangle::getAreaOfTriangle()const
{
	double ab = sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2) + pow(b.getZ() - a.getZ(), 2));
	double bc = sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2) + pow(c.getZ() - b.getZ(), 2));
	double ac = sqrt(pow(c.getX() - a.getX(), 2) + pow(c.getY() - a.getY(), 2) + pow(c.getZ() - a.getZ(), 2));
	double p = (ab+bc+ac)/2;
	double S = sqrt(p * (p - bc) * (p - ac) * (p - ab));
	return S;
}

void Triangle::coutType() const
{
	double ab = sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2) + pow(b.getZ() - a.getZ(), 2));
	double bc = sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2) + pow(c.getZ() - b.getZ(), 2));
	double ac = sqrt(pow(c.getX() - a.getX(), 2) + pow(c.getY() - a.getY(), 2) + pow(c.getZ() - a.getZ(), 2));
	if (bc == ac || bc == ab || ac == ab) std::cout << "The triangle is isosceles " << std::endl;
	if (ac == bc == ab) std::cout << "The triangle is equilateral " << std::endl;
	if (pow(ac, 2) + pow(bc, 2) == pow(ab, 2))std::cout << "The triangle is right-angled " << std::endl;
	if (pow(ac, 2) + pow(bc, 2) > pow(ab, 2))std::cout << "The triangle is acute ";
	if (pow(ac, 2) + pow(bc, 2) < pow(ab, 2))std::cout << "The triangle is obtuse " << std::endl;
	
}

std::istream& Triangle::ext(std::istream& in)
{
	std::cout << "Enter point A" << std::endl;
	Point* p1 = new Point();
	std::cin >> *p1;
	std::cout << "Enter point B" << std::endl;
	Point* p2 = new Point();
	std::cin >> *p2;
	std::cout << "Enter point D" << std::endl;
	Point* p3 = new Point();
	std::cin >> *p3;
	if (*p1 == *p2) {
		throw EqualPointException("Points A and B");
	}
	if (*p1 == *p3) {
		throw EqualPointException("Points A and C");
	}if (*p2 == *p3) {
		throw EqualPointException("Points B and C");
	}
	this->a = *p1;
	this->b = *p2;
	this->c = *p3;
	x = p3->getX();
	y = p3->getY();
	z = p3->getZ();
	/*delete p1;
	delete p2;
	delete p3;*/
	return in;
}

std::ostream& Triangle::ins(std::ostream& out) const
{
	return out;
}

bool operator<(const Point& lhs, Triangle& rhs)
{
	if (!rhs.isInPlane(lhs)) return false;
	double S = rhs.getAreaOfTriangle();
	Triangle triangle1(rhs.a, rhs.c, lhs);
	double s1 = triangle1.getAreaOfTriangle();
	Triangle triangle2(rhs.b, rhs.c, lhs);
	double s2 = triangle2.getAreaOfTriangle();
	Triangle triangle3(rhs.a, rhs.b, lhs);
	double s3 = triangle3.getAreaOfTriangle();
	s3 += s1 + s2;
	if (abs(S - s3) < 1e-9)return true;
	return false;
}

bool operator>(const Point& lhs , Triangle& rhs)
{
	if (!rhs.isInPlane(lhs)) return false;
	double S = rhs.getAreaOfTriangle();
	Triangle triangle1(rhs.a, rhs.c, lhs);
	double s1 = triangle1.getAreaOfTriangle();
	Triangle triangle2(rhs.b, rhs.c, lhs);
	double s2 = triangle2.getAreaOfTriangle();
	Triangle triangle3(rhs.a, rhs.b, lhs);
	double s3 = triangle3.getAreaOfTriangle();
	s3 += s1 + s2;
	if (s3 > S)return true;
	return false;
	
}

bool operator==(const Point& lhs, Triangle& rhs)
{
	if (!rhs.isInPlane(lhs)) return false;
	double S = rhs.getAreaOfTriangle();
	Triangle triangle1(rhs.a, rhs.c, lhs);
	double s1 = triangle1.getAreaOfTriangle();
	Triangle triangle2(rhs.b, rhs.c, lhs);
	double s2 = triangle2.getAreaOfTriangle();
	Triangle triangle3(rhs.a, rhs.b, lhs);
	double s3 = triangle3.getAreaOfTriangle();
	if (s1 == 0 || s2 == 0 || s3 == 0)return true;
	return false;
}
