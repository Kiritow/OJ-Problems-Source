#include<iostream>
#include<string.h>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int s[160];
int a[160];
void su(void)
{
    int i,j;
    for(i=2;i<151;i++)
    {
        if(!s[i])
        {
            for(j=i*2;j<151;j+=i)
            {
                s[j]=1;
            }
        }
    }
}
int main()
{
    int i,j,t,n;
    memset(s,0,sizeof(s));
    su();
    memset(a,0,sizeof(a));
    a[0]=1;
    for(i=2;i<151;i++)
    {
        if(!s[i])
        {
            for(j=i;j<151;j++)
            {
                a[j]+=a[j-i];
            }
        }
    }
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            scanf("%d",&n);
            printf("%d\n",a[n]);
        }
    }
    return 0;
}
