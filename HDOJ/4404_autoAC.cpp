#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
const double Pi=acos(-1.0);
const double EP=1e-10;
struct Point{
    double x,y;
};
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
int main(){
    Point p[105],cir;
    double r,area, x0, y0, v, angle, t, g;
    int i, n;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf", &x0, &y0, &v, &angle, &t, &g, &r)!=EOF){
        if(fabs(x0)+fabs(y0)+fabs(v)+fabs(angle)+fabs(t)+fabs(g)+
           fabs(r)<0.0000001)break;
        scanf("%d", &n);
        for(i=0; i<n; i++)
        scanf("%lf%lf", &p[i].x, &p[i].y);
        area=0;cir.x=x0+v*cos(angle/180.0*Pi)*t;
        cir.y=y0+v*sin(angle/180.0*Pi)*t-0.5*g*t*t;
        for(i=0;i<n;i++){
            area+=cal_area(p[i], p[(i+1)%n], cir, r);
        }
        printf("%.2f\n",fabs(area));
    }
    return 0;
}
