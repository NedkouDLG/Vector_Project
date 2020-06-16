#include "Point.h"

Point::Point()// Default конструктор
{
	this->setX(0);
	this->setY(0);
	this->setZ(0);
}

Point::Point(double x, double y, double z) //Конструктор с параметри
{
	this->setX(x);
	this->setY(y);
	this->setZ(z);
}

Point::Point(const Point& rhs) // Копиращ конструктор
{
	this->setX(rhs.getX());
	this->setY(rhs.getY());
	this->setZ(rhs.getZ());
}

Point& Point::operator=(const Point& rhs) // Предифиниране на оператор =
{
	if (this != &rhs) {
		this->setX(rhs.getX());
		this->setY(rhs.getY());
		this->setZ(rhs.getZ());
	}
	return *this;
}

bool operator==(const Point& lhs, const Point& rhs)// Предефиниране на оператор ==, която проверява дали две точки съвпадат
{
	if (lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY() && lhs.getZ() == rhs.getZ()) {
		return true;
	}else 
		return false;
}

Point::~Point()//Деструктор
{

}

std::istream& Point::ext(std::istream& in) //Въвеждане на точка чрез оператор >>
{
	std::cout << "Please enter value x of point: ";
	in >> this->x;
	std::cout << "Please enter value y of point: ";
	in >> this->y;						  
	std::cout << "Please enter value z of point: ";
	in >> this->z;
	return in;
}

std::ostream& Point::ins(std::ostream& out) const //Извеждане на точка чрез оператор <<
{
	out << "(" << this->x << ", " << this->y << ", " << this->z << ")";
	return out;
}
