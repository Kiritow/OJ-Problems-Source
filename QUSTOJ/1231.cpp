#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char buff[128];
void deal()
{
    int dec,binary;
    scanf("%d %d",&dec,&binary);
    int orgdec=dec;
    memset(buff,0,128);
    int i=0;
    while(dec>=binary)
    {
        buff[i++]='0'+dec%binary;
        dec=dec/binary;
    }
    buff[i]='0'+dec;
    int len=strlen(buff);
    int slen=len/2;
#ifndef __GNUC__
    printf("%s\n",buff);
#endif
    for(i=0;i<slen;i++)
    {
        if(buff[i]!=buff[len-i-1])
        {
            printf("Number %d is not palindrome in basis %d\n",orgdec,binary);
            return;
        }
    }
    printf("Number %d is palindrome in basis %d\n",orgdec,binary);
}
int main()
{
    int all;
    scanf("%d",&all);
    for(;all>0;all--)
    {
        deal();
    }
    return 0;
}
