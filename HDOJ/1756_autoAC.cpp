#include <iostream>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
#define esp 1e-8
#define ISZERO(a) (fabs(a)<1e-8)
#define ADD 1001
int n;
struct Point
{
    double x,y;
}a[110],b;
double chac(Point q,Point w,Point e,Point r)
{
    return (((w.x-q.x)*(e.y-q.y)-(w.y-q.y)*(e.x-q.x)) * ((w.x-q.x)*(r.y-q.y)-(w.y-q.y)*(r.x-q.x)));
}
bool calc()
{
    int i=0,ans;
    double c1,c2,c3;
    Point c;
    a[n]=a[0];
    while(i<n)
    {
        c.x=rand()+ADD;
        c.y=rand()+ADD;
        for(i=ans=0;i<n;i++)
        {
            c1=chac(b,c,a[i],a[i+1]);
            c2=chac(a[i],a[i+1],b,c);
            c3=chac(a[i+1],a[i],b,c);
            if(ISZERO(c1) && ISZERO(c2) && ISZERO(c3))return true;//杩浠ユ璇杈圭广
            if(ISZERO(c1))
            {
                if(!ISZERO(c2) || !ISZERO(c3))break;
            }
            if(c1<esp && c2<esp)ans++;
        }
    }
    return ans%2;
}
int main()
{
    int i,j,m;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf",&a[i].x,&a[i].y);
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%lf %lf",&b.x,&b.y);
            if(calc())printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
