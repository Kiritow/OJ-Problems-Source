#include<stdio.h>
#include<memory.h>
int main ()
{
    int s,i,b[26];
    char a[100001];
    while(gets(a)!=NULL)
    {
        memset(b,0,sizeof(b));
        for(i=0;a[i]!='\0';i++)
            b[a[i]-'a']++;
        for(i=0;i<26;i++)
            printf("%c:%d\n",'a'+i,b[i]);
        printf("\n");
    }
   return 0;
}
