#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
#define MP(x,y) make_pair(x,y)
const int MAXN= 110;
const double EPS = 1e-14;
const double INF = 1e50;
long double dp[1010][MAXN];
int fa[1010][MAXN],ord[1010];
double pm[MAXN][MAXN],pw[MAXN][MAXN];
int main()
{
    int ncase,n,m,w;
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d%d%d",&n,&m,&w);
        for(int i=0;i<n;++i)    scanf("%d",&ord[i]);
        for(int i=0;i<m;++i)
            for(int j=0;j<m;++j)
            {
                scanf("%lf",&pm[i][j]);
                if(pm[i][j]>EPS)
                    pm[i][j]=log(pm[i][j]);
                else    pm[i][j]=-INF;
            }
        for(int i=0;i<m;++i)
            for(int j=0;j<w;++j)
            {
                scanf("%lf",&pw[i][j]);
                if(pw[i][j]>EPS)
                    pw[i][j]=log(pw[i][j]);
                else    pw[i][j]=-INF;
            }
        for(int i=0;i<m;++i)    dp[n-1][i]=pw[i][ord[n-1]];
        for(int i=n-2;i>=0;--i)
        {
            for(int j=0;j<m;++j)    dp[i][j]=-INF;
            for(int j=0;j<m;++j)
                if(pw[j][ord[i]]>-INF+EPS)
                    for(int k=0;k<m;++k)
                        if(pm[j][k]>-INF+EPS&&dp[i][j]+EPS<dp[i+1][k]+pm[j][k]+pw[j][ord[i]])
                            dp[i][j]=dp[i+1][k]+pm[j][k]+pw[j][ord[i]],fa[i][j]=k;
        }
        int pos=0;
        long double best=-INF;
        for(int i=0;i<m;++i)
            if(best+EPS<dp[0][i]+pm[0][i])
                best=dp[0][i]+pm[0][i],pos=i;
        printf("%d",pos);
        for(int i=0;i<n-1;++i)
            printf(" %d",pos=fa[i][pos]);
        printf("\n");
    }
    return 0;
}
