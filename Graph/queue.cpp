#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream inp("input.txt");
ofstream outp("output.txt");

struct man //структура считывания людей
{
	void print();
	string f;//фамилия
	string i; //имя
	string o;//отчество
	string gender;//пол
	int v; //возраст 
	int s; //зарплата
};

void man::print()
{
	man tmp;
	outp << tmp.f << tmp.i << tmp.o << tmp.gender << tmp.v << tmp.s;
}

class Queue{ //класс очередь 
private:

struct Node{
man d;
Node *p;
}*h,*t;

public:
Queue(){ h = t = NULL; }

bool isEmpty() //непустоста очереди
{
	return !h;
}

void put(man x) //запись в хвост
{
	Node *tmp = new Node;
	if (!h)
		h = t= tmp;
	else
	{
		t->p=tmp;
		t=tmp;
	}
}

man take() //выборка из очереди
{
	Node *tmp = h;
	h=h->p;
	man x = tmp->d;
	delete tmp;
	if (!h)
		t = NULL;
	return x;
}
};

int main()
{
Queue myQ_man, myQ_female;
int n;

inp >> n;

while (inp.peek()!=EOF)
{
	man tmp;
	inp >> tmp.f >> tmp.i >> tmp.o >> tmp.gender >> tmp.v >> tmp.s;

	if (tmp.gender == "male")
		myQ_man.put(tmp);

	else 
		myQ_female.put(tmp);

}

while (!(myQ_man.isEmpty()))
{
	man tmp = myQ_man.take();
	tmp.print();
}

while (!(myQ_female.isEmpty()))
{
	man tmp = myQ_female.take();
	tmp.print();
}

inp.close();
outp.close();

return 0;
}