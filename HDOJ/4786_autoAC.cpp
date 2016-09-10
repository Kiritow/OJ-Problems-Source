#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int fib[30];
struct st
{
    int l,r,c;
}edge[100005];
int fa[100005];
int cmp(const void *a,const void *b)
{
    return (*(st*)b).c-(*(st*)a).c;
}
int getfa(int a)
{
    if(0==fa[a])
        return a;
    else
        return fa[a]=getfa(fa[a]);
}
int main()
{
    fib[0]=1,fib[1]=2;
    int flag;
    for(int i=2;fib[i-1]<=100000;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
    int t,ti=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&edge[i].l,&edge[i].r,&edge[i].c);
        }
        memset(fa,0,sizeof(fa));
        qsort(edge+1,m,sizeof(edge[0]),cmp);
        int hi=0,sum=0;
        for(int i=1;i<=m;i++)
        {
            int x=getfa(edge[i].l);
            int y=getfa(edge[i].r);
            if(x!=y)
            {
                fa[x]=y;
                hi+=edge[i].c;
                sum++;
            }
        }
        if(sum!=n-1)
        {
            printf("Case #%d: No\n",ti);
            ti++;
            continue;
        }
        int lo=0;
        memset(fa,0,sizeof(fa));
        for(int i=m;i>0;i--)
        {
            int x=getfa(edge[i].l);
            int y=getfa(edge[i].r);
            if(x!=y)
            {
                fa[x]=y;
                lo+=edge[i].c;
            }
        }
        flag=0;
        int i=0;
        while(fib[i]<=hi)
        {
            if(fib[i]>=lo&&fib[i]<=hi)
            {
                flag=1;
                break;
            }
            i++;
        }
        if(flag==1)
            printf("Case #%d: Yes\n",ti);
        else
            printf("Case #%d: No\n",ti);
        ti++;
    }
    return 0;
}
