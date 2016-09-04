#include<stdio.h>
int main()
{
    int A,B,C;
    while(scanf("%d%d%d",&A,&B,&C)!=EOF)
    {
        double x=(double)(B+C)/(A+B+C*2);
        printf("%.6lf\n",(1-x)*B-x*C);
    }    
    return 0;
}
