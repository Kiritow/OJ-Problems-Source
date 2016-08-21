#include <iostream>
#include <math.h>
using namespace std;
#define N 10005
#define EPS 1e-10
double MIN;
double n;
double x[N],y[N];
double yyy(double xx,int id)
{
    double yy,k;
    k=(y[id+1]-y[id])/(x[id+1]-x[id]);
    yy=y[id]+k*(xx-x[id]);
    return yy;
}
void san_fen(int m)
{
    int i;
    double x1,y1,x2,y2,midx1,midx2,d,elem1,elem2;
    for(i=0;i<m-1;i++)
    {
        x1=x[i];y1=y[i];
        x2=x[i+1];y2=y[i+1];
        d=(y2-y1)/(x2-x1);
        do
        {
            midx1=(x1+x2)/2;
            midx2=(midx1+x2)/2;
            elem1=n/(midx1*midx1)+yyy(midx1,i);
            elem2=n/(midx2*midx2)+yyy(midx2,i);
            if(elem1>elem2)
                x1=midx1;
            else if(elem1<elem2)
                x2=midx2;
        }
        while(fabs(elem1-elem2)>EPS);
        if(MIN>elem1)
            MIN=elem1;
    }
}
int main()
{
    int m,i;
    while(scanf("%d%lf",&m,&n)!=EOF)
    {
        MIN=999999.0;
        for(i=0;i<m;i++)
            scanf("%lf%lf",&x[i],&y[i]);
        san_fen(m);
        printf("%.3lf\n",MIN);
    }
    return 0;
}
