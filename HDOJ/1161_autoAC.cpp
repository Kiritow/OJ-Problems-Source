#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int i,len;
    char s[1000];
    while(gets(s))
    {
        len = strlen(s);
        for(i=0;i<len;i++)
            if(isupper(s[i]))s[i]=tolower(s[i]);
        printf("%s\n",s);
    }
    return 0;
}
