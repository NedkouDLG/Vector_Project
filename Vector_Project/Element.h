#pragma once
#include<iostream>
class Element //абстрактен клас
{
protected:
	double x;
	double y;
	double z;
	// x y z ще бъдат координатите на триизмерните обекти
	// Те са protected за да могат да бъдат видими от 
	// приятелските и наследяващите го класове
public:
	// get-ъри и set-ъри за x y z
	void setX(double);
	void setY(double);
	void setZ(double);
	// Те са виртуални тъй като някои класове имат различно
	// вземане на стойности за променлите
	virtual double getX() const;
	virtual double getY() const;
	virtual double getZ() const;

	// Виртуални функции, които се предефинират от всички
	// наследяващи класове за да се изведат или въведат 
	// правилно всеки тип обекти
	virtual std::ostream& ins(std::ostream&) const;
	virtual std::istream& ext(std::istream&);
};
// Предефиниране на операторите << и >> съответно за
// извеждане и въвеждане на обект 
std::ostream& operator<<(std::ostream&, const Element&);
std::istream& operator>>(std::istream&, Element&);
