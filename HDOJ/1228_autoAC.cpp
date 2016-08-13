#include <stdio.h>
#include <ctype.h>
#include <string.h>
int cmletter(char *s)
{
    int op;
    if(strcmp(s,"zero")==0) op=0;
    if(strcmp(s,"one")==0)op=1;
    if(strcmp(s,"two")==0) op=2;
    if(strcmp(s,"three")==0) op=3;
    if(strcmp(s,"four")==0) op=4;
    if(strcmp(s,"five")==0) op=5;
    if(strcmp(s,"six")==0) op=6;
    if(strcmp(s,"seven")==0) op=7;
    if(strcmp(s,"eight")==0) op=8;
    if(strcmp(s,"nine")==0) op=9; 
    return op;
}
int dig(char *t,char *u)
{
    int len1,s,r;
    len1 = strlen(u);
    if(len1>0)
        r = 10*cmletter(t)+cmletter(u);
    else
        r = cmletter(t);
    return r;
}
int main()
{
    int i,j,k,tg,len,a,b;
    char s[1000],t[16],u[16];
    while(gets(s))
    {
        len = strlen(s);
        tg = 0;
        for(i=0,j=0,k=0;i<len;i++)
        {
            if(s[i]=='+')break;
            if(islower(s[i])&&!tg)t[j++]=s[i];
            if(islower(s[i])&&tg) u[k++]=s[i];
            else if(isspace(s[i])) tg = 1;
        }
        t[j]='\0';
        u[k]='\0';
        a = dig(t,u);
        tg = 0;
        for(i=i+2,j=0,k=0;i<len;i++)
        {
            if(islower(s[i])&&!tg)t[j++]=s[i];
            if(islower(s[i])&&tg) u[k++]=s[i];
            else if(isspace(s[i])) tg = 1;
        }
        t[j]='\0';
        u[k]='\0';
        b = dig(t,u);
        if(a+b)printf("%d\n",a+b);
        else break;
    }
    return 0;
}
