#include<stdio.h>
#include<math.h>
int main()
{
    int T;
    double x1, x2, x3, y1, y2, y3, a, b, c, s;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
        a = ((y2-y1)*(x3-x2)/(x2-x1)-(y3-y2))/((x2*x2-x1*x1)*(x3-x2)/(x2-x1)-(x3*x3-x2*x2));
        b = ((y2-y1)-a*(x2*x2-x1*x1))/(x2-x1);
        c = y1-a*x1*x1-b*x1;
        s = (a/3*x3*x3*x3+b/2*x3*x3+c*x3)-(a/3*x2*x2*x2+b*x2*x2/2+c*x2)-(y3+y2)*(x3-x2)/2;
        printf("%.2lf\n",s);
    }
    return 0;
}
