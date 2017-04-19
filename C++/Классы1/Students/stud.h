#include <iostream>
using namespace std;
struct Student
{
	char  name[10];		
	int   num;			
	double  grade;		
};

class StudContainer
{
	int size;	  
	//Student* p;	  // ������ ������� � ���������
	int count;	  
public:
	Student* p;	 
	StudContainer(int);	 
	StudContainer(const StudContainer& c); 
	~StudContainer();		  
	bool insert(const Student& s);  // ��������� �������� � ���������
	bool del(char* name);	  // ���������� �������� �� ����������
	void sortByName();	  
	Student* findByName(char*);	
	void SortByNumAndName();	  // ���������� �� �������, ������
	void report();	  // ������� ����� � ����
	void print(ostream& out);	  
	int Size();				  
	int Count();	  
	friend istream& operator>>(istream& in, Student& s);
	friend ostream& operator<<(ostream& out, const Student& s);

};
