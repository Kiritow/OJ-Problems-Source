#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<map>
#define FIR first
#define SEC second
#define MP make_pair
#define inf 0x3f3f3f3f
#define LL long long
#define CLR(a, b) memset(a, b, sizeof(a))
using namespace std;
struct Point
{
    double x, y;
    Point(double x = 0, double y = 0)
        :x(x), y(y) {}
};
double EP = 0;
double x_mult(Point sp, Point ep, Point op){
    return (sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x);
}
double cross(Point a,Point b,Point c){
    return (a.x-c.x)*(b.x-c.x)+(a.y-c.y)*(b.y-c.y);
}
double dist(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double cal_area(Point a,Point b,Point c,double r){
    double A,B,C,x,y,tS;
    A=dist(b,c);
    B=dist(a,c);
    C=dist(b,a);
    if(A<r&&B<r)
    return x_mult(a,b,c)/2;
    else if(A<r&&B>=r){
        x=(cross(a,c,b)+sqrt(r*r*C*C-x_mult(a,c,b)*x_mult(a,c,b)))/C;
        tS=x_mult(a,b,c)/2;
        return asin(tS*(1-x/C)*2/r/B*(1-EP))*r*r/2+tS*x/C;
    }
    else if(A>=r&&B<r){
        y=(cross(b,c,a)+sqrt(r*r*C*C-x_mult(b,c,a)*x_mult(b,c,a)))/C;
        tS=x_mult(a,b,c)/2;
        return asin(tS*(1-y/C)*2/r/A*(1-EP))*r*r/2+tS*y/C;
    }
    else if(fabs(x_mult(a,b,c))>=r*C||cross(b,c,a)<=0||cross(a,c,b)<=0){
        if(cross(a,b,c)<0)
            if(x_mult(a,b,c)<0)
                return (-acos(-1.0)-asin(x_mult(a,b,c)/A/B*(1-EP)))*r*r/2;
            else return (acos(-1.0)-asin(x_mult(a,b,c)/A/B*(1-EP)))*r*r/2;
        else return asin(x_mult(a,b,c)/A/B*(1-EP))*r*r/2;
    }
    else{
        x=(cross(a,c,b)+sqrt(r*r*C*C-x_mult(a,c,b)*x_mult(a,c,b)))/C;
        y=(cross(b,c,a)+sqrt(r*r*C*C-x_mult(b,c,a)*x_mult(b,c,a)))/C;
        tS=x_mult(a,b,c)/2;
        return (asin(tS*(1-x/C)*2/r/B*(1-EP))+asin(tS*(1-y/C)*2/r/A*(1-EP)))*r*r/2+tS*((y+x)/C-1);
    }
}
double solve(Point p[], int n, Point cir, double r){
    double area=0;
    for(int i=0;i<n;i++){
        area+=cal_area(p[i], p[(i+1)%n], cir, r);
    }
    return area;
}
double pi = acos(-1.0);
int main()
{
    double v0, v1, D, T;int cas = 1;
    while(cin >> v0 >> v1 >> D >> T)
    {
        printf("Case %d: ", cas ++);
        Point cir = Point(-D, 0);
        double r = v0 * T;
        if(v0 * T <= D)
        {
            printf("%.7f\n", pi * r * r);
            continue;
        }
        double lft = D / v0, rgt = T;
        for(int i = 0; i < 100; i ++)
        {
            double mid = (lft + rgt) / 2;
            double midmid = (mid + rgt) / 2;
            double _mid = sqrt((v0 * mid) * (v0 * mid) - D * D) + v1 * (T - mid);
            double _midmid = sqrt((v0 * midmid) * (v0 * midmid) - D * D) + v1 * (T - midmid);
            if(_mid > _midmid) rgt = midmid;
            else lft = mid;
        }
        double t = (lft + rgt) / 2;
        double y = sqrt((v0 * t) * (v0 * t) - D * D) + v1 * (T - t);
        double x1 = T / t * D, y1 = sqrt(v0 * T * v0 * T - x1 * x1);
        x1 -= D;
        Point p[8];
        p[0] = Point(0, y);
        p[1] = Point(x1, y1);
        p[2] = Point(x1, -y1);
        p[3] = Point(0, -y);
        p[4] = Point(-x1, -y1);
        p[5] = Point(-x1, y1);
        p[6] = p[0];
        double ans = solve(p, 6, cir, r);
        ans = pi * r * r + x1 * y1 * 4 + x1 * (y - y1) * 2 - fabs(ans);
        printf("%.7f\n", ans);
    }
}
