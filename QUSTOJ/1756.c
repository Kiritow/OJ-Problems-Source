#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void replace(char* str,char a,char b)
{
    int L=strlen(str);
    for(int i=0;i<L;i++)
    {
        if(str[i]==a) str[i]=b;
    }
}

char msg[1024];
int main()
{
    gets(msg);
    char a,b;
    scanf("%c,%c",&a,&b);
    replace(msg,a,b);
    printf("%s\n",msg);
    return 0;
}
