#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int T;
    double s, l1, l2, v1, v2;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lf%lf%lf%lf", &l1, &l2, &v1, &v2);
        s=cos(1)*1.55741*v2*(l1-10)/v1/sin(1);
        if(s<0)printf("0\n");
        else if(s>l2)printf("%.0lf\n", l2);
        else printf("%.0lf\n", s);
    }
    return 0;
}
