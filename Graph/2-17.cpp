#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>
#include <queue> 
#include <fstream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

#define INF 100000

ifstream inp("input.txt");
ofstream outp("output.txt");

map <int,vector <int> > vec;
string str;
int n;
int u;
int pred[100]; // ������ �������
queue <int> q; // �������, �������� ������ ������ �������� � ��
int d[100] = {INF}; //������ �����
int visit[100] = {0}; //������ ���������

void bfs(int start)
{
visit[start] = 1;
q.push(start); // �������� �� ������ �������
pred[start]= -1; // ����������� ����� ��� ������ ����
while(!q.empty()) // ���� ����� �� ������� � �������
{
int v = q.front(); 
q.pop(); // ������� u ��������
for(size_t i = 0; i < vec[v].size(); i++ ) // ������� ������� �������
{int ver=vec[v][i];
if (visit[ver]==0) 
{
q.push(ver); // �������� �� ������� i
pred[ver] = v; // ���� ���������
if (d[v]==INF)
d[ver]=1; else 
d[ver] = d[v] + 1;
visit[ver] = 1;
}
}
} 

vector<int> path;
for (size_t l = 0; l < n; l++)
if (l!=start) 

cout << l+1 << " " << d[l] <<"\n";

}

int main()
{
int y;
inp >> n;
inp >> u;

getline(inp,str);

for (int i = 0; i < n; i++)
{
getline(inp,str);
stringstream sio(str);
int x;
sio>>y;
while (sio >> x)
vec[y-1].push_back(x-1);
}

bfs(u-1);

system("pause");
return 0;
}