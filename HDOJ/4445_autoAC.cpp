#include<cstdio>
#include<cmath>
const double PI=acos(-1.0);
const double eps=PI/276;
int n;
double h,l1,r1,l2,r2,v[200];
int cal(double x)
{
    int i,c=0;
    for(i=0;i<n;i++)
    {
        double v0=v[i]*sin(x),v1=v[i]*cos(x);
        double t=(sqrt(2*9.8*h+v1*v1)-v1)/9.8;
        double s=v0*t;
        if(s>=l2&&s<=r2) return 0;
        if(s>=l1&&s<=r1) c++;
    }
    return c;
}
int main()
{
    int i,ans;
    while(scanf("%d",&n),n)
    {
        scanf("%lf%lf%lf%lf%lf",&h,&l1,&r1,&l2,&r2);
        for(i=0;i<n;i++)scanf("%lf",&v[i]);
        double j=0;ans=0;
        while(j<PI)
        {
            int tmp=cal(j);
            if(tmp>ans) ans=tmp;
            j+=eps;
        }
        printf("%d\n",ans);
    }
    return 0;
}
