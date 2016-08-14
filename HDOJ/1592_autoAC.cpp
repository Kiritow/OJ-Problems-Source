#include<stdio.h>
#include<string.h>
int num[1010][1010];
int main()
{
    int i,n,j;
    memset(num,0,sizeof(num));
    num[0][1]=1;
    for(i=1;i<1010;i++)
    {
        for(j=1;j<1010;j++)
        {
            if(j==1)
                num[i][j]+=(num[i-1][j])*2+1;
            else
                num[i][j]+=num[i-1][j]*2;
        }
        for(j=2;j<1010;j++)
        {
            if(num[i][j-1]>9)
                num[i][j]+=num[i][j-1]/10;
            num[i][j-1]%=10;
        }
    }
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1010;i>=1;i--)
            if(num[n][i]!=0)
            {
                printf("%d",num[n][i]);
                break;
            }
            for(j=i-1;j>=1;j--)
                printf("%d",num[n][j]);
            printf("\n");
    }
    return 0;
}
