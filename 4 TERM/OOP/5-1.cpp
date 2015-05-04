#include <iostream>
 
 using namespace std;
 
class Time 
{
public:
  Time *next;
  Time() {
    timeCount++;
  }
  ~Time(){
    timeCount--;
  }
  static long timeCount;
};

long Time::timeCount;
 
int main(int argc, const char * argv[]) {
  class LinkedList //local class
  {
  private:
    Time *head; 
  public:
    LinkedList() {
      head = NULL;
    }
    ~LinkedList(){
      while (head != NULL) 
      {
        Time *tmp = head->next;
        delete head;
        head = tmp;
      }
    }
    
    void insert(Time* time)
    {
      time->next = head;
      head = time;
    }
    
    void show()
    {
      Time *tmp = head;
      while (tmp != NULL)
      {
        //cout << Time::timeCount << "  " << tmp << "\n";
        tmp = tmp->next;
      }
    }
    
    void pop(){
      Time *tmp = head;
      if (head != NULL)
      {
        head = head->next;
        delete tmp;
      }
    }
  };
  
  LinkedList *list = new LinkedList();

  for (int i = 0; i < 5; i++) 
  {
    Time *time = new Time();
    cout << "Created new Time object, static timeCount = " << Time::timeCount << endl;
    list->insert(time);
  }
  cout << endl;

  list->show();
  list->pop();

  cout << "Static count after one pop: " << Time::timeCount << endl;
  
  for (int i = 0; i < 5; i++) 
  {
    list->pop();
    cout << "removed one Time object, static timeCount now is " << Time::timeCount << endl;
  }
  
  cout << "Just for check — show current linkedlist (must be empty) :";
  list->show();
 
  
  return 0;
}