#include <cstdio>
#include <cmath>
int prime[20010],f[20000];
void prime_2()
{
    int n=20000,t=0;
    for (int i=2;i<=n;i++)
    {
        if (!f[i])
        {
            prime[t++]=i;
            int j=2*i;
            while (j<=n)
            {
                f[j]=1;
                j+=i;
            }
        }
    }
}
int main ()
{
    int n,x;
    prime_2();
    scanf("%d",&n);
    int max=-1,m=0;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&x);
        if (n==1) m=x;
        else
        for (int j=0;prime[j]<=x;j++)
            if (x%prime[j]==0&&j>max)
            {
                max=j;
                m=x;
            }
    }
    printf("%d",m);
    return 0;
}
