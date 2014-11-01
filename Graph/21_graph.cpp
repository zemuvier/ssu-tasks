#include <fstream>
#include <stdio.h> 
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <sstream> //строковые потоки

using namespace std;

/*bool f(int x,int l)
{ if (x=l) 
	return true;}*/

int main()
{
ifstream inp("input.txt");
ofstream outp("output.txt");
int n; 

string str;
int m1;
inp >> n;
inp >> m1;
vector <int> *vec = new vector <int> [n];

getline(inp,str);
for (int i = 0; i < n; i++)
	{
getline(inp,str);
stringstream sio(str);
int x;
while (sio >> x)
vec[i].push_back(x);

}
int k=0;
for (unsigned int i=0; i<vec[m1-1].size();i++)
{
for (unsigned int j=0; j<vec[vec[m1-1][i]-1].size();j++)
{ 
if ((vec[vec[m1-1][i]-1][j] == m1) && (vec[m1-1][i] != m1))
{
outp << vec[m1-1][i] << "\n";
k++;
}

} 
} 

if (k == 0)
outp << " NOPE " << endl;
;}