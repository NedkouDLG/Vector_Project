#pragma once
#include "Point.h"
#include "VectorLengthException.h"
class Vector:public Point
{
public:
	// �������� 5 + ��� ���� ���������� �� ���������
	Vector();
	Vector(const double&, const double&, const double&);
	Vector(const Point&, const Point&);
	Vector(const Vector&);
	Vector& operator =(const Vector&);
	~Vector();

	//�������� ������������ �� ������
	double operator ()(const Vector&, const Vector&);
	//������� �� �������
	double getLength() const;
	//��������� ������� �� ������ �� �������, ��� ���� � ������������ ���� Line
	//���� �� ���� ������, �� �� ������� � ��������� ������ ����� ������
	virtual Vector getDirection();

	bool isZero() const;
	bool isParallel(const Vector&);
	bool isPerpendicular(const Vector&);

	//������������� �� ���������� �� ��������� � ��������� �� ����� Vector
	virtual std::istream& ext(std::istream&);
	virtual std::ostream& ins(std::ostream&) const;
};

Vector operator +(const Vector&, const Vector&);
Vector operator -(const Vector&, const Vector&);
Vector operator ^(const Vector&, const Vector&);
Vector operator *(const double&, const Vector&);
double operator *(const Vector&, const Vector&);