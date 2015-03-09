#include <iostream>
#include <string>

using namespace std;

class Computers{
private:
		string ComputerName, ComputerProcessor, ComputerOS;
public:
	void Read()
	{
		cout << "Enter the name of computer: ";
		cin >> ComputerName;
		cout << "Enter the processor of computer: ";
		cin >> ComputerProcessor;
		cout << "Enter the OS of computer: ";
		cin >> ComputerOS;
	}
	void Show()
	{
		cout << "Computer's name: " << ComputerName << endl;
		cout << "Computer's processor: " << ComputerProcessor << endl;
		cout << "Computer's OS: " << ComputerOS << endl;
	}
	void Update(string NewName, string NewProcessor, string NewOS)
	{
		ComputerName = NewName;
		ComputerProcessor = NewProcessor;
		ComputerOS = NewOS;

	}
};

class List {
	private:
		struct tlist{
		Computers inf;
		tlist *next;
		tlist *prev;
		};

		tlist *h, *t;

	public:
		List(){
			h=t=NULL;
		}

		void add_list_t(Computers x){
			tlist*r=new tlist;
			r->inf=x;
			r->next=NULL;
			if (!h){
				r->prev=NULL; h=r;
			}
			else {
				t->next=r; r->prev=t;
			}
			t=r; 
		}

		void print(){ 
			tlist*r=h;
			while (r) {
				r->inf.Show();
				r=r->next;
			}
		}

		/*void delete_all (){
			tlist*r;
			while (h) {
				r=h; 
				if(r==t) h=t=NULL;
				else {
					h=h->next; h->prev=NULL; 
				}
				delete r;
			}
		}
		int empty_list(){
		return (h&&t) ? 0: 1;
		}*/
};

int main(){
	List a;
	int Number;
	cout << "Enter number: \n";
	cin >> Number;
	for (int i = 0; i < Number; i++)
	{
		Computers temp;
		temp.Read();
		a.add_list_t(temp);
	}
	a.print();
	return 0;
}