#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#define MAXN 111111
#define MAXM 555555
#define INF 100000011
#define lch(x) x<<1
#define rch(x) x<<1|1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define eps 1e-7
using namespace std;
long long h[1111][1111];
int n, m, t, p, q;
char mp[1111][1111], tmp[66];
long long a[66];
bool ok()
{
    for(int i = 0; i + p - 1 < n; i++)
        for(int j = q - 1; j < m; j++)
        {
            int flag = 1;
            for(int k = 0; k < p; k++)
                if(h[i + k][j] != a[k])
                {
                    flag = 0;
                    break;
                }
            if(flag) return true;
        }
    return false;
}
int main()
{
    int cas = 0;
    while(scanf("%d %d %d %d %d", &n, &m, &t, &p, &q) != EOF)
    {
        if(!n && !m && !t && !q && !p) break;
        for(int i = 0; i < n; i++) scanf("%s", mp[i]);
        memset(h, 0, sizeof(h));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < q; j++)
            {
                if(mp[i][j] == '*') h[i][q - 1] |= (1LL << j);
            }
        for(int i = 0; i < n; i++)
            for(int j = q; j < m; j++)
            {
                if(mp[i][j - q] == '*') h[i][j] = h[i][j - 1] - 1LL;
                else h[i][j] = h[i][j - 1];
                h[i][j] >>= 1LL;
                if(mp[i][j] == '*') h[i][j] |= (1LL << (q - 1));
            }
        int cnt = 0;
        while(t--)
        {
            for(int i = 0; i < p; i++)
            {
                scanf("%s", tmp);
                a[i] = 0;
                for(int j = 0; j < q; j++)
                    if(tmp[j] == '*') a[i] |= (1LL << j);
            }
            if(ok()) cnt++;
        }
        printf("Case %d: %d\n", ++cas, cnt);
    }
    return 0;
}
