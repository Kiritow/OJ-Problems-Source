#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<stack>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define FF(i, a, b) for(int i=a; i<b; i++)
#define FD(i, a, b) for(int i=a; i>=b; i--)
#define REP(i, n) for(int i=0; i<n; i++)
#define CLR(a, b) memset(a, b, sizeof(a))
#define LL long long
#define PB push_back
#define eps 1e-10
using namespace std;
const int maxn = 100010;
const int INF = (1<<21) + 10;
int T, n, a[maxn];
int has[INF];
char ch[10];
int calc(char *ch)
{
    int ret = 0;
    REP(i, 5)
    {
        if(isupper(ch[i])) ret = ret*16 + (ch[i]-'A') + 10;
        else ret = ret*16 + (ch[i]-'0');
    }
    return ret;
}
bool dfs(int val, int now, int len, int num)
{
    if(len == num)
    {
        REP(i, n) if(has[a[i]^val] == T) return true;
        return false;
    }
    FF(i, now, 21) if(dfs(val+(1<<i), i+1, len+1, num)) return true;
    return false;
}
int main()
{
    int ncas;
    scanf("%d", &ncas);
    for(T=1; T<=ncas; T++)
    {
        scanf("%d", &n);
        bool flag = 0;
        REP(i, n)
        {
            scanf("%s", ch);
            a[i] = calc(ch);
            if(has[a[i]] == T) flag = 1;
            has[a[i]] = T;
        }
        if(flag)
        {
            puts("0");
            continue;
        }
        int ans = 1;
        while(!dfs(0, 0, 0, ans)) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
