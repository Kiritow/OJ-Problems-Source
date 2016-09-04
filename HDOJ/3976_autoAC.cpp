#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const double eps = 1e-9;
const int MAXN = 100;
double a[MAXN][MAXN],x[MAXN];
int equ,var;
int Gauss()
{
    int i,j,k,col,max_r;
    for(k = 0,col = 0;k < equ && col < var;k++,col++)
    {
        max_r = k;
        for(i = k+1;i < equ;i++)
            if(fabs(a[i][col]) > fabs(a[max_r][col]))
                max_r = i;
        if(fabs(a[max_r][col]) < eps)return 0;
        if(k != max_r)
        {
            for(j = col;j < var;j++)
                swap(a[k][j],a[max_r][j]);
            swap(x[k],x[max_r]);
        }
        x[k]/=a[k][col];
        for(j = col+1;j < var;j++)a[k][j]/=a[k][col];
        a[k][col] = 1;
        for(int i = 0;i < equ;i++)
            if(i != k)
            {
                x[i] -=  x[k]*a[i][k];
                for(j = col+1;j < var;j++)a[i][j] -= a[k][j]*a[i][col];
                a[i][col] = 0;
            }
    }
    return 1;
}
int main()
{
    int n,m;
    int T;
    int iCase = 0;
    scanf("%d",&T);
    while(T--)
    {
        iCase++;
        scanf("%d%d",&n,&m);
        equ = var = n;
        memset(a,0,sizeof(a));
        int u,v,w;
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            a[u-1][v-1] += 1.0/w;
            a[u-1][u-1] += -1.0/w;
            a[v-1][u-1] += 1.0/w;
            a[v-1][v-1] += -1.0/w;
        }
        for(int i = 0;i < n-1;i++)
            x[i] = 0;
        x[0] = 1;
        for(int i = 0;i < n;i++)
            a[n-1][i] = 0;
        x[n-1] = 0;
        a[n-1][0] = 1;
        Gauss();
        printf("Case #%d: %.2lf\n",iCase,x[n-1]);
    }
    return 0;
}
