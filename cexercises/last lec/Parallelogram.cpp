#include"Parallelogram.h"

Parallelogram::Parallelogram()
{
	width = height = 0;
}

Parallelogram::Parallelogram(double w, double h)
{
	width = w;
	height = h;
}
double Parallelogram::Area()
{
	double ar;

	ar = width*height;
	return ar;
}
