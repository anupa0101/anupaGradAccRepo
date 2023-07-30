#ifndef RESULTS_H
#define RESULTS_H
#include"Marks.h"

class Results : public Marks
{
private:
	char Result; //holds whether student is PASS or FAIL
	void SetResult();

public:
	void PrintResults(); //Prints the results

};

#endif