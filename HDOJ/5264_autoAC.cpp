#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
const int maxn = 1005;
int T, n, m; 
string a, b, s;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        cin >> s;
        b = a = "";
        for (int i = 0; s[i]; i++)
        {
            if (i & 1) b = s[i] + b;
            else a = a + s[i];
        }
        cout << a << endl;
        cout << b << endl;
    }
}
