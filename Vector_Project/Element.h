#pragma once
class Element
{
protected:
	int x;
	int y;
	int z;
public:
	void setX(int);
	void setY(int);
	void setZ(int);
	int getX() const;
	int getY() const;
	int getZ() const;
};

