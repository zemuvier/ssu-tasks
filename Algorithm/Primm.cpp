#include <iostream>
#include <vector>
#include <iomanip>
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;
int n,m;
vector <pair<int,int> > g[500];//кроме вершин список смежности хранит и вес ребра
vector <bool> used(500,0);//вектор использованных вершин
int inf=10000000;
vector <int> d(500,inf);//вектор расстояний
int main()
{
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    cin>>n>>m;
    int x,y,l;
    pair <int,int> temp;
    forn(i,m){
        cin>>x>>y>>l;
        x--;
        y--;
        temp.first=y;
        temp.second=l;
        g[x].push_back(temp);
        temp.first=x;
        g[y].push_back(temp);
    }
    vector <pair<int,int> > path(500);   
    d[0]=0;
    while(true){
        int v=-1;
        int dist=inf;
        forn(u,n)
                if(!used[u] && dist>=d[u])
                {
                    v=u;
                    dist=d[u];
                }
                if (v==-1) break;
                used[v]=true;
                forn(u,g[v].size())
                    if(!used[g[v][u].first]) {
                        if (d[g[v][u].first]>g[v][u].second) path[g[v][u].first]=make_pair(v,g[v][u].first);
                        d[g[v][u].first]=min(d[g[v][u].first],g[v][u].second);                      
                    }
    }
    long long sum=0;
    forn(i,n) sum+=d[i];
    cout<<sum<<endl;
    forn(i,n-1)
        cout<<path[i+1].first+1<<" "<<path[i+1].second+1<<endl;
    
    return 0;
}