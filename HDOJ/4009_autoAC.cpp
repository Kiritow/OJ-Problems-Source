#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define INF 0x3FFFFFF
#define MAXN 2222
struct edge
{
    int  u,v,w;
}e[99999999];
int  a,b,c; 
int n,en;
int pre[MAXN],in[MAXN],id[MAXN],vis[MAXN];
int x[MAXN],y[MAXN],z[MAXN]; 
int getdis(int i,int j)
{
    return abs(x[i]-x[j])+abs(y[i]-y[j])+abs(z[i]-z[j]);
}
void add(int u,int v,int w)
{
    e[en].u=u;
    e[en].v=v;
    e[en++].w=w;
}
int zl(int root ,int vn)
{
    int ans=0;
    int cnt;
    while(1)  
    {
        for(int i=0;i<vn;i++)
            in[i]=INF,id[i]=-1,vis[i]=-1;
        for(int i=0;i<en;i++)
        {
            if(in[e[i].v]>e[i].w && e[i].u!=e[i].v)
            {
                pre[e[i].v]=e[i].u;
                in[e[i].v]=e[i].w;
            } 
        }
        in[root]=0;
        pre[root]=root;
        for(int i=0;i<vn;i++)
        {
            ans+=in[i];
            if(in[i]==INF)
                 return -1; 
        }
        cnt=0; 
        for(int i=0;i<vn;i++)
        {
            if(vis[i]==-1)
            {
                int t=i;
                while(vis[t]==-1)
                {
                    vis[t]=i;
                    t=pre[t];
                }
                if(vis[t]!=i || t==root) continue;
                for(int j=pre[t];j!=t;j=pre[j])
                    id[j]=cnt;
                id[t]=cnt++;
            }
        }
        if(cnt==0) break;
        for(int i=0;i<vn;i++)
            if(id[i]==-1)  
                id[i]=cnt++;
        for(int i=0;i<en;i++)
        {
            int u,v;
            u=e[i].u;
            v=e[i].v;
            e[i].u=id[u];
            e[i].v=id[v];
            e[i].w-=in[v];
        }
        vn=cnt;
        root=id[root];
    }
    return ans;
}
void solve()
{
    int cnt,j;
    en=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
        add(0,i,z[i]*a);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&cnt);
        for(int k=1;k<=cnt;k++)
        {
            scanf("%d",&j);
            if(i==j)
                continue;
            if(z[i]>=z[j])
                add(i,j,getdis(i,j)*b);
            else
                add(i,j,getdis(i,j)*b+c);
        }
    }
    int ans=zl(0,n+1);
    if(ans==-1)
    {
        printf("poor XiaoA\n");
        return;
    }
    printf("%d\n",ans);    
}
int main()
{
    while(scanf("%d%d%d%d",&n,&a,&b,&c)!=EOF && n+a+b+c)
        solve();
    return 0;
}
