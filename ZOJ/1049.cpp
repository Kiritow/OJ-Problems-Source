#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int t;
    double a,b;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%lf %lf",&a,&b);
        double R=sqrt(a*a+b*b);
        double S=3.14159*R*R/2;
        int year=S/50+1;
        printf("Property %d: This property will begin eroding in year %d.\n",i+1,year);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
