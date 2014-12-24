#include <fstream>
#include <stdio.h> 
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <sstream> //строковые потоки

using namespace std;

int GR[10][10];//граф
int visit[10];
int n;
int k = 0;

void dfs(int v) //алгоритм обхода в глубину
{
	int i;
	
	//cout << v << " ";
	visit[v] = true;
	for (i = 1; i <= n; i++)
		if ((!visit[i]) && (GR[v][i] != 0))
		{
			for (k = i+1; k <= n; k++)
				if ((GR[v][k] != 0) && (GR[k][i] != 0))
					k ++;
			dfs(i);			
		}
}

int main()
{
	int m;

	cout << "n = ";
	cin >> n;

	cout << "v = ";
	cin >> m;

	cout<<"The Matrix:\n";
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
		{	
			cout << "GR[" << i+1 << "][" << j+1 << "] > ";
			cin >> GR[i][j];
		}

		dfs(m);
		cout << k;	

		if (k == n+1)
		{
			cout << "Yes";
		}

		else 
			cout << "Nope";
}