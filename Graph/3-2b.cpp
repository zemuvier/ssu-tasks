//фб определить, существует ли путь длиной не более l между 2 заданными вершинами

#include <iostream>
#include <fstream>
#define inf 100000
using namespace std;

ifstream inp("input.txt");

struct Edges{
int u, v, w;
};

int n, e, m1, m2, l;
Edges edge[1000];
int d[1000];

//алгоритм Беллмана-Форда
void bellman_ford(int start, int stop)
{
	
	for (int i = 0; i<n; i++) 
		d[i] = inf;

	d[start] = 0;
	d[stop] = 0;
	bool x=true;

	for (int i=0; i<n; i++)
	{
		if (i!=n-1)
			for (int j=0; j<e; j++)
				if (d[edge[j].v]+edge[j].w<d[edge[j].u])
					d[edge[j].u]=d[edge[j].v]+edge[j].w;

		if (i==n-1)
			for (int j=0; j<e; j++)
				if (d[edge[j].v]+edge[j].w<d[edge[j].u])
					x=false;
	}
		if (!x) 
			cout << endl << "Graph wiht negative cycles" << endl;

	for (int i=0; i<n; i++)
		if (i+1 == stop)
		{
			if (d[i] > l)
				cout << endl << start << "->" << i+1 << "=" << "Not";
		else 
			cout <<endl << start << "->" << i+1 << "=" << d[i] << "Yep";
		}
}
//главная функция
int main()
{
	int w;
	inp >> n;
	e = 0;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
	{
		inp>>w;
		if (w!=0)
		{
			edge[e].v=i;
			edge[e].u=j;
			edge[e].w=w;
			e++;
		}
	}

	inp >> m1;
	inp >> m2;
	inp >> l;

	cout<<"m1-m2" << m1 << m2;
	bellman_ford(m1, m2);
	system("pause");
	return 0;
}