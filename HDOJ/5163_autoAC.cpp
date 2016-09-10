#include<iostream>
#include<cstdio>
using namespace std;
__int64 tt[100005];
__int64 sum[100005];
int main()
{
    int t;
    scanf("%d",&t);
    int n,m;
    int x,y;
    while(t--)
    {
        scanf("%d %d",&n,&m);
        tt[1]=tt[0]=0;
        for(int i=2;i<=n;i++)
        {
            scanf("%I64d",&tt[i]);
            tt[i]=tt[i-1]+tt[i];
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d %d",&x,&y);
            int now=(i-1)%n+1;
            if(now<=x && x<y)
                sum[i]=tt[y]-tt[now];
            if(now>x && x<y)
              sum[i]=2*tt[n]-tt[now]+tt[y];
            if(y<x)
                sum[i]=2*tt[n]-tt[now]-tt[y];
        }
        for(int i=1;i<=m;i++)
            printf("%I64d\n",sum[i]);
    }
     return 0;
}
