#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const db eps=1e-7;
const int MAXN=1005;
const int MAXM=100005;
const int INF=0x3f3f3f3f;
struct Edge
{
    int to,next,cap,flow;
}edge[MAXM];
int tol,head[MAXN];
int gap[MAXN],dep[MAXN],pre[MAXN],cur[MAXN];
void init()
{
    tol=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w,int rw=0)
{
    edge[tol].to=v;
    edge[tol].cap=w;
    edge[tol].next=head[u];
    edge[tol].flow=0;
    head[u]=tol++;
    edge[tol].to=u;
    edge[tol].cap=rw;
    edge[tol].next=head[v];
    edge[tol].flow=0;
    head[v]=tol++;
}
int sap(int st,int ed,int N)
{
    memset(gap,0,sizeof(gap));
    memset(dep,0,sizeof(dep));
    memcpy(cur,head,sizeof(head));
    int u=st;
    pre[u]=-1;
    gap[0]=N;
    int ans=0;
    while(dep[st]<N)
    {
        if(u==ed)
        {
            int Min=INF;
            for(int i=pre[u];i!=-1;i=pre[edge[i^1].to])
                if(Min>edge[i].cap-edge[i].flow)
                    Min=edge[i].cap-edge[i].flow;
            for(int i=pre[u];i!=-1;i=pre[edge[i^1].to])
            {
                edge[i].flow+=Min;
                edge[i^1].flow-=Min;
            }
            u=st;
            ans+=Min;
            continue;
        }
        bool flag=0;
        int v;
        for(int i=cur[u];i!=-1;i=edge[i].next)
        {
            v=edge[i].to;
            if(edge[i].cap-edge[i].flow && dep[v]+1==dep[u])
            {
                flag=1;
                cur[u]=pre[v]=i;
                break;
            }
        }
        if(flag)
        {
            u=v;
            continue;
        }
        int Min=N;
        for(int i=head[u];i!=-1;i=edge[i].next)
            if(edge[i].cap-edge[i].flow && dep[edge[i].to]<Min)
            {
                Min=dep[edge[i].to];
                cur[u]=i;
            }
        gap[dep[u]]--;
        if(!gap[dep[u]])return ans;
        dep[u]=Min+1;
        gap[dep[u]]++;
        if(u!=st)u=edge[pre[u]^1].to;
    }
    return ans;
}
struct Point
{
    db x,y;
    Point(){}
    Point(db _x,db _y):x(_x),y(_y){}
    Point operator + (const Point &t)const
    {
        return Point(x+t.x,y+t.y);
    }
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    Point operator * (const db &t)const
    {
        return Point(x*t,y*t);
    }
    db operator * (const Point &t)const
    {
        return x*t.x+y*t.y;
    }
    db operator ^ (const Point &t)const
    {
        return x*t.y-y*t.x;
    }
    db len()
    {
        return sqrt(x*x+y*y);
    }
}p[205];
struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e):s(_s),e(_e){}
};
Point PTS(Point P,Line L)
{
    Point result;
    db t=((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
    if(t>=0 && t<=1)
    {
        result=L.s+(L.e-L.s)*t;
    }
    else
    {
        if((P-L.s).len()<(P-L.e).len())result=L.s;
        else result=L.e;
    }
    return result;
}
struct Circle
{
    Point o;
    db r;
    Circle(){}
    Circle(Point _o,db _r):o(_o),r(_r){}
}c[205],tr[205];
int v[205];
vector<pair<int,int> >e;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int Max=0;
        for(int i=1;i<=n;i++)
            scanf("%lf%lf%lf%d",&c[i].o.x,&c[i].o.y,&c[i].r,&v[i]);
        for(int i=1;i<=m;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        for(int i=1;i<=k;i++)
            scanf("%lf%lf%lf",&tr[i].o.x,&tr[i].o.y,&tr[i].r);
        for(int i=1;i<=n;i++)
            Max=max(Max,v[i]);
        e.clear();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if((c[i].o-p[j]).len()<c[i].r+eps)
                {
                    bool isok=1;
                    for(int t=1;t<=k;t++)
                        if((PTS(tr[t].o,Line(c[i].o,p[j]))-tr[t].o).len()<tr[t].r+eps)
                            isok=0;
                    if(isok)
                        e.push_back(make_pair(i,n+j));
                }
        int l=0,r=(m-1)*Max+2;
        while(l<r)
        {
            int tt=(l+r)>>1;
            init();
            for(int i=1;i<=n;i++)
                addedge(0,i,tt/v[i]+1);
            for(int i=0;i<(int)e.size();i++)
                addedge(e[i].first,e[i].second,1);
            for(int i=1;i<=m;i++)
                addedge(n+i,n+m+1,1);
            if(sap(0,n+m+1,n+m+2)<m)l=tt+1;
            else r=tt;
        }
        printf("%d\n",(l==(m-1)*Max+2 ? -1 : l));
    }
    return 0;
}
