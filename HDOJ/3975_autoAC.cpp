#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define EPS 1e-8
int main(){
    int t,i,ca=1;
    scanf("%d",&t);
    double ti,g=10;
    double x0[3],vx[3],vy[3],d[3],v[3];
    double a,b,t1,c;
    while(t--){
        for(i=0;i<3;i++)scanf("%lf",x0+i);
        for(i=0;i<3;i++)scanf("%lf",v+i);
        for(i=0;i<3;i++)scanf("%lf",d+i);
        for(i=0;i<3;i++){
            vx[i]=v[i]*cos(d[i]);
            vy[i]=v[i]*sin(d[i]);
            if(i==0 || ti>2*vy[i]/g)
                ti=2*vy[i]/g;
        }
        a=(vx[0]-vx[1])*(vy[1]-vy[2])-((vx[1]-vx[2])*(vy[0]-vy[1]));
        b=(x0[0]-x0[1])*(vy[1]-vy[2])-(x0[1]-x0[2])*(vy[0]-vy[1]);
        printf("Case #%d: ",ca++);
        if(ti<EPS)
            printf("-1\n");
        else if(fabs(a)<EPS && fabs(b)<EPS)
            printf("Multiply answer\n");
        else if(fabs(a)<EPS)
            printf("-1\n");
        else{
            t1=-b/a;
            if(t1>EPS && ti-t1>-EPS )
                printf("%.4lf\n",t1+EPS);
            else
                printf("-1\n");
        }
    }
    return 0;
}
