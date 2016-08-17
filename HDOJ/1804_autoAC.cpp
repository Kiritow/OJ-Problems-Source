#include<stdio.h>
#include<string.h>
#define MAX 100+10
int fun2(char *str);
int fun1(char *str);
int main()
{
    int n1,n2;
    char str1[MAX][MAX],str2[MAX][MAX],str3[MAX][MAX];
    while(scanf("%d %d",&n1,&n2)>0)
    {
        memset(str3,'\0',sizeof(str3));
        for(int i=0;i<n1;i++)
        {
            scanf("%s %s",str1[i],str2[i]);
        }
        for(int i=0;i<n2;i++)
        {
            scanf("%s",str3[i]);
        }
        for(int i=0;i<n2;i++)
        {
            int flag=1;
            for(int j=0;j<n1;j++)
            {
                if(!strcmp(str1[j],str3[i]))
                {
                    printf("%s\n",str2[j]);
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                if(fun1(str3[i]))
                {
                    int len=strlen(str3[i]);
                    str3[i][len-1]='i';
                    str3[i][len]='e';
                    str3[i][len+1]='s';
                    printf("%s\n",str3[i]);
                }
                else if(fun2(str3[i]))
                {
                    strcat(str3[i],"es");
                    printf("%s\n",str3[i]);
                }
                else
                {
                    strcat(str3[i],"s");
                    printf("%s\n",str3[i]);
                }
            }
        }
    }
}
int fun1(char *str)
{
    int len=strlen(str);
    if(str[len-1]=='y'&&str[len-2]!='e'&&str[len-2]!='i'&&str[len-2]!='o'&&str[len-2]!='u')
    return 1;
    else
    return 0;
}
int fun2(char *str)
{
    int len=strlen(str);
    if(str[len-1]=='o'||str[len-1]=='s'||str[len-1]=='x'||(str[len-2]=='c'&&str[len-1]=='h')||(str[len-2]=='s'&&str[len-1]=='h'))
    return 1;
    else
    return 0;
}
