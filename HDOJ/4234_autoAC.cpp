#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define for if(0); else for
const double PI=acos(-1.0);
struct Point{
    double x,y,vx,vy,t;
    Point(){}
    Point(double x,double y){
        this->x=x;
        this->y=y;
    }
    Point(double x,double y,double d,double v){
        this->x=x;
        this->y=y;
        this->vx=v*cos(d*PI/180.0);
        this->vy=v*sin(d*PI/180.0);
        this->t=0;
    }
    Point go(double t) const{
        Point ret=*this;
        ret.x+=vx*t;
        ret.y+=vy*t;
        return ret;
    }
};
int n;
Point p[16];
double spd;
double dp[16][1<<15];
bool vis[16][1<<15];
double dis(const Point &a,const Point &b){
    double dx=a.x-b.x;
    double dy=a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}
double cost(const Point &a,const Point &b){
    Point ta=Point(b.x-a.x,b.y-a.y);
    Point v=Point(b.vx,b.vy);
    double V=dis(v,Point(0,0));
    double D=dis(ta,Point(0,0));
    double A=V*V-spd*spd;
    double C=D*D;
    double B=-2.0*(ta.x*v.x+ta.y*v.y);
    return (B-sqrt(B*B-4*A*C))/2.0/A;
}
int main() {
    setbuf(stdout,NULL);
    while(scanf("%d%lf",&n,&spd) &&(n!=0&&spd!=0)){
        p[0]=Point(0,0,0,0);
        for(int i=1;i<=n;i++){
            double x,y,d,v;
            scanf("%lf%lf%lf%lf",&x,&y,&d,&v);
            p[i]=Point(x,y,d,v);
        }
        memset(vis,0,sizeof(vis));
        vis[0][0]=1;
        for(int stat=1;stat<1<<n;stat++){
            for(int i=1;i<=n;i++){
                int prev=stat;
                prev &= ~ ( 1<< (i-1) );
                if(prev==stat) continue;
                for(int j=0;j<=n;j++) if(j!=i){
                    if(vis[j][prev]){
                        double val=dp[j][prev]+cost(p[j].go(dp[j][prev]),p[i].go(dp[j][prev]));
                        if(!vis[i][stat]) vis[i][stat]=1,dp[i][stat]=val;
                        else dp[i][stat]=min(dp[i][stat],val);
                    }
                }
            }
        }
        double ans=dp[1][(1<<n)-1];
        for(int i=1;i<=n;i++) ans=min(ans,dp[i][(1<<n)-1]);
        printf("%.2lf\n",ans);
    }
    return 0;
}
