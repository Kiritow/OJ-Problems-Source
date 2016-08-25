#include <stdio.h>
#include <math.h>
int main()
{
    double xQ,yQ;
    double k1;
    int a,b,x0,y0,T;
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            scanf("%d%d%d%d",&a,&b,&x0,&y0);
            k1=y0/(x0*1.0);
            xQ=sqrt((a*a*b*b*1.0)/(a*a*k1*k1+b*b));
            yQ=k1*xQ;int flag= 0;
            int w=a*a-b*b;
            if((x0*x0)/(a*a)+(y0*y0)/(b*b)<1)
            {
                printf("In ellipse\n");
                continue;
            }
            if(w < 0)
            {
                flag =1;
                w=-w;
            }
            double F1,F2;
            double c =sqrt(w*1.0);
            if(flag == 0)
            {
                 F1 = sqrt((xQ+c)*(xQ+c)+(yQ*yQ));
                 F2 = sqrt((xQ-c)*(xQ-c)+yQ*yQ);
            }
            else
            { 
                F1 = sqrt(xQ*xQ+(yQ+c)*(yQ+c));
                F2 = sqrt(xQ*xQ+(yQ-c)*(yQ-c));
            }
            double t = (sqrt)((xQ*xQ*b*b*b*b)*1.0+(yQ*yQ*a*a*a*a)*1.0);
            double d =a*a*b*b/(t*1.0);
            double D=d*d*F1*F2;
             D = a*a*b*b;
            printf("%.0lf\n",D);
        }
    }
    return 0;
}
