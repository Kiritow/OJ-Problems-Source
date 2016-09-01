#include<iostream>
#include<vector>
#include<stack>
#include<stdio.h>
using namespace std;
vector<int> V[1010];
stack<int> S;
int N;
int dfs(int v,int pre)   //涓寮
{
    int i,t;
    int sum=0;
    for(i=0;i<V[v].size();i++)
    {
        t=V[v][i];
        if(t!=pre)
        sum=sum^(dfs(t,v)+1);
    }
    return sum;
}
int main()
{
    int i,flag,t;
    while(scanf("%d",&N)!=EOF)
    {
        for(i=0;i<=N;i++)
            V[i].clear();
        while(!S.empty())
            S.pop();
        for(i=0;i<N;i++)
        {
            scanf("%d",&t);
            if(t!=-1)
            {
                V[t].push_back(i);
                V[i].push_back(t);
            }
            else
            {
                S.push(i);
            }
        }
        int t,sum=0;
        while(!S.empty())   
        {
            t=S.top();
            S.pop();
            sum=sum^dfs(t,-1);
        }
        if(sum)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
