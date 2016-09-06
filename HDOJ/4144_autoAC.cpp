#include <stdio.h>
#include <string.h>
int num(char c)
{
    if(c>='A' && c<='Z')
    return 0;
    else return 1;
}
int main()
{
    int n,i,k;
    char a[10005];
    while(~scanf("%d%s",&n,a))
    {
        for(i = 0;i<n;i+=5)
        {
            k = 0;
            if(num(a[i]))
            k+=16;
            if(num(a[i+1]))
            k+=8;
            if(num(a[i+2]))
            k+=4;
            if(num(a[i+3]))
            k+=2;
            if(num(a[i+4]))
            k++;
            printf("%c",k+'A');
        }
        printf("\n");
    }
    return 0;
}
