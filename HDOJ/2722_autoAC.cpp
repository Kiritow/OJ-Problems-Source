#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#define INF 100000000
#define L 2520
using namespace std;
int N,M;
int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int dp[25][25];
struct Block
{
    int a[4];
}mp[25][25];
int main()
{
    int i,j,k,v;
    char c;
    while(cin>>N>>M,N||M)
    {
        memset(mp,0,sizeof(mp));
        for(i=0;i<=N;i++)
        {
            for(j=0;j<M;j++)
            {
                cin>>v>>c;
                if(v)
                    v=L/v;
                if(c=='*')
                    mp[i][j].a[0]=mp[i][j+1].a[1]=v;
                if(c=='>')
                    mp[i][j].a[0]=v;
                if(c=='<')
                    mp[i][j+1].a[1]=v;
            }
            if(i!=N)
                for(j=0;j<=M;j++)
                {
                    cin>>v>>c;
                    if(v)
                        v=L/v;
                    if(c=='*')
                        mp[i][j].a[2]=mp[i+1][j].a[3]=v;
                    if(c=='v')
                        mp[i][j].a[2]=v;
                    if(c=='^')
                        mp[i+1][j].a[3]=v;
                }
        }
        for(i=0;i<=N;i++)
            for(j=0;j<=M;j++)
                dp[i][j]=INF;
        dp[0][0]=0;
        for(v=0;v<40;v++)
        for(i=0;i<=N;i++)
            for(j=0;j<=M;j++)
                for(k=0;k<4;k++)
                    if(mp[i][j].a[k])
                        if(dp[i+d[k][0]][j+d[k][1]]>dp[i][j]+mp[i][j].a[k])
                            dp[i+d[k][0]][j+d[k][1]]=dp[i][j]+mp[i][j].a[k];
        if(dp[N][M]==INF)
            cout<<"Holiday"<<endl;
        else
            cout<<dp[N][M]<<" blips"<<endl;
    }
    return 0;
}
