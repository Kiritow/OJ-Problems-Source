#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
const double pi=acos(-1);
int R,r,H,t,S;
double getlen(int n,double r)
{
    return 2.0*r*tan(pi/n);
}
int main()
{
    while(scanf("%d%d%d%d%d",&R,&r,&H,&t,&S)!=EOF)
    {
        double h=(double)H/t,ans=0;
        int limit=100000;
        for(int i=t;i>=1;i--)
        {
            double rr=1.0*(R-r)/t*(i-1)+r;
            int mi=3,ma=limit,mid,num;
            double s;
            while(mi<=ma)
            {
                mid=(mi+ma)>>1;
                double tmp=getlen(mid,rr)*h;
                if(tmp-S>1e-8)
                {
                    s=tmp;
                    num=mid;
                    mi=mid+1;
                }
                else
                ma=mid-1;
            }
            ans+=num*s;
            limit=num;
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}
