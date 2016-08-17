#include <stdio.h>
#include <string.h>
int str1[210][300]={{0}};
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        char str[300];
        gets(str);
        int len=strlen(str);
        str1[0][0]=1;
        str1[1][0]=2;
        for(int i=2;i<len;i++)
        {
            int c=0,k;
            for(k=0;k<300;k++)
            {
                int s=str1[i-1][k]+str1[i-2][k]+c;
                str1[i][k]=s%10;
                c=s/10;
            }
            while(c)
            {
                str1[i][k++]=c%10;
                c/=10;
            }
        }
        int i;
        for(i=299;i>=0;i--)
            if(str1[len-1][i])
                break;
        for(int j=i;j>=0;j--)
            printf("%d",str1[len-1][j]);
        printf("\n");
    }
    return 0;
}
