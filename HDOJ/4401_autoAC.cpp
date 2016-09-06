 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #define PI acos(-1.0)
 using namespace std;
 struct Node
 {
     double h,x;
 };
 Node a[1005],b[1005],st[1005];
 double L;
 int n,T1,T2,top;
 inline int DB(double x)
 {
     if(x>1e-10) return 1;
     if(x<-1e-10) return -1;
     return 0;
 }
 double cal1(Node a,Node b)
 {
     double k=(a.h-b.h)/(a.x-b.x);
     double x=a.x-a.h/k;
     return x;
 }
 double cal2(double x1,double x2,double h,int t)
 {
     double a=sqrt(h*h+x2*x2)-sqrt(h*h+x1*x1);
     double b=(x2-x1)*cos(PI/12.0*t);
     double c=12.0/PI;
     return c*(a-b);
 }
 double cal(double x1,double x2,double h,int t)
 {
     double B1,B2,B3;
     if(DB(x1)==0) B1=PI/2;
     else B1=atan(fabs(h/x1));
     B2=atan(fabs(h/x2));
     B3=PI/12*t;
     if(DB(B3-B1)>=0) return cal2(x1,x2,h,t);
     if(DB(B2-B3)>=0) return 0;
     double k=-tan(B3);
     return cal2(-h/k,x2,h,t);
 }
 int OK(Node a,Node b,Node c)
 {
     double k1=(a.h-b.h)/(a.x-b.x);
     double k2=(b.h-c.h)/(b.x-c.x);
     if(DB(k1-k2)==-1) return 1;
     return 0;
 }
 double solve(int t,Node a[])
 {
     top=0;
     st[++top]=a[1];
     double ans=0;
     int i,j;
     double x1,x2;
     for(i=2;i<=n;i++)
     {
         x1=a[i-1].x;
         x2=a[i-1].x;
         for(j=top;j>=2;j--)
         {
             x2=cal1(st[j-1],st[j]);
             if(DB(x2-a[i].x)>=0) break;
             ans+=cal(x1-st[j].x,x2-st[j].x,st[j].h,t);
             x1=x2;
         }
         ans+=cal(x1-st[j].x,a[i].x-st[j].x,st[j].h,t);
         while(top>=2&&OK(st[top-1],st[top],a[i])||top>=1&&DB(a[i].h-st[top].h)>=0)
              top--;
         st[++top]=a[i];
     }
     return ans;
 }
 int cmp(Node a,Node b)
 {
     return a.x<b.x;
 }
 double deal(int t)
 {
     double ans=0;
     int i;
     for(i=1;i<=n;i++)
     {
         b[i]=a[n+1-i];
         b[i].x=L-b[i].x;
     }
     double xx,yy,zz;
     if(t<=6) ans=solve(t,a);
     else
     {
         ans=solve(6,a);
         ans+=solve(6,b)-solve(12-t,b);
     }
     return ans;
 }
 int main()
 {
     while(scanf("%lf%d",&L,&n),n||L)
     {
         scanf("%d%d",&T1,&T2);
         int i;
         for(i=1;i<=n;i++) scanf("%lf%lf",&a[i].x,&a[i].h);
         sort(a+1,a+n+1,cmp);
         printf("%.5lf\n",deal(T2-6)-deal(T1-6));
     }
     return 0;
 }
