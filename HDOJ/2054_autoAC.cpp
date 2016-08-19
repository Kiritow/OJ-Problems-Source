#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
#define MA 100100
char num1[MA],num2[MA];
void cleanzero(char str[])
{
    int len=strlen(str),i;
    if(strstr(str,".")!=NULL)
    {
        for(i=len-1;str[i]=='0';i--)
        {
            str[i]='\0';
        }
        if(str[i]=='.')
            str[i]='\0';
    }
}
int main()
{
    while(scanf("%s%s",num1,num2)!=EOF)
    {
        cleanzero(num1);
        cleanzero(num2);
        if(strcmp(num1,num2))
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
