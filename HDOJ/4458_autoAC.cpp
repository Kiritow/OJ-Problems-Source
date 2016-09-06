#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const double EPS=1e-8;
const int maxn=100;
int n;
struct Point
{
    double x,y;
    Point (double x=0,double y=0):x(x),y(y){}
};
Point poly[maxn];
typedef Point Vector;
Vector operator + (Vector A,Vector B) {return Vector(A.x+B.x,A.y+B.y);}
Vector operator - (Point A,Point B) {return Vector(A.x-B.x,A.y-B.y);}
Vector operator * (Vector A,double p) {return Vector(A.x*p,A.y*p);}
Vector operator / (Vector A,double p) {return Vector(A.x/p,A.y/p);}
bool operator < (const Point &a,const Point &b){
    return a.x < b.x ||(a.x==b.x &&a.y < b.y);
}
int dcmp (double x){
    if(fabs(x)<EPS)
        return 0;
    else return x < 0?-1:1;
}
bool operator == (const Point &a ,const Point &b){
    return dcmp(a.x-b.x) ==0 && dcmp(a.y - b.y)==0;
}
double Cross (Vector A,Vector B) {return A.x*B.y - A.y*B.x;}
double Dot (Vector A,Vector B) {return A.x*B.x + A.y*B.y;}
bool isPointOnSegment (Point p,Point a1,Point a2)
{
    return dcmp ( Cross(a1-p,a2-p)  )==0 && dcmp(Dot (a1-p,a2-p))<0;
}
int online(Point a,Point b,Point p)
{
    Point v1,v2;
    v1=p-a;v2=p-b;
    if( dcmp(Cross(v1,v2))!=0)  //绉涓涓0 灏变ㄧ寸嚎涓
         return 0;
    else
       {
           if(dcmp(min(a.x,b.x)- p.x)<=0 && dcmp(p.x-max(a.x,b.x))<=0
               &&dcmp(min(a.y,b.y)- p.y)<=0 &&dcmp( p.y-max(a.y,b.y))<=0)
               return 1;
            else
                return 0;
       }
}
int isPointInPolygon (Point p)
{
    int wn=0;
    for(int i=0;i<n;i++){
        if( online (poly[i], poly[(i+1)%n],p)) return 0;
        int k=dcmp (Cross(poly[(i+1)%n]-poly[i],p-poly[i]));
        int d1=dcmp(poly[i].y-p.y);
        int d2=dcmp(poly[(i+1)%n].y-p.y);
        if(k>0 && d1<=0 && d2>0) wn++;
        if(k<0 && d2<=0 && d1>0) wn--;
    }
    if(wn!=0) return 1;
    return 0;
}
int main()
{
    double v,b,g;
    while (scanf("%lf %lf %lf",&v,&b,&g),v||b||g)
    {
        v=-v;
        scanf("%d",&n);
        bool flag=false;
        int i;
        double minx=1e12,maxx=-1e12,maxy=-1e12;
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf",&poly[i].x,&poly[i].y);
            if(poly[i].x>maxx)  maxx=poly[i].x;
            if(poly[i].x<minx)  minx=poly[i].x;
            if(poly[i].y>maxy)  maxy=poly[i].y;
        }
        double t;
        for(int i=0;;i++)
        {
            t=i*0.001;
            Point temp;
            temp.x=v*t;temp.y=b*t-0.5*g*t*t;
            if( isPointInPolygon(temp) )
            {
                printf("%.2f\n",t-EPS);
                flag=true;
                break;
            }
            if(!g && temp.y>maxy) break;
            if(temp.y<0) break;
        }
        if(!flag) printf("Miss!\n");
    }
    return 0;
}
