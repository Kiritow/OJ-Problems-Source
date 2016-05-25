#include <stdio.h>
#include <string.h>
 
char str[2048];
 
 
int iStack=0;
char stk[256][256];
 
int main()
{
    gets(str);
    int L=strlen(str);
    for(int i=0;i<L;i++)
    {
        if(str[i]==','||str[i]=='.')
        {
            str[i]=' ';
        }
    }
 
    char* p=str;
    while(sscanf(p,"%s",stk[iStack])==1)
    {
        p=p+strlen(stk[iStack])+1;
        iStack++;
    }
    for(int i=iStack-1;i>=0;--i)
    {
        printf("%s ",stk[i]);
    }
    return printf("\n"),0;
}
