#include <cstring>
#include <cstdio>
#include <queue>
#include <iostream>
#define inf 0x3f3f3f3f
#define MAXN 3000
#define MAXM 30000
using namespace std;
struct node
{
    int u,v,f,c;
};
node e[MAXM];
int first[MAXN],ne[MAXM],cc;
int inq[MAXN],pre[MAXN],preedge[MAXN],d[MAXN];
inline void add_edge(int u,int v,int f,int c)
{
    e[cc].u=u;
    e[cc].v=v;
    e[cc].f=f;
    e[cc].c=c;
    ne[cc]=first[u];
    first[u]=cc;
    cc++;
    e[cc].v=u;
    e[cc].u=v;
    e[cc].f=0;
    e[cc].c=-c;
    ne[cc]=first[v];
    first[v]=cc;
    cc++;
}
int SPFA(int s,int t)
{
    memset(inq,0,sizeof(inq));
    int i;
    for(i=0;i<=t;i++)
        d[i]=-inf;
    memset(pre,-1,sizeof(pre));
    memset(preedge,-1,sizeof(preedge));
    d[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        inq[u]=0;
        int i;
        for(i=first[u];i!=-1;i=ne[i])
        {
            int v=e[i].v;
            if(e[i].f)
            {
                if(d[v]<d[u]+e[i].c)
                {
                    d[v]=d[u]+e[i].c;
                    pre[v]=u;
                    preedge[v]=i;
                    if(!inq[v])
                    {
                        inq[v]=1;
                        q.push(v);
                    }
                }
            }
        }
    }
    if(d[t]==-inf)
        return 0;
    else
        return 1;
}
int Min_Cost_Flow(int s,int t)
{
    int ans_flow=0,ans_cost=0,mm,tmp;
    while(SPFA(s,t))
    {
        mm=inf;
        int u=t;
        while(pre[u]!=-1)
        {
            tmp=preedge[u];
            mm=min(mm,e[tmp].f);
            u=pre[u];
        }
        u=t;
        while(pre[u]!=-1)
        {
            tmp=preedge[u];
            e[tmp].f-=mm;
            e[tmp^1].f+=mm;
            u=pre[u];
        }
        ans_flow+=mm;
        ans_cost+=mm*d[t];
    }
    return ans_cost;
}
int V[100],H[100],P[100],A[100],B[100];
int win(int i,int j)
{
    int x,y;
    if(P[j]%A[i]==0)
        x=P[j]/A[i];
    else
        x=P[j]/A[i]+1;
    if(H[i]%B[j]==0)
        y=H[i]/B[j];
    else
        y=H[i]/B[j]+1;
    if(x<=y)
        return 1;
    else
        return 0;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        memset(first,-1,sizeof(first));
        memset(ne,-1,sizeof(ne));
        cc=0;
        int i;
        for(i=1;i<=n;i++)
            scanf("%d",&V[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&H[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&P[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&A[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&B[i]);
        int s=0,t=2*n+1,j;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(win(i,j))
                {
                    if(i==j)
                        add_edge(i,n+j,1,V[i]*100+1);
                    else
                        add_edge(i,n+j,1,V[i]*100);
                }
                else
                {
                    if(i==j)
                        add_edge(i,n+j,1,-V[i]*100+1);
                    else
                        add_edge(i,n+j,1,-V[i]*100);
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            add_edge(0,i,1,0);
            add_edge(n+i,t,1,0);
        }
        int res=Min_Cost_Flow(s,t);
        if(res/100<=0)
            printf("Oh, I lose my dear seaco!\n");
        else
            printf("%d %.3f%%\n",res/100,100*1.0*(res%100)/n);
    }
    return 0;
}
