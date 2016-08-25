#include<stdio.h>
#include<string.h>
int main()
{
    char a[35];
    int i,c,l;
    while(gets(a)&&a[0]!='#')
    {
        c=0;
        l=strlen(a);
        for(i=0;i<=l-2;i++)
            if(a[i]=='1')
                c++;
        if(a[l-1]=='e')
        {
            if(c%2!=0)
                a[l-1]='1';
            else
                a[l-1]='0';
        }
        else
        {
            if(c%2!=0)
                a[l-1]='0';
            else
                a[l-1]='1';
        }
        for(i=0;i<l;i++)
        {
            if(i==l-1)
                printf("%c\n",a[i]);
            else
                printf("%c",a[i]);
        }
    }
    return 0;
}
