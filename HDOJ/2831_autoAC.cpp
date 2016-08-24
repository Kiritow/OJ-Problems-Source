#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 111
int n,need;
int V[N],D[N];
int match[N],visit[N];
struct Eage{
    int to,next;
}eage[N*N];
int tot,head[N];
void add(int a,int b){
    eage[tot].to=b;eage[tot].next=head[a];head[a]=tot++;
}
int dfs(int k)
{
    int j,v;
    for(j=head[k];j!=-1;j=eage[j].next)
    {
        v=eage[j].to;
        if(visit[v])    continue;
        visit[v]=1;
        if(k*need+D[v]>V[v])    continue;
        if(match[v]==-1 || dfs(match[v]))
        {
            match[v]=k;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int i,l;
    int flag;
    while(scanf("%d%d",&n,&need)!=-1)
    {
        for(i=1;i<=n;i++)    scanf("%d%d",&V[i],&D[i]);
        tot=0;
        memset(head,-1,sizeof(head));
        for(i=1;i<=n;i++)for(l=1;l<=n;l++)
            add(i,l);
        flag=0;
        memset(match,-1,sizeof(match));
        for(i=1;i<=n;i++)
        {
            memset(visit,0,sizeof(visit));
            if(!dfs(i))    {flag=1;break;}
        }
        if(flag)    {printf("The zombies eat your brains!\n");continue;}
        for(i=1;i<=n;i++)    if(match[i]==1)    {printf("%d",i);break;}
        for(i=2;i<=n;i++)
        for(l=1;l<=n;l++)
            if(match[l]==i)    {printf(" %d",l);break;}
        printf("\n");
    }
    return 0;
}
