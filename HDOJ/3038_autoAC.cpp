#include<stdio.h>
#define MAXN 200010
int f[MAXN],r[MAXN];
int find(int x)
{
    if(x==f[x])
        return f[x];
    int t=find(f[x]);
    r[x]=r[x]+r[f[x]];                                 
    f[x]=t;
    return f[x];
}
int fun(int x,int y)
{
    if(x>y)
        return x-y;
    else y-x;
}
int Union(int x,int y,int sum)
{
    int a=find(x);
    int b=find(y);
    if(a==b)
    {
        if(fun(r[x],r[y])==sum)
            return 0;
        else return 1;
    }
    else 
    {
        f[a]=b;
        r[a]=r[y]+sum-r[x];
        return 0;
    }
}
int main()
{
    int n,m,i,ans,a,b,s;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        ans=0;
        for(i=0;i<=n;i++)
        {
            f[i]=i;
            r[i]=0;
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&a,&b,&s);
            a--;
            if(Union(a,b,s))
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
