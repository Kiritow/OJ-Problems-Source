#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#define MAXN 505
#define INF 1000000007
using namespace std;
const int dir[4][2]={{1,1},{-1,1},{1,-1},{-1,-1}};
int n, m,ans;
int dp[MAXN][MAXN][4],to[4]={3,2,1,0};
char st[MAXN][MAXN];
long long p[MAXN], r[MAXN][MAXN], c[MAXN][MAXN];
void cal(int x,int y,int k)
{
    int now=dp[x][y][k];
    x+=dir[k][0],y+=dir[k][1];
    while(x>=0&&x<n&&y>=0&&y<m)
    {
        if(dp[x][y][to[k]]<=now)    now=dp[x][y][to[k]];
        else    if(dp[x][y][to[k]]>=now+2)
            now+=2;
        else    ++now;
        ans=max(now,ans);
        x+=dir[k][0],y+=dir[k][1];
    }
}
long long ac1(int rr,int x,int y)
{
    int l=y-x+1;
    if (!x) return r[rr][y];
    return r[rr][y]-r[rr][x-1]*p[l];
}
long long ac2(int cc,int x,int y)
{
    int l=y-x+1;
    if (!x) return c[cc][y];
    return c[cc][y]-c[cc][x-1]*p[l];
}
int main()
{
    int cas;
    scanf("%d",&cas);
    p[0]=1;
    for (int i=1;i<=500;i++) p[i]=p[i-1]*131;
    while (cas--)
    {
        ans=1;
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++)
            scanf("%s",st[i]);
        for (int i=0;i<n;i++)
        {
            r[i][0]=st[i][0];
            for (int j=1;j<m;j++)
                r[i][j]=r[i][j-1]*131+st[i][j];
        }
        for (int i=0;i<m;i++)
        {
            c[i][0]=st[0][i];
            for (int j=1;j<n;j++)
                c[i][j]=c[i][j-1]*131+st[j][i];
        }
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                for(int k=0;k<4;++k)
                {
                    int a=k&1?i+1:n-i,b=k<2?m-j:j+1,l=0,r,mid,nx,ny,x2,y2;
                    r=min(a-1,b-1);
                    while(l<r)
                    {
                        mid=(l+r+1)/2;
                        nx=i+mid*dir[k][0],ny=j+mid*dir[k][1];
                        x2=i,y2=j;
                        if(x2<nx)   swap(x2,nx);
                        if(y2<ny)   swap(y2,ny);
                        if(ac1(i,ny,y2)==ac2(j,nx,x2))  l=mid;
                        else    r=mid-1;
                    }
                    dp[i][j][k]=l+1;
                }
        for(int i=0;i<m;++i)
            cal(0,i,2),cal(0,i,0),cal(n-1,i,1),cal(n-1,i,3);
        for(int i=0;i<n;++i)
            cal(i,m-1,2),cal(i,m-1,3),cal(i,0,1),cal(i,0,0);
        printf("%d\n",ans*(ans+1)/2);
    }
    return 0;
}
