#include <iostream>
#include <string.h>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
double a[150][150];
int b[150];
int main()
{
    int n,c,t,vr,vt1,vt2,l,i,j,k;
    double tr,ji;
    while(~scanf("%d",&l))
    {
        memset(a,0,sizeof(a));
        scanf("%d %d %d %d %d %d",&n,&c,&t,&vr,&vt1,&vt2);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
        }
        tr=(l*1.0)/(vr*1.0);
        b[n+1]=l;
        for(i = 0;i <= n + 1;i++)
        {
            for(j = i+1;j <= n + 1;j++)
            {
                ji=a[0][i];
                for(k=1;k<i;k++)
                {
                    if(ji>a[k][i])
                    {
                        ji=a[k][i];
                    }
                }
                if(i)a[i][j]+=ji+t;
                else a[i][j]+=ji;
                if(vt1>vt2)
                {
                    if(c<b[j]-b[i])
                    {
                        a[i][j]+=(c*1.0)/(vt1*1.0)+((b[j]-b[i]-c)*1.0)/(vt2*1.0);
                    }
                    else
                    {
                        a[i][j]+=((b[j]-b[i])*1.0)/(vt1*1.0);
                    }
                }
                else
                {
                    a[i][j]+=((b[j]-b[i])*1.0)/(vt2*1.0);
                }
            }
        }
        ji=a[0][n+1];
        for(k=1;k<n+1;k++)
        {
            if(ji>a[k][n+1])ji=a[k][n+1];
        }
        if(ji<tr)
        {
            printf("What a pity rabbit!\n");
        }
        else
        {
            printf("Good job,rabbit!\n");
        }
    }
    return 0;
}
