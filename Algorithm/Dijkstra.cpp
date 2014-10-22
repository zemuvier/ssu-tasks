/*Алгоритм Дейкстры находит кратчиайший путь от вершины s ко всем другим вершинам и к требуемой вершине t. Алгоритм работает 
поэтапно, находя на каждом этапе кратчайший путь от s к новой промежуточной вершине x. То есть, в каждом цикле мы добавляем
одну вершину к дереву вершин, для которых мы знаем кратчайший путь из s.*/

#include <iostream>

using namespace std;

int n;

void dksrt(int g[100][100], int start)
{
	int distance[100], count, index, i, u, m=start+1;
	bool visited[100];

	for (i=0; i<n; i++)
	{
		distance[i]=INT_MAX; 
		visited[i] = false;
	}

	distance[start]=0;

	for (count=0; count<n; count++)
	{
		int min=1000;

		for (i=0; i<n; i++)
			if (!visited[i] && distance[i]<=min)
			{
				min=distance[i]; 
				index=i;
			}

	u=index;
	visited[u]=true;

	for (i=0; i<n; i++)
		if (!visited[i] && g[u][i] && distance[u]!=INT_MAX && distance[u]+g[u][i]<distance[i])
			distance[i]=distance[u]+g[u][i];
	}

	cout<<"Min way: \t\n";

	for (i=0; i<n; i++) 
		if (distance[i]!=INT_MAX)
			cout<<m<<" > "<<i+1<<" = "<<distance[i]<<endl;

	else cout<<m<<" > "<<i+1<<" = "<<"маршрут недоступен"<<endl;
	}

//алгоритм выведет кратчайший путь от start ко всем другим вершинам, что определит минимальное остовное дерево с корнем start. 
int main()
{
	int g[100][100];//граф
	int s; //заданная вершина

	cout << "Input start = "; //стартовая вершина
	cin >> s;

	cout << "Input the number of of vertexes = ";
	cin >> n;

	cout << "Input graph: "; //считываем сам граф
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; j++)
		{
			cout << "g[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> g[i][j];  
		}

	dksrt(g, s-1);

	return 0;
}
