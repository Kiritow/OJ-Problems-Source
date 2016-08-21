#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N=22, M=1000;
int map[N][N],dp[N][N];
int main()
{
    int i,r,j,n,m,k,s,t,T;
    while(scanf("%d%d",&n,&m) && n+m)
    {
        memset(map,0,sizeof(map));
        for(i=0;i<m;i++){
            scanf("%d%d",&s,&t);
            map[s+1][t+1]=1;
        }
        scanf("%d",&T);
        while( T-- )
        {
            memset(dp,0,sizeof(dp));
            scanf("%d%d%d",&s,&t,&k);
            s++; t++;
            dp[0][s]=1;
            for(i=1;i<=k;i++) 
                for(r=1;r<=n;r++)
                    for(j=1;j<=n;j++)
                        if( map[r][j] ){
                            dp[i][j]+=dp[i-1][r];
                            dp[i][j]%=M;
                        }
            printf("%d\n",dp[k][t]);
        }
    }
    return 0;
}
