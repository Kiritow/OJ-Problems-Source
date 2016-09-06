#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
const double INF = 1e19;
double EPS = 1e-12;
bool zero(double t){return -EPS<t&&t<EPS;}
struct cvector{
    double x,y;
    cvector(double a,double b){x=a,y=b;}
    cvector(){}
};
cvector operator-(cvector a,cvector b){
    return cvector(a.x-b.x,a.y-b.y);
}
cvector operator+(cvector a,cvector b){
    return cvector(a.x+b.x,a.y+b.y);
}
double operator^(cvector a,cvector b){
    return a.x*b.y-b.x*a.y;
}
double operator*(cvector a,cvector b){
    return a.x*b.x+a.y*b.y;
}
struct cpoint{
    double x,y;
    void get(){scanf("%lf%lf",&x,&y);}
} p[19];
cvector operator-(cpoint a,cpoint b){
    return cvector(a.x-b.x,a.y-b.y);
}
double dist(cpoint a,cpoint b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
struct segline{
    cpoint a,b;
    segline(cpoint x,cpoint y){a=x,b=y;}
    segline(){}
};
bool intersect(segline s1,segline s2){
    return ((s1.a-s2.a)^(s2.b-s2.a))*((s1.b-s2.a)^(s2.b-s2.a))<-EPS&&
        ((s2.a-s1.a)^(s1.b-s1.a))*((s2.b-s1.a)^(s1.b-s1.a))<-EPS;
}
int n;
double solve4(){    
    return min(fabs(p[0].x-p[2].x),fabs(p[0].y-p[2].y));
}
double solve6()     
{
    double re[10];
    int t=0,k;
    for(int i=0;i<n;i++){
        re[i]=(p[i]-p[(i+n-1)%n])^(p[(i+1)%n]-p[i]);
        if(re[i]>0) t++;
    }
    if(t==1){
        for(int i=0;i<6;i++)
        if(re[i]>0) k=i;
    }else{
        for(int i=0;i<6;i++)
        if(re[i]<0) k=i;
    }
    return min(dist(p[k],p[(k+3)%n]),min(fabs(p[(k+2)%n].x-p[(k+n-2)%n].x),fabs(p[(k+2)%n].y-p[(k+n-2)%n].y)));
}
double oor6(int a,int  b) 
{
    cpoint t1 = p[(a+n-2)%n],t2 = p[(b+3)%n];
    return min(fabs(t1.x-t2.x),min(fabs(t1.y-t2.y),max(dist(p[a],p[(a+n-3)%n]),dist(p[b],p[(b+3)%n]))));
}
double oor5(int a,int b)   
{
    cpoint t1 = p[(a+n-2)%n],t2 = p[(b+2)%n];
    return min(fabs(t1.x-t2.x),min(fabs(t1.y-t2.y),min(dist(p[a],p[(a+n-3)%n]),dist(p[b],p[(b+3)%n]))));
}
double oor4(int a,int b)   
{
    double ans;
    if(zero(p[(a-2+n)%n].y-p[(b+2)%n].y))
    {
        ans = min(fabs(p[(a-1+n)%n].x-p[(b+1)%n].x),fabs(p[(a-2+n)%n].y-p[(a+2)%n].y));
    }else{
        ans = min(fabs(p[(a-1+n)%n].y-p[(b+1)%n].y),fabs(p[(a-2+n)%n].x-p[(a+2)%n].x));
    }
    ans = min(ans,min(dist(p[a],p[(a-3+n)%n]),dist(p[b],p[(b+3)%n])));
    return ans;
}
double oor3(int a,int b)   
{
    cpoint t1 = p[(a+2)%n],t2 = p[(b+2)%n];
    double ans = min(fabs(t1.x-t2.x),fabs(t1.y-t2.y));
    double A1=INF,A2=INF,B1=INF,B2=INF;
    if(intersect(segline(p[a],p[(a+3)%n]),segline(p[(a+4)%n],p[(a+5)%n])))
    A1=min(dist(p[(a+1)%n],p[(a+2)%n]),dist(p[b],p[(a+1)%n]));
    if(intersect(segline(p[a],p[(a-3+n)%n]),segline(p[(a-4+n)%n],p[(a-5+n)%n])))
    A2=min(dist(p[(a-1+n)%n],p[(a-2+n)%n]),dist(p[b],p[(a-1+n)%n]));
    if(intersect(segline(p[b],p[(b+3)%n]),segline(p[(b+4)%n],p[(b+5)%n])))
    B1=min(dist(p[(b+1)%n],p[(b+2)%n]),dist(p[a],p[(b+1)%n]));
    if(intersect(segline(p[b],p[(b-3+n)%n]),segline(p[(b-4+n)%n],p[(b-5+n)%n])))
    B2=min(dist(p[(b-1+n)%n],p[(b-2+n)%n]),dist(p[a],p[(b-1+n)%n]));
    if(A1!=INF)
    ans = min(ans,max(B1,A1));
    if(A2!=INF)
    ans = min(ans,max(B2,A2));
   // if(B1!=INF)
   // ans = min(ans,max(dist(p[b],p[(b+5)%n]),B1));
   // if(B2!=INF)
   // ans = min(ans,max(dist(p[b],p[(b+3)%n]),B2));
    //double A = max(min(dist(p[a],p[(a+3)%n]),A1),min(dist(p[a],p[(a+5)%n]),A2));
   // double B = max(min(dist(p[b],p[(b+3)%n]),B1),min(dist(p[b],p[(b+5)%n]),B2));
    ans = min(ans,max(min(dist(p[a],p[(a-3+n)%n]),dist(p[b],p[(b+3)%n])),
                      min(dist(p[a],p[(a+3)%n]),dist(p[b],p[(b-3+n)%n]))));
    return ans;
}
double solve8()
{
    double re[10];
    int t=0;
    for(int i=0;i<n;i++){
        re[i]=(p[i]-p[(i+n-1)%n])^(p[(i+1)%n]-p[i]);
        if(re[i]>0) t++;
    }
    if(t==2){
    }else{
        for(int i=0;i<n;i++) re[i] = 0-re[i];
    }
    int a,b;  
    int s = 0,k=0;
    for(int i=0;i<(n<<1);i++)
    {
        if(re[i%n]>0){
            s=max(s,k);
            k=0;
            if(i<n)
            a=b,b=i;
        }else{
            k++;
        }
    }
    if(b-a>4) swap(a,b);
    if(s==6)
    return oor6(a,b);
    if(s==5)
    return oor5(a,b);
    if(s==4)
    return oor4(a,b);
    if(s==3)
    return oor3(a,b);
    return 0;
}
int main()
{
    while(scanf("%d",&n)&&n)
    {
        for(int i=0;i<n;i++)
            p[i].get();
        if(n==4)
        printf("%.2lf\n",solve4());
        if(n==6)
        printf("%.2lf\n",solve6());
        if(n==8)
        printf("%.2lf\n",solve8());
    }
    return 0;
}
