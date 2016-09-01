#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<climits>
#define clr(x)memset(x,0,sizeof(x))
#define min(a,b)(a)<(b)?(a):(b)
const int INF=INT_MAX;
const int maxn=800;
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
int f[maxn];
int search(int x)
{
    return f[x] == x?x:(f[x] = search(f[x]));
}
void join(int x,int y)
{
    int fx = search(x);
    int fy = search(y);
    if(fx != fy){
        if(fx < fy)
            f[fy] = fx;
        else f[fx] = fy;
    }
}
struct noq
{
    int girl,boy;
}re[maxn*maxn];
int g[maxn][maxn];
int K;
struct Edge
{
    int xu,flow;
}edge[1000000];
int top;
int ok(int ti,int s,int t,int n)
{
    int i, j, k;
    for(i = 0; i < 2*n; i++)
    {
        e[edge[i].xu].c = ti;
        e[edge[i].xu^1].c = 0;
    }
    for(i = 2*n; i < top; i++)
    {
        e[edge[i].xu].c = edge[i].flow;
        e[edge[i].xu^1].c = 0;
    }
    int res = maxflow(s,t,t+1);
    if(res == n*ti)
        return 1;
    return 0;
}
int main()
{
    int T, n, m;
    int i, j, k, F;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d %d",&n, &m, &K, &F);
        for(i = 1; i <= n; i++)
            f[i] = i;
        for(i =  1; i <= m; i++)
            scanf("%d %d",&re[i].girl,&re[i].boy);
        int a, b;
        while(F--){
            scanf("%d %d",&a, &b);
            join(a,b);
        }
        clr(g);
        for(i = 1; i <= m; i++)
            g[search(re[i].girl)][re[i].boy] = 1;
        for(i = 1; i <= n; i++)
            for(j = 1;j <= n; j++)
                if(g[search(i)][j] == 1)
                    g[i][j] = 1;
        int s = 0;
        int t = n*3+1;
        tot = 0;
        memset(head,-1,sizeof(head));
        top = 0;
        for(i = 1; i <= n; i++){
            edge[top++].xu = tot;
            add(s,i,1,0);
        }
        for(i = n*2+1; i <= n*3; i++)
        {
            edge[top++].xu = tot;
            add(i,t,1,0);
        }
         for(i = 1; i <= n; i++){
            edge[top].xu = tot;
            edge[top++].flow = K;
            add(i,i+n,K,0);
        }
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
            {
                if(g[i][j]){
                    edge[top].xu = tot;
                    edge[top++].flow = 1;
                    add(i,j+2*n,1,0);
                }
                else{
                    edge[top].xu = tot;
                    edge[top++].flow = 1;
                    add(i+n,j+2*n,1,0);
                }
            }
        int l = 0, r = n, mid;
        int res=0;
        while(l <= r){
            mid = (l+r)>>1;
            if(ok(mid,s,t,n)){
                res = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        printf("%d\n",res);
    }
    return 0;
}
