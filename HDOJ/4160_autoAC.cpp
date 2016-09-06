#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 510
    struct  d
    {
        int w,l,h;
    }doll[max];
int match[max][max];
int link[max];
bool used[max];
 int n;
bool  dfs(int u)
{
    for(int v=1;v<=n;v++)
        if(match[u][v]==1&&!used[v])
        {
            used[v]=true;
            if(link[v]==-1||dfs(link[v]))
            {
                link[v]=u;
                return true;
            }
        }
    return false;
}
int Xiong()
{
    int res=0;
    memset(link,-1,sizeof(link));
    for(int i=1;i<=n;i++)
    {
        memset(used,false,sizeof(used));
            if(dfs(i))
                res++;
    }
    return res;
}
int main()
{
    int i,j;
    while(scanf("%d",&n)==1&&n)
    {
        for(i=1;i<=n;i++)
            scanf("%d%d%d",&doll[i].w,&doll[i].l,&doll[i].h);
        memset(match,0,sizeof(match));                     
         for(i=1;i<=n;i++) 
             for(j=1;j<=n;j++)
                 if(doll[i].w>doll[j].w&&doll[i].l>doll[j].l&&doll[i].h>doll[j].h)
                     match[i][j]=1;
         printf("%d\n",n-Xiong());        
    }
    return 0;
}
