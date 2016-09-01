#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int Check(char s[])
{
    int i,len;
    len=strlen(s);
    if(s[0]=='\\'||s[0]=='/')
    {
        return (1);
    }
    for(i=0;i<len;i++)
    {
        if(s[i]=='\\')
        {
            s[i]='/';
        }
    }
    for(i=0;i<len;i++)
    {
        if(s[i]==':')
        {
            if(s[i+1]=='/'&&s[i+2]=='/')
            {
                return (2);
            }
            else if(s[i+1]=='/'&&s[i+2]!='/')
            {
                return (3);
            }
        }
    }
    return (0);
}
int main()
{
    int t;
    char str[64];
    while(scanf("%d",&t)!=EOF)
    {
        getchar();
        while(t--)
        {
            int i,tag;
            memset(str,0,sizeof(str));
            gets(str);
            tag=Check(str);
            if(tag==1||tag==2)
            {
                printf("%s\n",tag==1?"It's a path in Unix-like systems!":"It's a URL!");
                for(i=0;str[i]!='\0';i++)
                {
                    if(str[i]=='\\')
                    {
                        str[i]='/';
                    }
                }
            }
            else if(tag==3)
            {
                printf("It's a path in Windows system!\n");
                for(i=0;str[i]!='\0';i++)
                {
                    if(str[i]=='/')
                    {
                        str[i]='\\';
                    }
                }
            }
            printf("%s\n",str);
        }
    }
    return (0);
}
