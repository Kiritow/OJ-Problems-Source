#include <cstdio>
#include <cstring>
#define MAXNUM 1005
int num1[MAXNUM][MAXNUM]; 
int num2[MAXNUM][MAXNUM]; 
int sum1[MAXNUM][MAXNUM]; 
int sum2[MAXNUM][MAXNUM];
int main(void)
{
    int n,m;
    memset(sum1,0,sizeof(sum1));
    memset(sum2,0,sizeof(sum2));
    while (~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                scanf("%d",&num1[i][j]);
                sum1[i][j] = num1[i][j] + sum1[i][j-1] + sum1[i-1][j] - sum1[i-1][j-1]; 
            }
        for(int i=1; i<=m; i++)
            for(int j=1; j<=m; j++)
            {
                scanf("%d",&num2[i][j]);
                sum2[i][j] = num2[i][j] + sum2[i][j-1] + sum2[i-1][j] - sum2[i-1][j-1]; 
            }
        bool flag = false;
        for(int i=m; i<=n; i++)
        {
            for(int j=m; j<=n; j++)
            {
                if (sum2[m][m] == sum1[i][j] - sum1[i][j-m] - sum1[i-m][j] + sum1[i-m][j-m])
                {
                    int k;
                    for(k=1; k<=m; k++)
                        if (sum2[k][k] != (sum1[i-m+k][j-m+k] - sum1[i-m][j-m+k] - sum1[i-m+k][j-m] + sum1[i-m][j-m]))
                        {
                            break;
                        }
                    if (k > m)
                    {
                        for(k=1; k<=m; k++)
                        {
                            int l;
                            for(l=1; l<=m; l++)
                            {
                                if (num2[k][l] != num1[i-m+k][j-m+l])
                                {
                                    break;
                                }
                            }
                            if (l <= m)
                                break;
                        }
                        if (k > m)
                            flag = true;
                    }
                }
                if (flag)
                    break;
            }
        }
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
