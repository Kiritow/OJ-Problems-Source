#include<iostream>
#include<memory.h>
#include<string>
#include<cstdio>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std; 
const int MAX=205;
const int inf=999999;
struct node
{
    int v,c,next;
}g[MAX*MAX];
int adj[MAX],dis[MAX],cur[MAX],num[MAX],pre[MAX];
int n,m,e,s,t,vn,S,H;
void add(int u,int v,int c)  
{  
    g[e].v=v; g[e].c=c; g[e].next=adj[u]; adj[u]=e++;  
    g[e].v=u; g[e].c=0; g[e].next=adj[v]; adj[v]=e++;  
}  
int sap()  
{  
    int i,u,v,flag,aug=inf+1,flow=0; 
    for(i=0;i<=vn;i++)  
    {  
        cur[i]=adj[i];  
        num[i]=dis[i]=0;  
    }  
    num[0]=vn;  
    pre[s]=u=s;  
    while(dis[s]<vn)  
    {  
        flag=0;  
        for(i=adj[u];i!=-1;i=g[i].next)  
        {  
            v=g[i].v;  
            if(g[i].c&&dis[u]==dis[v]+1)  
            {  
                flag=1;  
                aug=min(aug,g[i].c);  
                pre[v]=u;  
                cur[u]=i;  
                u=v;  
                if(u==t)  
                {  
                    flow+=aug;  
                    while(u!=s)  
                    {  
                        u=pre[u];  
                        g[cur[u]].c-=aug;  
                        g[cur[u]^1].c+=aug;  
                    }  
                    aug=inf+1;  
                }  
                break;  
            }  
        }  
        if(flag)  
            continue;  
        if(--num[dis[u]]==0)  
            break;  
        for(dis[u]=inf,i=adj[u];i!=-1;i=g[i].next)  
        {  
            v=g[i].v;  
            if(g[i].c&&dis[v]<dis[u])  
            {  
                dis[u]=dis[v];  
                cur[u]=i;  
            }  
        }  
        dis[u]++;  
        num[dis[u]]++;  
        u=pre[u];  
    }  
    return flow;  
}  
int main()
{
    int i,j,k,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&m,&S,&H);
        e=0;
        vn=2*n+2;
        s=S+n;
        t=H;
        memset(adj,-1,sizeof(adj));
        add(s,S,inf);
        add(H+n,T,inf);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&k);
            if(i!=S&&i!=H)
            {
                add(i,i+n,k);
            }
            else
            {
                add(i,i+n,inf);
            }
        }
        while(m--)
        {
            scanf("%d%d",&i,&j);
            if(i!=s&&j!=t)
            {
                add(i+n,j,inf);
                add(j+n,i,inf);
            }
            else
            {
                if(i==s)
                {
                    add(s,j,inf);
                }
                else
                {
                    add(i+n,t,inf);
                }
            }
        }
        printf("%d\n",sap());
    }
    return 0;
}
