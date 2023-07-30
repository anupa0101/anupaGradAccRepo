#ifndef MARKS_H
#define MARKS_H

class Marks
{
protected:
	float m_sub1, m_sub2, m_sub3;  //Holds the marks of 3 subjects
	char Name[20]; //Hold the name of the student

public:
	Marks();  // Default constructor initialize all marks to ZERO
	void SetMarks(float, float, float); // Sets the marks of 3 subjects in the order as defined
	void SetName(char[]);  //Sets the name
};

#endif