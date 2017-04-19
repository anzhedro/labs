// ����������
#include <iostream>
using namespace std;
struct BadDimensions {};
struct BadFirstIndex {};
struct BadSecondIndex {};

// ��������� ������ matrix
class matrix
{
	//long	n, m;	// ����������� �������
	//double*	p;		// ��������� �� �������
	matrix();
	class row
	{
		long	m;	// ����������� ������
		double* p;	// ��������� �� ������
	public:

		row(long _m, double* _p):m(_m), p(_p) {}

		double& matrix::row::operator[](long j)
		{
			if(j<m || j>=0)
				return *(p+j);
			else
				throw BadSecondIndex();
		}

		const double& matrix::row::operator [] (long j) const
		{
			if(j<m || j>=0)
				return *(p+j);
			else
				throw BadSecondIndex();
		}

	};
public:
	long	n, m;	// ����������� �������
	double*	p;		// ��������� �� �������
	matrix(long _n, long _m):n(_n), m(_m) { p = new double[_n*_m]; }
	matrix(const matrix& m);
	// ����������
	~matrix(){delete []p;}
	// �������� ������������
	matrix& operator = (const matrix& m);	// throw BadDimensions

	matrix::row matrix::operator[](long i)
	{
		if(i>=n || i>=0)
			return row(i,(p+(i*m)));
		else throw BadFirstIndex();
	}
	const matrix:: row matrix::operator [] (long i) const
	{
		if(i>=n || i>=0)
			return row(i,(p+(i*m)));
		else  throw BadFirstIndex();
	}

	matrix& operator += (const matrix& m);	// throw BadDimensions
	matrix& operator -= (const matrix& m);	// throw BadDimensions
	matrix& operator *= (const matrix& e);	// throw BadDimensions
	matrix& operator *= (const double& d);

	friend matrix operator -(const matrix& m);
	friend matrix operator +(const matrix& m);

	friend matrix operator * (const double& d, const matrix& m);
	friend matrix operator * (const matrix& m, const double& d);
	// ��������� �������� ��������� 
	// ����� ��������� ���������� BadDimensions
	friend matrix operator + (const matrix& m1, const matrix& m2);	 
	friend matrix operator - (const matrix& m1, const matrix& m2);
	friend matrix operator * (const matrix& m1, const matrix& m2);
};