/*Построение минимальных остовных деревьев. Более эффективен на разряженных 
графах. Алгоритм наращивает связные компоненты вершин, создавая в конце минимальное 
остовное дерево. Первоначально каждая верщшина является отдельной копмпонентой 
будущего дерева. Алгоритм ищет ребро для добавления в лес путем поиска самого легкого
ребра среди всех ребер, соединяющих 2 дерева в лесу */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct edge
{
    int x, y, w;
    edge(){}
    edge(int x, int y, int w): x(x), y(y), w(w) {}
};

bool cmp(const edge& a, const edge& b)
{
    return a.w < b.w;
}

vector <int> leader;

int getLeader(int x)
{
    if (x == leader[x])
        return x;

    return leader[x] = getLeader(leader[x]);    
}

bool unite(int x, int y)
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

    int n, m;
    scanf("%d%d", &n, &m);

    vector <edge> e(m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w);

        e[i].x--;
        e[i].y--;
    }

    sort(e.begin(), e.end(), cmp);

    leader.resize(n);
    for (int i = 0; i < n; i++)
        leader[i] = i;

    vector <edge> ans;

    for (int i = 0; i < m; i++)
    {
        int x = e[i].x, y = e[i].y;

        if (unite(x, y))
            ans.push_back(e[i]);
    }
    int sum = 0;
    for (int i = 0; i < ans.size(); i++)
        sum+=ans[i].w;
    printf("%d\n", sum);
    for (int i = 0; i < ans.size(); i++)
        printf("%d %d\n", ans[i].x + 1, ans[i].y + 1);
    
    return 0;
}