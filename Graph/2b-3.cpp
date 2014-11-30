//Определить, существует ли путь длиной не более L между двумя заданными вершинами графа с помощью
////алгоритма Форда-Беллмана.
//#include <fstream>
//#include <iostream>
//#define inf 100000
//using namespace std;
//
//ifstream inp("input.txt");
//
//struct Edges
//{
//  int u, v, w; //откуда, куда, вес
//  };
//
//  const int Vmax=1000;
//  const int Emax=Vmax*(Vmax-1)/2;
//  int i, j, n, e, start, stop;
//  Edges edge[Emax];
//  int d[Vmax]; //результаты работы - кратчайший путь из s в i
//
//  //алгоритм Беллмана-Форда
//  void bellman_ford(int n, int s, int st, int m)
//  {
//      int i, j;
//
//          //for (i=0; i<n; i++)
//              //  d[i]=inf;
//                  //d[s]=0;
//
//                      for (i=0; i<n-1; i++)
//                              for (j=0; j<e; j++)
//                                          if (d[edge[j].v] + edge[j].w < d[edge[j].u])/* && (d[edge[j].v] + edge[j].w < m))*/
//                                                              d[edge[j].u]=d[edge[j].v]+edge[j].w;
//
//                                                                  /*for (i=0; i<n; i++)
//                                                                          if (d[i]==inf)
//                                                                                          cout<<endl<<start<<"->"<<i+1<<"="<<"Not";*/
//
//                                                                                              cout << endl << start << "->" << stop << "=" << d[stop-1] << endl;
//                                                                                              }
//                                                                                              //главная функция
//                                                                                              int main()
//                                                                                              {
//                                                                                                  setlocale(LC_ALL, "Rus");
//                                                                                                      int w;
//                                                                                                          int l;
//
//                                                                                                              inp >> n;
//                                                                                                                  inp >> start;
//                                                                                                                      inp >> stop;
//                                                                                                                          inp >> l;
//                                                                                                                              e=0;
//                                                                                                                                  for (i=0; i<n; i++)
//                                                                                                                                      for (j=0; j<n; j++)
//                                                                                                                                          {
//                                                                                                                                                  inp >> i;
//                                                                                                                                                          inp >> j;
//                                                                                                                                                                  inp >> w;
//                                                                                                                                                                          if (w!=0)
//                                                                                                                                                                                  {
//                                                                                                                                                                                              edge[e].v=i;
//                                                                                                                                                                                                          edge[e].u=j;
//                                                                                                                                                                                                                      edge[e].w=w;
//                                                                                                                                                                                                                                  e++;
//                                                                                                                                                                                                                                          }
//                                                                                                                                                                                                                                              }
//
//
//                                                                                                                                                                                                                                                      cout<<"Список кратчайших путей:";
//                                                                                                                                                                                                                                                          bellman_ford(n, start-1, stop-1, l);
//                                                                                                                                                                                                                                                              //system("pause>>void");
//                                                                                                                                                                                                                                                              }
//
//                                                                                                                                                                                  }
//                                                                                                                                          }
//                                                                                              }
//  }
//}
