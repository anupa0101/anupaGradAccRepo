#include"Trapezoid.h"

Trapezoid::Trapezoid()
{
	side1 =  side2 = height = 0;
}

Trapezoid::Trapezoid(double x, double y, double h)
{
	side1 = x;
	side2 = y;
	height = h;
}

double Trapezoid::Area()
{
	double ar;
	ar = (side1 + side2)*0.5*height;

	return ar;
}
