#pragma once
class Element
{
protected:
	double x;
	double y;
	double z;
public:
	void setX(double);
	void setY(double);
	void setZ(double);
	double getX() const;
	double getY() const;
	double getZ() const;
};

