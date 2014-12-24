#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct edge// неорграф x Ч из какой вершины, y Ч в какую, w Ч вес ребра. 
{
int x, y, w;
edge(){}
edge(int x, int y, int w): x(x), y(y), w(w) {}
};

bool cmp(const edge& a, const edge& b) 
//ѕосле того, как считали граф, отсортировываем все ребра в пор€дке неубывани€

{
return a.w < b.w;
}

vector <int> leader;

int getLeader(int x)
//узнаем, в каком подмножестве находитс€ ребро
{
if (x == leader[x])
return x;

return leader[x] = getLeader(leader[x]); 
}

bool unite(int x, int y)//ƒл€ того, чтобы ответить на вопрос объедин€ть ли две вершины используетс€ функци€ unite. 
{
x = getLeader(x);
y = getLeader(y);

if (x == y)
return false;

if (rand() % 2 == 0)
swap(x, y);

leader[x] = y;
return true;
}

int main()
{
freopen("input.txt", "rt", stdin);
freopen("output.txt", "wt", stdout);

int n, m; // количество вершин и ребер
scanf("%d%d", &n, &m);

vector <edge> e(m); // записываем все в вектор

for (int i = 0; i < m; i++) // считываем список смежности с весом
{
scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w);

e[i].x--;
e[i].y--;
}

sort(e.begin(), e.end(), cmp); // производим сортировку с начала и до конца

leader.resize(n); // сортируем ребра и узнаем, в каком множестве они наход€тс€

for (int i = 0; i < n; i++)
leader[i] = i;

vector <edge> ans; // создаем вектор

for (int i = 0; i < m; i++)
{
int x = e[i].x, 
y = e[i].y;

if (unite(x, y))
ans.push_back(e[i]); // добавл€ем ребро в вектор
}
int sum = 0; // изначально сумма 0 
for (int i = 0; i < ans.size(); i++)
sum+=ans[i].w; // сумма весов
printf("%d\n", sum); // выводим сумму минимального остовного дерева
for (int i = 0; i < ans.size(); i++) // выводим вектор, то есть ребра в минимальном дереве
printf("%d %d\n", ans[i].x + 1, ans[i].y + 1);

return 0;
}