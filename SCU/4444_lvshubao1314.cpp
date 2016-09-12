/**
SCU - 4444 别样最短路径-大数据完全图
题目大意：给定一个完全图，其中有两种边，长度为a（不超过5e5）或长度为b（剩下的），求有1~n的最短路径（数据范围1e5）
解题思路：如果1和n之间连边为a那么答案一定为a和一条最短的全由b组成的路径的较小者，如果1和n之间连边为b，那么答案一定
           为b和一条最短的全由a组成的路径的较小者。对于第1种情况直接跑spfa就可以了，第二种情况由于边数较多，不能直接spfa
           从1开始搜索与其相连的边权为b的边，用set维护一下，由于每个点只入队1次，复杂度还是允许的。这种处理方法还是第一
           次做，感觉很巧妙
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
typedef long long LL;
const int INF=1e9+7;
const int maxn=100100;
int n,m,vis[maxn];
LL a,b,dis[maxn];
set<int>st,ts;
set<int>::iterator it;
int head[maxn],ip;
void init()
{
    memset(head,-1,sizeof(head));
    ip=0;
}
struct note
{
    int v,next;
}edge[maxn*10];
void addedge(int u,int v)
{
    edge[ip].v=v,edge[ip].next=head[u],head[u]=ip++;
}
void spfa()
{
    queue<int>q;
    for(int i=0;i<=n;i++)dis[i]=INF;
    memset(vis,0,sizeof(vis));
    dis[1]=0;
    q.push(1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].v;
            if(dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    printf("%lld\n",min(dis[n]*a,b));
}
void bfs()
{
    dis[n]=INF;
    st.clear(),ts.clear();
    for(int i=2;i<=n;i++)st.insert(i);
    queue<int>q;
    q.push(1);
    dis[1]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].v;
            if(st.count(v)==0)continue;
            st.erase(v),ts.insert(v);
        }
        for(it=st.begin();it!=st.end();it++)
        {
            q.push(*it);
            dis[*it]=dis[u]+1;
        }
        st.swap(ts);
        ts.clear();
    }
    printf("%lld\n",min(dis[n]*b,a));
}
int main()
{
    while(~scanf("%d%d%lld%lld",&n,&m,&a,&b))
    {
        init();
        int flag=0;
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            if(u>v)swap(u,v);
            addedge(u,v);
            addedge(v,u);
            if(u==1&&v==n)flag=1;
        }
        if(flag)bfs();
        else spfa();
    }
    return 0;
}
