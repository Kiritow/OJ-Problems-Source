#include<stdio.h>
#include<math.h>
#define eps 1e-5
#define PI 3.1415926535897932384626
int n,a[10001];
double angle;
int i,j,k,maxtop;
double dis[10001],t,top,ans,low,h;
int main()
{
    while(~scanf("%d%lf",&n,&angle))
    {
        if(angle<-eps) for(i=n-1;i>=0;i--) scanf("%d",&a[i]);
        else for(i=0;i<n;i++) scanf("%d",&a[i]);
        if(angle<-eps) angle=-angle;
        angle=PI*angle/180.0;
        t=-1;ans=0;
        for(i=0;i<n;i++)
        {
            dis[i]=((i+1)*tan(angle)+a[i]*1.0)/sqrt(tan(angle)*tan(angle)+1);
            if(t<dis[i]){t=dis[i];maxtop=i;} 
        }
        for(i=0;i<maxtop;i++)
        {
            top=a[i];
            for(j=i+1;j<=maxtop;j++)
            {
                if(dis[j]>dis[i]+eps)
                {
                    if(dis[j]-sin(angle)>dis[i]+eps)
                    {
                        top-=(j-i-1)*1.0*tan(angle);
                        ans+=(j-i-1)*(j-i-1)*0.5*tan(angle);
                    }
                    else
                    {
                        top-=(a[i]-a[j])*1.0;
                        ans+=(a[i]-a[j])*(a[i]-a[j])*0.5/tan(angle);
                    }
                    for(k=i+1;k<j;k++)
                        ans+=(top-a[k])*1.0;
                    i=j-1;
                    break;
                }
            }
        }
        for(i=n-1;i>maxtop;i--)
        {
            for(j=i-1;j>=maxtop;j--)
            {
                    h=i-j;
                    low=h*tan(angle)-(a[j+1]-a[i]);
                    top=(h-1)*tan(angle)-(a[j+1]-a[i]);
                    ans+=(top+low)/2.0;
                if(dis[j]>dis[i]+eps)
                    break;
            }
            i=j+1;
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
