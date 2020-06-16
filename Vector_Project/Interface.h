#pragma once
#include "Triangle.h"
#include "Segment.h"
#include <fstream>
#include <iomanip>
#include <vector>
class Interface
{
private:
	std::vector<double> stream;


	int readObject();
	int readPoint(std::ifstream&);
	int readVector(std::ifstream&);
	int readLine(std::ifstream&);
	int readSegment(std::ifstream&);
	int readTriangle(std::ifstream&);

	int mainMenu();
	int menuPoint(Point*&, std::ifstream&);
	int menuVector(Vector*&, std::ifstream&);
	int menuLine(Line*&, std::ifstream&);
	int menuSegment(Segment*&);
	int menuTriangle(Triangle*&, std::ifstream&);

	void checkTwoPointsCoincide(Point*&, std::ifstream&);

	void checkVectorForParallel(Vector*&, std::ifstream&);
	void checkVectorForPerpendicular(Vector*&, std::ifstream&);
	void addTwoVectors(Vector*&, std::ifstream&);
	void multiplicationNumVec(Vector*&, std::ifstream&);
	void scalarMultiplication(Vector*&, std::ifstream&);
	void vectorMultiplication(Vector*&, std::ifstream&);
	void mixedMultiplication(Vector*&, std::ifstream&);

	void findDirectionOfLine(Line*&);
	void findNormalVector(Line*&);
	void findAngleBetweenLines(Line*&, std::ifstream&);
	void isPointOnLine(Line*&, std::ifstream&);
	void isLineParallelWithLine(Line*&, std::ifstream&);
	void isLineMatchLine(Line*&, std::ifstream&);
	void isLinePerpendicularToLine(Line*&, std::ifstream&);


	void findLengthOfSegment(Segment*&);
	void findCenterOfSegment(Segment*&);

	void defineType(Triangle*&);
	void findArea(Triangle*&);
	void findPerimeter(Triangle*&);
	void findMedicenter(Triangle*&);
	void checkPointIsIn(Triangle*&, std::ifstream&);
	void checkPointIsOut(Triangle*&, std::ifstream&);
	void checkPointLiesSide(Triangle*&, std::ifstream&);
public:
	Interface();
	Interface(std::vector<double>);
	Interface(const Interface&);
	Interface& operator=(const Interface&);
	~Interface();
	void execute();
};

