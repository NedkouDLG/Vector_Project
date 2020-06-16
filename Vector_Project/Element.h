#pragma once
#include<iostream>
class Element //���������� ����
{
protected:
	double x;
	double y;
	double z;
	// x y z �� ����� ������������ �� ������������ ������
	// �� �� protected �� �� ����� �� ����� ������ �� 
	// ������������ � ������������� �� �������
public:
	// get-��� � set-��� �� x y z
	void setX(double);
	void setY(double);
	void setZ(double);
	// �� �� ��������� ��� ���� ����� ������� ���� ��������
	// ������� �� ��������� �� ����������
	virtual double getX() const;
	virtual double getY() const;
	virtual double getZ() const;

	// ��������� �������, ����� �� ������������ �� ������
	// ����������� ������� �� �� �� ������� ��� ������� 
	// �������� ����� ��� ������
	virtual std::ostream& ins(std::ostream&) const;
	virtual std::istream& ext(std::istream&);
};
// ������������� �� ����������� << � >> ��������� ��
// ��������� � ��������� �� ����� 
std::ostream& operator<<(std::ostream&, const Element&);
std::istream& operator>>(std::istream&, Element&);
