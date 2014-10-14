#include <iostream>

using namespace std;

struct node
{
int info; 
node *l, *r;
};
node * tree=NULL; 

void push(int a,node **t)
{
if ((*t)==NULL) //Если дерева не существует
{
  (*t)=new node; //Выделяем память
  (*t)->info=a; //Кладем в выделенное место аргумент a
  (*t)->l=(*t)->r=NULL; //Очищаем память для следующего роста
      return; 
}

//Дерево есть
if (a>(*t)->info) 
  push(a,&(*t)->r); //Если аргумент а больше чем текущий элемент, кладем его вправо
else push(a,&(*t)->l); //Иначе кладем его влево
}

void print (node *t,int u) //вывод дерева на экран
{
if (t==NULL) 
  return; //Если дерево пустое, то отображать нечего, выходим
else 
{
  print(t->l,++u);//С помощью рекурсивного посещаем левое поддерево
  for (int i=0;i<u;++i) 
    cout <<"|";
cout << t->info << endl; //И показываем элемент
u--;
}
print(t->r,++u); //С помощью рекурсии посещаем правое поддерево
}


int main ()
{ 
int sum = 0;
int n; //Количество элементов
int s; //Число, передаваемое в дерево
cout << "please, include number of elements" << endl;
cin >> n; //Вводим количество элементов

for (int i=0;i<n;++i)
{
cout << "include symbol" << endl;
cin >> s; //Считываем элемент за элементом
push(s,&tree); //И каждый кладем в дерево
}

cout << "you're three\n";
print(tree,0);

}