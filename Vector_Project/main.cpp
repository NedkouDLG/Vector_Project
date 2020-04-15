#include <iostream>
#include "Point.h"
using namespace std;
int main() {
	Point point(2, 3, 1);
	Point point2(1, 2, 3);
	Point point3(2, 3, 1);
	cout << (point == point2) << endl;
	cout << (point == point3) << endl;

	return 0;
}