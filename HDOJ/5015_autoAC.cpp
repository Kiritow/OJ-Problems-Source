#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<stack>
#include<map>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
#define maxn 110000
#define mod 10000007
#define LL __int64
struct matrix
{
    LL mat[15][15];
    matrix()
    {
        memset(mat,0,sizeof(mat));
    }
};
int a[11];
int n;
matrix mul(matrix A,matrix B)
{
    matrix C;
    int i,j,k;
    for(i=1; i<=n+2; i++)
    {
        for(j=1; j<=n+2; j++)
        {
            for(k=1; k<=n+2; k++)
            {
                C.mat[i][j]=(C.mat[i][j]+A.mat[i][k]*B.mat[k][j])%mod;
            }
        }
    }
    return C;
}
matrix powmul(matrix A,int k)
{
    matrix B;
    for(int i=1;i<=n+2;i++)B.mat[i][i]=1;
    while(k>=1)
    {
        if(k&1)B=mul(B,A);
        A=mul(A,A);
        k=k/2;
    }
    return B;
}
void print(matrix A)
{
    cout<<"matrix A"<<endl;
    for(int i=1;i<=n+2;i++)
    {
        for(int j=1;j<=n+2;j++)
        {
            cout<<A.mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int m;
    while(~scanf("%d%d",&n,&m))
    {
        matrix A,B;
        A.mat[1][1]=23;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&A.mat[i+1][1]);
        }
        A.mat[n+2][1]=3;
        for(int i=1;i<=n+1;i++)B.mat[i][1]=10;
        for(int i=1;i<=n+2;i++)B.mat[i][n+2]=1;
        for(int i=2;i<=n+1;i++)
        {
            for(int j=2;j<=i;j++)B.mat[i][j]=1;
        }
        B=powmul(B,m);
        A=mul(B,A);
        cout<<A.mat[n+1][1]<<endl;
    }
    return 0;
}
