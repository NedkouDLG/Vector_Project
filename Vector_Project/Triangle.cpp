#include "Triangle.h"
#include <iostream>
#include <cmath>
#include "Vector.h"
//Проверка на точка дали е в равнината на триъгълника
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
Triangle::Triangle() //Default конструктор
{
}

Triangle::Triangle(Point _a, Point _b, Point _c)// Конструктор с параметри три точки
{
	//Проверка дали някои от точките не съвпадат, ако съвпадат се хвърля изключение
	//и пише кои две съвпадат
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

Triangle::Triangle(const Triangle& rhs)//Копиращ конструктор
{
	this->a = rhs.a;
	this->b = rhs.b;
	this->c = rhs.c;
	x = rhs.c.getX();
	y = rhs.c.getY();
	z = rhs.c.getZ();
}

Triangle::~Triangle()//Деструктор
{
}

Triangle& Triangle::operator=(const Triangle& rhs)//Предифиниране на оператор =
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
//Функция изчисляваща периметъра на триъгълника
double Triangle::getPerimeter()const
{
	double ab = sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2) + pow(b.getZ() - a.getZ(), 2));
	double bc = sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2) + pow(c.getZ() - b.getZ(), 2));
	double ac = sqrt(pow(c.getX() - a.getX(), 2) + pow(c.getY() - a.getY(), 2) + pow(c.getZ() - a.getZ(), 2));
	return ab+bc+ac;
}
//Функция, която връща медицентъра на триъгълника
Point Triangle::getMedicenter()const
{
	double _x = (a.getX() + b.getX() + c.getX()) / 3;
	double _y = (a.getY() + b.getY() + c.getY()) / 3;
	double _z = (a.getZ() + b.getZ() + c.getY()) / 3;
	Point m(_x, _y, _z);
	return m;
}
//Функция, която изчислява лицето на триъгълника
double Triangle::getAreaOfTriangle()const
{
	double ab = sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2) + pow(b.getZ() - a.getZ(), 2));
	double bc = sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2) + pow(c.getZ() - b.getZ(), 2));
	double ac = sqrt(pow(c.getX() - a.getX(), 2) + pow(c.getY() - a.getY(), 2) + pow(c.getZ() - a.getZ(), 2));
	double p = (ab+bc+ac)/2;
	double S = sqrt(p * (p - bc) * (p - ac) * (p - ab));
	return S;
}
//Функция, която отпечатва вида на триъгълника
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
//Въвеждане на триъгълник чрез >>
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
//Извеждане нямаме, но е нужно да се създаде функцията тъй като тази функция е virtual
//и трябва да присъства във всички класове наследяващи Element
std::ostream& Triangle::ins(std::ostream& out) const
{
	return out;
}
//Проверка дали точката лежи във вътрещността на триъгълника
bool operator<(const Point& lhs, Triangle& rhs)
{
	if (!rhs.isInPlane(lhs)) return false;//Проверява се дали са в една и съща равнина
	//Намира се лицето на триъгълника
	double S = rhs.getAreaOfTriangle();
	Triangle triangle1(rhs.a, rhs.c, lhs);
	//Намира се лицето на триъгълник с точки А С и точката която се проверява дали е вътрешна
	double s1 = triangle1.getAreaOfTriangle();
	Triangle triangle2(rhs.b, rhs.c, lhs);
	//Намира се лицето на триъгълник с точки B С и точката която се проверява дали е вътрешна
	double s2 = triangle2.getAreaOfTriangle();
	Triangle triangle3(rhs.a, rhs.b, lhs);
	//Намира се лицето на триъгълник с точки А B и точката която се проверява дали е вътрешна
	double s3 = triangle3.getAreaOfTriangle();
	s3 += s1 + s2;
	//Събират се последните 3 лица и ако те са с лице равно на лицето на големия триъгълник,
	//тогава точка е вътре в триъгълника
	if (abs(S - s3) < 1e-9)return true;
	return false;
}
//Проверка дали точката лежи извън вътрещността на триъгълника, но в неговата равнина
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
	//Функцията е същата като за проеврката дали точката лежи във вътрешността на триъгъглника
	//само че тук ако сбора на трите лица е по-голям от лицето на основния триъгълник точката 
	//е външна за триъгълника
	if (s3 > S)return true;
	return false;
	
}
//Проверка дали точката лежи на някоя страна на триъгълника
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
	//Тук отново се смятат 3те лица и ако едно от тях е равно на 0 означава, 
	//че точката лежи върху една от страните
	if (s1 == 0 || s2 == 0 || s3 == 0)return true;
	return false;
}
