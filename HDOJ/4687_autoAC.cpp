#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MAXN = 50;
int N; 
bool Graph[MAXN][MAXN];
int Match[MAXN];
bool InQueue[MAXN],InPath[MAXN],InBlossom[MAXN];
int Head,Tail;
int Queue[MAXN];
int Start,Finish;
int NewBase;
int Father[MAXN],Base[MAXN];
int Count;
void Push(int u)
{
    Queue[Tail] = u;
    Tail++;
    InQueue[u] = true;
}
int Pop()
{
    int res = Queue[Head];
    Head++;
    return res;
}
int FindCommonAncestor(int u,int v)
{
    memset(InPath,false,sizeof(InPath));
    while(true)
    {
        u = Base[u];
        InPath[u] = true;
        if(u == Start) break;
        u = Father[Match[u]];
    }
    while(true)
    {
        v = Base[v];
        if(InPath[v])break;
        v = Father[Match[v]];
    }
    return v;
}
void ResetTrace(int u)
{
    int v;
    while(Base[u] != NewBase)
    {
        v = Match[u];
        InBlossom[Base[u]] = InBlossom[Base[v]] = true;
        u = Father[v];
        if(Base[u] != NewBase) Father[u] = v;
    }
}
void BloosomContract(int u,int v)
{
    NewBase = FindCommonAncestor(u,v);
    memset(InBlossom,false,sizeof(InBlossom));
    ResetTrace(u);
    ResetTrace(v);
    if(Base[u] != NewBase) Father[u] = v;
    if(Base[v] != NewBase) Father[v] = u;
    for(int tu = 1; tu <= N; tu++)
        if(InBlossom[Base[tu]])
        {
            Base[tu] = NewBase;
            if(!InQueue[tu]) Push(tu);
        }
}
void FindAugmentingPath()
{
    memset(InQueue,false,sizeof(InQueue));
    memset(Father,0,sizeof(Father));
    for(int i = 1;i <= N;i++)
        Base[i] = i;
    Head = Tail = 1;
    Push(Start);
    Finish = 0;
    while(Head < Tail)
    {
        int u = Pop();
        for(int v = 1; v <= N; v++)
            if(Graph[u][v] && (Base[u] != Base[v]) && (Match[u] != v))
            {
                if((v == Start) || ((Match[v] > 0) && Father[Match[v]] > 0))
                    BloosomContract(u,v);
                else if(Father[v] == 0)
                {
                    Father[v] = u;
                    if(Match[v] > 0)
                        Push(Match[v]);
                    else
                    {
                        Finish = v;
                        return;
                    }
                }
            }
    }
}
void AugmentPath()
{
    int u,v,w;
    u = Finish;
    while(u > 0)
    {
        v = Father[u];
        w = Match[v];
        Match[v] = u;
        Match[u] = v;
        u = w;
    }
}
void Edmonds()
{
    memset(Match,0,sizeof(Match));
    for(int u = 1; u <= N; u++)
        if(Match[u] == 0)
        {
            Start = u;
            FindAugmentingPath();
            if(Finish > 0)AugmentPath();
        }
}
int getMatch()
{
    Edmonds();
    Count = 0;
    for(int u = 1; u <= N;u++)
        if(Match[u] > 0)
            Count++;
    return Count/2;
}
bool g[MAXN][MAXN];
pair<int,int>p[150];
int main()
{
    int m;
    while(scanf("%d%d",&N,&m)==2)
    {
        memset(g,false,sizeof(g));
        memset(Graph,false,sizeof(Graph));
        int u,v;
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d",&u,&v);
            p[i] = make_pair(u,v);
            g[u][v] = true;
            g[v][u] = true;
            Graph[u][v] = true;
            Graph[v][u] = true;
        }
        int cnt0 = getMatch();
        vector<int>ans;
        for(int i = 1;i <= m;i++)
        {
            u = p[i].first;
            v = p[i].second;
            memcpy(Graph,g,sizeof(g));
            for(int j = 1;j <= N;j++)
                Graph[j][u] = Graph[u][j] = Graph[j][v] = Graph[v][j] = false;
            int cnt = getMatch();
            if(cnt < cnt0-1)
                ans.push_back(i);
        }
        int sz = ans.size();
        printf("%d\n",sz);
        for(int i = 0;i < sz;i++)
        {
            printf("%d",ans[i]);
            if(i < sz-1)printf(" ");
        }
        printf("\n");
    }
    return 0;
}
