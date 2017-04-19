#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <set>
#include <algorithm>
#include <iomanip>
#include <windows.h>
using namespace std;
struct cs
{
	string city;
	string star;
public:
	bool operator == (cs & s)
	{
		if(city < s.city || star < s.star)
			return true;
	}
};
int main()
{
	HANDLE Con;
	Con = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Con, 6);

	setlocale(LC_ALL, ".1251");
	ifstream in("in.txt");
	multimap <string, vector<string>> hotel;
	while(!in.eof())
	{
		string s;
		pair <string, vector<string>> pa;
		char *line = new char [60];
		in.getline(line, 60);
		char *p = strtok(line, ";");
		char ** word = new char*[3];
		int n = 0;
		while (p)
		{
			word[n] = new char [strlen(p) + 1];
			strcpy(word[n], p);
			p = strtok(NULL, "; ");
			n++;
		}
		pa.first = word[0];
		vector<string> h;
		h.push_back(word[1]);
		h.push_back(word[2]);
		pa.second = h;
		hotel.insert(pa);
	}
	in.close();

	cout << "------------------------------(1) Информация по городам:------------- \n";
	SetConsoleTextAttribute(Con, 7);
	multimap<string, vector<string>> ::const_iterator co;
	for(co = hotel.begin(); co != hotel.end() ; ++co)
	{
		cout << co->first << setw(25) << co->second[0] << "\t " << co->second[1] << endl;
	}


	SetConsoleTextAttribute(Con, 6);
	cout << "------------------------------(2) Поиск по городу-------------------- \n";
	SetConsoleTextAttribute(Con, 7);
	cout << "Введите город: ";
	string city; // 2)поиск по городу
	cin >> city;
	int n = 0;
	multimap< string, vector<string> >::const_iterator ifind = hotel.find( city );
	while (ifind != hotel.end())
	{
		if (ifind->first == city)
		{
			cout <<  ifind->second[0] << "\t" <<ifind->second[1] << endl;
			n++; 
		};
		ifind++;
	}
	if (n == 0)
	{
		SetConsoleTextAttribute(Con, 8);
		cout << "Город не найден!" << endl; //
		SetConsoleTextAttribute(Con, 7);
	}


	SetConsoleTextAttribute(Con, 6);
	cout << "------------------------------(3) Поиск по гостинице----------------- \n";
	SetConsoleTextAttribute(Con, 7);
	cout << "Введите гостиницу: ";
	string hostel;
	cin >> hostel;
	n = 0;
	multimap< string, vector<string> >::const_iterator find = hotel.begin();
	while (find != hotel.end())
	{
		if (find->second[0] == hostel)
		{
			cout << find->first << "\t" << find->second[0] <<"\t" << find->second[1] << endl;
			n++; 
		};
		find++;
	}
	if (n == 0)
	{
		SetConsoleTextAttribute(Con, 8);
		cout << "Гоcтиница не найдена!" << endl; //
		SetConsoleTextAttribute(Con, 6);
	}



	SetConsoleTextAttribute(Con, 6);
	cout << "------------------------------(4) Звёздности гостиниц в городах------ \n";
	SetConsoleTextAttribute(Con, 7);

	multimap< string, vector<string> >::const_iterator i;
	i = hotel.begin();
	string k = i->first;
	set<string> temp;
	cout << i->first << " ";
	while(i != hotel.end() )
	{
		if( k == i->first)
		{
			temp.insert(i->second[1]);
			i++;
		}
		else
		{
			set<string>:: const_iterator l;
			for(l = temp.begin(); l!=temp.end(); l++)
			{
				cout << *l << " ";
			}
			temp.clear();
			cout << endl;
			k = i->first;
			cout << i->first << " ";
		}
	}

	set<string>:: const_iterator l;
	for(l = temp.begin(); l != temp.end(); l++)
	{
		cout << *l << " ";
	}
	SetConsoleTextAttribute(Con, 6);
	cout << "\n---------------------------------------------------------------------\n";
	SetConsoleTextAttribute(Con, 7);

	return 0;
}