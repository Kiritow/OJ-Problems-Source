#include <stdio.h>
#include <string.h>
struct node
{
    int v,w;
}p[50];
int maxn,n,k,weight,vis[50];
void dfs(int wei,int val,int step,int sum)
{
    if(sum == k || wei == weight)
    {
        if(maxn<val)
        maxn = val;
        return ;
    }
    for(int i = step;i<=n;i++)
    {
        if(!vis[i] && sum+1<=k && wei+p[i].w<=weight)
        {
            vis[i] = 1;
            dfs(wei+p[i].w,val+p[i].v,i+1,sum+1);
            vis[i] = 0;
        }
    }
    return ;
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(i = 1;i<=n;i++)
        {
            scanf("%d%d",&p[i].v,&p[i].w);
            vis[i] = 0;
        }
        scanf("%d",&weight);
        maxn = 0;
        dfs(0,0,0,0);
        printf("%d\n",maxn);
    }
    return 0;
}
