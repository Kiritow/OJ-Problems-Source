#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
using namespace std;
const int inf=0x3f3f3f3f;
int head[3010],num[3010],d[3010],pre[3010],cur[3010];
char mp[110][110];
int n,m,cnt,nv,s,t;
int jx[]={0,0,1,-1};
int jy[]={1,-1,0,0};
struct node
{
    int u,v,cap;
    int next;
}edge[10000010];
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
    memset(d,-1,sizeof(d));
    memset(num,0,sizeof(num));
    queue<int >q;
    q.push(t);
    d[t]=0;
    num[0]=1;
    while(!q.empty()) {
        int i;
        int u=q.front();
        q.pop();
        for(i=head[u]; i!=-1; i=edge[i].next) {
            int v=edge[i].v;
            if(d[v]==-1) continue;
            d[v]=d[u]+1;
            num[d[v]]++;
            q.push(v);
        }
    }
}
int isap()
{
    memcpy(cur,head,sizeof(cur));
    int flow=0, u=pre[s]=s, i;
    bfs();
    while(d[s]<nv) {
        if(u==t) {
            int f=inf, pos;
            for(i=s; i!=t; i=edge[cur[i]].v) {
                if(f>edge[cur[i]].cap) {
                    f=edge[cur[i]].cap;
                    pos=i;
                }
            }
            for(i=s; i!=t; i=edge[cur[i]].v) {
                edge[cur[i]].cap-=f;
                edge[cur[i]^1].cap+=f;
            }
            flow+=f;
            u=pos;
        }
        for(i=cur[u]; i!=-1; i=edge[i].next) {
            if(d[edge[i].v]+1==d[u]&&edge[i].cap)
                break;
        }
        if(i!=-1) {
            cur[u]=i;
            pre[edge[i].v]=u;
            u=edge[i].v;
        } else {
            if(--num[d[u]]==0) break;
            int mind=nv;
            for(i=head[u]; i!=-1; i=edge[i].next) {
                if(mind>d[edge[i].v]&&edge[i].cap) {
                    mind=d[edge[i].v];
                    cur[u]=i;
                }
            }
            d[u]=mind+1;
            num[d[u]]++;
            u=pre[u];
        }
    }
    return flow;
}
int main()
{
    int T,n, m, i, j;
    int tt=1;
    char str[110];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        memset(mp,0,sizeof(mp));
        for(i=1;i<=n;i++)
        {
            scanf("%s",str);
            for(j=0;j<m;j++)
            {
                if(str[j]=='E')
                    mp[i][j+1]=2;
                else if(str[j]=='.')
                    mp[i][j+1]=1;
            }
        }
        cnt=0;
        s=0;
        t=(n+2)*(m+2)+1;
        nv=t+1;
        memset(head,-1,sizeof(head));
        for(i=0;i<=n+1;i++)
        {
            for(j=0;j<=m+1;j++)
            {
                if((i+j)%2==0)
                {
                    if(mp[i][j]==1)
                        add(i*(m+2)+j+1,t,inf);
                    else if(mp[i][j]==0)
                        add(s,i*(m+2)+j+1,inf);
                }
                else
                {
                    if(mp[i][j]==0)
                        add(i*(m+2)+j+1,t,inf);
                    else if(mp[i][j]==1)
                    {
                        add(s,i*(m+2)+j+1,inf);
                    }
                }
                for(int k=0;k<4;k++)
                {
                    int x=i+jx[k];
                    int y=j+jy[k];
                    if(x>=0&&x<=n+1&&y>=0&&y<=m+1)
                        add(i*(m+2)+j+1,x*(m+2)+y+1,1);
                }
            }
        }
        int ans;
        ans=isap();
        printf("Case %d: %d\n",tt++,(n+1)*(m+2)+(n+2)*(m+1)-ans);
    }
    return 0;
}
