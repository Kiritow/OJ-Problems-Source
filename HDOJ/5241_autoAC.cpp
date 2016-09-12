#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int a[10000],b[10000],c[10000];
void SP()
{
    memset(c,0,sizeof(c));
    int i,j;
    for(i=1;i<=a[0];i++)
        for(j=1;j<=b[0];j++)
            c[i+j-1]+=a[i]*b[j];
    i=1;
    for(i=1;i<9999;i++)
    {
        c[i+1]+=c[i]/10;
        a[i]=c[i]%10;
        if(a[i]) a[0]=i;
    }
}
void PP()
{
    memset(c,0,sizeof(c));
    int i,j;
    for(i=1;i<=b[0];i++)
        for(j=1;j<=b[0];j++)
            c[i+j-1]+=b[i]*b[j];
    i=1;
    for(i=1;i<9999;i++)
    {
        c[i+1]+=c[i]/10;
        b[i]=c[i]%10;
        if(b[i]) b[0]=i;
    }
}
int main()
{
    int t,tm;
    scanf("%d",&t);tm=t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("Case #%d: ",tm-t);
        if(!n) printf("1\n");
        else
        {
            n*=5;
            memset(a,0,sizeof(a));
            memset(b,0,sizeof(b));
            a[0]=1;a[1]=1;
            b[0]=1;b[1]=2;
            while(n)
            {
                if(n%2)
                    SP();
                PP();
                n/=2;
            }
            for(int i=a[0];i;i--) printf("%d",a[i]);
            printf("\n");
        }
    }
    return 0;
}
