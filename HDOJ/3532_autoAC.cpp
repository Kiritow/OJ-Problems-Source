#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#define FOR(i,s,e) for (int (i)=(s);(i)<(e);i++)
const double INF  = 1E20;
const double eps = 1E-10;
const int  MAXV = 300;
const double PI  = 3.1415926535897932384626;
struct POINT
{
 double x;
 double y;
 POINT(double a=0, double b=0) { x=a; y=b;} //constructor
};
double myatan2(double y,double x)
{
    double t = atan2(y,x);
    return t >= 0 ? t : t + 2*PI;
}
double angle[1010];
POINT p[1011];
int main()
{
    int n;
    while (scanf("%d",&n),n>0)
    {
        FOR(i,0,n)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        double max = -500;
        FOR(i,0,n)
        {
            int num = 0;
            FOR(j,0,n)
            if (i != j)
            angle[num++] = myatan2(p[i].y-p[j].y,p[i].x-p[j].x);
            sort(angle,angle+num);
            double min = INF;
            FOR(j,0,num-1)
            {
                double a = angle[j+1]-angle[j] < PI ? angle[j+1]-angle[j] : 2*PI-angle[j+1]-angle[j];
                if (min > a)
                min = a;
            }
            if (min > max)
            max = min ;
        }
        printf("%.4lf\n",fabs(max/PI*180));
    }
    return 0;
}
