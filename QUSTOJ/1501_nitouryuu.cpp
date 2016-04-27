#include <stdio.h>
#include <string.h>
 
int main(void)
{
    char a[101],b='9';
    while(gets(a))
    {
        for(int c=0;c<strlen(a);c++)
        {
            if(a[c]>b)
                b=a[c];
        }
        for(int c=0;c<strlen(a);c++)
        {
            printf("%c",a[c]);
            if(a[c]==b)
                printf("(max)");
        }
        printf("\n");
    }
    return 0;
}
 
/**************************************************************
    Problem: 1501
    User: 1508080122
    Language: C
    Result: 正确
    Time:0 ms
    Memory:768 kb
****************************************************************/
