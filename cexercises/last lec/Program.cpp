#include"A.h"
#include"B.h"
#include<iostream>
#include<conio.h>

using namespace std;

void main()
{
	A *pA;
	B objB, *pB;

	pA=new B;
	cout<<"\nBase class pointer is pointed at a derived class object\n";
	pA->Show();
	pA->Test();
	cout<<"\n\n";

	delete pA;
	pB = &objB;
	cout<<"\nDerived class pointer is pointed at a derived class object\n";
	pB->Show();
	
	cout<<"\n\n";

	_getch();
}
