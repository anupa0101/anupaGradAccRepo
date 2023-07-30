#ifndef PARALLEL_H
#define PARALLEL_H
#include"Quadrilateral.h"

class Parallelogram : public Quadrilateral
{
protected:
	double width, height;
public:
	Parallelogram();
	Parallelogram(double wi, double he);
	double Area();
};
#endif

