#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string str_merge(string a, string b)
{
    if (a == "") 
    {
        return b;
    }
    int i;
    int flag = 0;
    int pos;
    int alen = a.length();
    int blen = b.length();
    for (i = 1; i <= alen; i++) 
    {
        if (b.substr(0, i) == a.substr(alen - i, i)) 
        {
            flag = 1;
            pos = i;
        }
    }
    if (flag) 
    {
        return a + b.substr(pos, blen - pos);
    }
    else 
    {
        return a + b;
    }
}
int main()
{
    int n;
    int ans;
    int d[10];
    string str[10];
    string a;
    while (cin >> n) 
    {
        int i;
        for (i = 0; i < n; i++) 
        {
            cin >> str[i];
            d[i] = i;
        }
        ans = 1000;
        do 
        {
            string total = "";
            for (i = 0; i < n; i++) 
            {
                total = str_merge(total, str[d[i]]);
            }
            if (total.length() < ans) 
            {
                ans = total.length();
                a = total;
            }
        } while (next_permutation(d, d + n));
        cout << ans << endl;
    }
    return 0;
}
