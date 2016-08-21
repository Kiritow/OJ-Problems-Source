#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define maxt(a,b) (a>b?a:b)
int a[100001];
int b[100001];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int sum1,sum2,sum3,sum4,i,j,n,t,ji,s1,s2,max;
    while(~scanf("%d %d",&n,&t))
    {
        sum1=sum2=sum3=sum4=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n,cmp);
        for(i=0;i<n;i++)
        {
            if(a[i]<0)break;
        }
        ji=i;
        for(j=0;i<n;j++,i++)
        {
            b[j]=abs(a[i]);
        }
        sort(a,a+ji);
        s1=ji;
        s2=n-ji;
        for(i=0;i<s1;i++)
        {
            if(a[i]<=t)sum1++;
            else break;
        }
        for(i=0;i<s2;i++)
        {
            if(b[i]<=t)sum2++;
            else break;
        }
        max=0;
        ji=0;
        for(i=0;i<=t/2;i++)
        {
            ji=0;
            for(j=0;j<=s1;j++)
            {
                if(a[j]<=i)ji++;
                else break;
            }
            for(j=0;j<s2;j++)
            {
                if(b[j]<=t-2*i)ji++;
                else break;
            }
            if(ji>max)max=ji;
        }
        sum3=max;
        max=0;
        ji=0;
        for(i=0;i<=t/2;i++)
        {
            ji=0;
            for(j=0;j<=s2;j++)
            {
                if(b[j]<=i)ji++;
                else break;
            }
            for(j=0;j<s1;j++)
            {
                if(a[j]<=t-2*i)ji++;
                else break;
            }
            if(ji>max)max=ji;
        }
        sum4=max;
        printf("%d\n",maxt(maxt(sum1,sum2),maxt(sum3,sum4)));
    }
    return 0;
}
