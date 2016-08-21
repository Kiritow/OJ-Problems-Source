#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 65, P = 10001;
int map[N][N], n, s, t, m, nn;
char str[N][12], ss[12],st[12];
void mul(int a[][N], int b[][N]);
void init()
{
    int len;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%s", str[i]);
    }
    memset(map, 0, sizeof(map));
    for(int i=1; i<=n; i++)
    {
        len = strlen(str[i]);
        for(int j=1; j<=n; j++)
        {
            if(str[i][len-1] == str[j][0])
                map[i][j] = 1;
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            map[i+n][j] = map[i][j];
        }
        map[i+n][i+n] = 1;
    }
    mul(map, map);
    scanf("%s", ss);
    scanf("%s", st);
    for(int i=1; i<=n; i++)
    {
        if(strcmp(ss, str[i]) == 0)
            s = i;
        if(strcmp(st, str[i]) == 0)
            t = i;
    }
    nn = n;
    n *= 2;
    scanf("%d", &m);
}
void mul(int a[][N], int b[][N])
{
    int i,j,k;
    int c[N][N];
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
        {
            c[i][j] = 0;
            for(k = 1; k <= n; k++)
            {
                c[i][j] = c[i][j] + a[i][k]*b[k][j];
                c[i][j] = c[i][j] % P;
            }
        }
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            a[i][j] = c[i][j];
}
void solve()
{
    int i,j,k;
    int ans;
    int arraya[N][N],arrayb[N][N];
    memset(arraya,0,sizeof(arraya));
    for(i = 1; i <= n; i++)
        arraya[i][i] = 1;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            arrayb[i][j] = map[i][j];
    m = (m+1)/2;
    while(m)
    {
        if(1&m)
            mul(arraya,arrayb);
        mul(arrayb,arrayb);
        m = m>>1;
    }
    memset(arrayb, 0, sizeof(arrayb));
    for(int i=1; i<=nn; i++)
    {
        for(int j=1; j<=nn; j++)
         {
             arrayb[i][j+nn] = map[i+nn][j];
         }
        arrayb[i+nn][i+nn] = 1;
    }
    mul(arrayb,arraya);
    printf("%d\n",arrayb[s+nn][t]);
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        init();
        solve();
    }
    return 0;
}
