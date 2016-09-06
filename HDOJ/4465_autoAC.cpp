#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 400200
double f[N];
double logc(int n,int m)
{
    return f[m]-f[n]-f[m-n];
}
int main ()
{
    int n;
    int i,j,k=0;
    double p,ans,ret;
    f[0]=0;
    for (i=1;i<N;++i) f[i]=f[i-1]+log(1.0*i);
    while (scanf("%d%lf",&n,&p)!=EOF)
    {
        ans=0;
        double p1=log(p),p2=log(1-p);
        double q1=(n+1)*p1,q2=(n+1)*p2;
        for (i=0;i<n;++i)
        {
            ans+=((n-i)*exp(logc(n,n+i)+q1+i*p2));
            ans+=((n-i)*exp(logc(n,n+i)+q2+i*p1));
        }
        printf("Case %d: %.6lf\n",++k,ans);
    }
    return 0;
}
