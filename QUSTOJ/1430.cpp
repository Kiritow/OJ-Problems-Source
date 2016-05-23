#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int a,b,c,d;
    char tmp[256];
    int times;
    scanf("%d",&times);
    for(;times>0;times--)
    {
        scanf("%s",tmp);
        a=0;
        b=0;
        c=0;
        d=0;
        int len=strlen(tmp);
        int i;
        for(i=0;i<len;i++)
        {
            if(tmp[i]>='A'&&tmp[i]<='Z')
            {
                a=1;
            }
            else if(tmp[i]>='a'&&tmp[i]<='z')
            {
                b=1;
            }
            else if(tmp[i]>='0'&&tmp[i]<='9')
            {
                c=1;
            }
            else if(tmp[i]=='~'||tmp[i]=='!'||tmp[i]=='@'||tmp[i]=='#'||tmp[i]=='$'||tmp[i]=='%'||tmp[i]=='^')
            {
                d=1;
            }
        }
        if(a+b+c+d>=3)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
