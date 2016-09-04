#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const double eps=1e-10;
const double PI=acos(-1);
int dcmp(double x)
{
    return (x>eps)-(x<-eps);
}
struct Point3
{
    double x,y,z;
    Point3(double x=0,double y=0,double z=0):x(x),y(y),z(z) {}
};
typedef Point3 Vector3;
Vector3 operator+(Point3 A,Point3 B)
{
    return Point3(A.x+B.x,A.y+B.y,A.z+B.z);
}
Vector3 operator-(Point3 A,Point3 B)
{
    return Point3(A.x-B.x,A.y-B.y,A.z-B.z);
}
Vector3 operator*(Point3 A,double p)
{
    return Point3(A.x*p,A.y*p,A.z*p);
}
Vector3 operator/(Point3 A,double p)
{
    return Point3(A.x/p,A.y/p,A.z/p);
}
bool operator<(Point3 &A,Point3 &B)
{
    return A.x<B.x||(A.x==B.x&&A.y<B.y)||(A.x==B.x&&A.y==B.y&&A.z<B.z);
}
bool operator==(Point3 &A,Point3 &B)
{
    return dcmp(A.x-B.x)==0&&dcmp(A.y-B.y)==0&&dcmp(A.z-B.z)==0;
}
ostream & operator<<(ostream & out,Vector3 A)
{
    out<<A.x<<' '<<A.y<<' '<<A.z<<endl;
    return out;
}
double Dot(Vector3 A,Vector3 B)
{
    return  A.x*B.x+A.y*B.y+A.z*B.z;
}
double Length(Vector3 A)
{
    return sqrt(Dot(A,A));
}
double Angle(Vector3 A,Vector3 B)
{
    return acos(Dot(A,B)/Length(A)/Length(B));
}
Vector3 Cross(Vector3 A,Vector3 B)
{
    return  Vector3(A.y*B.z-A.z*B.y,A.x*B.z-A.z*B.x,A.x*B.y-A.y*B.x);
}
double Area2(Point3 A,Point3 B,Point3 C)
{
    return Length(Cross(B-A,C-A));
}
int nearest(double p)
{
    int a=floor(p);
    int b=ceil(p);
    if(b-p>=p-a) return b;
    else return a;
}
int main()
{
    int T;
    cin>>T;
    double a1,b1,a2,b2;
    double R=6371009;
    double x1,y1,z1,x2,y2,z2;
    while(T--)
    {
        cin>>b1>>a1>>b2>>a2;
        b1=b1/180.0*PI;
        a1=a1/180.0*PI;
        b2=b2/180.0*PI;
        a2=a2/180.0*PI;
        x1=R*cos(b1)*cos(a1);
        y1=R*cos(b1)*sin(a1);
        z1=R*sin(b1);
        x2=R*cos(b2)*cos(a2);
        y2=R*cos(b2)*sin(a2);
        z2=R*sin(b2);
        Point3 A=Point3(x1,y1,z1);
        Point3 B=Point3(x2,y2,z2);
        double real_dist=Length(A-B);
        Point3 P;
        double arc_dist=Angle(A-P, B-P)*R;
        printf("%.0lf\n",arc_dist-real_dist);
    }
}
