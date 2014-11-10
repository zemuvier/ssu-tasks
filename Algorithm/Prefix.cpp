#include <iostream>
#include <vector>
#include <string>

#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

string s2,s1;//s2 - какую строку мы ищем в строке s1

vector<int> prefix_function (string s) { //префикс-функция
    int len = s.length();
    vector<int> p(len); // значения префикс-функции
                      // индекс вектора соответствует номеру последнего символа аргумента
    p[0] = 0; // для префикса из нуля и одного символа функция равна нулю
 
        int k = 0;
    for(int i = 1; i < len; i++) 
    {      
        while ((k > 0) && (s[k] != s[i])) 
            k = p[k-1]; 

        if (s[k] == s[i])
            k++;

        p[i] = k;
    }
    return p;
}

int main() //главная функция 
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    
    cin >> s2 >> s1;
    s1 = s2+'#'+s1;
    
    
    vector<int> p=prefix_function (s1);

    for (int i = 1; i < p.size(); ++i)
    {
          cout << p[i] << " ";
    }

    return 0;
}