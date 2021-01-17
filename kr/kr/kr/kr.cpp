#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void addisolated(int** a, int n)
{
	int mod, del = n;
	while (del)
	{
		mod = rand() % n;
		for (int i = 0; i < n; i++)
			a[i][mod] = a[mod][i] = 0;
		del /= 2;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	ofstream fout("result.txt");

	int** a, n, sum = 0;
	cout << "Введите размер графа: ";
	cin >> n;

	a = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
		a[i] = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j)
				a[j][i] = a[i][j] = 0;
			else
				a[j][i] = a[i][j] = rand() % 2;

	addisolated(a, n);		//добавляем изолированные вершины в граф

	cout << "\n\nМатрица смежности графа:";
	fout << "\n\nМатрица смежности графа:";
	for (int i = 0; i < n; i++)
	{
		cout << "\n\n";
		fout << "\n\n";
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << setw(5);
			fout << a[i][j] << setw(5);
		}
	}

	cout << "\n\n\n\n\nИзолированные вершины: ";
	fout << "\n\n\n\n\nИзолированные вершины: ";

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 1 || a[j][i] == 1)
				break;
			if (j == n - 1)
			{
				sum++;
				cout << i << setw(5);
				fout << i << setw(5);
			}
		}
	cout << "\n\nКоличество изолированных вершин: " << sum;
	fout << "\n\nКоличество изолированных вершин: " << sum;
	fout.close();
}

