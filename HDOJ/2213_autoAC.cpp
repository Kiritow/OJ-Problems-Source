#include <iostream>
#include <string.h>
using namespace std;
char map[102][103];
long long dp[102][103][30];
int N,M,T;
int sx,sy,ex,ey;
int dir[5][2] = {1,0,-1,0,0,1,0,-1,0,0};
int main()
{
    while(scanf("%d%d%d",&N,&M,&T)==3)
    {
        memset(map,0,sizeof(map));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=N;i++)
            scanf("%s",&map[i][1]);
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                if(map[i][j]=='S')
                {
                    sx = i;
                    sy = j;
                    dp[i][j][0] = 1;
                }
                else if(map[i][j]=='E')
                {
                    ex = i;
                    ey = j;
                }
            }
        }
        for(int t=1;t<=T;t++)
        {
            for(int i=1;i<=N;i++)
            {
                for(int j=1;j<=M;j++)
                {
                    if(map[i][j]==0||map[i][j]=='X') continue;
                    dp[i][j][t] = 0;
                    for(int d=0;d<5;d++)
                    {
                        int tempi = i+dir[d][0];
                        int tempj = j+dir[d][1];
                        dp[i][j][t] += dp[tempi][tempj][t-1];
                    }
                }
            }
        }
        if(dp[ex][ey][T-1]>0)
        {
            printf("%I64d\n",dp[ex][ey][T-1]);
        }
        else if(dp[ex][ey][T]>0)
        {
            puts("Oh, my god, bad luck!");
        }
        else
        {
            puts("God will bless XX and WisKey!");
        }
    }
}
