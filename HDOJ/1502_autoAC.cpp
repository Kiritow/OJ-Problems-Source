#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#define N 1000000 
int f[70][70][70][30] = {0};  
int main()
{
    int i, j, k, n, p;
    f[0][0][0][0] = f[1][0][0][0] = f[1][1][0][0] = f[1][1][1][0] = 1;
    for(i = 2; i < 65; i++)
    {
        for(j = 0; j <= i; j++)
        {
            for(k = 0; k <=j; k++)
            {
                if(i - 1 >= j)
                {
                    for(p = 0; p < 30; p++)
                    {
                        f[i][j][k][p] += f[i - 1][j][k][p];
                        if(f[i][j][k][p] >= N)
                        {
                            f[i][j][k][p + 1] += f[i][j][k][p]/N;
                            f[i][j][k][p] %= N;
                        }
                    }
                }
                if(j - 1 >= k)                {
                    for(p = 0; p < 30; p++)
                    {
                        f[i][j][k][p] += f[i][j - 1][k][p];
                        if(f[i][j][k][p] >= N)
                        {
                            f[i][j][k][p + 1] += f[i][j][k][p]/N;
                            f[i][j][k][p] %= N;
                        }
                    }
                }
                if(k - 1 >= 0)
                {
                    for(p = 0; p < 30; p++)
                    {
                        f[i][j][k][p] += f[i][j][k - 1][p];
                        if(f[i][j][k][p] >= N)
                        {
                            f[i][j][k][p + 1] += f[i][j][k][p]/N;
                            f[i][j][k][p] %= N;
                        }
                    }
                }
            }
        }
    }
    while(scanf("%d",&n) != EOF)
    {
        for(i = 29; i >= 0; i--)
        {
            if(f[n][n][n][i])
            {
                printf("%d",f[n][n][n][i]);
                break;
            }
        }
        for(i--; i >= 0; i--)
        {
                printf("%06d",f[n][n][n][i]);
        }
        printf("\n\n");
    }
    return 0;
}
