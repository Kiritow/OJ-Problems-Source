#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define base 10000
#define maxx 100
void multiply(int a[],int max,int b)
{
    int i,array=0;
    for(i=max-1;i>=0;i--)
    {
        array+=b*a[i];
        a[i]=array%base;
        array/=base;
    }
}
void divide(int a[],int max,int b)
{
    int i,div=0;
    for(i=0;i<max;i++)
    {
        div=div*base+a[i];
        a[i]=div/b;
        div%=b;
    }
}
int main()
{
    int n,i;
    int a[101][maxx];                                                                      
    memset(a[1],0,maxx*sizeof(int));
    for(i=2,a[1][maxx-1]=1;i<101;i++)
    {
        memcpy(a[i],a[i-1],maxx*sizeof(int));
        multiply(a[i],maxx,4*i-2);
        divide(a[i],maxx,i+1);
    }
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<maxx&&a[n][i]==0;i++);
        printf("%d",a[n][i++]);
        for(;i<maxx;i++)
        {
            printf("%04d",a[n][i]);
        }
        printf("");
        printf("\n");
    }
    return 0;
}
