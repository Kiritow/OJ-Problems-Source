#include <stdio.h>
#include <string.h>
char s[1000010];
int main()
{
    int n;
    while (scanf("%d",&n)&&n)
    {
        getchar();
        gets(s);
        int len=strlen(s);
        int right=0;
        int circle=0;
        for (int i=0;i<len;i++)
        {
            if (s[i]!=' '&&(s[i]<'0'||s[i]>'9'))
            {
                int num=0;
                char ope=s[i];
                i++;
                bool have=false;
                for (;i<len;i++)
                    if (s[i]!=' ')
                    {
                        num=num*10+s[i]-'0';
                        have=true;
                    }
                    else break;
                if (ope=='r')
                {
                    if (!circle) right=(right+num)%n;
                    else right=((right-num)%n+n)%n;
                }
                else
                {
                    if (num&1) circle=1-circle;
                }
            }
        }
        if (!circle)
        {
            int x1=right;
            int x2=1+(n-right)%n+1;
            if (x1<=x2)
            {
                if (x1!=0) printf("r%d",x1);
            }
            else printf("m1 r%d m1",x2-2);
        }
        else
        {
            int x1=right+1;
            int x2=1+(n-right)%n;
            if (x1<=x2)
            {
                if (x1-1!=0) printf("r%d m1",x1-1);
                else printf("m1");
            }
            else printf("m1 r%d",x2-1);
        }
        printf("\n");
    }
    return 0;
}
