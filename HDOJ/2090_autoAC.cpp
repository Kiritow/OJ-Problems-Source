#include<stdio.h>
int main()
{
    double a,b;
    char s[100];
    double sum = 0.0;
    while(scanf("%s", s)!=EOF)
    {
        scanf("%lf%lf", &a, &b);
        sum += a*b;        
    }
    printf("%.1lf\n", sum);
    return 0;
}
