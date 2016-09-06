#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;
const double eps=1e-9;
int dcmp(double x){if(x<-eps) return -1;return x>eps;}
struct point3
{
    double x,y,z;
    point3(double x=0,double y=0,double z=0):x(x),y(y),z(z){}
    void read(){int xt,yt,zt;scanf("%d %d %d",&xt,&yt,&zt);x=xt;y=yt;z=zt;}
};
point3 operator -(point3 a,point3 b){return point3(a.x-b.x,a.y-b.y,a.z-b.z);}
point3 operator *(point3 a,double b){return point3(a.x*b,a.y*b,a.z*b);}
bool operator <(point3 a,point3 b){return a.x<b.x||(dcmp(a.x-b.x)==0&&a.y<b.y)||(dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0&&a.z<b.z);}
bool operator ==(point3 a,point3 b){return !(a<b||b<a);}
double dot(point3 a,point3 b){return a.x*b.x+a.y*b.y+a.z*b.z;}
double cross(point3 a,point3 b){return a.x*b.y-a.y*b.x;}
double length(point3 a){return sqrt(dot(a,a));}
int convexhull(point3 *p,int n,point3 *ch)  
{  
    sort(p,p+n);
    int nt=0;
    for(int i=0;i<n;i++)
    {
        if(!nt||!(p[nt-1]==p[i])) p[nt++]=p[i];
    }
    n=nt;
    int m=0;  
    for(int i=0;i<n;i++)  
    {  
        while(m>1&&dcmp(cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<=0) --m;  
        ch[m++]=p[i];  
    } 
    int k=m;  
    for(int i=n-2;i>=0;i--)  
    {  
        while(m>k&&dcmp(cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<=0) --m;  
        ch[m++]=p[i];  
    }  
    if(n>1) --m;  
    return m;  
}  
int n,m;
double a,b,c,d;
point3 p[105],p0,q[105],ch[105];
int main()
{
    int i,j;
    int at,bt,ct,dt;
    while(scanf("%d %d %d %d",&at,&bt,&ct,&dt)!=EOF&&(at||bt||ct||dt))
    {
        a=at,b=bt,c=ct,d=dt;
        scanf("%d",&n);
        for(i=0;i<n;i++) p[i].read();
        p0.read();
        for(i=0;i<n;i++) p[i]=p[i]-p0;
        d=d-dot(point3(a,b,c),p0);
        scanf("%d",&m);
        for(i=0;i<m;i++) q[i].read(),q[i]=q[i]-p0;
        int nt=0;
        for(i=0;i<n;i++)
        {
            double te=dot(point3(a,b,c),p[i]);
            if(dcmp(te)==0) continue;
            if(dcmp(d/te)>0) p[i]=p[i]*(d/te),++nt;
        }
        if(nt==0) printf("ZERO\n");
        else if(nt<n) printf("INF\n");
        else
        {
            for(i=0;i<n;i++)
            {
                if(ct) p[i].z=0;
                else if(bt) swap(p[i].y,p[i].z),p[i].z=0;
                else swap(p[i].x,p[i].z),p[i].z=0;
            }
            nt=convexhull(p,n,ch);
            int rt=0;
            for(i=0;i<m;i++)
            {
                double te=dot(point3(a,b,c),q[i]);
                if(dcmp(te)==0||dcmp(d/te)<0) continue;
                q[i]=q[i]*(d/te);
                if(ct) q[i].z=0;
                else if(bt) swap(q[i].y,q[i].z),q[i].z=0;
                else swap(q[i].x,q[i].z),q[i].z=0;
                for(j=0;j<nt;j++)
                {
                    if(dcmp(cross(q[i]-ch[j],ch[(j+1)%nt]-ch[j]))>=0) break;
                }
                if(j>=nt) {++rt;/*cout<<q[i].x<<" 1 "<<q[i].y<<endl;*/}
            }
            printf("%.2lf%%\n",100.0*rt/m);
        }
    }
    return 0;
}
