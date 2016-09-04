#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
const double eps=1e-12;
const double pi=acos(-1.0);
using namespace std;
typedef long long ll;
inline double sqr(double x)
{
    return x*x;
}
struct point
{
    double x, y, r;
    point(){}
    point(double _x, double _y, double _r){x=_x;y=_y;r=_r;}
    void read(){scanf("%lf%lf%lf", &x, &y, &r);}
    point operator -(const point &tp)const
    {
        return point(x-tp.x, y-tp.y, r-tp.r);
    }
    point operator +(const point &tp)const
    {
        return point(x+tp.x, y+tp.y, r+tp.r);
    }
    point operator *(const double &k)const
    {
        return point(x*k, y*k, r*k);
    }
}table, ball;
double dx, dy, tot;
int cross(point op, point sp, point ep)
{
    double ans=(sp.y-op.y)*(ep.x-op.x)-(ep.y-op.y)*(sp.x-op.x);
    if(ans>eps)return 1;
    return -1;
}
double angle(point a, point b)
{
    double area=a.x*b.x+a.y*b.y;
    double ablen=sqrt((a.x*a.x+a.y*a.y)*(b.x*b.x+b.y*b.y));
    return acos(area/ablen);
}
int main()
{
    int ca;
    scanf("%d", &ca);
    while(ca-->0)
    {
        table.read();
        ball.read();
        scanf("%lf%lf%lf", &dx, &dy, &tot);
        ball.x-=table.x;
        ball.y-=table.y;
        table.r-=ball.r;
        double a=sqr(dx)+sqr(dy);
        double b=2.0*(ball.x*dx*1.0+ball.y*dy*1.0);
        double c=sqr(ball.x)+sqr(ball.y)-sqr(table.r);
        double sti=(sqrt(sqr(b)-4.0*a*c)-b)/(2.0*a);
        if(sti-tot>eps)
        {
            printf("%.1lf %.1lf\n", (ball.x+tot*dx+table.x), (ball.y+tot*dy+table.y));
            continue;
        }
        point zero=point(0, 0, 0);
        point first=point(sti*dx+ball.x, sti*dy+ball.y, 0);
        int dir=cross(zero, first, ball);
        double ref=angle(ball-first, zero-first);
        double dis=cos(ref)*table.r*2;
        double v=sqrt(dx*dx+dy*dy);
        tot-=sti;
        double len=tot*v;
        double dti=len/dis;
        ll lti=(ll)(dti+eps);
        double perti=dis/v;
        double left=tot-perti*lti;
        double pang=(pi-2*ref)*lti;
        double stang=atan2(first.y, first.x);
        stang=stang+pang*dir;
        point now=point(cos(stang)*table.r, sin(stang)*table.r, 0);
        double vang=stang+(pi-2*ref)*dir;
        point next=point(cos(vang)*table.r, sin(vang)*table.r, 0);
        double rate=left/perti;
        point vec=next-now;
        now=now+(vec*rate);
        printf("%.1lf %.1lf\n", now.x+table.x, now.y+table.y);
    }
    return 0;
}
