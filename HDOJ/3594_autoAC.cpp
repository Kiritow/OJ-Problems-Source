# include<stdio.h>
# include<string.h>
# define N 20005
# define M 50005
# include<stack>
using namespace std;
struct node{
    int from,to,next;
}edge[M];
int tol,head[N],dfn[N],low[N],flag,count,cnt,n;
bool visit[N],vis[N];
stack<int>S;
void add(int a,int b)
{
    edge[tol].from=a;edge[tol].to=b;edge[tol].next=head[a];head[a]=tol++;
}
int min(int a,int b)
{
    return a<b?a:b;
}
void tarjan(int u)
{
    int j,v;
    dfn[u]=low[u]=cnt++;
    visit[u]=vis[u]=1;
    S.push(u);
    for(j=head[u];j!=-1;j=edge[j].next)
    {
        v=edge[j].to;
        if(!visit[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]) 
        {
            low[u]=min(low[u],dfn[v]);
            if(dfn[v]!=low[v]) flag=1; 
        }
        if(flag) return;
    }
    if(dfn[u]==low[u])
    {
        count++;
        do{
            v=S.top();
            S.pop();
            vis[v]=0;
        }while(v!=u);
    }
}
int main()
{
    int i,ncase,a,b;
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d",&n);
        tol=0;
        memset(head,-1,sizeof(head));
        while(scanf("%d%d",&a,&b)!=EOF)
        {
            if(!a && !b) break;
            add(a,b);
        }
        memset(visit,0,sizeof(visit));
        memset(vis,0,sizeof(vis));
        flag=0;
        count=0;
        cnt=0;
        for(i=0;i<n;i++)
            if(!visit[i]) tarjan(i);
        if(flag||count!=1) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
