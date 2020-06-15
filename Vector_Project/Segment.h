#pragma once
#include "Line.h"
class Segment:public Line
{
private:
	double tStart, tEnd;
	Point* a;
	Point* b;
public:
	Segment();
	Segment(const Point&, const Point&);
	Segment(const Segment&);
	Segment& operator=(const Segment&);
	~Segment();

	double getLenght() const;
	Point getMiddle();
	virtual std::istream& ext(std::istream&);
	virtual std::ostream& ins(std::ostream&) const;
	//double angle(const Line&) = delete;
};
bool operator==(const Point&, Segment&);