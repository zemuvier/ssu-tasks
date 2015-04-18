#include <iostream>
#include <string>

using namespace std;

class Data
{
private:
	int day, year, month;
public:
	void DoDataLikeThis()
	{
		cout << "Enter the day: ";
		cin >> day;	
		cout << "Enter the month: ";
		cin >> month;
		cout << "Enter the year: ";
		cin >> year;

		try 
		{
			throw 1; 
		}

		catch(string month)
		{
			cout << "Error!"; 
		}
		
		cout << day << "/" << month << "/" << year << endl;		
	}

};

int main()
{
	Data M; 
	M.DoDataLikeThis();
	return 0;
}