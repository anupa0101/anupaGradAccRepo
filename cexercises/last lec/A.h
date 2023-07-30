#ifndef A_H
#define A_H

class A
{
protected:
	int a;
public:
	A();
	virtual void Show() = 0; // Pure Virtual Function 
	void Test();
};

#endif
