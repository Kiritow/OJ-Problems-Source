#include <cstdio>
#include <cstring>
typedef long long ll;
const ll mod=1000000007;
ll mtrx[60][2][2];
void pre_pro()
{
    memset (mtrx , 0 , sizeof(mtrx));
    mtrx[0][0][0]=1;mtrx[0][0][1]=1;
    mtrx[0][1][0]=1;mtrx[0][1][1]=0;
    for (int t=0 ; t<60 ; ++t)
       for (int i=0 ; i<2 ; ++i)
         for (int j=0 ; j<2 ; ++j)
         {
             for (int k=0 ; k<2 ; ++k)
              mtrx[t+1][i][j]+=mtrx[t][i][k]*mtrx[t][k][j];
            mtrx[t+1][i][j]%=mod;
         }
}
ll fib (ll a)
{
    a--;
    ll mat[2][2]={1,0,0,1};
    ll tmp[2][2];
    for (int p=0 ; a ; a>>=1 , ++p)
    {
        if(!(a&1))continue;
        tmp[0][0]=mat[0][0];tmp[0][1]=mat[0][1];
        tmp[1][0]=mat[1][0];tmp[1][1]=mat[1][1];
        memset (mat, 0 , sizeof(mat));
        for (int i=0 ; i<2 ; ++i)
         for (int j=0 ; j<2 ; ++j)
         {
             for (int k=0 ; k<2 ; ++k)
                 mat[i][j]+=mtrx[p][i][k]*tmp[k][j];
             mat[i][j]%=mod;
         }
    }
    return mat[0][0];
}
ll sum(ll a)
{
    if(a==0)return 0;
    else return fib(2*a)*fib(2*a+1)%mod;
}
int main ()
{
    pre_pro();
    int cas;
    scanf("%d",&cas);
    while (cas--)
    {
        ll l,r;
        scanf("%I64d%I64d",&l,&r);
        printf("%d\n",(sum(r)-sum(l-1)+mod)%mod);
    }
    return 0;
}
