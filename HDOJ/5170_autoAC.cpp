#include <stdio.h>
#include <math.h>
#define eps 1e-12  
int main()
{
    double a,b,c,d;
    while(scanf("%lf%lf%lf%lf",&a,&b,&c,&d)!=EOF)
    {
        double s,s1;
        s=b*log(a);
        s1=d*log(c);
        if(a==1 &&c==1)  
        {
            printf("=\n");
            continue;
        }  
        if(fabs(s-s1)<eps)     
            printf("=\n"); 
        else if(s>s1)
            printf(">\n");
        else  if(s<s1)
            printf("<\n");
    }
    return 0;
}
