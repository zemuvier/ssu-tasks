#include <iostream>
#include <fstream>
#include <stdio.h> 
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	ifstream inp("input.txt");
	ofstream outp("output.txt");

	int n; int u;

	inp >> n; //количетсво вершин
	inp >> u; //вершина u 

	vector <int> *vec = new vector <int> [n + 1];
	int i = 1;
	char x; 

	while (inp >> x)
	{
		if (isdigit(x)) 
		{
			int b = x - '0';

			if (b == u)
			{	
				while (inp.get() != '\n')
				{
					i++;
					inp >> x; 
					int a = x - '0';
					vec[i].push_back(a);
				}
			}

			else /*if ((inp.get() == '\n'))*/
				i++;
		}
	}


	for (int i=0 ; i<n; i++)
	{ 
		for (unsigned int j=0; j<vec[i].size();j++)
				{
					//if (
					outp << vec[i][j] << " "; 
				} 
			outp << "\n";
	} 

}