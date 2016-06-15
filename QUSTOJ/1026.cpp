#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
double A[110][110];
int main()
{
    scanf("%d",&n);n++;
    for(int i=1;i<n;i++)
        for(int j=1;j<=n;j++)
            scanf("%lf",&A[i][j]);
    for(int i=1;i<n;i++)
    {
        int np=i;
        for(int j=i+1;j<n;j++)if(abs(A[np][i])<abs(A[j][i]))np=j;
        if(np!=i)swap(A[np],A[i]);
        //print();
        double GD=A[i][i];
        for(int j=1;j<=n;j++)A[i][j]/=GD;
        for(int j=1;j<n;j++)
        if(j!=i){
            GD=A[j][i];
            for(int k=1;k<=n;k++)
            A[j][k]-=GD*A[i][k];
        }
    }
    for(int i=1;i<n-1;i++)
    printf("%d ",(int)(round)(A[i][n]));
    printf("%d\n",(int)(round)(A[n-1][n]));
    return 0;
}
