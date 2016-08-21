#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
__int64 sum,ji;
void dfs(char s[],__int64 now,int ci)
{
    int i,j,len;
    char str[15];
    len=strlen(s);
    if(len == 0)
    {
        if(now == sum)ji++;
        return ;
    }
    if(ci == 0)
    {
        for(i=0;i<len;i++)
        {
            for(j=0;j<=i;j++)
            {
                str[j]=s[j];
            }
            str[j]=0;
            dfs(s+i+1,(__int64)atoi(str),ci+1);
        }
    }
    else
    {
        for(i=0;i<len;i++)
        {
            for(j=0;j<=i;j++)
            {
                str[j]=s[j];
            }
            str[j]=0;
            dfs(s+1+i,now+atoi(str),ci+1);
            dfs(s+1+i,now-atoi(str),ci+1);
        }
    }
}
int main()
{
    int i,j;
    char s[15];
    memset(s,0,sizeof(s));
    while(~scanf("%s %I64d",s,&sum))
    {
        ji=0;
        dfs(s,0,0);
        printf("%I64d\n",ji);
        memset(s,0,sizeof(s));
    }
    return 0;
}
