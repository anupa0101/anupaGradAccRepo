#include"Results.h"
#include<iostream>
#include<iomanip>

using namespace std;

void Results::SetResult()
{
	float avg = (m_sub1 + m_sub2 + m_sub3 )/3 ; 
	if( (m_sub1 < 30 ) || (m_sub2  < 30) || (m_sub3 < 30) || (avg <50))
	{
		Result ='F'; 
	}
	else
		Result ='P';
}

void Results::PrintResults()
{
	SetResult();
	cout<<left<<setw(25)<<Name<<Result;
}