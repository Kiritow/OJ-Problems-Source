#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<climits>
#include<queue>
using namespace std;
#define clr(x)memset(x,0,sizeof(x))
#define min(a,b)(a)<(b)?(a):(b)
const int INF=INT_MAX;
const int maxn=1005;
const int maxm=1000000;
struct node
{
    int from,to,next,c;
}e[maxm];
int tot;
int head[maxn];
void add(int s,int u,int f1,int f2)
{
    e[tot].from=s;
    e[tot].to=u;
    e[tot].c=f1;
    e[tot].next=head[s];
    head[s]=tot++;
    e[tot].from=u;
    e[tot].to=s;
    e[tot].c=f2;
    e[tot].next=head[u];
    head[u]=tot++;
}
int q[maxn];
int cnt[maxn];
int d[maxn];
int low[maxn];
int cur[maxn];
int maxflow(int s,int t,int n)
{
    int *front=q,*rear=q;
    for(int i=1;i<=n;i++)
    {
        d[i]=n;
        cnt[i]=0;
    }
    cnt[n]=n-1;
    cnt[0]++;
    d[t]=0;
    *rear++=t;
    while(front<rear)
    {
        int v=*front++;
        for(int i=head[v];i!=-1;i=e[i].next)
        {
            if(d[e[i].to]==n&&e[i^1].c>0)
            {
                d[e[i].to]=d[v]+1;
                cnt[n]--;
                cnt[d[e[i].to]]++;
                *rear++=e[i].to;
            }
        }
    }
    int flow=0, u=s, top=0;
    low[0]=INF;
    for(int i=1;i<=n;i++)
        cur[i]=head[i];
    while(d[s]<n)
    {
        int &i=cur[u];
        for(;i!=-1;i=e[i].next)
        {
            if(e[i].c>0&&d[u]==d[e[i].to]+1)
            {
                low[top+1]=min(low[top],e[i].c);
                q[++top]=i;
                u=e[i].to;
                break;
            }
        }
        if(i!=-1)
        {
            if(u==t)
            {
                int minf=low[top];
                for(int p=1,i;p<=top;++p)
                {
                    i=q[p];
                    e[i].c-=minf;
                    e[i^1].c+=minf;
                }
                flow+=minf;
                u=s;
                low[0]=INF;
                top=0;
            }
        }
        else
        {
            int old_du=d[u];
            cnt[old_du]--;
            d[u]=n-1;
            for(int i=head[u];i!=-1;i=e[i].next)
                if(e[i].c>0&&d[u]>d[e[i].to])
                    d[u]=d[e[i].to];
            cnt[++d[u]]++;
            if(d[u]<n)
                cur[u]=head[u];
            if(u!=s)
            {
                u=e[q[top]].from;
                --top;
            }
            if(cnt[old_du]==0)
                break;
        }
    }
    return flow;
}
struct EDGE
{
    int from,to,next,w;
}edge[maxm],ee[maxm];
int head2[maxn];
int head3[maxn];
int tt;
int t3;
void add2(int s,int t,int wi)
{
    edge[tt].from = s;
    edge[tt].to = t;
    edge[tt].w = wi;
    edge[tt].next = head2[s];
    head2[s] = tt++;
}
void add3(int s,int t,int wi)
{
    ee[t3].from = s;
    ee[t3].to = t;
    ee[t3].w = wi;
    ee[t3].next = head3[s];
    head3[s] = t3++;
}
struct dd
{
    int xu, di;
    bool operator < (dd t)const{
        return t.di<di;
    }
}x,in;
priority_queue<dd>dis;
int d1[maxn];
int d2[maxn];
void dijkstra(int u,int*d,int*hed,EDGE*ed,int&t)
{
    int i;
    in.xu = u;
    in.di = 0;
    d[u] = 0;
    dis.push(in);
    while(!dis.empty())
    {
        x = dis.top();
        dis.pop();
        for(i = hed[x.xu]; i; i = ed[i].next){
            in.xu = ed[i].to;
            in.di = x.di+ed[i].w;
            if(in.di < d[in.xu]){
                d[in.xu] = in.di;
                dis.push(in);
            }
        }
    }
}
int main()
{
    int T, i;
    int n, m, st, en;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n, &m);
        clr(head2);
        clr(head3);
        tt = 1;
        t3 = 1;
        int a,b,c;
        while(m--)
        {
            scanf("%d %d %d",&a, &b, &c);
            add2(a,b,c);
            add3(b,a,c);
        }
        scanf("%d %d",&st,&en);
        for(i = 1; i <= n; i++)
            d2[i] = d1[i] = INF;
        dijkstra(st,d1,head2,edge,tt);
        dijkstra(en,d2,head3,ee,t3);
        memset(head,-1,sizeof(head));
        tot = 0;
        for(i = 1; i < tt; i++)
        {
            if(d1[edge[i].from]+d2[edge[i].to]+edge[i].w == d1[en])
                add(edge[i].from,edge[i].to,1,0);
        }
        int res = maxflow(st,en,n);
        printf("%d\n",res);
    }
    return 0;
}
