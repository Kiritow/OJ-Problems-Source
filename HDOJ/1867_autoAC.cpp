#include <stdio.h>
#include <string.h>
int next[100005];
void getnext(char str[])
{
    int i = 1,j = 0;
    int len = strlen(str);
    next [0] = -1;
    while(i < len)
    {
        if(j == -1 || str[i] == str[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
int kmp(char str1[],char str2[])
{
    int i= 0,j = 0;
    int len1 = strlen(str1),len2 = strlen(str2);
    getnext(str2);
    while(i<len1 && j<len2)
    {
        if(j == -1 || str1[i] == str2[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if(i == len1)
        return j;
    return 0;
}
int main()
{
    int x,y;
    char str1[100005],str2[100005];
    while(scanf("%s%s",str1,str2)!=EOF)
    {
        x = kmp(str1,str2);
        y = kmp(str2,str1);
        if(x == y)
        {
            if(strcmp(str1,str2)>0)
            {
                printf("%s",str2);
                printf("%s\n",str1+x);
            }
            else
            {
                printf("%s",str1);
                printf("%s\n",str2+x);
            }
        }
        else if(x>y)
        {
            printf("%s",str1);
            printf("%s\n",str2+x);
        }
        else
        {
            printf("%s",str2);
            printf("%s\n",str1+y);
        }
    }
    return 0;
}
