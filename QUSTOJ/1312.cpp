#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char buff[1024];
int main()
{
    int times;
    scanf("%d%*c",&times);
    for(;times>0;times--)
    {
        memset(buff,0,1024);
        gets(buff);
        int len=strlen(buff);
        for(int i=0;i<len;i++)
        {
            if(buff[i]=='\\')
            {
                buff[i]='/';
            }
        }
        if(buff[0]=='/')
        {
            printf("It's a path in Unix-like systems!\n%s\n",buff);
            continue;
        }
        if(strstr(buff,"://")!=NULL)
        {
            printf("It's a URL!\n%s\n",buff);
            continue;
        }
        printf("It's a path in Windows system!\n");
        for(int i=0;i<len;i++)
        {
            if(buff[i]=='/')
            {
                buff[i]='\\';
            }
        }
        puts(buff);
    }
    return 0;
}
