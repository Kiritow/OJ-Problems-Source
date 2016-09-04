#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int M=150;
double matrix[M][M],ans[M][M],matrix1[M][M];
int n,m;
void mulmatrix(int p)
{
    int i,j,k;
    double c[M][M];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            c[i][j]=0;
            for(k=1;k<=n;k++)
                c[i][j]+=matrix1[i][k]*matrix[k][j];
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            matrix1[i][j]=c[i][j]/(p*1.0);
    }
}
void addmatrix()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            ans[i][j]+=matrix1[i][j];
    }
}
void read()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%.2lf ",ans[i][j]);
        printf("\n");
    }
}
int main()
{
    while(scanf("%d",&n),n)
    {
        int i,j,k;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%lf",&matrix[i][j]);
                if(i==j) {ans[i][j]=matrix1[i][j]=1.0;}
                else {ans[i][j]=matrix1[i][j]=0;}
            }
        }
        for(k=1;k<50;k++)
        {
            mulmatrix(k);
            addmatrix();
        }
        read();
    }
    return 0;
}
