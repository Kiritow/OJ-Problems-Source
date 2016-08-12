#include<iostream>
#define N 10000
char str1[N],str2[N];
void input(char *str)
{
    char tmp[N];
    getchar();
    gets(tmp);
    while(gets(tmp) && strcmp(tmp,"END"))
    {
        if(strlen(tmp)==0)
            strcat(str,"\n"); 
        else
            strcat(str,tmp);
    }
}
void dechar(char *str,int len)
{
    char tmp[N];
    int t=0;
    for(int i=0;i<len;i++)
        if(!(str[i]==' ' || str[i]=='\t' || str[i]=='\n'))
            tmp[t++]=str[i];
    tmp[t]='\0';
    strcpy(str,tmp);
}
int cmp()
{
    int n1,n2;
    n1=strlen(str1);
    n2=strlen(str2);
    if(n1==n2 && !strcmp(str1,str2))
        return 1;
    dechar(str1,n1);
    dechar(str2,n2);
    if(!strcmp(str1,str2))
        return 0;
    else
        return -1;
}
int main()
{
    int t,res;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            memset(str1,0,sizeof(str1));
            memset(str2,0,sizeof(str2));
            input(str1);
            input(str2);
            res=cmp();
            if(res==1) puts("Accepted");
            else if(res==0) puts("Presentation Error");
            else if(res==-1) puts("Wrong Answer");
        }
    }
    return 0;
}
