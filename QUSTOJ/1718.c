#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dx[32][32];

#define MAXN 20

void calc()
{
    dx[1][1]=1;
    for(int i=2;i<=MAXN;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dx[i][j]=dx[i-1][j-1]+dx[i-1][j];
        }
    }
}


int main()
{
    calc();
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            printf("%d ",dx[i][j]);
        }
        printf("\n");
    }
    return 0;
}
