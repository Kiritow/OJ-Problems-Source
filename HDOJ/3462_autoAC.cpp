#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define inf 1000000000
struct edge
{
    int to,cost,next;
    int T, mod;
}e[32000];
struct node
{
    int x,y,z;
    node(int _x=0, int _y=0, int _z=0):x(_x),y(_y),z(_z){}
    bool operator<(const node& a)const
    {
        return y>a.y;
    }
};
priority_queue<node> que;
bool visit[4000];
int dis[4000][2];
int pre[4000];
int next[8000];
int n,m,num;
int a[40][40];
void addedge(int from, int to, int cost, int T, int mod)
{
    e[num].to=to;e[num].cost=cost;
    e[num].T=T;e[num].mod=mod;
    e[num].next=pre[from];
    pre[from]=num;
    num++;
}
void make_map()
{
    num=1;
    memset(pre, 0, sizeof(pre));
    for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
    {
        addedge(4*i*m+4*j, 4*i*m+4*j+1, 1, a[i][j], 1);addedge(4*i*m+4*j+1, 4*i*m+4*j, 1, a[i][j], 1);
        addedge(4*i*m+4*j, 4*i*m+4*j+2, 1, a[i][j], 0);addedge(4*i*m+4*j+2, 4*i*m+4*j, 1, a[i][j], 0);
        addedge(4*i*m+4*j+3, 4*i*m+4*j+1, 1, a[i][j],0);addedge(4*i*m+4*j+1, 4*i*m+4*j+3, 1, a[i][j], 0);
        addedge(4*i*m+4*j+3, 4*i*m+4*j+2, 1, a[i][j],1);addedge(4*i*m+4*j+2, 4*i*m+4*j+3, 1, a[i][j], 1);
        if (j!=m-1)
        {
            addedge(4*i*m+4*j+1,4*i*m+4*(j+1),2,0,0);addedge(4*i*m+4*(j+1),4*i*m+4*j+1,2,0,0);
            addedge(4*i*m+4*j+3,4*i*m+4*(j+1)+2,2,0,0);addedge(4*i*m+4*(j+1)+2,4*i*m+4*j+3,2,0,0);
        }
        if (i!=n-1)
        {
            addedge(4*i*m+4*j+2,4*(i+1)*m+4*j,1,0,0);addedge(4*(i+1)*m+4*j,4*i*m+4*j+2,1,0,0);
            addedge(4*i*m+4*j+3,4*(i+1)*m+4*j+1,1,0,0);addedge(4*(i+1)*m+4*j+1,4*i*m+4*j+3,1,0,0);
        }
    }
}
void get_in(int to,int cost,int id)
{
    if (dis[to][id]<=cost||dis[to][0]<=cost) return;
    dis[to][id]=cost;
    que.push(node(to,cost,id));
}
int dfs(int x,int tt)
{
    while(!que.empty()) que.pop();
    for (int i=0;i<4*n*m;i++)
    {
        visit[i]=0;
        dis[i][0]=dis[i][1]=inf;
    }
    que.push(node(x,tt,0));
    while(!que.empty())
    {
        node out=que.top();
        que.pop();
        int x=out.x,y=out.y,z=out.z;
        if (visit[x]) continue;
        if (z==0)
        visit[x]=1;
        if (x==4*n*m-1) break;
        for (int i=pre[x]; i!=0; i=e[i].next)
        if (!visit[e[i].to])
        {
            int ty;
            if (e[i].T==0)
            {
                ty=y+e[i].cost;
                get_in(e[i].to,ty,z);
            }
            else
            {
                int tmp=(y+e[i].T-1)/e[i].T;
                if (y%e[i].T==0) tmp++;
                if (tmp%2==e[i].mod)
                {
                    ty=y+1;
                    get_in(e[i].to,ty,z);
                }
                else
                {
                    if (z==0)
                    {
                        ty=y+1;
                        get_in(e[i].to,ty,1);
                    }
                    ty=y+e[i].T-y%e[i].T+1;
                    get_in(e[i].to,ty,z);
                }
            }
        }
    }
    return min(dis[4*n*m-1][0],dis[4*n*m-1][1]);
}
int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        n--;m--;
        for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            scanf("%d",&a[i][j]);
        make_map();
        char tt[50];
        int ta,tb;
        scanf("%s",tt);
        for (int i=0;tt[i];i++)
        if (tt[i]==':') tt[i]=' ';
        sscanf(tt,"%d %d",&ta,&tb);
        ta=ta*60+tb;
        int ans=dfs(0,ta);
        ta=ans/60;
        tb=ans%60;
        printf("%02d:%02d\n",ta,tb);
    }
    return 0;
}
