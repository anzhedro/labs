#include <cstdio>
#include <algorithm>

using namespace std;
#define INF 1000000000 // предпологаем, что чисел больше такого не будет.

#define TREE_REAL_DATA 1024     // максимальное допустимое количество элементов
int tree_data[TREE_REAL_DATA * 2];  

// основная функция поиска.
// аргументы: p - текушая вершина(пронумерованы согласно рисунку).
// l, p - левая и правая границы отрезка, для которого tree_data[p] является максимумом.
// вообще можно было обойтись без этих параметров, и определять их исходя из p, но так проще и понятней.
// a, b - левая и правая границы отрезка, для которого необходимо найти минимум.
int __tree_find_max(int p, int l, int r, int a, int b) 
{
	if (b < l || r < a) return -INF;
	if (a <= l && r <= b) return tree_data[p];
	int r1 = __tree_find_max(p*2  , l, (l+r) / 2,   a, b); // опрос левого предка
	int r2 = __tree_find_max(p*2+1, (l+r)/2 + 1, r, a, b); // опрос правого предка
	return max(r1, r2); // нахождение большего из левого и правого поддеревьев
}

// более юзабильная оболочка для функции выше.
int tree_find_max(int a, int b)
{
	return __tree_find_max(1, 0, TREE_REAL_DATA - 1, a, b);
}

// обновление элемента № р.
void tree_update(int p, int x) 
{
	p += TREE_REAL_DATA; // преобразование позиции p к позиции в самом нижнем массве,
	// в котором реально находится массив со значениями.
	tree_data[p] = x;
	for(p/=2; p ; p/=2) {
		if (tree_data[p * 2] > tree_data[p * 2 + 1])
			tree_data[p] = tree_data[p * 2];
		else tree_data[p] = tree_data[p * 2 + 1];
	}
} 

// простейшая инициализация - установка всех значений в -INF
void tree_init()
{
	for (int i = 0; i < TREE_REAL_DATA * 2; i++) 
		tree_data[i] = -INF;
}

int main()
{
	tree_init();
	while ( 1 ){
		char c;
		scanf_s("%c", &c);
		if (c == 'Q') return 0; // выход
		if (c == 'F') {  // найти максимум на интервале a..b
			int a, b;
			scanf_s("%d%d", &a, &b);
			printf("%d\n", tree_find_max(a, b));
		}
		if (c == 'U') { // установить значение элемента p равым x.
			int p, x; 
			scanf_s("%d%d", &p, &x);
			tree_update(p, x);
		}
	}
}