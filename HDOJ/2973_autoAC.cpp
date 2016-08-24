#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
#define LL long long
#define M 3100300
int tag[M],p[M];
void Prime()
{
    memset(tag,0,sizeof(tag));
    memset(p,0,sizeof(p));
    int cnt=0,i,j;
    for( i=2;i<M;i++)
    {
        if(!tag[i])
            p[cnt++]=i;
        for( j=0;j<cnt&&p[j]*i<M;j++)
        {
            tag[i*p[j]]=1;
            if(i%p[j]==0)
                break;
        }
    }
    memset(p,0,sizeof(p));
    for( i=1;i<M/3;i++)
    {
        LL t=3*i+7;
        if(tag[t]==0)
            p[i]=p[i-1]+1;
        else
            p[i]=p[i-1];
    }
}
int main()
{
    int n,t;
    Prime();
    scanf("%d",&t);
    while(t--)
    {
            scanf("%d",&n);
            printf("%d\n",p[n]);
    }
    return 0;
}
