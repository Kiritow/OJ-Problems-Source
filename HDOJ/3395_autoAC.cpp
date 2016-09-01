#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define clr(x) memset(x, 0, sizeof(x))
#define M 210
const int INF = 0x1f1f1f1f;
int v;
int link[M], lx[M], ly[M];
int visx[M], visy[M], G[M][M];
int slack;
int DFS(int x)
{
    visx[x] = 1;
    for (int y = 1; y <= v; ++y)
    {
        if (visy[y])
            continue;
        int t = lx[x] + ly[y] - G[x][y];
        if (t == 0)
        {
            visy[y] = 1;
            if (link[y] == -1||DFS(link[y]))
            {
                link[y] = x;
                return 1;
            }
        }
        else if (slack > t)
            slack = t;
    }
    return 0;
}
int KM()
{
    int i,j;
    memset (link,-1,sizeof(link));
    memset (ly,0,sizeof(ly));
    for (i = 1;i <= v; ++i)
        for (j = 1,lx[i] = -INF;j <= v; ++j)
            if (G[i][j] > lx[i])
                lx[i] = G[i][j];
    for (int x = 1;x <= v; ++x)
    {
        memset(visx,0,sizeof(visx));
        memset(visy,0,sizeof(visy));
        while (1)
        {
            slack=INF;
            if (DFS(x))
                break;
            for(i = 1; i <= v; i++)
            {
                if(visx[i]) {  lx[i]-=slack;  visx[i]=0;  }
                if(visy[i]) {  ly[i]+=slack;  visy[i]=0;  }
            }
        }
    }
    int res = 0;
    for (i = 1;i <= v; ++i)
            res += G[link[i]][i];
    return res;
}
int main()
{
    int i, j, k;
    int n, val[110];
    char w[110];
    while(scanf("%d", &n) != EOF)
    {
        if(n == 0) break;
        clr(G);
        v = n;
        for(i = 1; i <= n; ++i)
        scanf("%d", &val[i]);
        for(i = 1; i <= n; ++i) {
            scanf("%s", w+1);
            for(j = 1; j <= n; ++j)
                if(w[j]-'0') G[i][j] = val[i]^val[j];
        }
        int ans = KM();
        printf("%d\n", ans);
    }
    return 0;
}
