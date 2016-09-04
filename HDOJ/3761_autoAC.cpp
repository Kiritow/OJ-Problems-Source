#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define eps 1e-10
#define N 50005
#define zero(a) (fabs(a)<eps)
using namespace std;
struct Point {
    double x,y;
    Point(){}
    Point(double tx,double ty){x=tx;y=ty;}
}p[N],q[N];
int n,m;
struct Segment{
    Point s,e;
    double angle;
    void get_angle(){angle=atan2(e.y-s.y,e.x-s.x);}
}seg[N];
double xmul(Point p0,Point p1,Point p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
double Get_Area(Point pt[],int n){
    double area=0;
    for(int i=1;i<n-1;i++)
        area+=xmul(pt[0],pt[i],pt[i+1]);
    return fabs(area)/2;
}
Point Get_Intersect(Segment s1,Segment s2){
    double u=xmul(s1.s,s1.e,s2.s),v=xmul(s1.e,s1.s,s2.e);
    Point t;
    t.x=(s2.s.x*v+s2.e.x*u)/(u+v);t.y=(s2.s.y*v+s2.e.y*u)/(u+v);
    return t;
}
void HalfPlaneIntersect(Segment seg[],int n){
    int idx;
    for(int i=0;i<n;i++)
        if(seg[i].angle+eps<seg[(i+1)%n].angle&&seg[i].angle+eps<seg[(i-1+n)%n].angle){
            idx=i;
            break;
        }
    Segment deq[N];
    deq[0]=seg[idx];deq[1]=seg[(idx+1)%n];
    int head=0,tail=1;
    idx=(idx+2)%n;
    for(int i=2;i<n;i++,idx=(idx+1)%n){
        while(head<tail&&xmul(seg[idx].s,seg[idx].e,Get_Intersect(deq[tail],deq[tail-1]))<-eps) tail--;
        while(head<tail&&xmul(seg[idx].s,seg[idx].e,Get_Intersect(deq[head],deq[head+1]))<-eps) head++;
        deq[++tail]=seg[idx];
    }
    while(head<tail&&xmul(deq[head].s,deq[head].e,Get_Intersect(deq[tail],deq[tail-1]))<-eps) tail--;
    while(head<tail&&xmul(deq[tail].s,deq[tail].e,Get_Intersect(deq[head],deq[head+1]))<-eps) head++;
    m=0;
    if(tail==head) return;
    for(int i=head;i<tail;i++){
        q[m++]=Get_Intersect(deq[i],deq[i+1]);
    }
    if(tail>head+1)
        q[m++]=Get_Intersect(deq[head],deq[tail]);
}
int slove(int mid){
    if(n-mid<=2) return 1;
    for(int i=0;i<n;i++){
        seg[i].s=p[i];
        seg[i].e=p[(i+mid+1)%n];
        seg[i].get_angle();
    }
    HalfPlaneIntersect(seg,n);
    return zero(Get_Area(q,m));
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        for(int i=1;i<=n/2;i++) swap(p[i],p[n-i]);
        int ans,low=0,high=n,mid;
        while(low<=high){
            mid=(low+high)/2;
            if(slove(mid)){ans=mid;high=mid-1;}
            else low=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
