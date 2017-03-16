#include <iostream>

using namespace std;

#define MAXN 101

int R,C;

int mp[MAXN][MAXN];
int dp[MAXN][MAXN];

int dfs(int line,int col)
{
    if(dp[line][col]!=0) return dp[line][col];



    if(line+1<R&&mp[line][col]>mp[line+1][col])
    {
        dp[line][col]=max(dp[line][col],dfs(line+1,col));
    }
    if(line-1>=0&&mp[line][col]>mp[line-1][col])
    {
        dp[line][col]=max(dp[line][col],dfs(line-1,col));
    }
    if(col+1<C&&mp[line][col]>mp[line][col+1])
    {
        dp[line][col]=max(dp[line][col],dfs(line,col+1));
    }
    if(col-1>=0&&mp[line][col]>mp[line][col-1])
    {
        dp[line][col]=max(dp[line][col],dfs(line,col-1));
    }

    dp[line][col]++;

    return dp[line][col];
}

int main()
{
    cin>>R>>C;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>mp[i][j];
        }
    }

    int maxval=-1;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            maxval=max(maxval,dfs(i,j));
        }
    }


    /*
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            maxval=max(maxval,dp[i][j]);
        }
    }
    */

    cout<<maxval<<endl;

    return 0;
}
