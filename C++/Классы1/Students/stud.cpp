#include "stud.h"
istream& operator>>(istream& in, Student& s)
{
	in >> s.name >> s.num >> s.grade;
	return in;
}

ostream& operator<<(ostream& out, const Student& s)
{
	out << s.name << " " << s.num << " " << s.grade << endl;
	return out;
}


void StudContainer::print(ostream &out)
{
	out << "Students:" << endl;
	for (int j = 0; j < count; j++)
		out << p[j].name << " " << p[j].num << " " << p[j].grade << endl;
}

StudContainer::StudContainer(int _n)
{
	size = _n;
	count = _n;
	p = new Student[_n];
}

StudContainer::StudContainer(const StudContainer &c)
{
	size=c.size;
	p=new Student[size];
	for (int j=0; j<size; j++)
	{
		p[j]=c.p[j];
	}
	count=c.count;
}

StudContainer::~StudContainer()
{
	delete []p;
}

int StudContainer::Size()
{
	return size;
}

int StudContainer::Count()
{
	return count;
}

int comp(const void* a, const void* b)
{
	Student *a1 = (Student*)a;
	Student *b1 = (Student*)b;
	return strcmp(a1->name, b1->name);
}

void StudContainer::sortByName()
{
	qsort(p, count, sizeof(Student), (*comp));
}

Student* StudContainer::findByName(char* q)
{
	return (Student*) bsearch(q, p, count, sizeof(Student), (*comp));
	return 0;
}

bool StudContainer::insert(const Student &s)
{
	if (count==size)
	{
		StudContainer A1(*this);
		delete []p;
		p=new Student[size+10];
		for (int j = 0; j < size; j++)
		{
			p[j] = A1.p[j];
		}
		size = size+10;
		p[count++] = s;		
	}
	else
	{
		p[count++] = s;
	}
	return true;
}
bool StudContainer::del(char *_name)
{
	int j = 0;
	while (strcmp(p[j].name, _name)!= 0)
	{
		j++;
	}
	for (; j<count; j++)
	{
		p[j]=p[j+1];
	}
	count--;
	return true;
}

int cmp(const void* a, const void* b)
{
	Student* a1=(Student*)a;
	Student* b1=(Student*)b;
	return a1->num - b1->num;
}


void StudContainer::SortByNumAndName()
{
	int j = 0, c = 0, flag;
	qsort(p, count, sizeof(Student), (*cmp));
	while (j < count)
	{
		c = p[j].num;
		flag = 0;
		int i = j;
		while (p[i].num == c)
		{
			flag++;
			i++;
		}
		qsort(p + j, flag, sizeof(Student), (*comp));
		j += flag;
	}
}
void StudContainer::report()
{
	int j = 0, c = 0, flag;
	qsort(p, count, sizeof(Student), (*cmp));
	while (j < count)
	{
		c = p[j].num;
		flag = 0;
		int i = j;
		double Grade = 0;
		while (p[i].num == c)
		{
			flag++;
			Grade += p[i].grade;
			i++;
		}
		Grade /= flag;
		cout << p[i-1].num << " - " << Grade << endl;
		j += flag;
	}
}