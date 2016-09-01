#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<algorithm>
#define eps 1e-6
#define N 10010
using namespace std;
struct Point
{
    double x,y;
    Point(){}
    Point(double a,double b):x(a),y(b){}
};
struct Line
{
    Point a,b;
    Line(){}
    Line(Point u,Point v):a(u),b(v){}
};
struct Info
{
    int n;
    Point p[N];
    Line l;
    Point fa;
};
Info a,b;
struct Node
{
    int u,v;
    double len;
    Node(){}
    Node(int u0,int v0,double len0):u(u0),v(v0),len(len0){}
}nod[8*N];
bool cccc(Node a,Node b)
{
    return a.len < b.len;
}
int nod_n;
int Sig(double a)
{
    return a<-eps?-1:a>eps;
}
Point Intersection(Line u,Line v)
{
    Point ret=u.a;
    double t=((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))/
             ((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
    ret.x+=(u.b.x-u.a.x)*t;
    ret.y+=(u.b.y-u.a.y)*t;
    return ret;
}
int cmp(Point a,Point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
double Dis(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int Find(double num,Point p[],int n,int ind)
{
    int left=0,right=n;
    if(ind==1)
    {
        while(left+1<right)
        {
            int mid=(left+right)>>1;
            if(Sig(num-p[mid].y)>=0)
                left=mid;
            else
                right=mid;
        }
    }
    else
    {
        while(left+1<right)
        {
            int mid=(left+right)>>1;
            if(Sig(num-p[mid].x)>=0)
                left=mid;
            else
                right=mid;
        }
    }
    return left;
}
Point operator +(Point a,Point b)
{
    Point tmp;
    tmp.x=a.x+b.x;
    tmp.y=a.y+b.y;
    return tmp;
}
void Init()
{
    double t;
    double ax,ay,bx,by,cx,cy,dx,dy;
    scanf("%d%d",&a.n,&b.n);
    scanf("%lf%lf%lf%lf",&ax,&ay,&bx,&by);
    scanf("%lf%lf%lf%lf",&cx,&cy,&dx,&dy);
    for(int i=0;i<a.n;i++)
    {
        scanf("%lf",&t);
        a.p[i].x=ax*t+bx*(1-t);
        a.p[i].y=ay*t+by*(1-t);
    }
    for(int i=0;i<b.n;i++)
    {
        scanf("%lf",&t);
        b.p[i].x=cx*t+dx*(1-t);
        b.p[i].y=cy*t+dy*(1-t);
    }
    sort(a.p, a.p+a.n, cmp);
    sort(b.p, b.p+b.n, cmp);
    a.l=Line(Point(ax,ay),Point(bx,by));
    a.fa=Point(by-ay,ax-bx);
    b.l=Line(Point(cx,cy),Point(dx,dy));
    b.fa=Point(dy-cy,cx-dx);
    nod_n=0;
    for(int i=0;i<a.n;i++)
    {
        Point tp=Intersection(b.l,Line(a.p[i],b.fa+a.p[i]));
        if(cx==dx)
        {
            double y=tp.y;
            if(Sig(y-b.p[0].y)<=0)
                    nod[nod_n++]=Node(i,a.n,Dis(a.p[i],b.p[0]));
            else if(Sig(y-b.p[b.n-1].y)>=0)
                nod[nod_n++]=Node(i,a.n+b.n-1,Dis(a.p[i],b.p[b.n-1]));
            else
            {
                int pos=Find(y,b.p,b.n-1,1);
                double d1=Dis(a.p[i],b.p[pos]);
                double d2=Dis(a.p[i],b.p[pos+1]);
                nod[nod_n++]=Node(i,a.n+pos,d1);
                nod[nod_n++]=Node(i,a.n+pos+1,d2);
            }
        }
        else
        {
            double x=tp.x;
            if(Sig(x-b.p[0].x)<=0)
                nod[nod_n++]=Node(i,a.n,Dis(a.p[i],b.p[0]));
            else if(Sig(x-b.p[b.n-1].x)>=0)
                nod[nod_n++]=Node(i,a.n+b.n-1,Dis(a.p[i],b.p[b.n-1]));
            else
            {
                int pos=Find(x,b.p,b.n-1,2);
                double d1=Dis(a.p[i],b.p[pos]);
                double d2=Dis(a.p[i],b.p[pos+1]);
                nod[nod_n++]=Node(i,a.n+pos,d1);
                nod[nod_n++]=Node(i,a.n+pos+1,d2);
            }
        }
    }
    for(int i=0;i<b.n;i++)
    {
        Point tp=Intersection(a.l,Line(b.p[i],a.fa+b.p[i]));
        if(ax==bx)
        {
            double y=tp.y;
            if(Sig(y-a.p[0].y)<=0)
                nod[nod_n++]=Node(i+a.n,0,Dis(b.p[i],a.p[0]));
            else if(Sig(y-a.p[a.n-1].y)>=0)
                nod[nod_n++]=Node(i+a.n,a.n-1,Dis(b.p[i],a.p[a.n-1]));
            else
            {
                int pos=Find(y,a.p,a.n-1,1);
                double d1=Dis(b.p[i],a.p[pos]);
                double d2=Dis(b.p[i],a.p[pos+1]);
                nod[nod_n++]=Node(i+a.n,pos,d1);
                nod[nod_n++]=Node(i+a.n,pos+1,d2);
            }
        }
        else
        {
            double x=tp.x;
            if(Sig(x-a.p[0].x)<=0)
                nod[nod_n++]=Node(i+a.n,0,Dis(b.p[i],a.p[0]));
            else if(Sig(x-a.p[a.n-1].x)>=0)
                nod[nod_n++]=Node(i+a.n,a.n-1,Dis(b.p[i],a.p[a.n-1]));
            else
            {
                int pos=Find(x,a.p,a.n-1,2);
                double d1=Dis(b.p[i],a.p[pos]);
                double d2=Dis(b.p[i],a.p[pos+1]);
                nod[nod_n++]=Node(i+a.n,pos,d1);
                nod[nod_n++]=Node(i+a.n,pos+1,d2);
            }
        }
    }
    for(int i=0;i<a.n-1;i++)
        nod[nod_n++]=Node(i,i+1,Dis(a.p[i],a.p[i+1]));
    for(int i=0;i<b.n-1;i++)
        nod[nod_n++]=Node(i+a.n,i+a.n+1,Dis(b.p[i],b.p[i+1]));
}
int parent[20010];
int find(int x)
{
    if(parent[x] != x)
        parent[x]=find(parent[x]);
    return parent[x];
}
int main()
{
    int cas;
    scanf("%d",&cas);
    for(int cc=1;cc<=cas;cc++)
    {
        Init();
        sort(nod,nod+nod_n,cccc);
        int n=a.n+b.n;
        for(int i=0;i<n;i++)
            parent[i]=i;
        int tmp=n-1;
        double total=0;
        int x,y;
        int px,py;
        for(int i=0;i<nod_n && tmp;i++)
        {
            x=nod[i].u;
            y=nod[i].v;
            px=find(x);
            py=find(y);
            if(px == py)
                continue;
            total+=nod[i].len;
            tmp--;
            if(rand()&1)
                parent[px]=py;
            else
                parent[py]=px;
        }
        printf("Case #%d: %.3f\n",cc,total);
    }
    return 0;
}
