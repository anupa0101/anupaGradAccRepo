#ifndef QUAD_H
#define QUAD_H

class Quadrilateral 
{
public:
	virtual double Area() = 0;	//Area is a PURE VIRTUAL function. It is NOT implemented in this class. 
								//"Area" is implemented only in its derived classes
};
#endif