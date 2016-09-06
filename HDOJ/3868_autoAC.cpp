#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define eps 1e-6
typedef struct
{
    double x,y;
}point;
point a[20005];
double ret;
point tag[20005];
double Dist(point p,point q)
{
    return sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y));
}
bool cmpx(point p,point q)
{
    if (p.x!=q.x) return p.x<q.x;
    return p.y<q.y;
}
bool cmpy(point p,point q)
{
    if (p.y!=q.y) return p.y<q.y;
    return p.x<q.x;
}
void Merge(int l,int r)
{
    int mid,x,y,i,j,k;
    double m;
    if (r-l+1<=6)
    {
        for (i=l;i<=r;i++)
        {
            for (j=i+1;j<=r;j++)
            {
                m=Dist(a[i],a[j]);
                if (m>ret/2) continue;
                for (k=j+1;k<=r;k++)
                {
                    ret=min(ret,m+Dist(a[j],a[k])+Dist(a[i],a[k]));
                }
            }
        }
        return;
    }
    mid=(l+r)/2;
    Merge(l,mid);
    Merge(mid+1,r);
    int up=0;
    for (i=l;i<=r;i++)
    {
        if (fabs(a[mid].x-a[i].x)<ret/2) tag[up++]=a[i];
    }
    sort(tag,tag+up,cmpy);
    for (i=0;i<up;i++)
    {
        for (j=i+1;j<up && j<=i+7;j++)
        {
            m=Dist(tag[i],tag[j]);
            if (m>ret/2) continue;
            for (k=j+1;k<up && k<=j+7;k++)
            {
                ret=min(ret,m+Dist(tag[j],tag[k])+Dist(tag[i],tag[k]));
            }
        }
    }
}
int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for (i=0;i<n;i++)
        {
            scanf("%lf%lf",&a[i].x,&a[i].y);
        }
        sort(a,a+n,cmpx);
        ret=999999999;
        Merge(0,n-1);
        printf("%.3lf\n",ret);
    }
    return 0;
}
