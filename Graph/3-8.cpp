//Вывести длины кратчайших путей от u до v1 и v2 в графе с отрицательными ребрами, 
//но без циклов отрицательного веса (Флойд)

#include <iostream>
#include <fstream>

using namespace std;

ifstream inp("input.txt");
ofstream outp("output.txt");

int u, v1, v2;
int n;
int D[10000][10000];
int GR[10000][10000];
const int INF = 1E9;

void FU(int a, int b)//алгоритм Флойда-Уоршелла
{
	for (int i = 0; i<n; i++) 
		for (int j = 0; j<n; j++)
			D[i][j] = GR[i][j];

	for (int i = 0; i<n; i++) 
		D[i][i] = 0;

	for (int k = 0; k<n; k++)
		for (int i = 0; i<n; i++)
			for (int j = 0; j<n; j++)
				if (D[i][k] < INF && D[k][j] < INF)
				{		D[i][j]=min(D[i][j], D[i][k] + D[k][j]);}//outp<<D[i][j]<<" "<<i+1<<" "<<j+1<<"D\n";}

	outp << a << " " << b << endl;
	outp << D[a-1][b-1] << endl;
}

int main()
{
	inp >> n;
	inp >> u >> v1 >> v2;

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
		{
			inp >> GR[i][j];
			if (GR[i][j] == 0)
				GR[i][j] = INF;
		}
	
	FU(u, v1);
	FU(u, v2); 

	return 0;
}