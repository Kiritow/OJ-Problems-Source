#include <stdio.h>
 
int a[4][4];
 
int main()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("array a:\n");
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("array b:\n");
    for(int i=3;i>=0;--i)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }
    return 0;
}
 
