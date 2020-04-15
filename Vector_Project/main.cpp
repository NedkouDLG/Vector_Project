#include <iostream>
#include "Point.h"
#include "Vector.h"
using namespace std;
int main() {
	Point point(2, 3, 1);
	Point point2(1, 2, 3);
	Point point3(3, 4, 2);
	Point point4(2, 3, 4);
	cout << (point == point2) << endl;
	cout << (point == point3) << endl;
	Vector vector(point, point2);
	Vector vector2(point3, point4);
	cout << vector.getBaseX() << " " << vector.getBaseY() << " " << vector.getBaseZ() << " " << endl;
	cout << vector.getLength() << endl;
	cout << (vector.isParallel(vector2)) << endl;
	Vector sum = vector + vector2;
	cout << sum.getBaseX() << " " << sum.getBaseY() << " " << sum.getBaseZ() << " " << endl;
	Vector b(6, 3, 2);
	Vector c(4, 9, 4);
	Vector a(2, 4, 6);
	cout << b(c, a) << endl;
	return 0;
}