#include <iostream>
/*#include "Point.h"
#include "Vector.h"
#include "Line.h"
#include "Triangle.h"
#include "Segment.h"*/
#include "Interface.h"
#include <cmath>
#include <locale>
using namespace std;
int main() {
	//setlocale(LC_ALL, ".OCP");
	setlocale(LC_ALL, "bulgarian");
	/*SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//cout << "С бг" << endl;*/
	//setvbuf(stdout, nullptr, _IOFBF, 1000);
	/*Point point(2, 3, 1);
	Point point2(1, 2, 3);
	Point point3(3, 4, 2);
	Point point4(2, 3, 4);
	cout << (point == point2) << endl;
	cout << (point == point3) << endl;
	Vector vector(point, point2);
	Vector vector2(point3, point4);
	Line lineT(point, vector);
	Line lineM(point3, vector2);
	cout << vector.getX() << " " << vector.getY() << " " << vector.getZ() << " " << endl;
	cout << vector.getLength() << endl;
	cout << (vector.isParallel(vector2)) << endl;
	Vector sum = vector + vector2;
	cout << sum.getX() << " " << sum.getY() << " " << sum.getZ() << " " << endl;
	Vector b(6, 3, 2);
	Vector c(4, 9, 4);
	Vector a(2, 4, 6);
	cout << b(c, a) << endl;
	Vector u(10, 4, -1);
	Line line1(point,u);
	Vector perpendicular = line1.getPerpendicularOfLine();
	cout << perpendicular.getX() << " " << perpendicular.getY() << " " << perpendicular.getZ() << endl;
	Triangle triangle(point, point2,point3);
	cout << triangle.getX() << endl;
	Vector n(1, 0, 3);
	Vector m(5, 5, 0);
	Line li(point3, m);//n
	Line li2(point3, m);
	cout << li.angle(li2) << endl;
	cout << (lineT || lineM) << endl;
	cout << (li == li2) << endl;
	Point t1(2,3,5), t2(2,3,5), t3(3,5,-2);
	try
	{
		Triangle newTriangle(t1, t2, t3);
		cout << newTriangle.getPerimeter() << endl;
		cout << newTriangle.getAreaOfTriangle() << endl;
		newTriangle.coutType();
	}
	catch (const EqualPointException& exception)
	{
		cout << "An equal point exception occured: " << exception.what() << endl;
	}
	

	
	/*Point checker(1.25, 3.59, 1.89);
	Point newChecker(1, 4, 0);
	cout << (checker < newTriangle) << endl;
	cout << (newChecker == newTriangle) << endl;
	Point aaa(3, 5, 6);
	Point bbb(-1, 2, 3);
	Point ddd(4, 5.75, 6.75);
	Line lllline(bbb, aaa);
	cout << (ddd + lllline) << endl;
	Point aa(2, 1, 0);
	Point bb(5, 0, 1);
	Segment seg(aa, bb);
	Segment* segp = new Segment(aa, bb);
	cout << seg.getLenght() << endl;
	cout << seg.getMiddle().getX() << " " << seg.getMiddle().getY() << " " << seg.getMiddle().getZ() << endl;*/
	/*Vector* r = new Vector();
	std::cin >> (*r);
	Vector* v1 = new Vector(2, 3, 4);
	Vector* v2 = new Vector(1, 1, 1);
	Vector* result = new Vector();
	(*result) = (*v1) + (*v2);
	cout << (*result) << endl;
	delete v1;
	delete v2;
	delete result;*/
	//Line line;
	vector<double> d;
	double n = 2.14;
	int m = 5;
	d.push_back(n);
	d.push_back((double)m);
	ofstream file("output.txt");
	for (double s : d) {
		file << s;
		//file << "\n";
	}
	file.close();
	Interface* inter = new Interface();
	inter->execute();
	delete inter;
	return 0;
}