#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std ;
const int maxn = 100010 ;
const int inf = 0x3f3f3f3f ;
struct Edge
{
    int v ;int w ;
    int next ;
}edge[maxn*10] ;
int head[maxn] ;
int dis[20][maxn] ;
int vis[maxn] ;
int nedge ;int a[maxn] ,num;
int n , m ;
void addedge(int u ,  int v , int w)
{
    edge[nedge].v = v ;
    edge[nedge].w = w ;
    edge[nedge].next = head[u] ;
    head[u] = nedge++ ;
}
void spfa(int st)
{
    queue<int> que ;
    memset(vis , 0 ,sizeof(vis)) ;
    for(int i = 0;i < n;i++)
    dis[st][i] = i == a[st] ? 0 : inf ;
    que.push(a[st]) ;
    vis[a[st]] = 1;
    while(que.size())
    {
        int u = que.front() ;
        que.pop() ;
        vis[u] = 0 ;
        for(int i = head[u] ; i != -1 ;i = edge[i].next)
        {
            int v = edge[i].v ;
            if(dis[st][v] > dis[st][u] + edge[i].w)
            {
                dis[st][v] = dis[st][u] + edge[i].w ;
                if(!vis[v])
                vis[v] = 1 , que.push(v) ;
            }
        }
    }
}
int ans = inf ;
void dfs(int pos , int sum , int step)
{
    if(step == num)
    {
        ans = min(ans , sum + dis[pos][0]) ;
        return ;
    }
    for(int i = 1;i <= num;i++)
    if(vis[a[i]])continue ;
    else
    {
        vis[a[i]] = 1;
        dfs(i , sum + dis[pos][a[i]] , step + 1) ;
        vis[a[i]] = 0 ;
    }
}
int main()
{
    int t ;
    scanf("%d" ,&t) ;
    while(t--)
    {
        scanf("%d%d" , &n , &m) ;
        memset(head , -1  , sizeof(head)) ;
        nedge = 0 ;
        while(m--)
        {
            int u , v , w ;
            scanf("%d%d%d"  , &u , &v ,&w) ;
            addedge(u , v , w) ;
            addedge(v , u , w) ;
        }
        scanf("%d" , &num) ;
        spfa(0) ;
        for(int i = 1;i <= num ; i++)
        scanf("%d" , &a[i]) , spfa(i) ;
        ans = inf ;
        memset(vis , 0  ,sizeof(vis)) ;
        dfs(0 , 0 , 0) ;
        cout<<ans<<endl;
    }
}
