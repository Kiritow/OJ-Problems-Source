#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char cmdline[10240];
int main()
{
    int line,word;
    scanf("%d%*c",&line);
    for(;line>0;line--)
    {
        memset(cmdline,0,10240);
        gets(cmdline);
        int i;
        int len=strlen(cmdline);
        word=0;
        for(i=1;i<len-1;i++)
        {
            if(cmdline[i]==' '&&cmdline[i-1]!=' '&&cmdline[i+1]!=' ')
            {
                word++;
            }
        }
        printf("%d\n",++word);
    }
    return 0;
}
