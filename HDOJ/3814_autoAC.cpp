#include<iostream>
#include<algorithm>
#include<cmath>
#define eps 1e-9
using namespace std;
double f_abs(double x){
    return x<0?-x:x;
}
struct Point{
    double x,y;
    bool up,dn;
    void disp(){
        printf("%lf %lf\n",x,y);
    }
    void get(){
        scanf("%lf%lf",&x,&y);
    }
    bool friend operator<(Point a,Point b){
        if(f_abs(a.x-b.x)<eps)return a.y<b.y;
        return a.x<b.x;
    }
    bool friend operator>(Point a,Point b){
        return b<a;
    }
    bool friend operator==(Point a,Point b){
        return f_abs(a.x-b.x)<eps&&f_abs(a.y-b.y)<eps;
    }
};
struct Line{
    Point s,e;
    bool friend operator<(Line a,Line b){
        return a.s<b.s;
    }
    void st(){
        Point t;
        if(s>e){
            t=s;s=e;e=t;
        }
    }
    void get(){
        s.get();e.get();
        st();
    }
};
Line line[200000],myl[2];
Point ep[200000];
int en;
double get_cross(Point a,Line b){
    double ax,ay,bx,by;
    ax=b.s.x-a.x;
    ay=b.s.y-a.y;
    bx=b.e.x-a.x;
    by=b.e.y-a.y;
    return ax*by-ay*bx;
}
int inter(Line a,Line b,Point &rp=Point()){
    double cj[2];
    cj[0]=get_cross(b.s,a);cj[1]=get_cross(b.e,a);
    if(cj[0]*cj[1]>eps)return 0;
    cj[0]=get_cross(a.s,b);cj[1]=get_cross(a.e,b);
    if(cj[0]*cj[1]>eps)return 0;
    if(f_abs(cj[0])<eps&&f_abs(cj[1])<eps){
        return 4;
    }
    if(f_abs(cj[0])<eps){
        rp=a.s;
        if(cj[1]>eps)return 2;
        else return 3;
    }else if(f_abs(cj[1])<eps){
        rp=a.e;
        if(cj[0]>eps)return 2;
        else return 3;
    }else{
        double key1=(a.e.x-a.s.x)*(b.e.y-b.s.y);  
        double key2=(b.e.x-b.s.x)*(a.e.y-a.s.y);  
        double key=key1-key2;  
        rp.x=(a.s.y-b.s.y)*(a.e.x-a.s.x)*(b.e.x-b.s.x);  
        rp.x-=key2*a.s.x-key1*b.s.x;  
        rp.x/=key;  
        if(f_abs(b.e.x-b.s.x)<eps)rp.y=(a.e.y-a.s.y)/(a.e.x-a.s.x)*(rp.x-a.s.x)+a.s.y;  
        else rp.y=(b.e.y-b.s.y)/(b.e.x-b.s.x)*(rp.x-b.s.x)+b.s.y;  
        return 1;
    }
}
int ln;
void get_myl2(){
    double dy=myl[0].e.y-myl[0].s.y,dx=myl[0].e.x-myl[0].s.x;
    double t=sqrt(dy*dy+dx*dx);
    dy/=t;dx/=t;
    myl[1].e=myl[0].s;
    myl[1].s.x=myl[1].e.x-300000*dx;
    myl[1].s.y=myl[1].e.y-300000*dy;
}
void get_data(){
    myl[0].get();
    int t,n,i;
    int pcnt=0;
    Point p[2],ini;
    ln=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ini.get();
        if(n==1)continue;
        p[0]=ini;
        bool f=0;
        for(i=1;i<n;i++){
            f^=1;
            p[f].get();
            line[ln].s=p[f^1];
            line[ln].e=p[f];
            line[ln++].st();
        }
        line[ln].s=p[f];
        line[ln].e=ini;
        line[ln++].st();
    }
    get_myl2();
}
double get_len(Point a,Point b){
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}
void get_ep(Line l){
    en=0;
    int t,i;
    for(i=0;i<ln;i++){
        t=inter(line[i],l,ep[en]);
        if(!t||t==4)continue;
        if(t==1){
            ep[en].up=1;
            ep[en++].dn=1;
        }else if(t==2){
            ep[en].up=1;
            ep[en++].dn=0;
        }else{
            ep[en].up=0;
            ep[en++].dn=1;
        }
    }
    sort(ep,ep+en);
    int ten=0;
    for(i=0;i<en;i++){
        if(ten&&ep[i]==ep[ten-1]){
            ep[ten-1].up^=ep[i].up;
            ep[ten-1].dn^=ep[i].dn;
        }else ep[ten++]=ep[i];
    }
    en=ten;
}
void run(){
    if(myl[0].s==myl[0].e){
        printf("0.00%%\n");
        return;
    }
    int i;
    bool in=0,left=0,right=0;
    get_ep(myl[1]);
    for(i=0;i<en;i++){
        left^=ep[i].up;
        right^=ep[i].dn;
    }
    if(left||right)in=1;
    else in=0;
    get_ep(myl[0]);
    double len=get_len(myl[0].s,myl[0].e),res=0;
    Point lp=myl[0].s;
    ep[en++]=myl[0].e;
    for(i=0;i<en;i++){
        if(ep[i]==myl[0].s)continue;
        if(in)res+=get_len(ep[i],lp);
        left^=ep[i].up;
        right^=ep[i].dn;
        if(left||right)in=1;
        else in=0;
        lp=ep[i];
    }
    printf("%.2lf%%\n",res*100/len);
}
int main(){
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        get_data();
        printf("Case %d: ",i);
        run();
    }
    return 0;
}
