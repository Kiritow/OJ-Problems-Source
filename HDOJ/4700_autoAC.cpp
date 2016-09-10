#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 110
#define INF (1e9)+5
int graph[N][N],cut[N][N];
int n;
bool check(vector<int>v)
{
    if(v.size()<=1) return true;
    int bridge=INF;
    for(int i=0;i<v.size();++i)
        for(int j=0;j<v.size();++j)
        bridge=min(bridge,cut[v[i]][v[j]]);
    vector<int>v0,v1;
    for(int i=0,x=v[0];i<v.size();++i)
    {
        if(cut[v[i]][x]>bridge) v0.push_back(v[i]);
        else v1.push_back(v[i]);
    }
    if(v0.empty()||v1.empty()) return false;
    for(int i=0;i<v0.size();++i)
        for(int j=0;j<v1.size();++j)
        {
            if(cut[v0[i]][v1[j]]!=bridge) return false;
        }
    graph[v0[0]][v1[0]]=graph[v1[0]][v0[0]]=bridge;
    return check(v0)&&check(v1);
}
int main ()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
                scanf("%d",&cut[i][j]);
            cut[i][i]=INF;
        }
        memset(graph,0,sizeof(graph));
        vector<int>v;
        for(int i=1;i<=n;++i) v.push_back(i);
        if(check(v))
        {
            for(int i=1;i<=n;++i) graph[i][i]=-1;
            printf("YES\n");
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                {
                    printf("%d",graph[i][j]);
                    if(j<n) printf(" ");
                    else printf("\n");
                }
        }
        else printf("NO\n");
    }
    return 0;
}
