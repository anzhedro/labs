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
	//Student* p;	  // массив записей о студентах
	int count;	  
public:
	Student* p;	 
	StudContainer(int);	 
	StudContainer(const StudContainer& c); 
	~StudContainer();		  
	bool insert(const Student& s);  // включение студента в контейнер
	bool del(char* name);	  // исключение студента из контейнера
	void sortByName();	  
	Student* findByName(char*);	
	void SortByNumAndName();	  // сортировка по группам, именам
	void report();	  // вывести отчет в файл
	void print(ostream& out);	  
	int Size();				  
	int Count();	  
	friend istream& operator>>(istream& in, Student& s);
	friend ostream& operator<<(ostream& out, const Student& s);

};
