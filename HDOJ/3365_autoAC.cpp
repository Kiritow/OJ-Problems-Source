#include<stdio.h>
#include<math.h>
#define N 10010
#define PI acos(-1)
#define EPS 1e-8
struct Point
{
    double x,y;
    void input(){scanf("%lf%lf",&x,&y);}
    void output(){printf("%.2lf %.2lf\n",x,y);}
}A[N],B[2],PA,PB;
double cosa,sina,k;
double length(Point P)
{
    return sqrt(P.x*P.x+P.y*P.y);
}
void rotate(Point &P)
{
    double t=P.x;
    P.x=P.x*cosa-P.y*sina;
    P.y=P.y*cosa+t*sina;
}
void expand(Point &P)
{
    P.x*=k;
    P.y*=k;
}
int main()
{
    int n,i,t,cnt=0;
    double a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;++i)
            A[i].input();
        for(i=0;i<2;++i)
            B[i].input();
        PA.x=A[1].x-A[0].x;
        PA.y=A[1].y-A[0].y;
        PB.x=B[1].x-B[0].x;
        PB.y=B[1].y-B[0].y;
        a=acos((PA.x*PB.x+PA.y*PB.y)/(length(PA)*length(PB)));
        if(PA.x*PB.y-PA.y*PB.x<EPS)
            a = 2.0 * PI - a;
        cosa=cos(a);
        sina=sin(a);
        k=length(PB)/length(PA);
        for(i=2;i<n;++i)
        {
            A[i].x-=A[0].x;
            A[i].y-=A[0].y;
            rotate(A[i]);
            expand(A[i]);
            A[i].x+=B[0].x;
            A[i].y+=B[0].y;
        }
        printf("Case %d:\n",++cnt);
        B[0].output();
        B[1].output();
        for(i=2;i<n;++i)
            A[i].output();
    }
    return 0;
}
