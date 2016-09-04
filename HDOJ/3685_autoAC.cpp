#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=100010;
const double ZERO=1e-8;
struct node
{
    double x,y;
}q[MAXN],p[MAXN];
int N,M;
void Init()
{
    scanf("%d",&N);
    for (int i=0;i<N;i++) 
        scanf("%lf%lf",&p[i].x,&p[i].y);
}
double det(node a,node b,node c)
{
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
double dot(node a,node b,node c)
{
    return (b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y);
}
double det3(node a,node b,node c)
{
    double s=det(a,b,c);
    if (fabs(s)<=ZERO) return 0;
    if (s<0) return -1; else return 1;
}
void Graham_scan(node *c,int &M0,int base,node q)
{
    while (M0>base && det3(c[M0-2],c[M0-1],q)<=0) --M0;
    c[M0]=q;
    ++M0;
}
bool cmp(node a,node b)
{
    if ((a.y<b.y) || (a.y==b.y && a.x<b.x)) return 1; else return 0;
}
node c[MAXN];
void Graham(node *p,int N0,node *q,int &M0)
{
    for (int i=0;i<=N0;++i) q[i]=p[i];
    sort(q,q+N0,cmp);
    M0=0;
    for (int i=0;i<N0;++i)
        Graham_scan(c,M0,1,q[i]);
    int M1=M0;
    for (int i=N0-1;i>=0;--i)
        Graham_scan(c,M0,M1,q[i]);
    for (int i=0;i<M0;++i)
        q[i]=c[i];
}
int Find(node a,node b,node c)
{
    double s=dot(b,a,c);
    if (s>ZERO) return 0; else return 1;
}
bool Cleck(node a,node b,node c)
{
    return ((!Find(a,b,c))&&(!Find(a,c,b)));
}
void Solve()
{
    node o,o1;
    double s=0,s1;
    o.x=o.y=0;
    for (int i=1;i<N-1;++i)
    {
        o1.x=(p[0].x+p[i].x+p[i+1].x)/3;
        o1.y=(p[0].y+p[i].y+p[i+1].y)/3;
        s1=det(p[0],p[i],p[i+1]);
        s+=s1;
        o.x+=o1.x*s1;
        o.y+=o1.y*s1;
    }
    o.x/=s;
    o.y/=s;
    Graham(p,N,q,M);
    q[M]=q[0];
    int ans=0;
    for (int i=0;i<M;++i)
        if (Cleck(o,q[i],q[i+1])) ++ans;
    printf("%d\n",ans);
}
int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
        Init();
        Solve();
    }
    return 0;
}
