#include "Vector.h"
#include <cmath>
Vector::Vector()// Default конструктор
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector::Vector(const double& x, const double& y, const double& z)// Конструктор с параметри х y z
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector::Vector(const Point& a, const Point& b)//Конструктор с параметри две точки
{
	this->x = b.getX() - a.getX();
	this->y = b.getY() - a.getY();
	this->z = b.getZ() - a.getZ();
}

Vector::Vector(const Vector& rhs)//Копиращ конструктор
{
	this->x = rhs.getX();
	this->y = rhs.getY();
	this->z = rhs.getZ();
}

Vector& Vector::operator=(const Vector& rhs)//Предифиниране на опрератор =
{
	if (this != &rhs) {
		this->x = rhs.getX();
		this->y = rhs.getY();
		this->z = rhs.getZ();
	}
	return *this;
}

Vector::~Vector()// Деструктор
{
}
//Предифиниране на оператор +
//Функцията събира два вектора и връща вектор
Vector operator+(const Vector& lhs, const Vector& rhs)
{
	Vector newVector;
	newVector.setX(lhs.getX() + rhs.getX());
	newVector.setY(lhs.getY() + rhs.getY());
	newVector.setZ(lhs.getZ() + rhs.getZ());
	return newVector;
}
//Предифиниране на оператор -
//Функцията изважда два вектора и връща вектор
Vector operator-(const Vector& lhs, const Vector& rhs)
{
	Vector newVector;
	newVector.setX(lhs.getX() - rhs.getX());
	newVector.setY(lhs.getY() - rhs.getY());
	newVector.setZ(lhs.getZ() - rhs.getZ());
	return newVector;
}
//Предифиниране на оператор ^
//Функцията прави векторно произведение на два вектора и връща вектор
Vector operator^(const Vector& lhs, const Vector& rhs)
{
	Vector newVector;
	newVector.setX(lhs.getY()*rhs.getZ() - lhs.getZ()*rhs.getY());
	newVector.setY(lhs.getZ()*rhs.getX() - lhs.getX()*rhs.getZ());
	newVector.setZ(lhs.getX()*rhs.getY() - lhs.getY()*rhs.getX());
	return newVector;
}
//Предифиниране на оператор *
//Функцията умножава реално чисто с вектор и връща вектор
Vector operator*(const double& r, const Vector& rhs)
{
	Vector newVector;
	newVector.setX(rhs.getX() * r);
	newVector.setY(rhs.getY() * r);
	newVector.setZ(rhs.getZ() * r);
	return newVector;
}
//Предифиниране на оператор *
//Функцията прави скаларно произведение на два вектора и връща реално число
double operator*(const Vector& lhs, const Vector& rhs)
{
	double sum = lhs.getX() * rhs.getX() + lhs.getY() * rhs.getY() + lhs.getZ() * rhs.getZ();
	return sum;
}
//Предифиниране на оператор ()
//Функцията прави смесено произведение на 3 вектора и връща реално число
double Vector::operator()(const Vector& lhs, const Vector& rhs)
{
	Vector uv = *this ^ lhs;
	double sum = uv * rhs;
	return sum;
}

//Функцията връща дължината на вектора
double Vector::getLength() const
{
	double len = (double)sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	return len;
}
//Функцията връща посоката  на вектора
Vector Vector::getDirection()
{
	if (this->getLength() == 0) {
		throw VectorLengthException(); //Хвърля се изключение ако дължината е 0
		return Vector(0,0,0);
	}
	Vector newVector;
	newVector.setX(this->x / this->getLength());
	newVector.setY(this->y / this->getLength());
	newVector.setZ(this->z / this->getLength());
	return newVector;
}
// Функция за проверка дали вектора е нулев
bool Vector::isZero() const
{
	if (x == y == z == 0) 
		return true;
	else
		return false;
}
//Функция за проверка дали два вектора са успоредни
bool Vector::isParallel(const Vector& rhs)
{
	if (this->getLength() == 0 || rhs.getLength() == 0) {
		throw VectorLengthException(); //Хвърля се изключение ако единия от двата вектора е нулев
	}
	double check1 = this->x / rhs.getX();
	double check2 = this->y / rhs.getY();
	double check3 = this->z / rhs.getZ();
	if (check1 == check2 == check3) return true; //Трябва двата вектора да са в едно и също съотношение
	else return false;
}
//Функция за проверка дали два вектора са перпендикулярни
bool Vector::isPerpendicular(const Vector& rhs)
{
	if (this->getLength() == 0 || rhs.getLength() == 0) {
		throw VectorLengthException();//Хвърля се изключение ако единия от двата вектора е нулев
	}
	double check1 = this->x * rhs.getX();
	double check2 = this->y * rhs.getY();
	double check3 = this->z * rhs.getZ();
	double sum = check1 + check2 + check3;
	if (sum == 0) return true;
	else return false;
}
//Въвеждане на вектор чрез оператор >>
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
//Извеждане на вектор чрез оператор <<
std::ostream& Vector::ins(std::ostream& out) const
{
	out << "(" << this->x << ", " << this->y << ", " << this->z << ")";
	return out;
}
