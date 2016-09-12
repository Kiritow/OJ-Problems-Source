#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;
typedef long long LL;
const double pi=acos(-1.0),eps=1e-6;
void File()
{
    freopen("D:\\in.txt","r",stdin);
    freopen("D:\\out.txt","w",stdout);
}
template <class T>
inline void read(T &x)
{
    char c=getchar(); x=0;
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) {x=x*10+c-'0'; c=getchar();}
}

LL n,mod=1e9+7;

LL extend_gcd(LL a,LL b,LL &x,LL &y)
{
    if(a==0&&b==0) return -1;
    if(b==0){x=1;y=0;return a;}
    LL d=extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

LL mod_reverse(LL a,LL n)
{
    LL x,y;
    LL d=extend_gcd(a,n,x,y);
    if(d==1) return (x%n+n)%n;
    else return -1;
}

LL phi(LL n)
{
     LL res=n,a=n;
     for(int i=2;i*i<=a;i++)
     {
         if(a%i==0)
         {
             res=res/i*(i-1);
             while(a%i==0) a/=i;
         }
     }
     if(a>1) res=res/a*(a-1);
     return res;
}

struct Matrix
{
    LL A[3][3];
    int R, C;
    Matrix operator*(Matrix b);
};

Matrix X, Y, Z;

Matrix Matrix::operator*(Matrix b)
{
    Matrix c;
    memset(c.A, 0, sizeof(c.A));
    int i, j, k;
    for (i = 1; i <= R; i++)
        for (j = 1; j <= b.C; j++)
            for (k = 1; k <= C; k++)
                c.A[i][j] = (c.A[i][j] + (A[i][k] * b.A[k][j]) % mod) % mod;
    c.R = R; c.C = b.C;
    return c;
}

void init()
{
    memset(X.A, 0, sizeof X.A);
    memset(Y.A, 0, sizeof Y.A);
    memset(Z.A, 0, sizeof Z.A);

    Y.R = 2; Y.C = 2;
    for (int i = 1; i <= 2; i++) Y.A[i][i] = 1;

    X.R = 2; X.C = 2;
    X.A[1][1]=0; X.A[1][2]=1;
    X.A[2][1]=1; X.A[2][2]=1;

    Z.R = 1; Z.C = 2;
    Z.A[1][1]=0; Z.A[1][2]=1;
}

LL work(int x)
{
    x--;
    while (x)
    {
        if (x % 2 == 1) Y = Y*X;
        x = x >> 1;
        X = X*X;
    }
    Z = Z*Y;
    return Z.A[1][2];
}

LL fib(int x)
{
    if(x==0) return 0;
    init();
    return work(x);
}

int main()
{
    while(~scanf("%lld",&n))
    {
        if(n==1) { printf("2\n"); continue; }
        LL ans=0;

        for(LL i=1;i*i<=n;i++)
        {
            if(n%i!=0) continue;

            LL t=phi(n/i)*((fib(i-1)+fib(i+1))%mod)%mod;
            ans=(ans+t)%mod;

            if(n/i!=i)
            {
                t=phi(i)*((fib(n/i-1)+fib(n/i+1))%mod)%mod;
                ans=(ans+t)%mod;
            }
        }

        LL ni=mod_reverse(n,mod);
        ans=ans*ni%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
