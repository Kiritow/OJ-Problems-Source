#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define ll int 
#define N 20050
#define M 105000
#define inf 10737418
struct Edge{  
    ll from, to, cap, nex;  
}edge[M*4];
ll head[N], edgenum;  
void add(ll u, ll v, ll cap){  
    Edge E = { u, v, cap, head[u]};  
    edge[ edgenum ] = E;  
    head[u] = edgenum ++;
    Edge E2= { v, u, 0,   head[v]};  
    edge[ edgenum ] = E2;  
    head[v] = edgenum ++;  
}  
ll sign[N];  
bool BFS(ll from, ll to){  
    memset(sign, -1, sizeof(sign));  
    sign[from] = 0;  
    queue<ll>q;  
    q.push(from);  
    while( !q.empty() ){  
        int u = q.front(); q.pop();  
        for(ll i = head[u]; i!=-1; i = edge[i].nex)  
        {  
            ll v = edge[i].to;  
            if(sign[v]==-1 && edge[i].cap)  
            {  
                sign[v] = sign[u] + 1, q.push(v);  
                if(sign[to] != -1)return true;  
            }  
        }  
    }  
    return false;  
}  
ll Stack[N], top, cur[N];  
ll dinic(ll from, ll to){
    ll ans = 0;  
    while( BFS(from, to) )  
    {  
        memcpy(cur, head, sizeof(head));  
        ll u = from;      top = 0;  
        while(1)  
        {  
            if(u == to)  
            {  
                ll flow = inf, loc;
                for(ll i = 0; i < top; i++)  
                    if(flow > edge[ Stack[i] ].cap)  
                    {  
                        flow = edge[Stack[i]].cap;  
                        loc = i;  
                    }  
                    for(ll i = 0; i < top; i++)  
                    {  
                        edge[ Stack[i] ].cap -= flow;  
                        edge[Stack[i]^1].cap += flow;  
                    }  
                    ans += flow;  
                    top = loc;  
                    u = edge[Stack[top]].from;  
            }  
            for(ll i = cur[u]; i!=-1; cur[u] = i = edge[i].nex) 
                if(edge[i].cap && (sign[u] + 1 == sign[ edge[i].to ]))break;  
            if(cur[u] != -1)  
            {  
                Stack[top++] = cur[u];  
                u = edge[ cur[u] ].to;  
            }  
            else  
            {  
                if( top == 0 )break;  
                sign[u] = -1;  
                u = edge[ Stack[--top] ].from;  
            }  
        }  
    }  
    return ans;  
}  
void init(){memset(head,-1,sizeof head);edgenum = 0;}
char mp[15][15];
int n, m, T;
int Hash(int x,int y){return x*m+y;}
vector<int>E,P;
int dis[150][150], step[4][2]={1,0,-1,0,0,1,0,-1};
bool vis[150][150];
void bfs(int sx,int sy){
    int start = Hash(sx,sy);
    memset(vis, 0, sizeof vis);
    vis[sx][sy] = 1;
    dis[start][start] = 0;
    queue<int>qx,qy;    while(!qx.empty())qx.pop(); while(!qy.empty())qy.pop();
    qx.push(sx), qy.push(sy);
    while(!qx.empty()){
        int x = qx.front(), y = qy.front();
        qx.pop(); qy.pop();
        for(int i = 0; i < 4; i++){
            int dx = x + step[i][0], dy = y + step[i][1];
            if(!(0<=dx&&dx<n&&0<=dy&&dy<m))continue;
            if(vis[dx][dy] || mp[dx][dy]!='.')continue;
            vis[dx][dy] = 1;
            dis[Hash(dx,dy)][start] = dis[start][Hash(dx,dy)] = dis[start][Hash(x,y)]+1;
            qx.push(dx); qy.push(dy);
        }
    }
}
bool ok(int TIME){
    init();
    int from = N-2, to = N-1;
    for(int i = 0; i < P.size(); i++)add(from, P[i], 1);
    for(int i = 0; i < P.size(); i++)
    {
        for(int j = 0; j < E.size(); j++)
            if(dis[P[i]][E[j]]<=TIME)    add(P[i],j*150+150+dis[P[i]][E[j]],1);
    }
    for(int i = 0; i < E.size(); i++)
        for(int j = 1; j <= TIME; j++) 
        {
            add(i*150+150+j, to, 1);
            if(j!=TIME)
                add(i*150+150+j,i*150+150+j+1,inf);
        }
    return dinic(from,to)==P.size();
}
int main(){
    int i, j;
    while(~scanf("%d %d %d",&n,&m,&T)){
        E.clear(); P.clear();
        memset(dis, 0, sizeof dis);
        memset(mp, 0, sizeof mp);
        for(i=0;i<n;i++)scanf("%s",mp[i]);
        for(i=0;i<n;i++)for(j=0;j<m;j++)
        {
            if(mp[i][j]=='E')E.push_back(Hash(i,j));
            else if(mp[i][j]=='.')P.push_back(Hash(i,j));
        }
        if(P.size()==0){puts("0");continue;}    if(E.size()==0){puts("impossible");continue;}
        for(i = 0; i < E.size(); i++)bfs(E[i]/m, E[i]%m);
        int l = 1, r = 256, ans = inf;
        while(l<=r)
        {
            int mid = (l+r)>>1;
            if(ok(mid))ans = min(ans, mid), r = mid-1;
            else l = mid+1;
        }
        if(T<ans || ans==inf){puts("impossible");continue;}
        else printf("%d\n",ans);
    }
    return 0;
}
