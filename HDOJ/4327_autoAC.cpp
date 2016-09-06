#include <cmath>
#include <cstdio>
#include<algorithm>
using namespace std;
const  double INF = 1000000000.0;
const  int maxn = 1010;
const double eps = 1e-12;
inline double sgn(double x) {return fabs(x)<eps?0:(x>0?1:-1);}
struct Point{
    double x,y;
    Point(double tx=0,double ty=0){x=tx;y=ty;}
    bool operator == (const Point& t) const {
        return sgn(x-t.x)==0 && sgn(y-t.y)==0;
    }
     Point operator - (const Point& t) const {
        Point tmp;
        tmp.x = x - t.x;
        tmp.y = y - t.y;
        return tmp;
    }
}p[maxn],tmp[maxn],pp[maxn],GP;
struct Seg{Point s,e;};
struct Line {
    double a, b, c;
};
double cross(Point a,Point b,Point c){return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);}
inline Point intersect(Point x,Point y,double a,double b,double c){  
    double u = fabs(a * x.x + b * x.y + c);  
    double v = fabs(a * y.x + b * y.y + c);  
    return Point( (x.x * v + y.x * u) / (u + v) , (x.y * v + y.y * u) / (u + v) );  
}  
int n,ban_tot;
void CUT1(double a,double b,double c){
    int i,tot=0;
    for(int i = 1; i <= ban_tot; ++i){  
        if(a*p[i].x + b*p[i].y + c >= eps) pp[++tot] = p[i];  
        else {  
            if(a*p[i-1].x + b*p[i-1].y + c > eps){  
                pp[++tot] = intersect(p[i],p[i-1],a,b,c);  
            }  
            if(a*p[i+1].x + b*p[i+1].y + c > eps){  
                pp[++tot] = intersect(p[i],p[i+1],a,b,c);  
            }  
        }  
    }  ban_tot=tot;
    pp[tot+1]=pp[1];pp[0]=pp[tot];
    memcpy(p,pp,sizeof(pp));
}
void CUT2(double a,double b,double c){       
    int i,tot=0;
    for(int i = 1; i <= ban_tot; ++i){  
        if(!(a*p[i].x + b*p[i].y + c > eps) ) pp[++tot] = p[i];
        else {  
            if(a*p[i-1].x + b*p[i-1].y + c < -eps){  
                pp[++tot] = intersect(p[i],p[i-1],a,b,c);  
            }  
            if(a*p[i+1].x + b*p[i+1].y + c < -eps){  
                pp[++tot] = intersect(p[i],p[i+1],a,b,c);  
            }  
        }  
    }  ban_tot=tot;
    pp[tot+1]=pp[1];pp[0]=pp[tot];
    memcpy(p,pp,sizeof(pp));
}
Line Turn(Point s, Point e) {                                        
    Line ln;
    ln.a = s.y - e.y;
    ln.b = e.x - s.x;
    ln.c = s.x*e.y - e.x*s.y;
    return ln;
}
Line make(Point a,Point b)
{
    double x0=(a.x+b.x)/2;
    double y0=(a.y+b.y)/2;
    Line tmp=Turn(a,b);
    Line ans;
    ans.a=tmp.b;
    ans.b=-tmp.a;
    ans.c=tmp.a*y0-tmp.b*x0;
    return ans;
}
Line ln[maxn];
inline double PPdis(Point a, Point b) {                               
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
inline double PLdis(Point p,Point l1,Point l2){                      
    return fabs(cross(p,l1,l2))/PPdis(l1,l2);
}
double calc(Point *p,int n)
{
      if(n<3) return 0;
      double area=0,V=0;
      for(int i=0;i<n;i++) area+=p[(i+1)%n].y*(p[i].x-p[(i+2)%n].x);
      area/=2;
      area=fabs(area);
      double H=10;
      int pos=0;
      for(int i=0;i<n;i++)
      {
          if(2-p[i].x-p[i].y<H)
          {
                  H=2-p[i].x-p[i].y;
                  pos=i;
          }
      }
      V+=area*H;
      for(int i=pos+1;;i++)
      {  
          int id1=i%n;
          int id2=(i+1)%n;
          if(id2==pos) break;
          double h=PLdis(p[pos],p[id1],p[id2]);
          double s=((2-p[id1].x-p[id1].y-H) + (2-p[id2].x-p[id2].y-H)) * PPdis(p[id1],p[id2])/2;
          V+=s*h/3;
      }
      return V;
}
double ans[110];
int main(){
    int t,ca=1,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lf%lf",&tmp[i].x,&tmp[i].y);
        for(int i=1;i<=n;i++)
        {
            p[1]=Point(0,0);
            p[2]=Point(0,1);
            p[3]=Point(1,1);
            p[4]=Point(1,0);
            p[0]=p[4];
            p[5]=p[1];
            ban_tot=4;
            double x0=tmp[i].x,y0=tmp[i].y;
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                Line mid_line = make(tmp[i],tmp[j]);
                double a=mid_line.a,b=mid_line.b,c=mid_line.c;
                if(a*x0+b*y0+c >= eps)
                {
                    CUT1(a,b,c);
                }
                else 
                {
                    CUT2(a,b,c);
                }
            }
            double tmpv=calc(p,ban_tot);
            ans[i]=tmpv;
        }
        printf("Case #%d:\n",ca++);
        for(int i=1;i<=n;i++)
        {
            printf("%.6lf\n",ans[i]);
        }
    }
    return 0;
}
