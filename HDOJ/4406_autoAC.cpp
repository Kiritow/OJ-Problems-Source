#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
#include <vector>
#include <string>
#include <set>
#define LL long long
#define myabs(x) ((x)>0?(x):(-(x)))
using namespace std;
const int inf=0x3f3f3f3f;
const double tinf=100000;
const int maxn=100;
const int maxm=1500*2;
struct Edge
{
    int from,to,next;
    double val,cap,flow;
};
Edge e[maxm];
int head[maxn];
int cre[maxn],bas[maxn],vis[maxn];
double dis[maxn],score[110];
int p[maxn];
int n,kin,m,tot,s,t;
void addedge(int from,int to,double cap,double val)
{
    e[tot].from=from; e[tot].to=to;
    e[tot].cap=cap; e[tot].flow=0;
    e[tot].val=val;
    e[tot].next=head[from];
    head[from]=tot++;
    e[tot].from=to; e[tot].to=from;
    e[tot].cap=0; e[tot].flow=0;
    e[tot].next=head[to];
    e[tot].val=-val;
    head[to]=tot++;
}
double mfmc()
{
    queue<int> q;
    int f;
    double sum=0;
    int i;
    for(;;)
    {
        for(i=s;i<=t;i++) dis[i]=-inf;
        memset(vis,0,sizeof(vis));
        dis[s]=0;
        vis[s]=1;
        q.push(s);
        int i,v;
        while(!q.empty())
        {
            f=q.front(); q.pop();
            vis[f]=0;
            for(i=head[f];i!=-1;i=e[i].next)
            {
                v=e[i].to;
                if(e[i].cap>e[i].flow&&dis[f]+e[i].val>dis[v])
                {
                    p[v]=i;
                    dis[v]=dis[f]+e[i].val;
                    if(!vis[v])
                    {
                        vis[v]=1;
                        q.push(v);
                    }
                }
            }
        }
        if(dis[t]<=0) break;
        double a=(double)inf;
        for(i=t;i!=s;)
        {
            a=min(a,e[p[i]].cap-e[p[i]].flow);
            i=e[p[i]].from;
        }
        sum+=a*dis[t];
        for(i=t;i!=s;)
        {
            e[p[i]].flow+=a;
            e[p[i]^1].flow-=a;
            i=e[p[i]].from;
        }
    }
    return sum;
}
int main()
{
    int i;
    for(i=60;i<=100;i++) score[i]=4.0-3.0*(100-i)*(100-i)/1600;
    while(~scanf("%d%d%d",&n,&kin,&m))
    {
        if(!n&&!kin&&!m) break;
        memset(head,-1,sizeof(head));
        int j,k,tem;
        s=0; t=n+m+1;
        tot=0;
        double w=0,basic=0,sum=0;
        for(i=1;i<=m;i++)
        {
            scanf("%d",&cre[i]);
            w+=cre[i];
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d",&bas[i]);
            if(bas[i]<60)
            {
                addedge(0,i,60-bas[i],tinf);
                sum=sum+(60-bas[i])*tinf;
                bas[i]=60;
            }
            basic=basic+score[bas[i]]*cre[i];
            for(j=bas[i]+1;j<=100;j++)
                addedge(0,i,1,(score[j]-score[j-1])*cre[i]);
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf("%d",&tem);
                if(tem)
                    addedge(j,m+i,inf,0);
            }
        }
        for(i=m+1;i<t;i++)
            addedge(i,t,kin,0);
        double ans=mfmc();
        if(ans>=sum)
        {
            ans=(basic+(ans-sum))/w;
            printf("%.6lf\n",ans);
        }
        else printf("0.000000\n");
    }
    return 0;
}
