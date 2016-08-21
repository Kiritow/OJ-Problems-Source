#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int MAXN=10010;
struct Node
{
    int to;
    int next;
    int len;
}edge[MAXN*2];
int head[MAXN];
int tol;
int maxn[MAXN];
int smaxn[MAXN];
int maxid[MAXN];
int smaxid[MAXN];
void init()
{
    tol=0;
    memset(head,-1,sizeof(head));
}
void add(int a,int b,int len)
{
    edge[tol].to=b;
    edge[tol].len=len;
    edge[tol].next=head[a];
    head[a]=tol++;
    edge[tol].to=a;
    edge[tol].len=len;
    edge[tol].next=head[b];
    head[b]=tol++;
}
void dfs1(int u,int p)
{
    maxn[u]=0;
    smaxn[u]=0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==p)continue;
        dfs1(v,u);
        if(smaxn[u]<maxn[v]+edge[i].len)
        {
            smaxn[u]=maxn[v]+edge[i].len;
            smaxid[u]=v;
            if(smaxn[u]>maxn[u])
            {
                swap(smaxn[u],maxn[u]);
                swap(smaxid[u],maxid[u]);
            }
        }
    }
}
void dfs2(int u,int p)
{
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==p)continue;
        if(v==maxid[u])
        {
            if(edge[i].len+smaxn[u]>smaxn[v])
            {
                smaxn[v]=edge[i].len+smaxn[u];
                smaxid[v]=u;
                if(smaxn[v]>maxn[v])
                {
                    swap(smaxn[v],maxn[v]);
                    swap(smaxid[v],maxid[v]);
                }
            }
        }
        else
        {
            if(edge[i].len+maxn[u]>smaxn[v])
            {
                smaxn[v]=edge[i].len+maxn[u];
                smaxid[v]=u;
                if(smaxn[v]>maxn[v])
                {
                    swap(smaxn[v],maxn[v]);
                    swap(maxid[v],smaxid[v]);
                }
            }
        }
        dfs2(v,u);
    }
}
int main()
{
    int n;
    int v,len;
    while(scanf("%d",&n)!=EOF)
    {
        init();
        for(int i=2;i<=n;i++)
        {
            scanf("%d%d",&v,&len);
            add(i,v,len);
        }
        dfs1(1,-1);
        dfs2(1,-1);
        for(int i=1;i<=n;i++)
          printf("%d\n",maxn[i]);
    }
    return 0;
}
