#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <vector>
#include<string>
using namespace std;
const int MAXN=1010;
const int INF=0x3f3f3f3f;
int dis[MAXN][MAXN];
bool used[MAXN];
vector<int>vec[MAXN];
queue<int>que;
void bfs(int i)
{
    memset(used,false,sizeof(used));
    dis[i][i]=0;
    used[i]=true;
    que.push(i);
    while(!que.empty())
    {
        int t=que.front();
        que.pop();
        int m=vec[t].size();
        for(int j=0;j<m;j++)
        {
            int v=vec[t][j];
            if(used[v])continue;
            if(dis[i][v]>dis[i][t]+1)
            dis[i][v]=dis[i][t]+1;
            que.push(v);
            used[v]=true;
        }
    }
}
map<string,int>mp;
int main() {
    string str;
    string str2;
    int n,m,i,j;
    while(scanf("%d",&n)==1 && n)
    {
        mp.clear();
        for(i=0;i<n;i++)
        {
            cin>>str;
            mp[str]=i;
        }
        for(i=0;i<n;i++)
        {
            dis[i][i]=0;
            for(j=i+1;j<n;j++)
                dis[i][j]=dis[j][i]=INF;
        }
        scanf("%d",&m);
        for(i=0;i<n;i++)vec[i].clear();
        while(m--)
        {
            cin>>str>>str2;
            int t1=mp[str];
            int t2=mp[str2];
            vec[t1].push_back(t2);
            vec[t2].push_back(t1);
        }
        for(i=0;i<n;i++)bfs(i);
        int ans=0;
        for(i=0;i<n;i++)
             for(j=i+1;j<n;j++)
                 ans=ans>dis[i][j]?ans:dis[i][j];
        if(ans==INF)ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
