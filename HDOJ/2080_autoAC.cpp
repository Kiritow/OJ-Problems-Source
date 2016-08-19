#include<stdio.h>
#include<math.h>
#define Pi 3.141592653
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {        
        double x1,y1,x2,y2;
        scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
        double ans=0;
        ans=acos( ((x1*x1 + y1*y1 + x2*x2 + y2*y2- (x1-x2)*(x1-x2) - (y1-y2)*(y1-y2) )/(2* sqrt(x1*x1 + y1*y1) * sqrt(x2*x2 + y2*y2) )))*180/Pi;
        printf("%.2lf\n",ans);
    }    
    return 0;
}
