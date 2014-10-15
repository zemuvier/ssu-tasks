#include<iostream>
#include<fstream>
using namespace std;

class Queue
{
private:
struct tqueue
{
int inf;
tqueue *next;
};
tqueue *h, *t;
public:
Queue()
{h=t=NULL;}


void insert(int item)
{
tqueue *r = new tqueue;
r->inf=item;
r->next=NULL;
if (!h&&!t)
h=t=r;
else {t->next=r;
t=r;
}
}

bool isEmpty()
{
return !h;
}


int take ()
{
tqueue*r=h;
int i=r->inf;
h=r->next;
delete r;
if (isEmpty())
t=NULL;
return i;
}


};

class Stack
{
private:
struct tstack
{
int inf;
tstack *next;
};
tstack *s;

public:
Stack()
{
s=NULL;
}

void push(int item)
{ 
tstack *r=new tstack;
r->inf=item;r->next=s;
s=r;
}

int pop()
{
tstack *r=s; int i=r->inf; s=r->next;
delete r; 
return i;
}
int peek()
{
return s->inf;
}
int empty_stack()
{
return (s) ? 0: 1;
}

};
int main()
{
Stack myS;
Queue myQ;
int i,j,h;

ifstream inp("input.txt");
ofstream outp("output.txt");

while(inp >> i)
{
if (i%2 == 0)
myQ.insert(i); 
}

while (!myQ.isEmpty())
{ 
j=myQ.take();
if (j < 0)
myS.push(j);
}

while (!myS.empty_stack())
{
i=myS.pop();
outp << i  << " ";
}
inp.close();
outp.close();
}