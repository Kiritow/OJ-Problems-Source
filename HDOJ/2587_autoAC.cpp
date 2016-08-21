#include<cstdio>
const int mod = 20090308;
const int MAXN=1002;
long long  a[MAXN],b[MAXN],c[MAXN],d[MAXN],m;
int n;
int main()
{
    a[0]=b[0]=c[0]=d[0]=0;
    while(scanf("%d%I64d",&n,&m)!=EOF)
    {
        if(m==1)
        {
            a[1]=2;
            for(int i=2;i<=n;i++)
                a[i] =( 2 * a[i-1]+ 2* a[i-2]+3 ) % mod;
        }
        else
        {
            a[1]=b[1]=c[1]=2*m;
            d[1]=m;
            for(int i=2;i<=n;i++)
            {
                d[i]= ( 2*b[i-1]+ m ) % mod;
                b[i]= ( 2*b[i-1]+2*m+d[i-1] ) % mod;
                if(m==2)
                    c[i]=( 2* b[i-1]+ 4+ 2* d[i-1]+2* b[i-2] + 4+2* d[i-2] +a[i-2] ) %mod;
                else
                    c[i]=( b[i-1]+ m+4*(d[i-1]+m)+c[i-1] ) % mod;
                a[i]= ( b[i-1]+ d[i-1]+ c[i-1]+2*m ) % mod;
            }
        }
        printf("%d\n",a[n]);
    }
    return 0;
}
