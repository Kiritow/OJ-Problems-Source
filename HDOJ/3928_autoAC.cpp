#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#define Maxn 100
#define inf 1<<30
using namespace std;
int T, n, f[Maxn][Maxn], out[Maxn][Maxn];
int le[Maxn], ri[Maxn];
int dfs(int x, int y)
{
     if (f[x][y] != -1) return f[x][y];
     if (out[x][y] == 1) return f[x][y] = 0;
     int t1, t2, t3, tmp = inf;
     for (int i=1; i<=n; i++)
     {
         t1 = t2 = t3 = -inf;
         int x1 = x, yy1 = min(le[i]-1, y);  
         if (yy1 == y) continue;
         if (x1 <= yy1 && out[x1][yy1]) t1 = dfs(x1, yy1);
         int x2 = max(le[i]+1, x), y2 = min(ri[i]-1, y);  
         if (x2 == x && y2 == y) continue;     
         if (x2 <= y2 && out[x2][y2]) t2 = dfs(x2, y2);
         int x3 = max(ri[i], x), y3 = y;     
         if (x3 == x) continue;         
         if (x3 <= y3 && out[x3][y3]) t3 = dfs(x3, y3); 
         tmp = min(tmp, max(t1,max(t2, t3)));         
     }
     return f[x][y] = tmp + 1;
     }
int main()
{
    int k;
    scanf("%d", &T);
    for (int t=1; t<=T; t++)
    {
        memset(le, -1, sizeof(le));
        memset(f, -1, sizeof(f));
        memset(out, 0, sizeof(out));
        scanf("%d", &n);
        for (int i=1; i<=2*n; i++)
        {
            scanf("%d", &k);  
            if (le[k] == -1) le[k] = i;
            else ri[k] = i; 
        }
        for (int i=1; i<=2*n; i++)
          for (int j=i; j<=2*n; j++)
            for (int p=1; p<=n; p++)
            if (ri[p] <= j && ri[p] >= i) out[i][j]++;
        printf("Case #%d: %d\n", t, dfs(2, 2*n));
    }
    return 0;
    }
