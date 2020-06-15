#include "Interface.h"

int Interface::readObject()
{
	std::ifstream file("file.txt", std::ios::in);
	if (!file) {
		std::cout << "There was error! Cannot open file! Please check path!" << std::endl;
		return 0;
	}
	int n = 0;
	file >> n;
	//std::cout << n << std::endl;
	switch (n)
	{
	case 1:
		readPoint(file);
		break;
	case 2:
		readVector(file);
		break;
	case 3:
		readLine(file);
		break;
	case 4:
		readSegment(file);
		break;
	case 5:
		readTriangle(file);
		break;

	}
	file.close();
}

int Interface::readPoint(std::ifstream& file)
{
	double x = 0.0, y = 0.0, z = 0.0;
	file >> x;
	file >> y;
	file >> z;
	int n;
	file >> n;
	//std::cout << x << " " << y << " " << z << std::endl;
	Point* point = new Point(x, y, z);
	switch (n)
	{
	case 1:
		checkTwoPointsCoincide(point,file);
		break;
	}

	delete point;
	return 0;
}

int Interface::readVector(std::ifstream& file)
{
	double x = 0.0, y = 0.0, z = 0.0;
	file >> x;
	file >> y;
	file >> z;
	int n;
	file >> n;
	Vector* vector = new Vector(x, y, z);
	switch (n)
	{
	case 1:
		std::cout << "The length of vector is " << vector->getLength() << std::endl;
		break;
	case 2:
		std::cout << "The direction of vector is " << vector->getDirection() << std::endl;
		break;
	case 3:
		if (vector->isZero())
			std::cout << "The vector is zero" << std::endl;
		else std::cout << "The vector is not zero" << std::endl;
		break;
	case 4:
		checkVectorForParallel(vector, file);
		break;
	case 5:
		checkVectorForPerpendicular(vector,file);
		break;
	case 6:
		addTwoVectors(vector,file);
		break;
	case 7:
		multiplicationNumVec(vector,file);
		break;
	case 8:
		scalarMultiplication(vector,file);
		break;
	case 9:
		vectorMultiplication(vector,file);
		break;
	case 10:
		mixedMultiplication(vector,file);
		break;
	}
	delete vector;
	return 0;
}

int Interface::readLine(std::ifstream& file)
{
	double x = 0.0, y = 0.0, z = 0.0;
	file >> x >> y >> z;
	Point p1(x, y, z);
	char ch;
	file >> ch;
	file >> x >> y >> z;
	Point p2(x, y, z);
	Line* line = new Line(p1, p2);
	int n;
	file >> n;
	switch (n)
	{
	case 1:
		findDirectionOfLine(line);
		break;
	case 2:
		findNormalVector(line);
		break;
	case 3:
		findAngleBetweenLines(line, file);
		break;
	case 4:
		isPointOnLine(line, file);
		break;
	case 5:
		isLineParallelWithLine(line, file);
		break;
	case 6:
		isLineMatchLine(line, file);
		break;
	case 7:
		isLinePerpendicularToLine(line, file);
		break;
	}
	
	delete line;
	return 0;
}

int Interface::readSegment(std::ifstream& file)
{
	double x = 0.0, y = 0.0, z = 0.0;
	file >> x >> y >> z;
	Point p1(x, y, z);
	char ch;
	file >> ch;
	file >> x >> y >> z;
	Point p2(x, y, z);
	Segment* segment = new Segment(p1, p2);
	int n = 0;
	file >> n;
	switch (n)
	{
	case 1:
		findLengthOfSegment(segment);
		break;
	case 2:
		findCenterOfSegment(segment);
		break;
	}
	delete segment;
	return 0;
}

int Interface::readTriangle(std::ifstream& file)
{
	double x = 0.0, y = 0.0, z = 0.0;
	file >> x >> y >> z;
	char ch;
	file >> ch;
	Point p1(x, y, z);
	file >> x >> y >> z;
	file >> ch;
	Point p2(x, y, z);
	file >> ch;
	file >> x >> y >> z;
	Point p3(x, y, z);
	Triangle* triangle = new Triangle();
	try {
		triangle = new Triangle(p1, p2, p3);
	}
	catch (EqualPointException& exception) {
		std::cout << "An equal point exception occured: " << exception.what() << std::endl;
	}
	int n = 0;
	file >> n;
	switch (n)
	{
	case 1:
		defineType(triangle);
		break;
	case 2:
		findArea(triangle);
		break;
	case 3:
		findPerimeter(triangle);
		break;
	case 4:
		findMedicenter(triangle);
		break;
	case 5:
		checkPointIsIn(triangle, file);
		break;
	case 6:
		checkPointIsOut(triangle, file);
		break;
	case 7:
		checkPointLiesSide(triangle, file);
		break;
	}
	return 0;
}

int Interface::mainMenu()
{
	std::cout << "Please choose type of geometric object:" << std::endl;
	std::cout << "	1 - Point" << std::endl;
	std::cout << "	2 - Vector" << std::endl;
	std::cout << "	3 - Line" << std::endl;
	std::cout << "	4 - Segment" << std::endl;
	std::cout << "	5 - Triangle" << std::endl;
	std::cout << "0 - Go Back" << std::endl;
	std::ifstream file;
	Point* point = nullptr;
	Vector* vector = nullptr;
	Line* line = nullptr;
	Segment* segment = nullptr;
	Triangle* triangle = nullptr;
	int n;
	std::cin >> n;
	switch (n)
	{
	case 1:
		while (menuPoint(point,file) != 0);
		break;
	case 2:
		while (menuVector(vector, file) != 0);
		break;
	case 3:
		while (menuLine(line,file) != 0);
		break;
	case 4:
		while(menuSegment(segment)!=0);
		break;
	case 5:
		while (menuTriangle(triangle,file) != 0);
		break;
	
	}
	delete point;
	delete vector;
	delete line;
	delete segment;
	delete triangle;
	return n;
}

int Interface::menuPoint(Point*& point, std::ifstream& file)
{
	if (point == nullptr) {
		point = new Point();
		std::cin >> *point;
	}
	std::cout << "Please choose operation for the object:" << std::endl;
	std::cout << "	1 - check if two points coincide " << std::endl;
	std::cout << "0 - Go Back" << std::endl;
	int n;
	std::cin >> n;
	switch (n)
	{
	case 1:
		checkTwoPointsCoincide(point,file);
		break;
	}
	
	return n;
}

int Interface::menuVector(Vector*& vector, std::ifstream& file)
{
	if (vector == nullptr) {
		vector = new Vector();
		std::cin >> (*vector);
	}
	std::cout << "Please choose operation for the object:" << std::endl;
	std::cout << "	1 - calculate length of vector" << std::endl;
	std::cout << "	2 - calculate direction of vector" << std::endl;
	std::cout << "	3 - check for zero vector" << std::endl;
	std::cout << "	4 - check for parallelism of two vectors" << std::endl;
	std::cout << "	5 - check for perpendicularity of two vectors" << std::endl;
	std::cout << "	6 - summation of two vectors" << std::endl;
	std::cout << "	7 - multiplication of vector with real number" << std::endl;
	std::cout << "	8 - scalar product of two vectors" << std::endl;
	std::cout << "	9 - vector product of two vectors" << std::endl;
	std::cout << "	10 - mixed product of three vectors" << std::endl;
	std::cout << "0 - Go Back" << std::endl;
	int n;
	std::cin >> n;
	switch (n)
	{
	case 1:
		std::cout << "The length of vector is " << vector->getLength() << std::endl;
		break;
	case 2:
		std::cout << "The direction of vector is " << vector->getDirection() << std::endl;
		
		break;
	case 3:
		if (vector->isZero())
			std::cout << "The vector is zero" << std::endl;
		else std::cout << "The vector is not zero" << std::endl;
		break;
	case 4:
		checkVectorForParallel(vector,file);
		break;
	case 5:
		checkVectorForPerpendicular(vector,file);
		break;
	case 6:
		addTwoVectors(vector,file);
		break;
	case 7:
		multiplicationNumVec(vector,file);
		break;
	case 8:
		scalarMultiplication(vector,file);
		break;
	case 9:
		vectorMultiplication(vector,file);
		break;
	case 10:
		mixedMultiplication(vector,file);
		break;
	}
	
	return n;
}

int Interface::menuLine(Line*& line, std::ifstream& file)
{
	if (line == nullptr) {
		line = new Line();
		std::cin >> (*line);
	}
	std::cout << "Please choose operation for the object:" << std::endl;
	std::cout << "	1 - Find direction of line" << std::endl;
	std::cout << "	2 - Find normal vector" << std::endl;
	std::cout << "	3 - Find angle between two lines" << std::endl;
	std::cout << "	4 - Is point on line" << std::endl;
	std::cout << "	5 - Is line parallel with another line" << std::endl;
	std::cout << "	6 - Is line match another line" << std::endl;
	std::cout << "	7 - Is line perpendicullar to other line" << std::endl;
	std::cout << "0 - Go Back" << std::endl;
	int n;
	std::cin >> n;
	switch (n)
	{
		case 1:
		findDirectionOfLine(line);
		break;
	case 2:
		findNormalVector(line);
		break;
	case 3:
		findAngleBetweenLines(line,file);
		break;
	case 4:
		isPointOnLine(line,file);
		break;
	case 5:
		isLineParallelWithLine(line,file);
		break;
	case 6:
		isLineMatchLine(line,file);
		break;
	case 7:
		isLinePerpendicularToLine(line,file);
		break;
	}

	
	
	return n;
}

int Interface::menuSegment(Segment*& segment)
{
	if (segment == nullptr) {
		segment = new Segment();
		std::cin >> *segment;
	}
	std::cout << "Please choose operation for the object:" << std::endl;
	std::cout << "	1 - Find length of segment" << std::endl;
	std::cout << "	2 - Find center of segment" << std::endl;
	std::cout << "0 - Go Back" << std::endl;
	int n;
	std::cin >> n;
	switch (n)
	{
	case 1:
		findLengthOfSegment(segment);
		break;
	case 2:
		findCenterOfSegment(segment);
		break;
	}
	
	return n;
}

int Interface::menuTriangle(Triangle*& triangle, std::ifstream& file)
{
	if(triangle==nullptr)
		try
		{
			triangle = new Triangle();
			std::cin >> *triangle;
		}
		catch (const EqualPointException& exception)
		{
			std::cout << "An equal point exception occured: " << exception.what() << std::endl;
			//triangle = new Triangle();
		}
	
	std::cout << "Please choose operation for the object:" << std::endl;
	std::cout << "	1 - Define type of triangle" << std::endl;
	std::cout << "	2 - Find area of triangle" << std::endl;
	std::cout << "	3 - find perimeter of triangle" << std::endl;
	std::cout << "	4 - Find medicenter of triangle" << std::endl;	
	std::cout << "	5 - Check point is inside the triangle" << std::endl;
	std::cout << "	6 - Check point is outside the triangle" << std::endl;
	std::cout << "	7 - Check point lies on the side of triangle" << std::endl;
	std::cout << "0 - Go Back" << std::endl;
	int n;
	std::cin >> n;
	switch (n)
	{
	case 1:
		defineType(triangle);
		break;
	case 2:
		findArea(triangle);
		break;
	case 3:
		findPerimeter(triangle);
		break;
	case 4:
		findMedicenter(triangle);
		break;
	case 5:
		checkPointIsIn(triangle,file);
		break;
	case 6:
		checkPointIsOut(triangle,file);
		break;
	case 7:
		checkPointLiesSide(triangle,file);
		break;
	}
	
	return n;
}

void Interface::checkTwoPointsCoincide(Point*& rhs, std::ifstream& file)
{
	Point* point = new Point();
	if (file.peek() == std::ifstream::traits_type::eof())
		std::cin >> *point;
	else {
		double x = 0.0, y = 0.0, z = 0.0;
		file >> x >> y >> z;
		point->setX(x);
		point->setY(y);
		point->setZ(z);
	}
	if (*rhs == *point)
		std::cout << *rhs << " match with " << *point << std::endl;
	else std::cout << *rhs << " do not match with " << *point << std::endl;
	delete point;
}

void Interface::checkVectorForParallel(Vector*& rhs, std::ifstream& file)
{
	Vector* vector = new Vector();
	if (file.peek() == std::ifstream::traits_type::eof()) {
		std::cin >> (*vector);
	}
	else {
		double x = 0.0, y = 0.0, z = 0.0;
		file >> x >> y >> z;
		vector->setX(x);
		vector->setY(y);
		vector->setZ(z);
	}
	if (rhs->isParallel(*vector)) {
		std::cout << "The two vectors are parallel" << std::endl;
	}else std::cout << "The two vectors are not parallel" << std::endl;
	delete vector;
}

void Interface::checkVectorForPerpendicular(Vector*& rhs, std::ifstream& file)
{

	Vector* vector = new Vector();
	if (file.peek() == std::ifstream::traits_type::eof()) {
		std::cin >> (*vector);
	}
	else {
		double x = 0.0, y = 0.0, z = 0.0;
		file >> x >> y >> z;
		vector->setX(x);
		vector->setY(y);
		vector->setZ(z);
	}
	if (rhs->isPerpendicular(*vector)) {
		std::cout << "The two vectors are perpendicular" << std::endl;
	}
	else std::cout << "The two vectors are not perpendicular" << std::endl;
	delete vector;
}

void Interface::addTwoVectors(Vector*& rhs, std::ifstream& file)
{

	Vector* vector = new Vector();
	if (file.peek() == std::ifstream::traits_type::eof()) {
		std::cin >> (*vector);
	}
	else {
		double x = 0.0, y = 0.0, z = 0.0;
		file >> x >> y >> z;
		vector->setX(x);
		vector->setY(y);
		vector->setZ(z);
	}
	Vector* result = new Vector();
	(*result) = (*rhs) + (*vector);
	std::cout << (*result) << " = " << (*rhs) << " + " << (*vector) << std::endl;
	delete vector;
	delete result;
}

void Interface::multiplicationNumVec(Vector*& rhs, std::ifstream& file)
{
	double number = 0.0;
	if (file.peek() == std::ifstream::traits_type::eof()) {
		std::cout << "Please enter number: ";
		std::cin >> number;
	}
	else {
		file >> number;
	}
	Vector* result = new Vector();
	(*result) = number * (*rhs);
	std::cout << (*result) << " = " << number << " * " << (*rhs) << std::endl;
}

void Interface::scalarMultiplication(Vector*& rhs, std::ifstream& file)
{
	Vector* vector = new Vector();
	if (file.peek() == std::ifstream::traits_type::eof()) {
		std::cin >> (*vector);
	}
	else {
		double x = 0.0, y = 0.0, z = 0.0;
		file >> x >> y >> z;
		vector->setX(x);
		vector->setY(y);
		vector->setZ(z);
	}
	double result = (*rhs) * (*vector);
	std::cout << result << " = " << (*rhs) << " * " << (*vector) << std::endl;
	delete vector;
}

void Interface::vectorMultiplication(Vector*& rhs, std::ifstream& file)
{
	Vector* vector = new Vector();
	if (file.peek() == std::ifstream::traits_type::eof()) {
		std::cin >> (*vector);
	}
	else {
		double x = 0.0, y = 0.0, z = 0.0;
		file >> x >> y >> z;
		vector->setX(x);
		vector->setY(y);
		vector->setZ(z);
	}
	Vector* result = new Vector();
	(*result) = (*rhs) ^ (*vector);
	std::cout << (*result) << " = " << (*rhs) << " ^ " << (*vector) << std::endl;
	delete vector;
	delete result;
}

void Interface::mixedMultiplication(Vector*& rhs, std::ifstream& file)
{
	Vector* vec1 = new Vector();
	Vector* vec2 = new Vector();
	if (file.peek() == std::ifstream::traits_type::eof()) {
		std::cin >> (*vec1);
		std::cin >> (*vec2);
	}
	else {
		double x = 0.0, y = 0.0, z = 0.0;
		file >> x >> y >> z;
		vec1->setX(x);
		vec1->setY(y);
		vec1->setZ(z);
		char ch;
		file >> ch;
		file >> x >> y >> z;
		vec2->setX(x);
		vec2->setY(y);
		vec2->setZ(z);
	}
	double result = *rhs*((*vec1), *vec2);
	std::cout << result << " = (" << (*rhs) << " x " << (*vec1) << ") . " << (*vec2) << std::endl;
	delete vec1;
	delete vec2;
}

void Interface::findDirectionOfLine(Line*& rhs)
{
	try
	{
		Vector res = rhs->getDirection();
		std::cout << "Direction of line is " << res << std::endl;
	}
	catch (const VectorLengthException& exc)
	{
		std::cout << exc.what() << std::endl;
	}
}

void Interface::findNormalVector(Line*& rhs)
{
	std::cout << "Normal vector is " << *rhs->getPerpendicularOfLine() << std::endl;
}

void Interface::findAngleBetweenLines(Line*& rhs, std::ifstream& file)
{
	Line* line = new Line();
	if (file.peek() == std::ifstream::traits_type::eof())
		std::cin >> *line;
	else {
		double x = 0.0, y = 0.0, z = 0.0;
		file >> x >> y >> z;
		Point p1(x, y, z);
		char ch;
		file >> ch;
		file >> x >> y >> z;
		Point p2(x, y, z);
		line = new Line(p1, p2);
	}
	double res = rhs->angle(*line);
	std::cout << "Angle between the two lines is " << std::setprecision(2) << res << std::endl;
	delete line;
}

void Interface::isPointOnLine(Line*& rhs, std::ifstream& file)
{
	Point* point = new Point();
	if (file.peek() == std::ifstream::traits_type::eof())
		std::cin >> *point;
	else {
		double x = 0.0, y = 0.0, z = 0.0;
		file >> x >> y >> z;
		point->setX(x);
		point->setY(y);
		point->setZ(z);
	}
	bool flag = *point + *rhs;
	if (flag)
		std::cout << "Point " << *point << " lies on the line" << std::endl;
	else
		std::cout << "Point " << *point << " does not lie on the line" << std::endl;
	delete point;
}

void Interface::isLineParallelWithLine(Line*& rhs, std::ifstream& file)
{
	Line* line = new Line();
	if (file.peek() == std::ifstream::traits_type::eof())
		std::cin >> *line;
	else {
		double x = 0.0, y = 0.0, z = 0.0;
		file >> x >> y >> z;
		Point p1(x, y, z);
		char ch;
		file >> ch;
		file >> x >> y >> z;
		Point p2(x, y, z);
		line = new Line(p1, p2);
	}
	bool flag = *rhs || *line;
	if (flag)
		std::cout << "Lines are parallel" << std::endl;
	else
		std::cout << "Lines are not parallel" << std::endl;
	delete line;
}

void Interface::isLineMatchLine(Line*& rhs, std::ifstream& file)
{
	Line* line = new Line();
	if (file.peek() == std::ifstream::traits_type::eof())
		std::cin >> *line;
	else {
		double x = 0.0, y = 0.0, z = 0.0;
		file >> x >> y >> z;
		Point p1(x, y, z);
		char ch;
		file >> ch;
		file >> x >> y >> z;
		Point p2(x, y, z);
		line = new Line(p1, p2);
	}
	bool flag = *rhs == *line;
	if (flag)
		std::cout << "Lines are mathcing" << std::endl;
	else
		std::cout << "Lines are not matching" << std::endl;
	delete line;
}

void Interface::isLinePerpendicularToLine(Line*& rhs, std::ifstream& file)
{
	Line *line = new Line();
	if (file.peek() == std::ifstream::traits_type::eof())
		std::cin >> *line;
	else {
		double x = 0.0, y = 0.0, z = 0.0;
		file >> x >> y >> z;
		Point p1(x, y, z);
		char ch;
		file >> ch;
		file >> x >> y >> z;
		Point p2(x, y, z);
		line = new Line(p1, p2);
	}
	bool flag = (*rhs) | (*line);
	if (flag)
		std::cout << "Lines are perpendicular" << std::endl;
	else
		std::cout << "Lines are not perpendicular" << std::endl;
	delete line;
}

void Interface::findLengthOfSegment(Segment*& rhs)
{
	double res = rhs->getLenght();
	std::cout << "The length of segment is" << std::setprecision(2) << res << std::endl;
}

void Interface::findCenterOfSegment(Segment*& rhs)
{
	Point point = rhs->getMiddle();
	std::cout << "The center of segment is " << point << std::endl;
}

void Interface::defineType(Triangle*& rhs)
{
	rhs->coutType();
}

void Interface::findArea(Triangle*& rhs)
{
	double area = rhs->getAreaOfTriangle();
	std::cout << "The area of traingle is " << area << std::endl;
}

void Interface::findPerimeter(Triangle*& rhs)
{
	double p = rhs->getPerimeter();
	std::cout << "The perimeter of triangle is " << p << std::endl;
}

void Interface::findMedicenter(Triangle*& rhs)
{
	Point p = rhs->getMedicenter();
	std::cout << "The medicenter of triangle is " << p << std::endl;
}

void Interface::checkPointIsIn(Triangle*& rhs, std::ifstream& file)
{
	Point* p = new Point();
	if (file.peek() == std::ifstream::traits_type::eof())
		std::cin >> *p;
	else {
		double x = 0.0, y = 0.0, z = 0.0;
		file >> x >> y >> z;
		p->setX(x);
		p->setY(y);
		p->setZ(z);
	}
	if (*p < *rhs) std::cout << "The point is inside triangle" << std::endl;
	else std::cout << "The point is not inside triangle" << std::endl;
	delete p;
}

void Interface::checkPointIsOut(Triangle*& rhs, std::ifstream& file)
{
	Point* p = new Point();
	if (file.peek() == std::ifstream::traits_type::eof())
		std::cin >> *p;
	else {
		double x = 0.0, y = 0.0, z = 0.0;
		file >> x >> y >> z;
		p->setX(x);
		p->setY(y);
		p->setZ(z);
	}
	if (*p > *rhs) std::cout << "The point is outside triangle" << std::endl;
	else std::cout << "The point is not outside triangle" << std::endl;
	delete p;
}

void Interface::checkPointLiesSide(Triangle*& rhs, std::ifstream& file)
{
	Point* p = new Point();
	if (file.peek() == std::ifstream::traits_type::eof())
		std::cin >> *p;
	else {
		double x = 0.0, y = 0.0, z = 0.0;
		file >> x >> y >> z;
		p->setX(x);
		p->setY(y);
		p->setZ(z);
	}
	if (*p == * rhs) std::cout << "The point lies on side of triangle" << std::endl;
	else std::cout << "The point does not lie on side of triangle" << std::endl;
	delete p;

}

Interface::Interface()
{
}

Interface::~Interface()
{
}

void Interface::execute()
{
	while (1) {
		std::cout << "Choose how to execute" << std::endl;
		std::cout << "1 - Execute from file" << std::endl;
		std::cout << "2 - Execute from console" << std::endl;
		std::cout << "0 - Exit" << std::endl;
		int n;
		std::cin >> n;
		if (n == 1) readObject();
		else if (n == 2) while (mainMenu() != 0);
		else if (n == 0) break;
	}
}
