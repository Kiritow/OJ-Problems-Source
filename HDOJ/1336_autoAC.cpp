#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
map<string , int> table;
int main()
{
    int cnt = 1;
    for(char i = 'a'; i <= 'z'; ++i)
    {
      string tmp;
      tmp += i;
      table[tmp] = cnt ++;
    }
    for(char i = 'a'; i <= 'z'; ++i)
        for(char j = i + 1; j <= 'z'; ++j)
        {
            string tmp;
            tmp += i;tmp += j;
            table[tmp] = cnt ++;
        }
    for(char i = 'a'; i <= 'z'; ++i)
        for(char j = i + 1; j <= 'z'; ++j)
                for(char k = j + 1; k <= 'z'; ++k)
                {
                    string tmp;
                    tmp += i;tmp += j;tmp += k;
                    table[tmp] = cnt ++;
                }
    for(char i = 'a'; i <= 'z'; ++i)
        for(char j = i + 1; j <= 'z'; ++j)
                for(char k = j + 1; k <= 'z'; ++k)
                    for(char l = k + 1; l <= 'z'; ++l)
                    {
                        string tmp;
                        tmp += i;tmp += j;tmp += k;tmp += l;
                        table[tmp] = cnt ++;
                    }
    for(char i = 'a'; i <= 'z'; ++i)
        for(char j = i + 1; j <= 'z'; ++j)
                for(char k = j + 1; k <= 'z'; ++k)
                    for(char l = k + 1; l <= 'z'; ++l)
                        for(char m = l + 1; m <= 'z'; ++m)
                        {
                            string tmp;
                            tmp += i;tmp += j;tmp += k;tmp += l;tmp += m;
                            table[tmp] = cnt ++;
                        }
    string word;
    while(cin >> word)
    {
        map<string , int>::iterator it = table.find(word);
        if(it == table.end())
        {cout << 0 << endl;}
        else
        {cout << it->second << endl;}
    }
    return 0;
}
