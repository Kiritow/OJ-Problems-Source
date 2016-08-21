#include<stdio.h>
#include<string.h>
int main()
{
    char s1[200001],s2[110000];
    while(~scanf("%s %s",s1,s2))
    {
        sprintf(s1,"%s%s",s1,s1);
        if(strstr(s1,s2))puts("yes");
        else puts("no");
    }
}
