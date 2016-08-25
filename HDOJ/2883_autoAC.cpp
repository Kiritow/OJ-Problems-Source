#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <climits>
#include <algorithm>
using namespace std;
#define min(a,b)(a)<(b)?(a):(b)
const int INF=INT_MAX;
const int maxn=2000;
const int maxm=10000000;
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
    for(int i=0;i<n;i++)
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
    for(int i=0;i<n;i++)
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
struct edge
{
    int st,en,c,d;
}ta[205];
int di[500];
int main()
{
    int i, j, k, n, m;
    int sum;
    while(scanf("%d %d",&m, &n)!=EOF)
    {
        tot = 0;
        sum = 0;
        memset(head,-1,sizeof(head));
        int s = 0;
        int t = m+2*m;
        int a,b,c,d;
        int top = 0;
        for(i = 1; i <= m; i++)
        {
            scanf("%d %d %d %d",&ta[i].st, &ta[i].c, &ta[i].en, &ta[i].d);
            di[top++] = ta[i].st;
            di[top++] = ta[i].en;
        }
        sort(di,di+top);
        top--;
        for(i = 1; i <= top; i++)
            add(i+m,t,(di[i]-di[i-1])*n,0);
        for(i = 1; i <= m; i++)
        {
            add(s,i,ta[i].c*ta[i].d,0);
            sum += ta[i].c*ta[i].d;
            for(j = 1; j <= top; j++)
                if(ta[i].st<=di[j-1]&&di[j] <=ta[i].en)
                      add(i,j+m,INF,0);
        }
        int res = maxflow(s,t,t+1);
        if(res == sum)
        printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
