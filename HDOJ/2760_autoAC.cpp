#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int T;
string str[105];
int l, n;
void work()
{
    scanf("%d%d\n", &l, &n);
    for (int i = 0; i < n; ++i) cin >> str[i];
    str[n] = str[0];
    int ans = n * l;
    string cur = str[0];
    for (int i = 1; i < n; ++i) {
        int common = 0;
        for (int cl = 1; cl <= l; ++cl) if (cur.substr(cur.size() - cl, cl) == str[i].substr(0, cl)) common = cl;
        cur += str[i].substr(common);
    }
    printf("%d\n", cur.size());
}
int main()
{
    while (scanf("%d", &T) != EOF)
        while (T--) work();
}
