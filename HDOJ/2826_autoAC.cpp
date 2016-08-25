#include <iostream>
#include <string>
#include<algorithm>
#include <cstdio>
#include<cmath>
using namespace std;
const double eps = 1e-8;
int dcmp(double x)
{
    if( fabs(x)<eps)
        return 0;
    return x < 0 ? -1:1;
}
struct pnode
{
    double x,y;
    pnode(double x =0.0,double y=0.0):x(x),y(y){}
    int pread()
    {
        return scanf("%lf %lf",&x,&y);
    }
    pnode operator - (const pnode &b)const{ return pnode(x-b.x,y-b.y);}
    bool operator < (const pnode&b)const
    {
        return dcmp(x-b.x) <0 || (dcmp(x-b.x)== 0 && dcmp(y-b.y)<0);
    }
    double operator ^(const pnode&b)const
    {
        return x*b.y - y *b.x;
    }
};
typedef pnode myvec;
myvec a,b,c,d;
pnode pa[305],pb[305];
double cross( pnode p0,pnode p1,pnode p2)
{
    return (p1-p0) ^ (p2-p0);
}
double polygon_area(pnode*p,int n)
{
    double area = 0.0;
    for( int i = 1;i < n-1 ;++i )
        area += cross( p[0], p[i], p[i+1]);
    return area*0.5;
}
double dot(myvec v)
{
    return v.x*v.x + v.y *v.y;
}
void getpnode(int n,pnode *p,myvec &v,myvec &w)
{
    p[0].pread();
    p[1].pread();
    myvec tmp = p[1] - p[0];
    v = w = tmp;
    for( int i = 2; i < n ;++i )
    {
        p[i].pread();
        v = p[i] - p[i-1];
        if( dcmp(dot(tmp)-dot(v))<0 )
            v = tmp;
        if( dcmp( dot(tmp)-dot(v)) > 0 )
            w = tmp;
    }
    tmp = p[n-1] - p[0];
    if( dcmp(dot(tmp)-dot(v))<0 )
            v = tmp;//v 涓哄澶杈瑰舰杈
    if( dcmp( dot(tmp)-dot(v)) > 0 )
            w = tmp;
}
int main()
{
    int n;
    while( ~scanf("%d\n",&n))
    {
        getpnode(n,pa,a,c);
        getpnode(n,pb,b,d);
        double aarea =  polygon_area(pa,n);
        double barea =  polygon_area(pb,n);
        double k1 = sqrt(dot(a))/sqrt(dot(b));
        double k2 = sqrt( dot(c)) /sqrt(dot(d));
        if( dcmp(aarea - barea*k1*k1)==0 && dcmp(aarea - barea *k2*k2)==0 && dcmp(k1-k2)==0)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
