#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct point
{
    double x,y,z;
    point(double _x,double _y,double _z)
        {
            x=_x;y=_y;z=_z;
        }
};
struct Vector  
{
    double x,y,z;
    Vector(double _x,double _y,double _z)
        {
            x=_x,y=_y,z=_z;
        }
};
struct plane   
{
    double a,b,c,d;
    plane(double _a,double _b,double _c,double _d)
        {
            a=_a,b=_b,c=_c,d=_d;
        }
};
Vector getvector(point a,point b)
{
    Vector ans=Vector(a.x-b.x,a.y-b.y,a.z-b.z);
    return ans;
}
Vector Common_Vertical_Line(Vector a,Vector b)
{
    Vector ans=Vector(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
    return ans;
}
double pointDis(Vector a)
{
    return sqrt((a.x*a.x+a.y*a.y+a.z*a.z));
}
plane getPlane(Vector a,Vector b,point c) 
{
    Vector line=Common_Vertical_Line(a,b);
    plane ans=plane(line.x,line.y,line.z,line.x*(-1)*c.x+line.y*(-1)*c.y+line.z*(-1)*c.z);
    return ans;
}
point getPoint(plane P,Vector B,point C)
{
    double k=((-1)*P.b*C.y-P.a*C.x-P.c*C.z-P.d)/(P.a*B.x+P.b*B.y+P.c*B.z);
    point ans=point(B.x*k+C.x,B.y*k+C.y,B.z*k+C.z);
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double a,b,c;
        scanf("%lf%lf%lf",&a,&b,&c);point x1=point(a,b,c);
        scanf("%lf%lf%lf",&a,&b,&c);point y1=point(a,b,c);
        scanf("%lf%lf%lf",&a,&b,&c);point x2=point(a,b,c);
        scanf("%lf%lf%lf",&a,&b,&c);point y2=point(a,b,c);
        Vector  l1=getvector(x1,y1);
        Vector  l2=getvector(x2,y2);
        Vector line=Common_Vertical_Line(l1,l2);
        plane p1=getPlane(l1,line,x1);
        plane p2=getPlane(l2,line,x2);
        point ans2=getPoint(p1,l2,x2);
        point ans1=getPoint(p2,l1,x1);
        Vector ans=getvector(ans1,ans2);
        printf("%.6lf\n",pointDis(ans));
        printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n",ans1.x,ans1.y,ans1.z,ans2.x,ans2.y,ans2.z);
    }
    return 0;
}
