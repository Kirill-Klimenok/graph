#include <iostream>
#include <queue>

using namespace std;

int wave(vector < vector <int> > A, int numCity, int St, int Fi)  //numCity-количесво вершин , St-начало , Fi-конец
{
	queue<int> iQueue;
	int* distance = new int[numCity];

	for (int i = 0; i < numCity; i++)
	{
		distance[i] = INT_MAX;
	}

	iQueue.push(St);
	distance[St] = 0;

	while (!iQueue.empty())
	{
		int Curr = iQueue.front();
		iQueue.pop();
		for (int i = 0; i < numCity; i++)// делаем обход по матрице и ищем путь
		{
			if (A[Curr][i] >= 1)
			{
				if (distance[i] > distance[Curr] + A[Curr][i])
				{
					distance[i] = distance[Curr] + A[Curr][i];
					iQueue.push(i);
				}
			}
		}
	}

	return distance[Fi];
}

int SearchMiddle(vector < vector <int> > A, int N, int St1, int St2)
{
	int C = N;
	for (int i = 0; i < N; i++)
	{
		--C;
		if (wave(A, N, St1, C) == wave(A, N, St2, C) && wave(A, N, St1, C) != 0 && wave(A, N, St1, C) != INT_MAX)
		{
			return wave(A, N, St1, C);
		}
	}
	return -1;
}

int main()
{
	int n = 5;

	vector < vector<int> > mas(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mas[i][j] = 0;
		}
	}

	FILE* f;
	fopen_s(&f, "text.txt", "r");

	while (!(feof(f)))
	{
		int a, b;
		char c[2];
		fscanf_s(f, "%i%s%i", &a, c, _countof(c), &b);
		mas[a - 1][b - 1] = 1;
	}

	printf("%i", SearchMiddle(mas, n, 1, 1));
}
