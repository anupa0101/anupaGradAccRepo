#include<iostream>
#include<conio.h>
#include"Results.h"

using namespace std;

int main()
{
	const int students = 3;
	char Names[students][20];

	Results Std[students];

	float Marks[3];

	for(int i = 0 ; i< students ; i++)
	{
		cout<<"\nEnter the name of student "<<i+1<<"\t";
		cin.getline(Names[i], 20);
		cout<<"\nMarks of "<<Names[i]<<"\n";
		for(int k = 0 ; k < 3 ; k++)
		{
			cout<<"Subject "<<k +1<<"\t";
			cin>>Marks[k];
		}
		Std[i].SetMarks(Marks[0], Marks[1], Marks[2]);
		Std[i].SetName(Names[i]);
		cout<<"\n\n";
		cin.ignore(); //This ignores the Enter key press of previous input. If not used, it takes the Enter key stroke as the input to next getline()
	}
	
	cout<<"\n\nExamination Results - (P - Pass , F - Fail)\n\n";
	for(int i = 0 ; i< students ; i++)
	{
		Std[i].PrintResults();
		cout<<"\n";
	}
	_getch();
}
