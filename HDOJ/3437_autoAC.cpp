#include <stdio.h>
#include <algorithm>
#include <math.h>
#define zero(x) if(dcmp(x)==0)x=0
#define cross(p0,p1,p2) ((p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x))
#define dot(p0,p1,p2) ((p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y))
#define luoti(h) (sqrt(2*(h)/9.18))
#define ponseg(p0,p1,p2) (dcmp(cross(p0,p1,p2))==0&&dcmp(dot(p0,p1,p2))<=0)
using namespace std;
const double eps=1e-4;
const double inf=1e10;
struct point{
    double x,y;
};
struct wx{
    double z,k;
    int n,type;
    point p[11];
}rec[11];
double cmp(wx a,wx b){
    return a.z>b.z;
}
int dcmp(double x){
    return (x>eps)-(x<-eps);
}
bool reach(double vx,double vy,double x,double y,double z,wx pol){
    double sum=luoti(z-pol.z);
    point p;
    p.x=x+sum*vx;
    p.y=y+sum*vy;
    for(int i=0;i<pol.n;i++)
        if(ponseg(p,pol.p[i],pol.p[i+1]))
            return 1;
    int judge=dcmp(cross(p,pol.p[0],pol.p[1]));
    for(int i=1;i<pol.n;i++)
        if(dcmp(cross(p,pol.p[i],pol.p[i+1]))*judge<0)
            return 0;
    return 1;
}
int segsec(point p1,point p2,point p3,point p4,point &cp){
    double u=cross(p1,p2,p3),v=cross(p2,p1,p4);
    if(dcmp(u+v)){
        cp.x=(p3.x*v+p4.x*u)/(v+u);
        cp.y=(p3.y*v+p4.y*u)/(v+u);
        if(ponseg(cp,p1,p2)&&ponseg(cp,p3,p4))return 1;
    }return 0;
}
void roat(double x,double y,double &vx,double &vy,double k){
        double s=sin(k),c=cos(k);
        zero(s);
        zero(c);
        vx=(x*c-y*s);
        vy=(x*s+y*c);
}
double judge(point a,point b,double vx,double vy){ 
    if(dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0)return 0;
    if(dcmp(a.x-b.x)==0)return fabs((a.y-b.y)/vy);
    return fabs((a.x-b.x)/vx);
}
double into(double &vx,double &vy,double &x,double &y,double &z,wx pol){
    double sum=luoti(z-pol.z);
    x+=(sum*vx);
    y+=(sum*vy);
    z=pol.z;
    point p0,p1,cp;
    p0.x=x;
    p0.y=y;
    if(pol.type==1)vx=pol.k;
    else if(pol.type==2)vy=pol.k;
    else roat(vx,vy,vx,vy,pol.k);
    if(dcmp(vx)==0&&dcmp(vy)==0){
        for(int i=0;i<pol.n;i++)
            if(ponseg(p0,pol.p[i],pol.p[i+1]))
                return 0.0;
        return -inf;
    }
    p1.x=x+10000*vx;
    p1.y=y+10000*vy;
    for(int i=0;!segsec(p0,p1,pol.p[i],pol.p[i+1],cp)&&i<pol.n;i++);
    x=cp.x;
    y=cp.y;
    sum+=judge(p0,cp,vx,vy);
    return sum;
}
int main(){
    int tim,n;
    scanf("%d",&tim);
    for(int cas=0;cas<tim;){
        double vx,vy,x=0,y=0,z;
        printf("Case %d: ",++cas);
        scanf("%lf%lf%lf%d",&vx,&vy,&z,&n);
        for(int i=0;i<n;i++){
            scanf("%lf%d",&rec[i].z,&rec[i].n);
            for(int j=0;j<rec[i].n;j++)
                scanf("%lf%lf",&rec[i].p[j].x,&rec[i].p[j].y);
            rec[i].p[rec[i].n]=rec[i].p[0];
            scanf("%d%lf",&rec[i].type,&rec[i].k);
            if(rec[i].z<=0||rec[i].z>z){
                i--;
                n--;
            }
        }
        if(z<0){
            puts("Forever!");
            continue;
        }
        sort(rec,rec+n,cmp);
        double times=0;
        for(int i=0;times>=0&&i<n;i++)
            if(reach(vx,vy,x,y,z,rec[i])){
                times+=into(vx,vy,x,y,z,rec[i]);
            }
        if(times<0)puts("Forever!");
        else printf("%.2lf\n",times+luoti(z));
    }
    return 0;
}
