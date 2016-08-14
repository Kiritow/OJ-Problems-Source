#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<memory.h>
using namespace std;
int dp[524289];
int get_solve(int state,int x)
{
    int ret=state;
    for(int i=x;i<=20;i+=x)
    ret&=~(1<<(i-2));
    for(int i=2;i<=20;i++)
    {
        if(ret&(1<<(i-2)))
        for(int j=x;i-j-2>=0;j+=x)
        {
            if(!(ret&(1<<(i-j-2))))
            {
                ret&=~(1<<(i-2));
                break;
            }
        }
    }
    return ret;
}
int dfs(int state)
{
    if(dp[state]!=-1) return dp[state];
    for(int i=2;i<=20;i++)
    {
        if(state&(1<<(i-2)))
        {
            if(dfs(get_solve(state,i))==0)
            return dp[state]=1;
        }
    }
    return dp[state]=0;
}
int main()
{
    int t,n,a[21];
    int count=1;
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int state=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            state|=1<<(a[i]-2);
        }
        printf("Scenario #%d:\n",count++);
        if(dfs(state)==0)
        puts("There is no winning move.\n");
        else
        {
            printf("The winning moves are:");
            for(int i=0;i<n;i++)
            {
                    if(dfs(get_solve(state,a[i]))==0)
                        printf(" %d",a[i]);
            }
            puts(".\n");
        }
    }
}
