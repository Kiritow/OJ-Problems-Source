#include <stdio.h>
#include <string.h>
int main()
{
    int i;
    char s[85];
    while(gets(s)&&s[0]!='#')
    {
        int l=strlen(s);
        for(i=0;i<l;i++)
        {
            if(s[i]==' ')
                s[i]=1;
            if(s[i]=='!')
                s[i]=2;
            if(s[i]=='$')
                s[i]=3;
            if(s[i]=='%')
                s[i]=4;
            if(s[i]=='(')
                s[i]=5;
            if(s[i]==')')
                s[i]=6;
            if(s[i]=='*')
                s[i]=7;
        }
        for(i=0;i<l;i++)
        {
            if(s[i]==1)
                printf("%%20");
            if(s[i]==2)
                printf("%%21");
            if(s[i]==3)
                printf("%%24");
            if(s[i]==4)
                printf("%%25");
            if(s[i]==5)
                printf("%%28");
            if(s[i]==6)
                printf("%%29");
            if(s[i]==7)
                printf("%%2a");
            if(s[i]!=1 &&s[i]!=2 &&s[i]!=3 &&s[i]!=4&&s[i]!=5 &&s[i]!=6 &&s[i]!=7)
                printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}
