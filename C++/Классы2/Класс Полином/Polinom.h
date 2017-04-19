#include "Plist.h"
class Polinom
{
	Plist P;
public:
	Polinom();
	Polinom(const Polinom&);
	~Polinom();
	Polinom& operator =(Polinom& X);
	friend Polinom operator *(Polinom& X, const node& Y);
	friend Polinom operator +(Polinom& X, Polinom& Y);
	friend Polinom operator -(Polinom& X, Polinom& Y);
	friend Polinom operator *(Polinom& X, Polinom& Y);
	friend istream& operator >>(istream& in, Polinom& X);
	friend ostream& operator <<(ostream& out, Polinom& X);
};