#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
protected:
	double A[3][3];
public:
	Matrix();
	Matrix(double [3][3]);
	Matrix operator+(Matrix);
	Matrix operator-(Matrix);
	friend Matrix operator*(double, Matrix);
	friend Matrix operator*(Matrix, double);
	void operator*= (double); 
	void Print();
};

#endif 