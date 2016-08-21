#include<stdio.h>
#include<string.h>
int main()
{
    char c[80];
    int n,i,j,l;
    while(scanf("%s%d",c,&n)==2)
    {
        getchar();
        l=strlen(c);
        if(n<0)
            n=-((-n)%8)+8;
        n=n%8;
        if(n==0)
            puts(c);
        if(n==1)
        {
            for(i=strlen(c)-1;i>=0;i--)
            {
                for(j=0;j<i;j++)
                {
                    putchar(' ');
                }
                printf("%c\n",c[i]);
            }
        }
        if(n==2)
        {
            for(i=strlen(c)-1;i>=0;i--)
            {
                for(j=0;j<(l/2);j++)
                {
                    putchar(' ');
                }
                printf("%c\n",c[i]);
            }
        }
        if(n==3)
        {
            for(i=strlen(c)-1;i>=0;i--)
            {
                for(j=0;j<strlen(c)-1-i;j++)
                {
                    putchar(' ');
                }
                printf("%c\n",c[i]);
            }
        }
        if(n==4)
        {
            for(i=strlen(c)-1;i>=0;i--)
            {
                putchar(c[i]);
            }
            putchar('\n');
        }
        if(n==5)
        {
            for(i=0;i<strlen(c);i++)
            {
                for(j=0;j<strlen(c)-1-i;j++)
                {
                    putchar(' ');
                }
                printf("%c\n",c[i]);
            }
        }
        if(n==6)
        {
            for(i=0;i<strlen(c);i++)
            {
                for(j=0;j<l/2;j++)
                {
                    putchar(' ');
                }
                printf("%c\n",c[i]);
            }
        }
        if(n==7)
        {
            for(i=0;i<strlen(c);i++)
            {
                for(j=0;j<i;j++)
                {
                    putchar(' ');
                }
                printf("%c\n",c[i]);
            }
        }
    }
}
