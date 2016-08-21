#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
#define maxn 30
double a[maxn];
int main()
{
    int  n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            break;
        }
        int i;
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++)
        {
            scanf("%lf",&a[i]);
        }
        sort(a+1,a+n+1);
        double sum=0.0;
        int flag=0;
        for(i=1;i<=n;i++)
        {
            if(sum>=a[i])
            {
                flag=1;
                printf("YES\n");
                break;
            }
            sum+=a[i];
        }
        if(flag==0)
        {
            printf("NO\n");
        }
    }
    return 0;
}
