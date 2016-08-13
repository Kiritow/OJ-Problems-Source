#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
double r[4];
int is_integer(double t)
{
    int i=t+0.0000005;
    if(fabs(t-i)<0.000001)
        return i;
    return 0;
}
int try_height(int i,int sw)
{
    double dh=sw/r[i];
    int h=dh+.0000005;
    if(fabs(h-dh)<0.000001)
        return h;
    return -1;
}
int try_weight(int i,int sh)
{
    double dw=sh*r[i];
    int w=dw+.0000005;
    if(fabs(w-dw)<0.000001)
        return w;
    return -1;
}
bool fill(int sw, int sh)
{
    int w,h,tw,th,j,k,a[4]={0,1,2,3};
    for(j=0;j<24;j++)
    {
        tw=sw,th=sh;
        for(k=0;k<4&&th&&tw;k++)
        {
            h=try_height(a[k],tw);
            if(h!=-1&&h<=th)
                th-=h;
            else
            {
                w=try_weight(a[k],th);
                if(w==-1||w>tw)
                    break;
                tw-=w;
            }
        }
        if (k==4&&(!tw||!th))
            return true;
        next_permutation(a,a+4);
    }
    return false;
}
int fit(int w ,int i,int j)
{
    double h=w/(r[i]+r[j]);
    int ret=is_integer(h);
    if(is_integer(h*r[i]) && is_integer(h*r[j]))
        return ret;
    return 0;
}
bool mixture(int sw,int sh)
{
    int a[4]={0,1,2,3};
    int i,j,k,h1,h2,tw,th;
    for(i=0;i<24;i++)
    {
        tw=sw,th=sh;
        h1=fit(tw,a[0],a[1]);
        h2=fit(tw,a[2],a[3]);
        if(h1&&h2&&h1+h2==sh)
            return true;
        next_permutation(a,a+4);
    }
    return false;
}
int main()
{
    int i,t,w,h,sw,sh;
    for(t=1;scanf("%d%d",&sw,&sh),sw+sh;t++)
    {
        bool found=false;
        for(i=0;i<4;i++)
        {
            scanf("%d%d",&w,&h);
            r[i]=w*1.0/h;
        }
        if(fill(sw,sh))
            found=true;
        else
        {
            if(mixture(sw,sh))
                found=true;
            else
            {
                for(i=0;i<4;i++)
                    r[i]=1/r[i];
                found=mixture(sh,sw);
            }
        }
        if(found)
            printf("Set %d: Yes\n",t);
        else
            printf("Set %d: No\n",t);
    }
    return 0;
}
