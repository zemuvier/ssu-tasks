#include <iostream>
#include <vector>
#include <string>
#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

string s;

vector<int> z_function (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);


cin >> s; //считывается подстрока и строка

vector<int> p= z_function (s);

forn(i,p.size())
{


cout << p[i] << " "; //выводится номера первого вхождения подстроки в строку

}

return 0;
}