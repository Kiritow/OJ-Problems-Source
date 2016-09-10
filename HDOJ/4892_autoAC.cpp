#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define prt(k) cout<<#k" = "<<k<<endl
#include <cmath>
#include <algorithm>
const int N = 333;
const int M = 41;
const int MAXN = 12111;     
int sqr(int x) { return x * x; }
struct P
{
    double x, y; int t;
    P() {}
    P(double _x, double _y) { x=_x, y=_y; }
    double dis(P b)
    {
        return sqrt((x-b.x)*(x-b.x)+(y-b.y)*(y-b.y));
    }
    double operator * (P b)
    {
        return x*b.y - y*b.x;
    }
    P operator - (P b) { return P(x-b.x,y-b.y); }
}p[454];
double dis(P a, P b) { return a.dis(b); }
int n, m, kind;
P a[334], b[545];
const double inf = 1e18;
const double eps = 1e-8;
double cross(P a, P b) { return a * b; }
double cross(P a, P b, P c) { return (b - a) * (c - a); }
int cmp(double x) { return x < -eps ? -1 : x > eps; }
bool in(P p, P a, P b, P c)
{
    double t = fabs(cross(p,a,b)) + fabs(cross(p,b,c)) + fabs(cross(p,a,c));
    return cmp(t - fabs(cross(a,b,c))) == 0;
}
int side(P a, P b, P s, P t)
{
    return cmp(cross(s,a,t) * cross(s,b,t));
}
int mask[MAXN];
int id[M][M][M];
int getID(int i, int j, int k)
{
    int a[3];
    a[0] = i, a[1] = j, a[2] = k;
    sort(a, a+3);
    return id[a[0]][a[1]][a[2]];
}
double w[M][M];
const int E = 1012000;
int to[E], ne[E]; double cost[E];
int head[MAXN];
int tot;
void initEdge()
{
    tot = 0;
    memset(head, -1, sizeof head);
}
void addEdge(int u, int v, double w)
{
    to[tot] = v, cost[tot] = w;
    ne[tot] = head[u];
    head[u] = tot++;
}
double d[66][MAXN];
#include <queue>
int cnt;    
bool inq[MAXN];
void spfa(double d[], int n)
{
    queue<int> q;
    for(int i=0;i<n;i++) inq[i] = true, q.push(i);
    while(!q.empty())
    {
        int u=q.front(); q.pop();   inq[u] = false; 
        for(int i=head[u];~i;i=ne[i])
        {
            int v = to[i];
            if(d[v] > d[u] + cost[i] + eps)
            {
                d[v] = d[u] + cost[i];
                if(!inq[v])
                {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}
double solve()
{
    memset(inq, 0, sizeof inq);
    for(int S=0;S<(1<<kind);S++)
    {
        spfa(d[S], cnt);
        for(int u=0;u<cnt;u++)
        {
            for(int e=head[u];~e;e=ne[e])
            {
                int v = to[e];
                d[S|mask[v]][v] = min(d[S|mask[v]][v], d[S][u] + cost[e]);
            }
        }
    }
    double ans = inf;
    for(int i=0;i<cnt;i++) ans = min(ans, d[(1<<kind)-1][i]);
    return ans;
}
int main()
{
    while(scanf("%d%d%d", &n, &m, &kind)==3)
    {
        initEdge();
        for(int i=0;i<n;i++) scanf("%lf%lf", &a[i].x, &a[i].y);
        for(int i=0;i<n;i++) scanf("%d", &a[i].t), a[i].t--;
        for(int i=0;i<m;i++) scanf("%lf%lf", &b[i].x, &b[i].y), p[i] = b[i];
        cnt = 0;
        memset(mask, 0, sizeof mask);
        for(int i=0;i<m;i++)
        {
            w[i][i] = 0;
            for(int j=i+1;j<m;j++)
                w[i][j] = w[j][i] = dis(p[i], p[j]);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                for(int k=j+1;k<m;k++)
                {
                    mask[cnt] = 0;
                    for(int t = 0; t < n; t++)
                    {
                        int id = a[t].t;
                        if(in(a[t], b[i],b[j],b[k]))
                        {
                            mask[cnt] |= (1<<id);
                        }
                    }
                    for(int t=0;t<(1<<kind);t++) d[t][cnt] = inf;
                    d[mask[cnt]][cnt] = w[i][j] + w[j][k] + w[i][k];
                    id[i][j][k] = cnt++;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                for(int k=0;k<m;k++)
                {
                    for(int t=k+1;t<m;t++)
                    {
                        if(k==i||k==j||t==i|t==j) continue;
                        if(side(p[k], p[t], p[i], p[j]) != -1) continue;
                        int u = getID(i, j, k);
                        int v = getID(i, j, t);
                        addEdge(u, v, w[i][t] + w[t][j] - w[i][j]);
                        addEdge(v, u, w[i][k] + w[k][j] - w[i][j]);
                    }
                }
            }
        }
        double ans = solve();
        if(cmp(ans - inf) >= 0) printf("Impossible\n");
        else printf("%.12f\n", ans);
    }
    return 0;
}
