/*Алгоритм Прима для построения минимального остовного дерева начиает обход с 1 вершины и создает дерево, добавляя по 1 ребру, пока не будут включены все 
вершины. На каждом этапе мы вставляем в дерево новую вершину. "Жадный" алгоритм выбирает ребро с наименьшим весом */

#include <iostream>

using namespace std;

int matx[100][100];//матрица смежности
int visited[100] = {0}; 
int v, ne = 1;
int MIN; //текущее минималньое расстояние
int mm;

int main()
{
	int m;
	int u,v;
	int p[100] = {0}; //массив вершин, по которым будет составляться путь
	int pp  = 0; //индекс 
	cout << "Number of vertex = ";
	cin >> m;

	cout << "Matrix: ";
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> matx[i][j];
			if (matx[i][j] == 0)
				matx[i][j] = 1000;
		}

	visited[1] = 1;

	while (ne < m)
	{
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++)
				if (matx[i][j] < 1000)
					if (visited[i] != 0)
					{
						MIN = matx[i][j];
						u = i;
						v = j;
					}

					if ((visited[u] == 0) || (visited[v] == 0))
					{
						p[pp] = v;
						pp++;
						ne++;
						mm += MIN;
						visited[v] = 1;
					}
		
		matx[u][v] = 1000;
	}

	cout << "\n";
 
	cout << 1 << " --> ";
	for (int i = 0;i < m-1; i++)
	{
	  cout << p[i];
	  if (i < m-2) 
	  	cout << " --> ";
	}
 	cout << endl;
	cout << "Min is "<< mm;

	return 0;
}