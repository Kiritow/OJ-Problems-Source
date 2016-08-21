#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#define NUM 1100
#define N 33
#define M 11
using namespace std;
int dp[N][N][M],Max[N][N][M];
int sum[N][N][N][N][M];
struct num
{
    int x,y,t;
}a[NUM];
bool cmp(num p1,num p2)
{
    return p1.x<p2.x;
}
int main()
{
    int n,d,m;
    while(scanf("%d %d %d",&n,&d,&m)!=EOF)
    {
        if(!n&&!m&&!d)
        {
            break;
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].t);
            a[i].x+=5;
            a[i].y+=5;
        }
        n=n+7;
        sort(a+1,a+m+1,cmp);
        for(int x1=0;x1<=n-1;x1++)
        {
            for(int y1=0;y1<=n-1;y1++)
            {
                for(int x2=0;x2<=n-1;x2++)
                {
                    for(int y2=0;y2<=n-1;y2++)
                    {
                        for(int t=1;t<=10;t++)
                        {
                            sum[x1][y1][x2][y2][t]=0;
                        }
                    }
                }
            }
        }
        for(int x1 = 0;x1<=n-1;x1++)
        {
            for(int y1=0;y1<=n-1;y1++)
            {
                for(int x2=x1;x2<=n-1&&x2<=x1+d;x2++)
                {
                    int y2=0;
                    if(x2==x1)
                    {
                        y2 = y1;
                    }
                    for(;y2<=n-1&&y2<=y1+d;y2++)
                    {
                        if(((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))>d*d)
                        {
                            continue;
                        }
                        for(int i=1;i<=m;i++)
                        {
                            int x = a[i].x;
                            int y = a[i].y;
                            int t = a[i].t;
                            if(x>x2)
                            {
                                break;
                            }
                            if(x1==x2&&y1==y2&&x==x1&&y==y1)
                            {
                                sum[x1][y1][x2][y2][t]++;
                                continue;
                            }else if(x1==x2&&y1==y2)
                            {
                                continue;
                            }
                            if(x==x1&&x==x2&&y>=y1&&y<=y2)
                            {
                                sum[x1][y1][x2][y2][t]++;
                                sum[x2][y2][x1][y1][t]++;
                                continue;
                            }
                            double k = (double)(y2-y1)/(double)(x2-x1);
                            double D = (double)(y2) - k *(double)(x2);
                            if(fabs(k*(double)(x)+D-(double)(y))<=1e-7&&x>=x1&&x<=x2)
                            {
                                sum[x1][y1][x2][y2][t]++;
                                sum[x2][y2][x1][y1][t]++;
                            }
                        }
                    }
                }
            }
        }
        memset(dp,0,sizeof(dp));
        memset(Max,0,sizeof(Max));
        for(int t=1;t<=10;t++)
        {
            for(int x1 =0;x1<=n-1;x1++)
            {
                for(int y1=0;y1<=n-1;y1++)
                {
                    for(int x2=0;x2<=n-1;x2++)
                    {
                        for(int y2=0;y2<=n-1;y2++)
                        {
                            //dp[x1][y1][x2][y2][t];
                            if(((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))>d*d)
                            {
                                continue;
                            }
                            int mmax=0;
                            for(int kb=1;kb<=t-1;kb++)
                            {
                                mmax=max(mmax,dp[x1][y1][kb]);
                            }
                            Max[x2][y2][t]=max(Max[x2][y2][t],mmax+sum[x1][y1][x2][y2][t]);
                        }
                    }
                }
            }
            for(int x2=0;x2<=n-1;x2++)
            {
                for(int y2=0;y2<=n-1;y2++)
                {
                   dp[x2][y2][t] = Max[x2][y2][t];
                }
            }
        }
        int res = 0;
        for(int i=0;i<=n-1;i++)
        {
            for(int j=0;j<=n-1;j++)
            {
                for(int t=1;t<=10;t++)
                {
                    res = max(res,dp[i][j][t]);
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
