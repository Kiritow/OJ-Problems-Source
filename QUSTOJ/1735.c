#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
/*
int main()
{
    int a;
    scanf("%d",&a);
    a=((a/1000)+5)%10+(((a/100)+5)%10)*100+(((a/10)+5)%10)*10+((a+5)%10)*1000;
    printf("%d\n",a);
    return 0;
}
//*/
void swap(char* a,char* b)
{
    char tmp=*b;
    *b=*a;
    *a=tmp;
}
char buff[512];
int main()
{
    scanf("%s",buff);
    for(int i=0;i<4;i++)
    {
        buff[i]+=5;
        if(buff[i]>'9') buff[i]-=10;
    }
    swap(&buff[0],&buff[3]);
    swap(&buff[1],&buff[2]);
    printf("%s\n",buff);
    return 0;
}
