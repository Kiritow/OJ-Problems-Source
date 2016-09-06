#include <cmath>
#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const double eps=1e-10;
const int INF=1<<29;
const double PI=acos(-1.0);
int doublecmp(double x){
    if(fabs(x)<eps)return 0;else return x<0?-1:1;
}
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;
Vector operator+(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}
Vector operator-(Point a,Point b){return Vector(a.x-b.x,a.y-b.y);}
Vector operator*(Vector a,double p){return Vector(a.x*p,a.y*p);}
Vector operator/(Vector a,double p){return Vector(a.x/p,a.y/p);}
bool operator<(const Point&a,const Point&b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
bool operator==(const Point&a,const Point&b){
    return doublecmp(a.x-b.x)==0&&doublecmp(a.y-b.y)==0;
}
bool operator!=(const Point&a,const Point&b){return a==b?false:true;}
struct Segment{
    Point a,b;
    Segment(){}
    Segment(Point _a,Point _b){a=_a,b=_b;}
    bool friend operator<(const Segment& p,const Segment& q){return p.a<q.a||(p.a==q.a&&p.b<q.b);}
    bool friend operator==(const Segment& p,const Segment& q){return (p.a==q.a&&p.b==q.b)||(p.a==q.b&&p.b==q.a);}
};
struct Circle{
    Point c;
    double r;
    Circle(){}
    Circle(Point _c, double _r):c(_c),r(_r) {}
    Point point(double a)const{return Point(c.x+cos(a)*r,c.y+sin(a)*r);}
    bool friend operator<(const Circle& a,const Circle& b){return a.r<b.r;}
};
struct Line{
    Point p;
    Vector v;
    double ang;
    Line() {}
    Line(const Point &_p, const Vector &_v):p(_p),v(_v){ang = atan2(v.y, v.x);}
    bool operator<(const Line &L)const{return  ang < L.ang;}
};
double Dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double Length(Vector a){return sqrt(Dot(a,a));}
double Angle(Vector a,Vector b){return acos(Dot(a,b)/Length(a)/Length(b));}
double Cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
double Area2(Point a,Point b,Point c){return Cross(b-a,c-a);}
double DegreeToRadius(double deg){return deg/180*PI;}
double GetRerotateAngle(Vector a,Vector b){
    double tempa=Angle(a,Vector(1,0));
    if(a.y<0) tempa=2*PI-tempa;
    double tempb=Angle(b,Vector(1,0));
    if(b.y<0) tempb=2*PI-tempb;
    if((tempa-tempb)>0) return tempa-tempb;
    else return tempa-tempb+2*PI;
}
Vector Rotate(Vector a,double rad){
    return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}
Vector Normal(Vector a){
    double L=Length(a);
    return Vector(-a.y/L,a.x/L);
}
Point GetLineProjection(Point p,Point a,Point b){
    Vector v=b-a;
    return a+v*(Dot(v,p-a)/Dot(v,v));
}
Point GetLineIntersection(Point p,Vector v,Point q,Vector w){
    Vector u=p-q;
    double t=Cross(w,u)/Cross(v,w);
    return p+v*t;
}
int ConvexHull(Point* p,int n,Point* ch){
    sort(p,p+n);
    int m=0;
    for(int i=0;i<n;i++){
        while(m>1&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    int k=m;
    for(int i=n-2;i>=0;i--){
        while(m>k&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    if(n>0) m--;
    return m;
}
double Heron(double a,double b,double c){
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2){
    double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1);
    double c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
    return doublecmp(c1)*doublecmp(c2)<0&&doublecmp(c3)*doublecmp(c4)<0;
}
double CutConvex(const int n,Point* poly, const Point a,const Point b, vector<Point> result[3]){
    vector<Point> points;
    Point p;
    Point p1=a,p2=b;
    int cur,pre; 
    result[0].clear(); 
    result[1].clear(); 
    result[2].clear();
    if(n==0) return 0;
    double tempcross;
    tempcross=Cross(p2-p1,poly[0]-p1);
    if(doublecmp(tempcross)==0) pre=cur=2;
    else if(tempcross>0) pre=cur=0;
    else pre=cur=1;
    for(int i=0;i<n;i++){
        tempcross=Cross(p2-p1,poly[(i+1)%n]-p1);
        if(doublecmp(tempcross)==0) cur=2;
        else if(tempcross>0) cur=0;
        else cur=1;
        if(cur==pre){
            result[cur].push_back(poly[(i+1)%n]); 
        }
        else{
            p1=poly[i]; 
            p2=poly[(i+1)%n];
            p=GetLineIntersection(p1,p2-p1,a,b-a);
            points.push_back(p); 
            result[pre].push_back(p); 
            result[cur].push_back(p); 
            result[cur].push_back(poly[(i+1)%n]); 
            pre=cur;
        }
    }
    sort(points.begin(),points.end());
    if(points.size()<2){
        return 0; 
    }
    else{
        return Length(points.front()-points.back());
    }
}
double DistanceToSegment(Point p,Segment s){
    if(s.a==s.b) return Length(p-s.a);
    Vector v1=s.b-s.a,v2=p-s.a,v3=p-s.b;
    if(doublecmp(Dot(v1,v2))<0) return Length(v2);
    else if(doublecmp(Dot(v1,v3))>0) return Length(v3);
    else return fabs(Cross(v1,v2))/Length(v1);
}
bool isPointOnSegment(Point p,Segment s){
    return doublecmp(DistanceToSegment(p,s))==0;
}
int isPointInPolygon(Point p, Point* poly,int n){
    int wn=0;
    for(int i=0;i<n;i++){
        Point& p2=poly[(i+1)%n];
        if(isPointOnSegment(p,Segment(poly[i],p2))) return -1;
        int k=doublecmp(Cross(p2-poly[i],p-poly[i]));
        int d1=doublecmp(poly[i].y-p.y);
        int d2=doublecmp(p2.y-p.y);
        if(k>0&&d1<=0&&d2>0)wn++;
        if(k<0&&d2<=0&&d1>0)wn--;
    }
    if(wn) return 1;
    else return 0;
}
double PolygonArea(vector<Point> p){
    double area=0;
    int n=p.size();
    for(int i=1;i<n-1;i++)
        area+=Cross(p[i]-p[0],p[i+1]-p[0]);
    return area/2;
}
int PSLGtoPolygons(Segment arr[],int n,vector<Point>* Polygons){
    int count=n-1;
    bool vis[9999];memset(vis,0,sizeof vis);
    Point star=arr[0].a,pre=arr[0].a,cur=arr[0].b,purpose=arr[0].b;vis[0]=true;
    int mark;
    while(purpose!=star){
        double theta=-INF;
        for(int i=0;i<n;i++)if(!vis[i]&&arr[i].a==cur&&arr[i].b!=pre){
            if(theta<GetRerotateAngle(pre-cur,arr[i].b-cur)){
                theta=GetRerotateAngle(pre-cur,arr[i].b-cur);
                purpose=arr[i].b;
                mark=i;
            }
        }
        vis[mark]=true;count--;
        pre=cur;cur=purpose;
    }
    int polyidx=0;
    while(count>0){
        for(int i=0;i<n;i++)if(!vis[i]){
            star=arr[i].a,pre=arr[i].a,cur=arr[i].b,purpose=arr[i].b;vis[i]=true;count--;
            Polygons[polyidx].clear();
            Polygons[polyidx].push_back(cur);
            break;
        }
        while(purpose!=star){
            double theta=-INF;
            for(int i=0;i<n;i++)if(!vis[i]&&arr[i].a==cur&&arr[i].b!=pre){
                if(theta<GetRerotateAngle(pre-cur,arr[i].b-cur)){
                    theta=GetRerotateAngle(pre-cur,arr[i].b-cur);
                    purpose=arr[i].b;
                    mark=i;
                }
            }
            vis[mark]=true;count--;
            Polygons[polyidx].push_back(purpose);
            pre=cur;cur=purpose;
        }
        polyidx++;
    }
    return polyidx;
}
int GetLineCircleIntersection(Line L,Circle C,Point& p1,Point& p2){
    double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y-C.c.y;
    double e = a*a + c*c, f = 2*(a*b+c*d), g = b*b + d*d -C.r*C.r;
    double delta = f*f - 4*e*g;
    if(doublecmp(delta) < 0)  return 0;
    if(doublecmp(delta) == 0) {
        p1=p1=C.point(-f/(2*e));
        return 1;
    }
    p1=(L.p+L.v*(-f-sqrt(delta))/(2*e));
    p2=(L.p+L.v*(-f+sqrt(delta))/(2*e));
    return 2;
}
struct Allpoint{
    Point p;
    int pos;
    bool friend operator<(Allpoint a,Allpoint b){
        if(a.pos==-1&&a.pos==b.pos) return a.p<b.p;
        else if(a.pos==-1) return true;
        else if(b.pos==-1) return false;
        else return a.p<b.p;
    }
}allpoint[8000];
int idx=0;
int lpint(Line l, Point a, Point b, Point c, Allpoint *sol) {
    int ret = 0;
    if (doublecmp(Cross(l.v, a - b)) != 0) {
        sol[ret].p = GetLineIntersection(l.p,l.v, a, b-a);
        if (isPointOnSegment(sol[ret].p, Segment(a, b))) ret++;
    }
    if (doublecmp(Cross(l.v, c - b)) != 0) {
        sol[ret].p = GetLineIntersection(l.p,l.v,c, b-c);
        if (isPointOnSegment(sol[ret].p, Segment(c, b))) ret++;
    }
    if (doublecmp(Cross(l.v, a - c)) != 0) {
        sol[ret].p = GetLineIntersection(l.p,l.v, a, c-a);
        if (isPointOnSegment(sol[ret].p, Segment(a, c))) ret++;
    }
    if (ret < 2) return 0;
    sort(sol, sol + ret);
    if (ret == 3) {
        if (sol[0].p == sol[1].p) sol[1].p = sol[2].p;
    }
    if (sol[0].p == sol[1].p) return 0;
    return 2;
}
int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--){
        double v1,v2,v,t,x;
        int n;
        idx=0;
        scanf("%lf%lf%lf%lf%lf",&v1,&v2,&v,&t,&x);
        scanf("%d",&n);
        double time = v2 * t / (v2 - v1);
        Line l = Line(Point(x, 0), Point(x - v1 * time, v * time)-Point(x,0));
        for(int i=0;i<n;i++){
            Point O;
            double r,h;
            Allpoint ip[4];
            scanf("%lf%lf%lf%lf", &O.x, &O.y, &r, &h);
            int ipp = lpint(l, Point(O.x + r, O.y), Point(O.x - r, O.y), Point(O.x, O.y + h), ip);
            if (ipp) {
                if (ip[1] < ip[0]) swap(ip[0], ip[1]);
                for (int i = 0; i < 2; i++) ip[i].pos= i & 1, allpoint[idx++] = ip[i];
            }
            int ipc = GetLineCircleIntersection(l,Circle(O, r), ip[0].p,ip[1].p);
            if (ipc==2) {
                if (ip[1] < ip[0]) swap(ip[0], ip[1]);
                if (doublecmp(ip[1].p.y - O.y) >= 0) continue;
                if (doublecmp(ip[0].p.y - O.y) > 0) ip[0].p = GetLineIntersection(l.p,l.v, O, Point(1.0, 0));
                for (int i = 0; i < 2; i++) ip[i].pos = i & 1, allpoint[idx++] = ip[i];
            }
        }
        sort(allpoint, allpoint + idx);
        int cnt = 0;
        double sum = 0, lp = x - v1 * time, rp = x, ls = lp;
        for (int i = 0; i < idx; i++) {
            if (allpoint[i].p.x > rp) break;
            if (allpoint[i].p.x < lp) {
                if (allpoint[i].pos) cnt--; 
                else cnt++;
            } else {
                if (allpoint[i].pos) {
                    if (cnt == 1) sum += allpoint[i].p.x - ls;
                    cnt--;
                } else {
                    if (cnt == 0) ls = allpoint[i].p.x;
                    cnt++;
                }
            }
        }
        if (cnt > 0) sum += rp - ls;
        printf("Case %d: %.4f\n", cas++, sum / v1);
    }
}
