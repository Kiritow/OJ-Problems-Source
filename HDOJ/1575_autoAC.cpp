#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
const int MAX=101;
int n;
using namespace std;
typedef struct Matrix
{
    int mat[MAX][MAX];
}matrix;
matrix A,B;
Matrix matrix_mul(matrix a,matrix b)
{
    matrix c;
    memset(c.mat,0,sizeof(c.mat));
    int i,j,k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=n;k++)
            {
                c.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
                c.mat[i][j]%=9973;
            }
        }
    }
    return c;
}
Matrix matrix_quick_power(matrix a,int k)
{
    int i;
    matrix b;
    memset(b.mat,0,sizeof(b.mat));
    for(i=1;i<=n;i++)
    b.mat[i][i]=1;
    while(k)
    {
        if(k&1)
        {
            b=matrix_mul(a,b);
            k-=1;
        }
        else
        {
            a=matrix_mul(a,a);
            k>>=1;
        }
    }
    return b;
}
int main()
{
    int i,j,sum,k,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                cin>>A.mat[i][j];
                A.mat[i][j]%=9973;
            }
        }
        B=matrix_quick_power(A,k);
        sum=0;
        for(i=1;i<=n;i++)
        {
            sum+=B.mat[i][i];
            sum%=9973;
        }
        cout<<sum<<endl;
    }
    return 0;
}
