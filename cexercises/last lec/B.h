#ifndef B_H
#define B_H
#include"A.h"

class B : public A
{
protected:
	int b;
public:
	B();
	void Show();   // Overriding the base class's Show function
	void Print();
};

#endif