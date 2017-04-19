#include "Polinom.h"
Polinom::Polinom(): P() {}
Polinom::Polinom(const Polinom &X): P(X.P) {}
Polinom::~Polinom(){}
Polinom operator*(Polinom& X, const node& Y)
{
	Polinom A1(X);
	node *t;
	t = A1.P.get_head();
	while (t)
	{
		t->coeff = t->coeff * Y.coeff;
		t->deg = t->deg + Y.deg;
		t = t->next;
	}
	return A1;
}
Polinom operator-(Polinom& X, Polinom& Y)
{
	Polinom Z(Y);
	node* t;
	t = Z.P.get_head();
	while (t)
	{
		t->coeff = -(t->coeff);
		t = t->next;
	} 
	Polinom X1;
	X1 = X + Z;
	return X1;
}

Polinom operator+(Polinom& X, Polinom& Y)
{
	Polinom A1;
	node *t = X.P.get_head();
	node *t1 = Y.P.get_head();
	while (t != NULL && t1 != NULL)
	{
		if (t->deg > t1->deg)
		{
			node *t2 = new node(t->coeff, t->deg);
			A1.P.pushback(*t2);
			t = t->next;
		}
		else
		{
			if (t->deg < t1->deg)
			{
				node *t2 = new node(t1->coeff, t1->deg);
				A1.P.pushback(*t2);
				t1 = t1->next;
			}
			else
			{
				node *t2 = new node(t1->coeff+t->coeff, t1->deg);
				A1.P.pushback(*t2);
				t = t->next;
				t1 = t1->next;
			}
		}
	}
	while (t != NULL)
	{
		A1.P.pushback(*t);
		t = t->next;
	}
	while (t1 != NULL)
	{
		A1.P.pushback(*t1);
		t1 = t1->next;
	}
	return A1;
}
Polinom operator*(Polinom& X, Polinom& Y)
{
	Polinom R;
	node *t = Y.P.get_head();
	while (t != NULL)
	{
		Polinom B;
		B = X*(*t);
		R = R+B;
		t = t->next;
	}
	return R;

}
ostream& operator << (ostream& out,  Polinom& R)
{
	node *temp;
	temp = R.P.get_head();
	int i = 0, j = 0;
	while (temp != NULL)
	{
		if (temp->coeff == 0) i++;
		j++;
		temp = temp->next;
	}
	temp = R.P.get_head();
	if (j == i) { cout << "0" << endl; return out;}
	while (temp != NULL)
	{
		if (temp->coeff != 0)
		{
			if (temp->deg != 0 && temp->deg != 1) cout << temp->coeff << "x^" << temp->deg;
			else
				if (temp->deg == 1) cout << temp->coeff << "x";
				else
					cout << temp->coeff;
			if (temp->next != NULL)
			{
				if (temp->coeff > 0) cout << " + ";
			}
		}
		temp = temp->next;
	}
	cout << endl;
	return out;
}
istream& operator >> (istream& in, Polinom &R)
{
	int kol, cof, step;
	node *temp;
	temp = new node;
	cout << "¬ведите количество слагаемых в полиноме: ";
	in >> kol;
	for (int i = 0; i < kol; i++)
	{
		if (i == 2)
		{
			cout << "¬ведите 3-е слагаемое: ";
		}
		else
		{
			cout << "¬ведите " << i+1 << "-ое слагаемое: ";
		}
		cin >> cof >> step;
		temp->coeff = cof;
		temp->deg = step;
		temp->next = NULL;
		R.P.pushback(*temp);
	}	
	return in;
}
Polinom& Polinom::operator =(Polinom &X)
{
	if (this == &X)
		return *this;
	else
	{
		this->P = X.P;
		return *this;
	}
}