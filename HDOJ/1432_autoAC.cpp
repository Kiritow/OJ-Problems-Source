#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <cmath>
#include <queue>
#include <list>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <iostream>
#include <stack>
using namespace std;
#define ISZREO(x) (fabs(x)<1e-7)
const double PI = acos(-1.0);
struct Point
{
    double x,y;
}a[1100],c[1100],Q;
double b[800];
void fun1(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        c[i].x=a[i].x-Q.x;
        c[i].y=a[i].y-Q.y;
    }
}
void fun2(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        b[i]=atan2(c[i].y,c[i].x);
        if(b[i]<0)b[i]+=PI;
    }
    sort(b,b+n);
}
int main()
{
    int i,n,j,ans,cy;
    double ji,p;
    Point temp;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf",&a[i].x,&a[i].y);
        }
        ans=0;
        for(i=0;i<n;i++)
        {
            Q=a[i];
            fun1(n);
            fun2(n);
            ji=-9999999.99;
            for(j=0;j<n;j++)
            {
                if(!ISZREO(ji-b[j]))
                {
                    cy=1;
                    ji=b[j];
                }
                else 
                {
                    cy++;
                    if(cy>ans)
                    {
                        ans=cy;
                        p=ji;
                    }
                }
            }
        }
        if(ans == 0)ans++;
        if(!ISZREO(p))ans++;
        printf("%d\n",ans);
    }
    return 0;
}
