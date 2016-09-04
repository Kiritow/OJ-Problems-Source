#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 101;
const int INF = 0x3f3f3f3f;
int n, m;
int a[maxn];
int cal(int a, int b)
{
    int M = a ^ b;
    int num = 0;
    while(M)
    {
        M &= (M-1);
        num++;
    }
    return num;
}
int get_ans(int t)
{
    int min = INF, num = 0, ans;
    for(int i = 0; i < n; i++)
    {
        num = cal(a[i], t);
        if(num < min) { min = num; ans = a[i]; }
    }
    return ans;
}
void read_case()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
}
void solve()
{
    read_case();
    int t;
    while(m--)
    {
        scanf("%d", &t);
        int ans = get_ans(t);
        printf("%d\n", ans);
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        solve();
    }
    return 0;
}
