#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000009
#define pb push_back
vector <int> p[15];
int st[15];
int f[1<<16][20];
int to[15][20][20];
long long dp[15][25][25];
int num[1<<16];
int dx[]= {0,0,-1,1,1,1,-1,-1};
int dy[]= {-1,1,0,0,1,-1,1,-1};
int check(int x,int y)
{
    if(x>=0 && x<4 && y>=0 && y<4)return 1;
    return 0;
}
int nxt(int t)
{
    int ret=0;
    rep(i,17)
    {
        int x=i/4;
        int y=i%4;
        int cnt=0;
        for(int j=0; j<8; j++)
        {
            int nx = x+dx[j];
            int ny = y+dy[j];
            if(check(nx,ny))
            {
                int pos = nx*4+ny;
                if((1<<pos)&t)
                    cnt++;
            }
        }
        if((1<<i)&t)
        {
            if(cnt==2||cnt==3)
                ret^=(1<<i);
        }
        else
        {
            if(cnt==3)
                ret^=(1<<i);
        }
    }
    return ret;
}
void init()
{
    int n = 1<<16;
    memset(num,0,sizeof(num));
    rep(i,n)rep(j,17)
    if(i&(1<<j))
        num[i]++;
    rep(i,n)f[i][0]=nxt(i);
    for(int i=1; i<=18; i++)
        for(int j=0; j<n; j++)
            f[j][i]=f[f[j][i-1]][i-1];
}
int getnxt(int s,int t)
{
    for(int i=18; i>=0; i--)
        if((1<<i)<=t)
        {
            t-=(1<<i);
            s=f[s][i];
        }
    return s;
}
int main()
{
    int L,K,M,T,N,t;
    init();
    scanf("%d",&L);
    rep(cas,L)
    {
        scanf("%d%d%d%d",&K,&M,&T,&N);
        rep(i,K)p[i].clear();
        memset(st,0,sizeof(st));
        rep(k,K)rep(i,4)rep(j,4)
        {
            scanf("%d",&t);
            if(t)st[k]^=(1<<(i*4+j));
        }
        int n=1<<16;
        memset(to,0,sizeof(to));
        rep(k,K) // 10*2^16
            rep(i,n)
            if((st[k]&i) == st[k])
            {
                int j=i^st[k];
                int cnt1=num[j];
                int _nxt=getnxt(i,T);
                int cnt2=num[_nxt];
                to[k][cnt1][cnt2]++;
            }
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=1;
        for(int k=0; k<K; k++)
        {
            for(int i=0; i<=M; i++)
            {
                for(int j=0; j<=N; j++)
                {
                    if(dp[k][i][j]==0)continue;
                    for(int p=0; p<=16; p++)
                    {
                        for(int q=0; q<=16; q++)
                        {
                            if(to[k][p][q]==0)continue;
                            if(i+p<=M && j+q<=N)
                                dp[k+1][i+p][j+q]=(dp[k+1][i+p][j+q]+dp[k][i][j]*to[k][p][q])%mod;
                        }
                    }
                }
            }
        }
        long long ret=0;
        for(int i=0; i<=M; i++)
            ret=(ret+dp[K][i][N])%mod;
        printf("Case #%d: %I64d\n",cas+1,ret);
    }
}
