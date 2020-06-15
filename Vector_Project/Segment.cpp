#include "Segment.h"
#include "Segment.h"

Segment::Segment()
{
}

Segment::Segment(const Point& a, const Point& b)
{
	this->a = new Point(a);
	this->b = new Point(b);
	Line* line = new Line(a, b);
	Vector direction = line->getDirection();
	tStart = (a.getX() - a.getX()) / direction.getX();
	tEnd = (b.getX() - a.getX()) / direction.getX();
	delete line;
	
}

Segment::Segment(const Segment& rhs)
{
	tStart = rhs.tStart;
	tEnd = rhs.tEnd;
	a = rhs.a;
	b = rhs.b;
}

Segment& Segment::operator=(const Segment& rhs)
{
	if (this != &rhs) {
		tStart = rhs.tStart;
		tEnd = rhs.tEnd;
		a = rhs.a;
		b = rhs.b;
	}
	return *this;
	// TODO: insert return statement here
}

Segment::~Segment()
{
	delete a;
	delete b;
}

double Segment::getLenght() const
{
	Vector* vec = new Vector((*a), (*b));
	return vec->getLength();
}

Point Segment::getMiddle()
{
	double _x = (a->getX() + b->getX()) / 2;
	double _y = (a->getY() + b->getY()) / 2;
	double _z = (a->getZ() + b->getZ()) / 2;
	return Point(_x,_y,_z);
}

std::istream& Segment::ext(std::istream& in)
{
	Point* a = new Point();
	Point* b = new Point();
	std::cout << "Enter begin point" << std::endl;
	std::cin >> *a;
	std::cout << "Enter end point" << std::endl;
	std::cin >> *b;
	this->a = a;
	this->b = b;
	Line* line = new Line(*a, *b);
	Vector direction = line->getDirection();
	tStart = (a->getX() - a->getX()) / direction.getX();
	tEnd = (b->getX() - a->getX()) / direction.getX();
	delete line;
	return in;
}

std::ostream& Segment::ins(std::ostream& out) const
{
	return out;
}

bool operator==(const Point& point, Segment& line)
{
	//double t1 = (point.getX()-line.)
	return false;
}
