#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define Mod 1000000007
#define eps 1e-8
using namespace std;
int dx[8] = {0,0,1,-1,1,-1,1,-1};
int dy[8] = {1,-1,0,0,1,1,-1,-1};
double a,b,c,d,e,f;
double dis(double x,double y,double z)
{
    return sqrt(x*x + y*y + z*z);
}
double calc(double x,double y)
{
    double A = c;
    double B = d*y+e*x;
    double C = f*x*y + a*x*x + b*y*y - 1.0;
    double delta = B*B-4.0*A*C;
    if(delta < 0.0) return Mod+10.0;    
    delta = sqrt(delta);
    double soz1 = (-B + delta)/(2.0*A);
    double soz2 = (-B - delta)/(2.0*A);
    if(dis(x,y,soz1) < dis(x,y,soz2))
        return soz1;
    return soz2;
}
double Simulated_Annealing()
{
    double x = 0,y = 0,z = sqrt(1.0/c);  
    double step = 1.0, rate = 0.99;
    while(step > eps)
    {
        for(int k=0;k<8;k++)
        {
            double kx = x + step*dx[k];
            double ky = y + step*dy[k];
            double kz = calc(kx,ky);
            if(kz >= Mod) continue;
            if(dis(kx,ky,kz) < dis(x,y,z))
            {
                x = kx,y = ky,z = kz;
            }
        }
        step *= rate;
    }
    return dis(x,y,z);
}
int main()
{
    while(scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f)!=EOF)
    {
        printf("%.7f\n",Simulated_Annealing());
    }
    return 0;
}
