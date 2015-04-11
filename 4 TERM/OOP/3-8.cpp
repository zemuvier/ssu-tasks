#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <istream>

using namespace std;

class Transport
{
public:
	void ct()
	{
		cout << "I'm the transport!";
	}
};

class Car: Transport
{
public:
	void cc()
	{
		cout << "I'm the car and I can do BeepBeep";
	}
};

class Train: Transport
{
public:
	void ctn()
	{
		cout << "I'm the train and I can do Choo-Choo";
	}
};

class Plane: Transport
{
public:
	void cp()
	{
		cout << "I'm the plane and I can fly";
	}
};

class Type
{
public:
	void ctp()
	{
		cout << "I'm the type";
	}
};

class Passenger: Type
{
public:
	void cpas()
	{
		cout << "I'm the passenger type ";
	}
};

class Freight: Type
{
public:
	void cfr()
	{
		cout << "I'm the freight type ";
	}
};

class Boeing: Passenger, Plane
{
private:
	string X;
public:
	void boeing()
	{
		cout << "Boeing's route: ";
		cin >> X;
		cout << "I'm the passenger plane Boeing: " << X;
		cout << endl;
	}
};

class Toyota: Passenger, Car
{
private:
	string Y;
public:
	void toyota()
	{
		cout << "Toyota's route: ";
		cin >> Y;
		cout << "I'm the passenger car Toyota: " << Y;
		cout << endl;
	}
};

class Kawasaki: Freight, Train
{
private:
	string Z;
public:
	void kawasaki()
	{
		cout << "Kawasaki's route: ";
		cin >> Z;
		cout <<"I'm the freight train Kawasaki: " << Z;
		cout << endl;
	}
};

int main()
{
	Boeing B;
	Toyota T;
	Kawasaki K;

	int N;
	cout << "Numbers of routes: ";
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		B.boeing();
		T.toyota();
		K.kawasaki();
	}

	return 0;
}
