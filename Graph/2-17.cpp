//Найти длины кратчайших путей из вершины u во все остальные(2-17)
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <sstream> //строковые потоки
//#include <vector>
//#include <fstream>
//
//using namespace std;
//
//ifstream inp("input.txt");
//ofstream outp("output.txt");
//
//string str;
//int n; //число вершин
//vector<vector<int> > g; //граф
//int u; //данная вершина
//int used[100] = {0};
//int dist[100];
//vector < pair<int, int> > g[100]; //в g[u] лежит список пар: длина путей между u,v и вершина v
//
//class queue
//{
//private:
//struct Node
//{
//  int d;
//      Node *p;
//      }*h,*t;
//
//      public:
//      queue(){ h = t = NULL; }
//
//      bool isEmpty() //непустоста очереди
//      {
//          return !h;
//          }
//
//          void put(int x) //запись в хвост
//          {
//              Node *tmp = new Node;
//                  if (!h)
//                          h = t= tmp;
//                              else
//                                  {
//                                          t->p=tmp;
//                                                  t=tmp;
//                                                      }
//                                                      }
//
//                                                      int take() //выборка из очереди
//                                                      {
//                                                          Node *tmp = h;
//                                                              h=h->p;
//                                                                  int x = tmp->d;
//                                                                      delete tmp;
//                                                                          if (!h)
//                                                                                  t = NULL;
//                                                                                      return x;
//                                                                                      }
//                                                                                      };
//
//                                                                                      queue<int> q;
//
//                                                                                      void bfs(int u)
//                                                                                      {
//                                                                                        dist[u] = 0;
//                                                                                          p[u] = u
//                                                                                            q.put(u);
//                                                                                              while (!q.empty()) {
//                                                                                                  int u = q.front();
//                                                                                                      q.pop();
//                                                                                                          for (int i = 0; i < (int) g[u].size(); i++)
//                                                                                                              {
//                                                                                                                    int v = g[u][i].second;
//                                                                                                                          int len = g[u][i].first;
//                                                                                                                                if (dist[v] > dist[u] + len)
//                                                                                                                                      {
//                                                                                                                                              p[v] = u;
//                                                                                                                                                      dist[v] = dist[u] + len;
//                                                                                                                                                              q.put(v);
//                                                                                                                                                                    }
//                                                                                                                                                                        }
//                                                                                                                                                                          }
//
//
//                                                                                                                                                                            for (int i = 0; i < g[u-1].size(); i++)
//                                                                                                                                                                                  cout << i << " = " << dist[i] << endl;
//                                                                                                                                                                                  }
//                                                                                                                                                                                  int main()
//                                                                                                                                                                                  {
//                                                                                                                                                                                      inp >> n;
//                                                                                                                                                                                          inp >> u;
//
//                                                                                                                                                                                              getline(inp, str);
//
//                                                                                                                                                                                                  for (int i = 0; i<n; i++)
//                                                                                                                                                                                                      {
//                                                                                                                                                                                                              getline(inp,str);
//                                                                                                                                                                                                                      stringstream sio(str);
//                                                                                                                                                                                                                              int x;
//
//                                                                                                                                                                                                                                      while (sio >> x)
//                                                                                                                                                                                                                                                  g[i].push_back(x);
//                                                                                                                                                                                                                                                      }
//
//                                                                                                                                                                                                                                                          bfs(u);
//
//                                                                                                                                                                                                                                                              return 0;
//                                                                                                                                                                                                                                                              }
//                                                                                                                                                                                                      }
//                                                                                                                                                                                  }
//                                                                                                                                      }
//                                                                                                              }
//                                                                                              }
//                                                                                      }
//                                                      }
//                                  }
//          }
//      }
//}}
