#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 25
char str[MAXN];
int n,len,relen,ans,l,flag;
int path[MAXN];
int repath[MAXN];
void dfs(int pos,int sum)
{
    if(sum > n) return ;
    if(pos == len)
    {
        if(sum <= n && sum >= ans)
        {
            if(sum == ans) flag = 2;
            else
            {
                ans = sum,relen = 0,flag = 1;
                for(int i = 0 ; i < l ; i++)
                    repath[relen++] = path[i]; 
            }
        }
        return ;
    }
    int tmp = 0;
    for(int i = pos ; i < len ; i++)
    {
        tmp = tmp * 10 + str[i] - '0';
        path[l++] = tmp;  
        dfs(i + 1,sum + tmp);
        l--;
    }
}
int main()
{
    while(~scanf("%d%s",&n,str) && n && str[0] != '0')
    {
        len = strlen(str);
        memset(path,0,sizeof(path));
        memset(repath,0,sizeof(repath));
        l = 0,ans = 0,flag = 0;
        dfs(0,0);
        if(flag == 0) printf("error\n");
        else if(flag == 2) printf("rejected\n");
        else
        {
            printf("%d",ans);
            for(int i = 0 ;i < relen ; i++)
                printf(" %d",repath[i]);
            printf("\n");
        }
    }
    return 0;
}
