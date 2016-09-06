#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
const double eps=1e-9;
const double pi=acos(-1.0);
using namespace std;
double l, r, ang;
bool mark, ok;
int an, bn, n;
void check(double a)
{
    if((!mark)&&(fabs(a-180.0)>eps)&&(fabs(a)>eps))mark=true;
    if(fabs(a-180.0)<eps)an++;
    else if(fabs(a)<eps)bn++;
    if(a<180.0&&a>l)l=a;
    else if(a>180.0&&360.0-a>r)r=360.0-a;
    if(l+r>180.0)ok=false;
}
int main()
{
    int i, t;
    double tmp;
    scanf("%d", &t);
    while(t-->0)
    {
        ang=0;
        l=r=0;
        mark=false;
        an=0;bn=1;
        ok=true;
        scanf("%d", &n);
        for(i=0; i<n; i++)
        {
            scanf("%lf", &tmp);
            if(ok)
            {
                if(tmp<0)tmp=-tmp;
                else tmp=360.0-tmp;
                ang+=tmp;
                if(ang>=360.0)ang-=360.0;
                check(ang);
            }
        }
        if(ok)
        {
            if(!mark)
            {
                if(an>0)ok=false;
            }
            else
            {
                if(an>0&&fabs(l)<eps)l=180.0;
                else if(an>0&&fabs(r)<eps)r=180.0;
                if(l+r-180.00>eps)ok=false;
            }
        }
        if(ok)printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
