/*#include <iostream>
struct BadDimensions {};
struct BadFirstIndex {};
struct BadSecondIndex {};

class int_array
{

	class row
	{
		friend class int_array;
		int *first_cell_in_row;
		row (int *p, int_array &c1):first_cell-in_row(p), c(c1) {}
		int_array &c;
	public:
		int &operator[](int index);
	};

	int nrows;
	int ncols;
	int *the_array;
public:
	virtual	~int_array(void);
	int_array(int rows, int cols);
	row operator[] (int index);

int_array::int_array(int rows,int cols):nrows(rows), ncols(cols), the_array(new int[rows * cols]) {}
int_array::~int_array(void)
{
	delete []the_array;
}

inline int_array::row int_array::operator[] (int index)
{
	if (index < 0 || index >= nrows) throw BadFirstIndex;
	return row(the_array + (ncols * index, *this);
}
inline int &int_array::row::operator [](int index)
{
	if (index < 0 || index >= c.ncols) throw BadSecondIndex;
	return first_cell_in_row[index];
}
int_array& operator *=(const int_array& A) // результат - матрица  nrows x A.ncols, старая удаляется
{
	int *p = new int[nrows * A.ncolls];
	for (int i = 0; i < nrows; i++)
	{
		for (int j = 0; j < A.ncols; j++)
		{
			int summ = 0; 
			for (int k = 0; k < ncols; k++)
				Summ += the_array[i * ncols + k] * A[k][j];
		}
		p[i * A.ncols + j] = summ;
	}
	delete []the_array;
	the_array = p;
	return *this;
}

friend int_array operator* (const int_array &A, cons int_array &B)
{
	int_array C(A.rows, B.cols);
	...
	return c;
}
};*/