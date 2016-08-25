#include<stdio.h>
int n,m,min;
int ai[10],mi[10],used[10];
int dfs(int dep,int hp)
{
    int i;    
    if(hp<=0)
    {
        if(dep-1<min) min=dep-1;
        return 0; 
    }
    if(dep>=min) return 0;
    for(i=1;i<=n;i++)
        if(used[i]==0)
        {
            used[i]=1;
            if(hp<=mi[i]) 
                dfs(dep+1,hp-2*ai[i]);
            else 
                dfs(dep+1,hp-ai[i]);
            used[i]=0;
        }
}
int main()
{
    int i;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++) scanf("%d%d",&ai[i],&mi[i]);
        for(i=1;i<=n;i++) used[i]=0;
        min=n+1;
        dfs(1,m);
        if(min==n+1) min=-1;
        printf("%d\n",min);
    }
}
