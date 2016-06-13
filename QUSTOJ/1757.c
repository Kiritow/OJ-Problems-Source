#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace(char* str,char* From,char* To)
{
    static char buffer[1024];
    int L=strlen(From);
    char* p;
    while((p=strstr(str,From))!=NULL)
    {
        memset(buffer,0,1024);
        strncpy(buffer,str,p-str);
        strcat(buffer,To);
        strcat(buffer,p+L);
        strcpy(str,buffer);
    }
}

char msg[1024];
char a[1024];
char b[1024];
int main()
{
    gets(msg);
    gets(a);
    gets(b);
    replace(msg,a,b);
    printf("%s\n",msg);
    return 0;
}
