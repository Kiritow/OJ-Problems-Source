#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<memory.h>
using namespace std;
const int M=10002;
const int INF=(1e9)-1;
int t,n,m,tot;
int gap[M],dis[M],pre[M],head[M],cur[M],s[M];
int NE,NV,sink,a[M],b[M],c[M],d[M];
struct Node
{
    int c,pos,next;
} E[M*4];
#define FF(i,NV) for(int i=0;i<NV;i++)
int sap(int s,int t)
{
    memset(dis,0,sizeof(int)*(NV+1));
    memset(gap,0,sizeof(int)*(NV+1));
    FF(i,NV) cur[i] = head[i];
    int u = pre[s] = s,maxflow = 0,aug =INF;
    gap[0] = NV;
    while(dis[s] < NV)
    {
loop:
        for(int &i = cur[u]; i != -1; i = E[i].next)
        {
            int v = E[i].pos;
            if(E[i].c && dis[u] == dis[v] + 1)
            {
                aug=min(aug,E[i].c);
                pre[v] = u;
                u = v;
                if(v == t)
                {
                    maxflow += aug;
                    for(u = pre[u]; v != s; v = u,u = pre[u])
                    {
                        E[cur[u]].c -= aug;
                        E[cur[u]^1].c += aug;
                    }
                    aug =INF;
                }
                goto loop;
            }
        }
        if( (--gap[dis[u]]) == 0)   break;
        int mindis = NV;
        for(int i = head[u]; i != -1 ; i = E[i].next)
        {
            int v = E[i].pos;
            if(E[i].c && mindis > dis[v])
            {
                cur[u] = i;
                mindis = dis[v];
            }
        }
        gap[ dis[u] = mindis+1 ] ++;
        u = pre[u];
    }
    return maxflow;
}
void addEdge(int u,int v,int c )
{
    E[NE].c = c;
    E[NE].pos = v;
    E[NE].next = head[u];
    head[u] = NE++;
    E[NE].c = 0;
    E[NE].pos = u;
    E[NE].next = head[v];
    head[v] = NE++;
}
int main()
{
    int n, m,sum, source, sink, vn,k;
    while(scanf("%d %d", &n, &m),(n||m))
    {
        NE=0,tot=0;
        sum = 0;
        source = 0;
        sink=m+1;
        NV=sink+1;
        memset(head, -1, sizeof(head));
        memset(s,0,sizeof(s));
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&vn);
            addEdge(source,i,vn);
            sum+=vn;
        }
        scanf("%d",&k);
        for(int i=1;i<=k;i++)
        {
            scanf("%d%d%d%d",&a[i],&b[i],&d[i],&c[i]);
            s[d[i]]+=c[i];
        }
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(i!=j&&b[i]==a[j]&&d[i]!=d[j])
                {
                    addEdge(d[i],d[j],INF);
                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            addEdge(i,sink,s[i]);
        }
        printf("%d\n",sum-sap(source,sink));
    }
    return 0;
}
