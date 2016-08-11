//#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <bitset>
#include <string>
#include <time.h>
using namespace std;
long double esp=1e-11;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define cle(a) while(!a.empty())a.pop()
#define mem(p,c) memset(p,c,sizeof(p))
#define mp(A, B) make_pair(A, B)
#define pb push_back
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
typedef long long int LL;
const long double PI = acos((long double)-1);
const LL INF=0x3f3f3f3f3f3f3f3fll;
const LL MOD =1000000007ll;
const int maxn=5001;
LL dp[2][maxn][3];
LL m[maxn][4];
int in[maxn][2],n;
void update(int x,int a,int b,LL ans)
{
    if(a==0&&b==0&&x!=n)return;
    if(a>=0&&b>=0&&(a-b+1)>=0&&(a-b+1)<3)
    {
        dp[x&1][a][a-b+1]=min(dp[x&1][a][a-b+1],ans);
        //printf("****%d %d %d %lld\n",x,a,b,ans);
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("inlay.in", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //::iterator iter;                  %I64d
    //for(int x=1;x<=n;x++)
    //for(int y=1;y<=n;y++)
    //scanf("%d",&a);
    //printf("%d\n",ans);
    int s,e;
    scanf("%d%d%d",&n,&s,&e);
    LL t;
    for(int x=1;x<=n;x++)
    {
        scanf("%I64d",&t);
        m[x][0]=m[x][2]=t;
        m[x][1]=m[x][3]=-t;
        in[x][0]=1;
        in[x][1]=1;
    }
    for(int y=0;y<4;y++)
        for(int x=1;x<=n;x++)
        {
            scanf("%I64d",&t);
            m[x][y]+=t;     //printf("%d %d %lld\n",x,y,m[x][y]);
        }
    m[s][0]=m[s][1]=0;
    m[e][2]=m[e][3]=0;
    in[s][0]=0;
    in[s][1]=1;
    in[e][0]=1;
    in[e][1]=0;
    memset(dp,0x3f,sizeof(dp));
    LL a,b;
    dp[0][0][1]=0;
    for(int x=1;x<=n;x++)
    {
        mem(dp[x&1],0x3f);
        for(int y=0;y<=n;y++)
        for(int z=0;z<3;z++)
        if(dp[(x-1)&1][y][z]!=INF)
        {
            a=y;
            b=a+1-z;
            if(b<0)continue;
            //printf("%d %d %d %lld\n",x-1,a,b,dp[(x-1)&1][y][z]);
            if(a-in[x][1]>=0)
            update(x,a-in[x][1]+in[x][0],b,dp[(x-1)&1][y][z]+m[x][1]+m[x][2]);
            if(b-in[x][0]>=0)
            update(x,a,b-in[x][0]+in[x][1],dp[(x-1)&1][y][z]+m[x][0]+m[x][3]);
            update(x,a+in[x][0],b+in[x][1],dp[(x-1)&1][y][z]+m[x][1]+m[x][3]);
            if(a-in[x][1]>=0&&b-in[x][0]>=0)
            update(x,a-in[x][1],b-in[x][0],dp[(x-1)&1][y][z]+m[x][0]+m[x][2]);
        }
    }
    printf("%I64d\n",dp[n&1][0][1]);
    return 0;
}
