#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int t,N;
char s[10][10];
bool suit[10][1<<8+5];
int dp[8][11][1<<8][1<<8];
int one[1<<8+5];
inline void init()
{
    memset(suit,0,sizeof(suit));
    for(int i=0;i<8;i++)
    {
        for(int j=0;j< 1<<8;j++)
        {
            int tag=1;
            for(int k=0;k<8;k++)
            {
                if(s[i][k]=='*'&&(j&(1<<k)))
                {
                    tag=0;break;
                }
            }
            if(tag) suit[i][j]=1;
        }
    }
}
inline int getOne(int i)
{
    int ans=0;
    while(i)
    {
        ans+=i%2;
        i/=2;
    }
    return ans;
}
int main()
{
    for(int i=0;i< 1<<8;i++)
    {
        one[i]=getOne(i);
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&N);
        for(int i=0;i<8;i++) scanf("%s",s[i]);
        init();
        memset(dp,0,sizeof(dp));
        for(int i=0;i< 1<<8;i++)
        {
            if(suit[0][i]&&one[i]<=N)
            {
                dp[0][one[i]][i][0]=1;
            }
        }
        for(int i=1;i<8;i++)
            for(int n=0;n<=N;n++)
            for(int j=0;j< 1<<8;j++)
        {
            if(one[j]>n) continue;
            if(!suit[i][j]) continue;
            for(int k=0;k< 1<<8;k++)
            {
                if(one[k]+one[j]>n) continue;
                if(k&(j<<2)) continue;
                if(k&(j>>2)) continue;
                for(int r=0;r< 1<<8;r++)
                {
                    if(one[k]+one[j]+one[r]>n) continue;
                    if(r&(j<<1)) continue;
                    if(r&(j>>1)) continue;
                    dp[i][n][j][k]+=dp[i-1][n-one[j]][k][r];
                }
            }
        }
        int ans=0;
        for(int i=0;i< 1<<8;i++)
        {
            if(suit[7][i])
            {
                for(int j=0;j< 1<<8;j++)
                {
                    if(suit[6][j])
                    {
                        ans+=dp[7][N][i][j];
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}
