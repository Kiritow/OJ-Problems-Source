#include <stdio.h>
#include <math.h>
#include <string.h>
int p[20000];
bool sushu(int a)
{
    int i;
    for(i=2;i<=sqrt((double)(a));i++)
    {
        if(a%i==0)
            return 0;
    }
    return 1;
}
bool huiwen(int a)
{
    int b[44];
    int l=0,i;
    int c=a;
    while(a)
    {
        b[l++]=a%10;
        a/=10;
    }
    for(i=0;i<l/2;i++)
    {
        if(b[i]!=b[l-1-i])
            break;
    }
    if(i==l/2 &&sushu(c))
        return 1;
    else
        return 0;
}
int main()
{
    int i;
    int a,b;
    memset(p,0,sizeof(p));
    int l=0;
    for(i=5;i<=9989900;i++)
    {
        if(huiwen(i))
        {
            p[l++]+=i;
        }
    }
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        for(i=0;i<l;i++)
        {
            if(p[i]  &&p[i]>=a &&p[i]<=b)
                printf("%d\n",p[i]);
        }
        printf("\n");
    }
    return 0;
}
