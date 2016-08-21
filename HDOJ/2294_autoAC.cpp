#include <stdio.h>
#include <string.h>
#include <iostream>
#define MAX_DIMENSION 35 
using namespace std;
typedef __int64 MATRIX_TYPE;
typedef __int64 MAX_INT_TYPE; 
typedef MATRIX_TYPE Matrix[MAX_DIMENSION][MAX_DIMENSION];
int ndim=MAX_DIMENSION;
int mod=1234567891;
void m_zero(Matrix  x)
{
    memset(x, 0, sizeof(MATRIX_TYPE)*MAX_DIMENSION*MAX_DIMENSION);
}
void m_one(Matrix  x)
{
    int i;
    m_zero(x);
    for(i=0;i<ndim;++i)x[i][i]=1;
}
void m_copy(Matrix  src,Matrix  dest)
{
    memcpy(dest,src, sizeof(MATRIX_TYPE)*MAX_DIMENSION*MAX_DIMENSION);
}
void m_add(Matrix  x,Matrix  y,Matrix  z)
{
    int i,j;
    for(i=0;i<ndim;i++)
        for(j=0;j<ndim;j++)
            if(mod<=1)z[i][j]=x[i][j]+y[i][j];
            else z[i][j]=(x[i][j]+(MAX_INT_TYPE)y[i][j])%mod;//module
}
void m_multiple(Matrix  a,Matrix b,Matrix c)
{
    int i,j,k;
    MAX_INT_ t;
    for(i=0;i<ndim;i++)
        for(j=0;j<ndim;j++)
        {
            t=0;
            if(mod<=1)
                for(k=0;k<ndim;k++) t+=a[i][k]*b[k][j];
            else
                for(k=0;k<ndim;k++){
                    t+=(a[i][k]*(MAX_INT_TYPE)b[k][j])%mod;
                    t%=mod;
                }
            c[i][j]=t;
        }
}
void m_pow_with_saved(Matrix  x_p[],unsigned int n, Matrix y)
{
    Matrix temp;
    m_one(y);
    for(int k=1;n;++k,n>>=1)
    {
        if ((n & 1) != 0)
        {
            m_multiple(x_p[k],y,temp);
            m_copy(temp,y);
        }
    }
}
void m_pow_sum1(Matrix  x_p[],unsigned int n, Matrix y)
{
    m_zero(y);
    if(n==0)return;
    if(n==1) m_copy(x_p[1],y);
    else
    {
        Matrix temp;
        m_pow_sum1(x_p,n>>1,temp);
        m_add(temp,y,y);
        Matrix temp2;
        m_pow_with_saved(x_p,n>>1,temp2);
        Matrix temp3;
        m_multiple(temp,temp2,temp3);
        m_add(temp3,y,y);
        if(n&1)
        {
            m_multiple(temp2,temp2,temp3);
            m_multiple(temp3,x_p[1],temp2);
            m_add(temp2,y,y);
        }
    }
}
void m_pow_sum(Matrix x, unsigned int n, Matrix y)
{
    unsigned int i=0,logn,n2=n;
    for(logn=0,n2=n;n2;logn++,n2 >>= 1);
    Matrix *pow_arry=new Matrix[logn==0?2:(logn+1)];
    m_one(pow_arry[0]);
    m_copy(x,pow_arry[1]);
    for(i=1;i<logn;i++)
    {
        m_multiple(pow_arry[i],pow_arry[i],pow_arry[i+1]);
    }
    m_pow_sum1(pow_arry,n,y);
    delete []pow_arry;
}
void view_mat(Matrix a, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
int main(void)
{
    int cas;
    scanf("%d", &cas);
    while(cas--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        Matrix a;
        ndim = k + 1;
        m_zero(a);
        for(int i = 0; i <= k; i++)
        {
            if(i == 0)
                continue;
            a[i][i] = i;
            a[i - 1][i] = k - i + 1;
        }    
        Matrix asum, res, addsum, f1, ans;
        m_one(res);
        m_pow_sum(a, n - 1, asum);
        m_add(res, asum, addsum);
        m_zero(f1);
        f1[0][1] = k;
        m_multiple(f1, addsum, ans);
        printf("%d\n", ((ans[0][k] % mod) + (__int64)mod) % mod);
    }
    return 0;
}
