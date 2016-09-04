#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<vector>
using namespace std;
vector<int>v[110];
int dfs(int x,int pre)
{
    int ans=0;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]!=pre)
        ans^=(1+dfs(v[x][i],x));
    }
    return ans;
}
int main()
{
    int n,m,a,b;
    while(scanf("%d",&n)!=EOF)
    {
        int ans=0,cnt=0;
        while(n--)
        {
            scanf("%d",&m);
            for(int i=1;i<=m;i++)
            v[i].clear();
            for(int i=1;i<m;i++)
            {
                scanf("%d%d",&a,&b);
                v[a].push_back(b);
                v[b].push_back(a);
            }
            int s=dfs(1,-1);
            if(s>1) cnt++;
            ans^=s;
        }
        if(cnt>=1)
        {
            if(ans) puts("PP");
            else puts("QQ");
        }
        else
        {
            if(ans) puts("QQ");
            else puts("PP");
        }
    }
}
