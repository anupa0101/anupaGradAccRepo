#include"Matrix.h"
#include<iostream>
using namespace std;

Matrix::Matrix()
{
	for(int i = 0 ; i<3; i++)
	{
		for(int j=0 ; j<3 ; j++)
		{
			A[i][j] = 0;
		}
	}
}
Matrix::Matrix(double Ary[3][3])
{
	for(int i = 0 ; i<3; i++)
	{
		for(int j=0 ; j<3 ; j++)
		{
			A[i][j] = Ary[i][j];
		}
	}
}

Matrix Matrix::operator+(Matrix a)
{
	Matrix sum;
	for(int i = 0 ; i<3; i++)
	{
		for(int j=0 ; j<3 ; j++)
		{
			sum.A[i][j] = A[i][j] + a.A[i][j];
		}
	}
	return sum;
}
Matrix Matrix::operator-(Matrix a)
{
	Matrix sub;
	for(int i = 0 ; i<3; i++)
	{
		for(int j=0 ; j<3 ; j++)
		{
			sub.A[i][j] = A[i][j] - a.A[i][j];
		}
	}
	return sub;
}

Matrix operator*(double a, Matrix m)
{
	Matrix mulp;
	for(int i = 0 ; i<3; i++)
	{
		for(int j=0 ; j<3 ; j++)
		{
			mulp.A[i][j] =  m.A[i][j]*a;
		}
	}
	return mulp;
}

Matrix operator*(Matrix m ,double a)
{
	Matrix mulp;
	for(int i = 0 ; i<3; i++)
	{
		for(int j=0 ; j<3 ; j++)
		{
			mulp.A[i][j] =  m.A[i][j]*a;
		}
	}
	return mulp;
}



void Matrix::Print()
{
	for(int i = 0 ; i<3; i++)
	{
		cout<<"\n";
		for(int j=0 ; j<3 ; j++)
		{
			cout<<A[i][j]<<"\t";
		}
	}
}

void Matrix::operator*=(double a)
{
	for(int i = 0 ; i<3; i++)
	{
		for(int j=0 ; j<3 ; j++)
		{
			A[i][j] =  A[i][j]*a;
		}
	}
}
