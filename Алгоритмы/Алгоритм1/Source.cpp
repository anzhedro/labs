#include <iostream>
#include <fstream>
#define MAX 300003
using namespace std;

struct team{
	int x;
	int y;
	int z;

	team & operator=(const team & obj){
		x = obj.x;
		y = obj.y;
		z = obj.z;
		return *this;
	}
}; 

int comp_team(const team* obj1,const team* obj2){
    return (*obj1).x-(*obj2).x;
}


int main()
{
	int x, y, z, N;

	ifstream in("input.txt");

	in >> N;
	team *mas = new team[N];

	for(int i = 0; i < N; ++i)
	{
		in >> mas[i].x >> mas[i].y >> mas[i].z;		
	}

	in.close();

	qsort(mas, N, sizeof(team), (int(*)(const void*,const void*))comp_team);

	team t;
	int key = 0;
	t = mas[0];
	int q = 0;
	for (int i = 1; i < N; ++i)
	{
		if ((mas[i].y < t.y) && (mas[i].z < t.z))
		{
			mas[q].x = mas[q].y = mas[q].z = MAX;
			t = mas[i];
			int y = i;
			i = q;
			q = y;
			key ++;
		}

	}

	/*team t;
	int key = 0;
	for (int i = 0; i < N; ++i)
	{
		if (mas[i].x != MAX)
			t = mas[i];
		else
			continue;
		for (int j = 0; j < N; ++j)
		{
			if ((mas[j].x < t.x) && (mas[j].y < t.y) && (mas[j].z < t.z))
			{
				key++;
				mas[i].x = mas[i].y = mas[i].z = MAX;
				break;
			}
			if (mas[j].x != MAX)
			{
				if ((t.x < mas[j].x) && (t.y < mas[j].y) && (t.z < mas[j].z))
				{
					key++;
					mas[j].x = mas[j].y = mas[j].z = MAX;
				}
			}
		}
	}*/


	for (int i = 0; i < N; ++i)
	{
		cout << mas[i].x << " " << mas[i].y << " " << mas[i].z << endl;
	}
	cout << N << " " << key << " " << N - key << endl;
	ofstream out("output.txt");
	//out << N - key;
	out.close();

	return 0;
}