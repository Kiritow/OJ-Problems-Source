#include <stdio.h>
#include <cmath>
#include <vector>
#include <map>
#include <time.h>
#include <cstring>
#include <set>
#include<iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define inf 0x6f6f6f6f
double liangdianzhijiandejuli(double ax,double ay,double x1,double y1)
{
    return sqrt((ax-x1)*(ax-x1)+(ay-y1)*(ay-y1));
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double ax,ay,bx,by,cx,cy,k,l;
        double x1,y1,ans;
        scanf("%lf",&k);
        scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy);
        if((k*ax-ay-k*cx+cy)*(k*bx-by-k*cx+cy)>0)
        {
            y1=(2*bx*k+by*k*k-by-2*k*cx+2*cy)/(k*k+1);
            x1=bx-(y1-by)*k;
            ans=liangdianzhijiandejuli(ax,ay,x1,y1);
        }
        else
             ans=liangdianzhijiandejuli(ax,ay,bx,by);
             printf("%.2lf\n",ans);
    }
    return 0;
}
