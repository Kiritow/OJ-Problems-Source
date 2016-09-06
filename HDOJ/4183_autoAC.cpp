#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int head[10000], s, t, nv, maxint=99999999, cnt;
int cur[400], num[400], d[400], q[100000], pre[400];
struct Node
{
    double q;
    int x, y, r;
}dian[1000];
int cmp(Node x, Node y)
{
    return x.q<y.q;
}
struct node
{
    int u, v, cap, next;
}edge[100000];
void add(int u, int v, int cap)
{
    edge[cnt].v=v;
    edge[cnt].cap=cap;
    edge[cnt].next=head[u];
    head[u]=cnt++;
    edge[cnt].v=u;
    edge[cnt].cap=0;
    edge[cnt].next=head[v];
    head[v]=cnt++;
}
void bfs()
{
    memset(num,0,sizeof(num));
    memset(d,-1,sizeof(d));
    int f1=0, f2=0, i;
    q[f1++]=t;
    d[t]=0;
    num[0]=1;
    while(f1>=f2)
    {
        int u=q[f2++];
        for(i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].v;
            if(d[v]==-1)
            {
                d[v]=d[u]+1;
                num[d[v]]++;
                q[f1++]=v;
            }
        }
    }
}
void isap()
{
    memcpy(cur,head,sizeof(cur));
    bfs();
    int flow=0, u=pre[s]=s, i;
    while(d[s]<nv)
    {
        if(u==t)
        {
            int f=maxint, pos;
            for(i=s;i!=t;i=edge[cur[i]].v)
            {
                if(f>edge[cur[i]].cap)
                {
                    f=edge[cur[i]].cap;
                    pos=i;
                }
            }
            for(i=s;i!=t;i=edge[cur[i]].v)
            {
                edge[cur[i]].cap-=f;
                edge[cur[i]^1].cap+=f;
            }
            flow+=f;
            u=pos;
        }
        for(i=cur[u];i!=-1;i=edge[i].next)
        {
            if(d[edge[i].v]+1==d[u]&&edge[i].cap)
            {
                break;
            }
        }
        if(i!=-1)
        {
            cur[u]=i;
            pre[edge[i].v]=u;
            u=edge[i].v;
        }
        else
        {
            if(--num[d[u]]==0) break;
            int mind=nv;
            for(i=head[u];i!=-1;i=edge[i].next)
            {
                if(mind>d[edge[i].v]&&edge[i].cap)
                {
                    cur[u]=i;
                    mind=d[edge[i].v];
                }
            }
            d[u]=mind+1;
            num[d[u]]++;
            u=pre[u];
        }
    }
    if(flow>=2)
        printf("Game is VALID\n");
    else
        printf("Game is NOT VALID\n");
}
int main()
{
    int i, j, n, x, y, r, T;
    scanf("%d",&T);
    while(T--)
    {
        memset(head,-1,sizeof(head));
        cnt=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lf%d%d%d",&dian[i].q,&dian[i].x,&dian[i].y,&dian[i].r);
        }
        sort(dian,dian+n,cmp);
        if(dian[0].r+dian[n-1].r*1.0>sqrt((dian[0].x-dian[n-1].x)*(dian[0].x-dian[n-1].x)*1.0+(dian[0].y-dian[n-1].y)*(dian[0].y-dian[n-1].y)*1.0))
        {
            printf("Game is VALID\n");
            continue ;
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(dian[i].r*1.0+dian[j].r>sqrt((dian[i].x-dian[j].x)*(dian[i].x-dian[j].x)+(dian[i].y-dian[j].y)*(dian[i].y-dian[j].y)))
                {
                    add(i,j,1);
                }
            }
        }
        s=0;
        t=n-1;
        nv=t+1;
        isap();
    }
    return 0;
}
