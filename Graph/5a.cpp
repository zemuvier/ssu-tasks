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

string str;
int visit[100] = {0};
int n;
int v;
int k = 0;
vector <vector <int> > vec;

void dfs(int m) //алгоритм обхода в глубину
{
	visit[m] = 1;

	for (int i = 0; i < vec[m-1].size(); i++)
	if (visit[vec[m-1][i]] == 0)
	{
		visit[i] = 1;
		dfs(vec[m-1][i]); 
	}

	for (int i = 0; i < m; i++)
		if (visit[i] == 1)
		{
			cout << i << " ";
			k++;
		}
}

int main()
{
ifstream inp("input.txt");
ofstream outp("output.txt");

inp >> n;

vec.resize(n);

getline(inp,str);

for (int i = 0; i < n; i++)
{
	getline(inp,str);
	stringstream sio(str);
	int x;

	while (sio >> x)
		vec[i].push_back(x);
}
	dfs(n); 

	cout << k;

	if (k == n)
	cout << "YEP";

	else 
		cout << "NOPE";

	return 0;
}