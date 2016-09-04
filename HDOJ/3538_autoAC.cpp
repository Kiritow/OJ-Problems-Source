#include<algorithm>
#include <cstring>
#include<cstdio>
#include<stdlib.h>
#define L(i) (1 << (i))
#define MAXM 3000000
using namespace std;
int dp[3000000][22];
int dis[22][22];
int f[22];
int main()
{
   int n, m;
    while(~scanf("%d%d",&n, &m))
   {
        memset(f,0,sizeof(f));  
        for(int i = 0;i < L(n);i ++)
            for(int j = 0;j < n;j ++)
                dp[i][j] = MAXM;  
         for(int i = 0;i < n;i ++)
            for(int j = 0;j < n;j ++)
                scanf("%d",dis[i] + j);
        for(int i = 0;i < m;i ++)
        {
            int u, v;
            scanf("%d%d", &u,&v);
            f[v] |= L(u);        
        }
        dp[1][0] = 0;   
        int S = L(n);
        for(int s = 0;s < S;s ++)          
            for(int i = 0;i < n;i ++)      
                if(dp[s][i] == MAXM)continue;
                else
                for(int j = 1;j < n;j ++)   
                {
                    if(dis[i][j] == -1)continue;
                    if(!(s & L(i)))continue;        
                    if(s & L(j))continue;       
                    if(f[j] != (s & f[j]))continue;
                    dp[s|L(j)][j] = min(dp[s][i] + dis[i][j],dp[s|L(j)][j]);
                }
        int ans = MAXM;
        S = L(n) - 1;
        for(int i = 0;i < n;i ++)    
            ans = min(ans, dp[S][i]);
        if(ans >= MAXM)printf("-1\n");
        else printf("%d\n",ans);
   }
    return 0;
}
