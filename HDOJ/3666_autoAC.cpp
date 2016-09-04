#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
using namespace std;
const int V = 808, E=400000;
const double INF=1e5;
double d[V],cost[E];
int n,m,verNum;
int head[V],pnt[E],nxt[E],e;
int cnt[V];
double u,l;
void addedge(int u,int v,double c)
{
    pnt[e]=v;
    cost[e]=c;
    nxt[e]=head[u];
    head[u]=e++;
}
bool relax(int u,int v,double w)
{
    if(d[v]>d[u]+w)
    {
        d[v]=d[u]+w;
        return 1;
    }
    return 0;
}
int spfa()
{
    int vis[V];
    int i;
    //int Q[E];
    queue<int> Q;
    for(i=1;i<verNum;++i)
    {
        cnt[i] = 0;
        d[i]=INF;
        vis[i]=0;
    }
    vis[0]=1;
    d[0]=0;
    cnt[0] = 1;
    //int top=1;
    //Q[0]=0;
    Q.push(0);
    int u,v;
    double w;
    int nm = sqrt(verNum * 1.0); //涓寮归借跺澶╁ㄦ
    while(!Q.empty())
    {
        //u=Q[--top];
        u = Q.front();
        Q.pop();
        vis[u]=0;
        for(i=head[u];i!=-1;i=nxt[i])
        {
            v=pnt[i];
            w=cost[i];
            if(relax(u,v,w) && !vis[v])
            {
                if(++cnt[v] > nm) 
                    return 0;
                //Q[top++]=v;
                Q.push(v);
                vis[v]=1;
            }
        }
    }
    return 1;
}
int main()
{
    while(scanf("%d%d%lf%lf",&n,&m,&l,&u) == 4)
    {
        double c,ll = log(l),uu = log(u);
        int i,j;
        verNum = n + m;
        memset(head,-1,sizeof(head));
        e = 0;
        for(i = 0; i < n; ++i)
            for(j = 0; j < m; ++j)
            {
                scanf("%lf",&c);
                c = log(c);
                addedge(i,j+n,c-ll);
                addedge(j+n,i,uu-c);
            }
        if(spfa())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
