#ifndef TRAP_H
#define TRAP_H
#include"Quadrilateral.h"
class Trapezoid : public Quadrilateral
{
protected:
	double side1, side2, height;
public:
	Trapezoid();
	Trapezoid(double lengh_1, double length_2, double he);
	double Area();
};

#endif
