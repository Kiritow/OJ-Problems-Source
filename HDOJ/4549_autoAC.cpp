#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
const int MOD=1e9+7;
struct Matrix
{
    long long mat[2][2];
};
Matrix mul(Matrix a,Matrix b)
{
    Matrix ret;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
        {
            ret.mat[i][j]=0;
            for(int k=0;k<2;k++)
            {
                ret.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
                ret.mat[i][j]%=(MOD-1);
            }
        }
    return ret;
}
Matrix pow_M(Matrix a,int n)
{
    Matrix ret;
    memset(ret.mat,0,sizeof(ret.mat));
    ret.mat[0][0]=ret.mat[1][1]=1;
    Matrix temp=a;
    while(n)
    {
        if(n&1)ret=mul(ret,temp);
        temp=mul(temp,temp);
        n>>=1;
    }
    return ret;
}
long long pow_m(long long a,long long n)
{
    long long ret=1;
    long long temp=a%MOD;
    while(n)
    {
        if(n&1)
        {
            ret*=temp;
            ret%=MOD;
        }
        temp*=temp;
        temp%=MOD;
        n>>=1;
    }
    return ret;
}
int main()
{
    int a,b,n;
    Matrix tmp;
    tmp.mat[0][0]=0;
    tmp.mat[0][1]=tmp.mat[1][0]=tmp.mat[1][1]=1;
    while(scanf("%d%d%d",&a,&b,&n)==3)
    {
        Matrix p=pow_M(tmp,n);
        int ans=(pow_m(a,p.mat[0][0])*pow_m(b,p.mat[1][0]))%MOD;
        printf("%d\n",ans);
    }
    return 0;
}
