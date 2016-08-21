#include<stdio.h>
#include<math.h> 
double r, R, H, V;
double volume( double h )
{
 double u = r + ( R- r ) * h / H;
 return (  3.1415926535897932384626433832795* h * (u* u + r * u + r * r) / 3.0 );
}
double erfen(double bottom,double top)
{
    double mid;
    while(top-bottom>1e-10)
    {
        mid=(top+bottom)/2;
        if(volume(mid)>V)
        {
            top=mid-1e-11;
        }
        else
        {
            bottom=mid+1e-11;
        }
    }
    return (bottom+top)/2;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf %lf %lf", &r, &R, &H, &V);
        printf("%.6lf\n",erfen(0,H));
    }
    return 0;
}
