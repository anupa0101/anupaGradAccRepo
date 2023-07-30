#include"Marks.h"
#include<iostream>
#include<cstring>
using namespace std;

Marks::Marks()
{
	m_sub2 = m_sub1 = m_sub3 = 0;
}

void Marks::SetMarks(float a, float b, float c)
{
	m_sub1 = a;
	m_sub2 = b;
	m_sub3 = c;
}

void Marks::SetName(char nam[])
{
	strcpy(Name,nam);
}