#include"Quadrilateral.h"
#include"Parallelogram.h"
#include"Trapezoid.h"
#include<iostream>
#include<conio.h>

using namespace std;

void main()
{
	Quadrilateral *pQad;
	pQad = new Parallelogram(4,5);

	cout<<"\n\nArea of the Parallegram is  "<<pQad->Area();
	delete pQad;

	pQad = new Trapezoid(2, 3, 5 );
	cout<<"\n\nArea of the Trapezoid is  "<<pQad->Area();

	delete pQad;
	_getch();
}