#include"stdio.h"
#include"math.h"
double jie(int n)
{
    double y=1;
    int i;
    for(i=2;i<=n;i++)
        y*=i;
    return y;
}
double c(int n,int x)
{
    double z;
    z=jie(n)/jie(x)/jie(n-x);
    return z;
}
int main()
{
    double ans;
    int n;
    int s;
    double x,y;
    int i;
    while(scanf("%d%d",&n,&s)!=-1)
    {
        if(s>n)
        {
            printf("100.00000\n");
            continue;
        }
        x=y=0;
        for(i=0;i<s;i++)
            x+=c(n,i)*pow(2,n-i);
        for(i=0;i<=s;i++)
            y+=c(n,i)*pow(2,n-i);
        ans=x/y;
        printf("%0.5lf\n",ans*100);
    }
    return 0;
}
