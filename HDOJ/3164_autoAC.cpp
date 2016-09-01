#include<cstdio>
#include<cmath>
int d[1000050]={1};
int f(int i)
{
    if(d[i]==0)
    {
        double a=sin(i);
        d[i]=f((int)(i-sqrt(i+0.0)))+f((int)log(i+0.0))+f((int)(i*a*a));
        d[i]%=1000000;
    }
    return d[i];
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n!=-1)
    {
        printf("%d\n",f(n));
    }
    return 0;
}
