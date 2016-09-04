#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 10010;
int tot,n,m,ans;
const int inf = 999999999;
struct Edge
{
    int t,w;
    int next;
    int vis;
}edge[1000005];
int head[maxn],E;
void add(int s,int t,int w)
{
    edge[E].t=t;
    edge[E].w=w;
    edge[E].vis=0;
    edge[E].next=head[s];
    head[s]=E++;
}
int Btype,Time,N,M;
int dfn[maxn],low[maxn],belong[maxn];
int  st[maxn],Top;
int tt[100010][3],cnt;
inline int min(int a,int b){return a<b?a:b;}
void dfs(int s)
{
    int i,t;
    st[++Top]=s;
    dfn[s]=low[s]=++Time;
    for (i=head[s];i!=-1;i=edge[i].next)
    {    
        if(edge[i].vis)continue;    
        edge[i].vis=edge[i^1].vis=1;
        t=edge[i].t;
        if (!dfn[t])
        {
            dfs(t);
            low[s]=min(low[s],low[t]);
            if(dfn[s]<low[t])  
            {
                tt[++cnt][0]=s,tt[cnt][1]=t,tt[cnt][2]=edge[i].w;
            }
        }
        else low[s]=min(low[s],dfn[t]);
    }
    if(dfn[s]==low[s])
    {
        Btype++;
        do{
            t=st[Top--];
            belong[t]=Btype;
        }while(t!=s);
    }
}
void SCC(int n)
{
    int i;
    Time=0;Btype=0;Top=0;
    memset(dfn,0,sizeof(int)*(n+1));
    for(i=1;i<=n;i++)if(!dfn[i])
        dfs(i);
}
int find(int s,int t)
{
    int i;
    int Min=inf,vice_Min=inf,rr=inf;
    for(i=head[s];i!=-1;i=edge[i].next)
    {
        int v=edge[i].t;
        if(v==t) continue;
        int w=find(v,s);
        if(w<vice_Min) vice_Min=w; 
        if(edge[i].w<vice_Min) vice_Min=edge[i].w;
        if(Min>vice_Min) swap(vice_Min,Min);
        if(Min<rr) rr=Min;
    }
    if(ans>vice_Min) ans=vice_Min;
    return rr;
}
int a1,a2,flag;
int main()
{
    int i,a,b,w;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(head,-1,sizeof(head));E=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            add(a,b,w);
            add(b,a,w);
        }
        cnt=0;     
        SCC(n);
        memset(head,-1,sizeof(head));E=0;
        int C=inf;
        for(i=1;i<=cnt;i++)
        {
            add(belong[tt[i][0]],belong[tt[i][1]],tt[i][2]);
            add(belong[tt[i][1]],belong[tt[i][0]],tt[i][2]);
            if(tt[i][2]<C){C=tt[i][2]; a=belong[tt[i][0]],b=belong[tt[i][1]];}
        }
        ans=inf;
        find(a,b);
        find(b,a);
        if(ans==inf) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}
