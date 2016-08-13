#include <stdio.h>
int p[1222];
int i;
int find(int x)
{
    if(x!=p[x])
        p[x]=find(p[x]);
    return p[x];
}
int hebing(int x,int y)
{
    return p[x]=y;
}
int main()
{
    int n,m,x,y,x1,y1;
    while(~scanf("%d%d",&n,&m)&&n)
    {
        for(i=1;i<=1222;i++)
            p[i]=i;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            x1=find(x);
            y1=find(y);
            if(x1!=y1)
                hebing(x1,y1);
        }
        int ans=0;
        for(i=1;i<=n;i++)
        {
            if(p[i]==i)
                ans++;
        }
        printf("%d\n",ans-1);
    }
    return 0;
}
