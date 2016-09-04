#include <string.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 409
int S,T;
struct edge
{
    int v,flow,cost;
    edge *next,*opp;
}A[500009],*adj[maxn];
#define NEW() &A[++ANS]
int ANS;
inline void addedge(int u,int v,int flow,int cost)
{
    edge *ptr=NEW();
    ptr->v=v;
    ptr->flow=flow;
    ptr->cost=cost;
    ptr->next=adj[u]->next;
    ptr->opp=&A[ANS^1];
    adj[u]->next=ptr;
}
#define Inf 1000000000
int q[1000009],d[maxn];
bool vis[maxn];
edge *pre[maxn];
bool spfa()
{
    memset(vis,0,sizeof(vis));
    for(int i=S;i<=T;i++)
        d[i]=Inf;
    int head=0,tail=1,u,v;
    q[0]=S;
    d[S]=0;
    while(head!=tail)
    {
        u=q[head++];
        vis[u]=false;
        for(edge *ptr=adj[u]->next;ptr!=NULL;ptr=ptr->next)
        {
            v=ptr->v;
            if(ptr->flow&&d[v]>d[u]+ptr->cost)
            {
                d[v]=d[u]+ptr->cost;
                pre[v]=ptr;
                if(!vis[v])
                {
                    vis[v]=true;
                    q[tail++]=v;
                }
            }
        }
    }
    return d[T]!=Inf;
}
int solve()
{
    int mincost=0;
    while(spfa())
    {
        edge *ptr;
        int low=Inf;
        for(int i=T;i!=S;)
        {
            ptr=pre[i];
            low=min(low,ptr->flow);
            i=ptr->opp->v;
        }
        for(int i=T;i!=S;)
        {
            ptr=pre[i];
            ptr->flow-=low;
            ptr->opp->flow+=low;
            i=ptr->opp->v;
        }
        if(d[T]>=0)
            break;
        mincost+=low*d[T];
    }
    return mincost;
}
int main()
{
    int Q;
    scanf("%d",&Q);
    while(Q--)
    {
        int s,t,v,n;
        S=0;    
        scanf("%d",&n);
        ANS=-1;
        for(int i=0;i<406;i++)
        {
            adj[i]=new edge();
            adj[i]->next=NULL;
        }
        for(int k=1;k<=n;k++)
        {
            scanf("%d%d%d",&s,&t,&v);
            s++;
            t++;
            addedge(s,t+1,1,-v);
            addedge(t+1,s,0,v);
            T=max(T,t+1);
        }
        for(int i=S;i<T;i++)
        {
            addedge(i,i+1,2,0);
            addedge(i+1,i,0,0);
        }
        printf("%d\n",-solve());
    }
    return 0;
}
