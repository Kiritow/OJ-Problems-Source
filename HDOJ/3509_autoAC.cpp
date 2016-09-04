#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int N=55;
LL x[N][N],y[N][N],s[N][N];
LL A[N],B[N],F1[N],F2[N],tmp;
int f1,f2,a,b,K,n,m;
int i,j,k,t;
void mul(LL x[N][N],LL y[N][N])
{
    int i,j,k;
    for(i=0; i<K+2; ++i)
    {
        for(j=0; j<K+2; ++j)
        {
            for(s[i][j]=k=0; k<K+2; ++k)
                s[i][j]+=x[i][k]*y[k][j]%m;
            s[i][j]%=m;
        }
    }
    for(i=0; i<K+2; ++i)
        for(j=0; j<K+2; ++j)
            x[i][j]=s[i][j];
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>f1>>f2>>a>>b>>K>>n>>m;
        A[0]=B[0]=F1[0]=F2[0]=1;
        for(i=1; i<K+2; ++i)
        {
            A[i]=A[i-1]*a%m;
            B[i]=B[i-1]*b%m;
            F1[i]=F1[i-1]*f1%m;
            F2[i]=F2[i-1]*f2%m;
        }
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        for(i=0; i<K+2; ++i)x[i][i]=1;
        y[0][0]=y[0][1]=1;
        for(i=1; i<K+2; ++i)
        {
            for(j=1,tmp=1,k=K-i+2; k--; ++j)
            {
                y[i][j]=(tmp%m)*A[k]%m;
                y[i][j]=(y[i][j]*B[j-1])%m;
                tmp*=k;
                tmp/=j;
            }
        }
        --n;
        while(n)
        {
            if(n&1)mul(x,y);
            mul(y,y);
            n>>=1;
        }
        tmp=F1[K]*x[0][0]%m;
        for(i=1; i<K+2; ++i)
        {
            tmp+=((F2[K-i+1]*F1[i-1])%m)*x[0][i];
            tmp%=m;
        }
        cout<<tmp<<endl;
    }
    return 0;
}
