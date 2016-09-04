#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define sqr(a) ((a)*(a))
#define trarea(p) fabs ((vdet(p[0],p[1],p[2])/2.0))
double const EPS = 1e-12;
int const maxn = 20011;
struct point{double x,y;int flag;};
struct circle{
        point c;
        double r;
};
inline double vdet(point op,point p1,point p2){
        return (p1.x-op.x)*(p2.y-op.y)-(p2.x-op.x)*(p1.y-op.y);
}
inline double dis(point a,point b){
        return sqr(a.x-b.x)+sqr(a.y-b.y);
}
inline point get_out_circle(point p[]){  
        double c1,c2,xa,xb,xc,ya,yb,yc;
        point o;
        xa=p[0].x,xb=p[1].x,xc=p[2].x;
        ya = p[0].y,yb = p[1].y,yc = p[2].y;
        c1 = (sqr(xa) + sqr(ya) - sqr(xb) - sqr(yb))/2.0;
        c2 = (sqr(xa) + sqr(ya) - sqr(xc) - sqr(yc))/2.0;
        o.x = (c1*(ya-yc)-c2*(ya-yb))/((xa-xb)*(ya-yc)-(xa-xc)*(ya-yb));
        o.y = (c1*(xa-xc)-c2*(xa-xb))/((ya-yb)*(xa-xc)-(ya-yc)*(xa-xb));
        return o;
}
inline double get_out_r(point p[]){  
        double a = dis(p[0],p[1]),b = dis(p[1],p[2]),c = dis(p[2],p[0]),s = trarea(p);
        return a*b*c/sqr(4*s);
}
point must_on[3],p[maxn];
circle mc;
inline void get_circle(int tm){  
        switch(tm){
                case 0:mc.r = -1;
                       break;
                case 1:mc.r = 0,mc.c = must_on[0];
                       break;
                case 2:{
                               mc.r = dis(must_on[0],must_on[1])/4.0;
                               mc.c.x = (must_on[0].x+must_on[1].x)/2.0;
                               mc.c.y = (must_on[0].y + must_on[1].y)/2.0;
                       }break;
                case 3:{
                               mc.r = get_out_r(must_on);
                               mc.c = get_out_circle(must_on);
                       }break;
        }
}
inline void min_circle(int t,int ton){
        get_circle(ton);
        if(ton >= 3)return;
        for(int i = 0; i < t; ++i){
                if(p[i].flag == 1){
                    if(dis(mc.c,p[i]) > mc.r + EPS){ 
                        must_on[ton] = p[i];
                        min_circle(i,ton+1);
                    }
                }
                else {
                    if(dis(mc.c,p[i]) + EPS < mc.r){ 
                        must_on[ton] = p[i];
                        min_circle(i,ton+1);
                    }
                }
        }
}
int main(){
        int n,m;
        while (scanf("%d%d",&n,&m) != EOF){
                for(int i = 0; i < n; ++i){
                        scanf("%lf%lf",&p[i].x,&p[i].y);
                        p[i].flag = 1;
                }
                for(int i = n; i < m + n; ++i){
                        scanf("%lf%lf",&p[i].x,&p[i].y);
                        p[i].flag = 2;
                }
                n = n + m;
                random_shuffle(p,p+n); 
                min_circle(n,0);
                printf("%.3lf %.3lf\n%.3lf\n",mc.c.x,mc.c.y,sqrt(mc.r));
        }
        return 0;
}
