#pragma once
#include <iostream>
#include <string.h>
using std:: ostream;
using std:: istream;

class Complex
{
	int re;
	int im;

public:
	Complex(void) {
		re = im = 0;
	}
	Complex(int _re, int _im = 0) {
		re = _re;
		im = _im;
	}

	friend ostream& operator<< (ostream &stream, Complex compl) {
		if ((!compl.re) &&(!compl.im)) stream << '0';
		else
		{
		if (compl.re) stream << compl.re;
		if (compl.im) {
			if (compl.im > 0)
				stream << " +" << "i" << compl.im;
			else
				stream << "-i" << compl.im;
		}
		}
		return stream;
	}
	friend istream &operator >> (istream &stream, Complex &compl) {
		char* str =  new char[10];
		char* p = 0;
		int i = 0;

		stream >> str;

		if (str[0] == 'i')
		{
			str[0] = '0';
			compl.re = 0;
			compl.im = atoi(str);
			return stream;
		}

		if ((str[1] == 'i') && (str[0] == '-'))
		{
			str[0] = '0';
			str[1] = '0';
			compl.re = 0;
			compl.im = -atoi(str);
			return stream;
		}


		p = strchr(str, 'i');
		if (!p)
		{
			compl.re = atoi(str);
			compl.im = 0;
			return stream;
		}

		
		char *z1, *z2, *T;
		z1 = strtok(str, "+i");
		z2 = strtok(NULL, "+i");
		T = strrchr(z1, '-');
		if (T && (T != z1)) 
		{
			compl.im = -atoi(z2);
			*T = '\0';
		}
		else
			compl.im = atoi(z2);
		compl.re = atoi(z1);
		return stream;
	}

	Complex operator+ (const Complex& ob2) {
		Complex res;
		res.re = this->re + ob2.re;
		res.im = this->im + ob2.im;
		return res;
	}
	Complex operator- (const Complex& ob2) {
		Complex res;
		res.re = this->re - ob2.re;
		res.im = this->im - ob2.im;
		return res;
	}
	Complex operator* (const Complex& ob2) {
		Complex res;
		res.re = ((this->re * ob2.re) - (this->im * ob2.im));
		res.im = ((this->re * ob2.im) + (this->im * ob2.re));
		return res;
	}
};
