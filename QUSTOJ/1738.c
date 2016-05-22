#include <stdio.h>
char str[256];
char ans[256];
int main()
{
    scanf("%s",str);
    int a=0;
    int b=0;
    while(str[a]!=0)
    {
        if((str[a]-'0')%2) ans[b++]=str[a];
        ++a;
    }
    printf("%s\n",ans);
    return 0;
}
