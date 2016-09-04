#include <stdio.h>
#include <string.h>
__int64 a,b;
char s1[20],s2[20];
int len1,len2;
int main()
{
    int i;
    while(~scanf("%s%s",s1,s2))
    {
        len1 = strlen(s1);
        len2 = strlen(s2);
        a = b = 0;
        for(i = 0; i<len1;i++)
        {
            if(s1[i]>='0' && s1[i]<='9')
            {
                a = a*10+s1[i]-'0';
            }
        }
        if(s1[0] == '-')
            a = -a;
        for(i=0;i<len2;i++)
        {
            if(s2[i]>='0' && s2[i]<='9')
                b = b*10+s2[i]-'0';
        }
        if(s2[0] == '-')
            b = -b;
        printf("%I64d\n",a+b);
    }
    return 0;
}
