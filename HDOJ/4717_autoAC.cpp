#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
const double eps=1e-14;
const int maxn=303;
int n;
struct node{
    double x,y,vx,vy;
}e[maxn*maxn];
double cross(node a,node b,double t)
{
    return (a.x+a.vx*t-b.x-b.vx*t)*(a.x+a.vx*t-b.x-b.vx*t)+(a.y+a.vy*t-b.y-b.vy*t)*(a.y+a.vy*t-b.y-b.vy*t);
}
double find(double t)
{
    double ans=0;
    int i,j;
    for(i=0;i<n;i++)
    for(j=i+1;j<n;j++)
        ans=max(ans,cross(e[i],e[j],t));
    return ans;
}
int main()
{
    int T,tt=0;
    scanf("%d",&T);
    while(T--)
    {
        int i,j,k;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%lf%lf%lf%lf",&e[i].x,&e[i].y,&e[i].vx,&e[i].vy);
        double l,r,m1,m2;
        l=0,r=1e8;
        for(i=0;i<100;i++)
        {
            m1=l+(r-l)/3;
            m2=r-(r-l)/3;
            if(find(m1)<find(m2)) r=m2;
            else l=m1;
        }
        printf("Case #%d: %.2lf %.2lf\n",++tt,l,sqrt(find(l)));
    }
    return 0;
}
