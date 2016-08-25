#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int i,j,len,flag[28],rear[300];
    int top;
    char str[5][74];
    while(gets(str[1]))
    {
        gets(str[2]);
        gets(str[3]);
        gets(str[4]);
        memset(flag,0,sizeof(flag));
        for(i=1;i<=4;i++)
        {
            len=strlen(str[i]);
            for(j=0;j<len;j++)
            {
                if(str[i][j]>='A'&&str[i][j]<='Z')
                {
                    flag[str[i][j]-'A']++;
                }
            }
        }
        top=0;
        for(i=0;i<26;i++)
        {
            if(top<flag[i])
            {
                top=flag[i];
            }
        }
        memset(rear,0,sizeof(rear));
        for(i=top;i>0;i--)
        {
            for(j=25;j>=0;j--)
            {
                if(flag[j]>=i)
                {
                    rear[i]=j;
                    break;
                }
            }
        }
        for(i=top;i>0;i--)
        {
            for(j=0;j<26&&j<=rear[i];j++)
            {
                if(flag[j]>=i)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
                if(j<25&&j<rear[i])
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        for(i=0;i<25;i++)
        {
            printf("%c ",i+'A');
        }
        printf("Z\n");
    }
    return (0);
}
