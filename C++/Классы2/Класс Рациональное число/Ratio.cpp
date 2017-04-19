#include "Ratio.h";
void ratio::Reduce()
{    
	int i, min;
	if (abs(chis) > abs(znam)) 
		min = abs(znam);
	else
		min = abs(chis);
	for (i = min; i > 1; i--)
		if (chis  % i == 0 && znam % i == 0)
			break;
	if (i == 0) { cout << "!!!DIVIDE 0!!!\n"; exit(0);}
	if (chis == 0) znam = 1;
	chis /= i;
	znam /= i;
}

istream& operator>>(istream& in, ratio& r)
{
	in >> r.chis >> r.znam;
	return in;
}

ostream& operator<<(ostream& out, const ratio& r)
{
	if (r.chis == r.znam) { out << 1 << "\n"; return out;}
	if (r.chis == 0) { out << 0 << "\n"; return out;}
	if (r.znam == 1) { out << r.chis << "\n"; return out;}
	/*if (r.znam == 0) { out << "!!!DIVIDE 0!!!" << "\n"; return out;}*/
	out << r.chis << " / " << r.znam << "\n";
	return out;
}

ratio::ratio():chis(0), znam(0) {}

ratio::ratio(long n, long d):chis(n), znam(d) {}

ratio::ratio(const ratio& r)
{
	chis = r.chis;
	znam = r.znam;
}

ratio& ratio::operator = (const ratio& r)
{
	if (this == &r) return *this;
	chis = r.chis;
	znam = r.znam;
	return *this;
}

ratio& ratio::operator += (const ratio& r)
{
	if (znam == r.znam) 
		chis += r.chis;
	else
	{
		chis *= r.znam;
		int d = r.chis;
		d *= znam;
		chis += d;
		znam *= r.znam;
	}
	return *this;
}

ratio& ratio::operator -= (const ratio& r)
{
	if (znam == r.znam) 
		chis -= r.chis;
	else
	{
		chis *= r.znam;
		int d = r.chis;
		d *= znam;
		chis -= d ;
		znam *= r.znam;
	}
	return *this;
}

ratio& ratio::operator *= (const ratio& r)
{
	chis *= r.chis;
	znam *= r.znam;
	return *this;
}

ratio& ratio::operator /= (const ratio& r)
{
	chis *= r.znam;
	znam *= r.chis;
	return *this;
}
ratio operator -(const ratio& r)
{
	ratio r1(r);
	r1.chis = - r.chis;
	return r1;
}

ratio operator +(const ratio& r)
{
	ratio r1(r);
	r1.chis = abs(r.chis);
	return r1;
}

bool operator < (const ratio& r1, const ratio& r2)
{
	int a = r1.chis * r2.znam;
	int b = r2.chis * r1.znam;
	if (a < b) 
		return true;
	else 
		return false;
}

bool operator > (const ratio& r1, const ratio& r2)
{
	int a = r1.chis * r2.znam;
	int b = r2.chis * r1.znam;
	if (a > b) 
		return true;
	else 
		return false;
}

bool operator == (const ratio& r1, const ratio& r2)
{
	int a = r1.chis * r2.znam;
	int b = r2.chis * r1.znam;
	if (a == b) 
		return true;
	else 
		return false;
}

bool operator != (const ratio& r1, const ratio& r2)
{
	int a = r1.chis * r2.znam;
	int b = r2.chis * r1.znam;
	if (a != b) 
		return true;
	else 
		return false;
}

bool operator <= (const ratio& r1, const ratio& r2)
{
	int a = r1.chis * r2.znam;
	int b = r2.chis * r1.znam;
	if (a <= b) 
		return true;
	else 
		return false;
}

bool operator >= (const ratio& r1, const ratio& r2)
{
	int a = r1.chis * r2.znam;
	int b = r2.chis * r1.znam;
	if (a >= b) 
		return true;
	else 
		return false;
}

ratio operator + (const ratio& r1, const ratio& r2)
{
	ratio r;
	if (r1.znam == r2.znam) 
	{
		r.chis = r1.chis + r2.chis;
		r.znam = r1.znam;	
	}
	else
	{
		int a =	r1.chis * r2.znam;
		int b = r2.chis * r1.znam;
		r.chis = a + b;
		r.znam =r1.znam * r2.znam;
	}
	if (r.chis != 0) r.Reduce();

	return r;
}

ratio operator - (const ratio& r1, const ratio& r2)
{
	ratio r;
	if (r1.znam == r2.znam) 
	{
		r.chis = r1.chis - r2.chis;
		r.znam = r1.znam;	
	}
	else
	{
		int a =	r1.chis * r2.znam;
		int b = r2.chis * r1.znam;
		r.chis = a - b;
		r.znam =r1.znam * r2.znam;
	}
	if (r.chis != 0) r.Reduce();

	return r;
}

ratio operator / (const ratio& r1, const ratio& r2)
{
	ratio r;
	r.chis = r1.chis * r2.znam;
	r.znam = r2.chis * r1.znam;
	if (r.chis != 0) r.Reduce();

	return r;
}

ratio operator * (const ratio& r1, const ratio& r2)
{
	ratio r;
	r.chis = r1.chis * r2.chis;
	r.znam = r2.znam * r1.znam;
	if (r.chis != 0) r.Reduce();
	return r;
}

ratio::operator double(void) const
{
	double s = 0.0;
	s = (double)this->chis / (double)this->znam;
	return s;
}