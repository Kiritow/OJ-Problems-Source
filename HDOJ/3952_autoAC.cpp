#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
struct Point {
    double x, y;
    Point operator - (const Point& t) const {
        Point tmp;
        tmp.x = x - t.x;
        tmp.y = y - t.y;
        return tmp;
    }
    Point operator + (const Point& t) const {
        Point tmp;
        tmp.x = x + t.x;
        tmp.y = y + t.y;
        return tmp;
    }
    bool operator == (const Point& t) const {
        return fabs(x-t.x) < eps && fabs(y-t.y) < eps;
    }
}; 
struct pol{
    Point node[11];
    int num;
}P[11];
inline double Cross(Point a, Point b, Point c) {                   
    return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y); 
}
bool dotOnSeg(Point p, Point s, Point e) {                            
    if ( p == s || p == e )        // 蜂电规娉
        return true;
    return Cross(p,s,e) < eps && 
        (p.x-s.x)*(p.x-e.x)<eps && (p.y-s.y)*(p.y-e.y)<eps;
}
struct Line {
    double a, b, c;
};
Line Turn(Point s, Point e) {                                       
    Line ln;
    ln.a = s.y - e.y;
    ln.b = e.x - s.x;
    ln.c = s.x*e.y - e.x*s.y;
    return ln;
}
bool Line_Inst(Line l1, Line l2, Point &p) {                        
    double d = l1.a*l2.b - l2.a*l1.b;
    if ( fabs(d) < eps )    return false;
    p.x = (-l1.c*l2.b + l2.c*l1.b) / d;
    p.y = (-l1.a*l2.c + l2.a*l1.c) / d;
    return true; 
}
int main()
{
    int t,i,j,k,cases=1;
    scanf("%d",&t);
    int x,y,m,n,ans;
    while(t--)
    {
         scanf("%d",&n);
         for(i=1;i<=n;i++)
         {
             scanf("%d",&P[i].num);
             for(j=1;j<=P[i].num;j++)
                  scanf("%lf%lf",&P[i].node[j].x,&P[i].node[j].y);
         }
     if(n<=2){ printf("Case %d: %d\n",cases++,n);continue;}
     Point p;
     int max=0;
         for(i=1;i<=n;i++)
         {
             for(j=i+1;j<=n;j++)
             {
                 for(k=1;k<=P[i].num;k++)
                 {
                     for(m=1;m<=P[j].num;m++)
                     {   
                         ans=2;                   
                         Line a=Turn(P[i].node[k],P[j].node[m]) ;
                         for(x=1;x<=n;x++)
                         {
                             if(x==i||x==j) continue;
                             for(y=1;y<P[x].num;y++)
                             {
                                 Line b=Turn(P[x].node[y],P[x].node[y+1]);
                                 if(Line_Inst(a,b,p)&&dotOnSeg(p,P[x].node[y],P[x].node[y+1]))    
                                 {
                                     ans++;
                                     break;
                                 }
                             }
                         }
                         if(ans>max) max=ans;
                     }
                 }
             }
         }
         printf("Case %d: %d\n",cases++,max);
    }
    return 0;
}
