#include <set>
#include <map>
#include <queue>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define eps 1e-8
#define pi acos(-1.0)
#define inf 107374182
#define inf64 1152921504606846976
#define lc l,m,tr<<1
#define rc m + 1,r,tr<<1|1
#define iabs(x)  ((x) > 0 ? (x) : -(x))
#define clear1(A, X, SIZE) memset(A, X, sizeof(A[0]) * (SIZE))
#define clearall(A, X) memset(A, X, sizeof(A))
#define memcopy1(A , X, SIZE) memcpy(A , X ,sizeof(X[0])*(SIZE))
#define memcopyall(A, X) memcpy(A , X ,sizeof(X))
#define max( x, y )  ( ((x) > (y)) ? (x) : (y) )
#define min( x, y )  ( ((x) < (y)) ? (x) : (y) )
using namespace std;
struct node1
{
    double x,y,l,r;
    bool operator <(const node1 a)const
    {
        return l<a.l;
    }
} Point[1005];
int main()
{
    int n,T,ans,cnt;
    double d,temp,now,drift,r;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%lf",&n,&d);
        for(int i=0; i<n; i++)
        {
            scanf("%lf%lf",&Point[i].x,&Point[i].y);
            temp=sqrt(Point[i].x*Point[i].x+Point[i].y*Point[i].y);
            if(temp<=d)
            {
                n--;
                i--;
            }
            else
            {
                if(Point[i].x==0)
                {
                    if(Point[i].y>0)now=0.5*pi;
                    else now=1.5*pi;
                }
                else if(Point[i].y==0)
                {
                    if(Point[i].x>0)now=0;
                    else now=pi;
                }
                else
                {
                    now=asin(iabs(Point[i].y)/temp);
                    if(Point[i].x<0&&Point[i].y>=0)now=pi-now;
                    else if(Point[i].x<=0&&Point[i].y<0)now+=pi;
                    else if(Point[i].x>0&&Point[i].y<=0)now=2*pi-now;
                }
                drift=asin(d/temp);
                //printf("*%lf %lf\n",now,drift);
                Point[i].l=now-drift;
                Point[i].r=now+drift;
            }
        }
        if(n==0)
        {
            puts("0");
            continue;
        }
        sort(Point,Point+n);
        for(int i=n; i<2*n; i++)
        {
            Point[i]=Point[i-n];
            Point[i].l+=2*pi;
            Point[i].r+=2*pi;
        }
        ans=inf;
        for(int i=0; i<n; i++)
        {
            r=Point[i].r;
            cnt=1;
            for(int j=i+1; j<n+i; j++)
            {
                if(r>Point[j].r)r=Point[j].r;
                else if(r<Point[j].l)
                {
                    cnt++;
                    r=Point[j].r;
                }
            }
            ans=min(ans,cnt);
        }
        printf("%d\n",ans);
    }
    return 0;
}
