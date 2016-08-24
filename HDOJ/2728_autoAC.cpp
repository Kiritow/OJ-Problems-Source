#include<stdio.h>
double max(double a,double b)
{
    if(a>b)
        return a;
    else
        return b;
}
double min(double a,double b)
{
    if(a>b)
        return b;
    else
        return a;
}
int main()
{
    int a,b,c,d,z;
    double x1,x2,x3,x4,y1,y2;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF&&(a!=0||b!=0||c!=0||d!=0))
    {
        if(c>=a&&d>=b)
            printf("100%%\n");
        else if(c>=b&&d>=a)
            printf("100%%\n");
        else 
        {
            x1=c*1.0/a;
            x2=d*1.0/b;
            y1=min(x1,x2);
            x3=c*1.0/b;
            x4=d*1.0/a;
            y2=min(x3,x4);
            z=max(y1,y2)*100;
            printf("%d%%\n",z);
        }
    }
    return 0;
}
