#include <stdio.h>
#include <string.h>
char p1[10001],p2[10001];
int main()
{
    int i,j,len1,len2;
    while(scanf("%s%s",p1,p2)!=EOF)
    {
        len1 = strlen(p1);
        len2 = strlen(p2);
        if(len1 > len2)
        {
            for(i = 0;i <= len1-len2-1;i ++)
            printf("d %c\n",p1[i]);
            for(j = 0;j <= len2-1;j ++)
            {
                printf("m %c\n",p2[j]);
            }
        }
        else if(len1 == len2)
        {
            for(i = 0;i <= len2-1;i ++)
            {
                printf("m %c\n",p2[i]);
            }
        }
        else if(len1 < len2)
        {
            for(i = 0;i <= len2-len1-1;i ++)
            printf("a %c\n",p2[i]);
            for(j = len2-len1;j <= len2-1;j ++)
            printf("m %c\n",p2[j]);
        }
    }
    return 0;
}
