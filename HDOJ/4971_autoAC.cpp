#include<iostream>
#include<cstdio>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define mt(a,b) memset(a,b,sizeof(a))
using namespace std;
const int M = 123456;
const int inf = 0x7f7f7f7f;
int profit[30],cost[60];
class Tarjan { 
public:
    struct E {
        int u,v,next;
    } e[M<<4]; 
    int le,head[M],Index,Bcnt,num[M],belong[M],dfn[M],low[M];
    bool instack[M];
    stack<int> s;
    void tarjan(int u) {
        dfn[u]=low[u]=++Index;
        instack[u]=true;
        s.push(u);
        int v;
        for(int i=head[u]; ~i; i=e[i].next) {
            v=e[i].v;
            if(!dfn[v]) {
                tarjan(v);
                low[u]=min(low[u],low[v]);
            } else if(instack[v]) {
                low[u]=min(low[u],dfn[v]);
            }
        }
        if(dfn[u]==low[u]) {
            Bcnt++;
            do {
                v=s.top();
                s.pop();
                instack[v]=false;
                belong[v]=Bcnt;
                num[Bcnt]++;
            } while(u!=v);
        }
    }
    void init() {
        le=Index=Bcnt=0;
        mt(head,-1);
        mt(num,0);
        mt(dfn,0);
        mt(low,0);
        mt(instack,0);
        while(!s.empty()) s.pop();
    }
    void add(int u,int v) {
        e[le].u=u;
        e[le].v=v;
        e[le].next=head[u];
        head[u]=le++;
    }
    void solve(int n) {
        for(int i=1; i<=n; i++) {
            if(!dfn[i]) {
                tarjan(i);
            }
        }
    }
    int getbcnt() {
        return Bcnt;
    }
    int getbelong(int id) {
        return belong[id];
    }
    int getnum(int id) {
        return num[id];
    }
} gx;
class Dinic {
    struct E {
        int u,v,next,flow;
    } e[M<<1];
    int le,flow,head[M],temp[M],cur[M],level[M],path[M];
    bool used[M];
    queue<int> q;
public:
    int getflow() {
        return flow;
    }
    bool bfs(int s,int t) {
        mt(level,-1);
        while(!q.empty()) q.pop();
        q.push(s);
        level[s]=1;
        while(!q.empty()) {
            int u=q.front();
            q.pop();
            for(int i=head[u]; ~i; i=e[i].next) {
                int v=e[i].v;
                if(level[v]==-1&&e[i].flow) {
                    level[v]=level[u]+1;
                    q.push(v);
                    if(v==t) return true;
                }
            }
        }
        return false;
    }
    void init() {
        le=0;
        mt(head,-1);
    }
    void add(int u,int v,int flow) {
        e[le].u=u;
        e[le].v=v;
        e[le].flow=flow;
        e[le].next=head[u];
        head[u]=le++;
        e[le].u=v;
        e[le].v=u;
        e[le].flow=0;
        e[le].next=head[v];
        head[v]=le++;
    }
    void solve(int s,int t) {
        int p,now,tempp;
        bool flag;
        flow=0;
        while(bfs(s,t)) {
            for(int i=0; i<M; i++) {
                temp[i]=head[i];
                used[i]=true;
            }
            p=1;
            path[p]=s;
            while(p) {
                int u=path[p];
                if(u==t) {
                    now=inf;
                    for(int i=1; i<p; i++) {
                        now=min(now,e[cur[path[i]]].flow);
                    }
                    flow+=now;
                    for(int i=1; i<p; i++) {
                        e[cur[path[i]]].flow-=now;
                        e[cur[path[i]]^1].flow+=now;
                        if(!e[cur[path[i]]].flow) tempp=i;
                    }
                    p=tempp;
                } else {
                    flag=false;
                    for(int i=temp[u]; ~i; i=e[i].next) {
                        int v=e[i].v;
                        if(used[v]&&e[i].flow&&level[u]+1==level[v]) {
                            cur[u]=i;
                            temp[u]=e[i].next;
                            flag=true;
                            path[++p]=v;
                            break;
                        }
                    }
                    if(flag) continue;
                    p--;
                    used[u]=false;
                }
            }
        }
    }
} ts;
struct project_problems {
    int num;
    int question[55];
} project[25];
int Map[55][55];
struct Node {
    int value;
} newgraph[55];
int main() {
    int _,cas = 0;
    int n,m;
    int allprofit;
    scanf("%d",&_);
    while(_--) {
        scanf("%d%d",&n,&m);
        allprofit = 0;
        for(int i=0; i<n; i++) {
            scanf("%d",&profit[i]);
            allprofit += profit[i];
        }
        for(int i=0; i<m; i++) {
            scanf("%d",&cost[i]);
        }
        ts.init();
        gx.init();
        for(int i=0; i<n; i++) {
            int num;
            scanf("%d",&num);
            project[i].num = num;
            for(int j=0; j<num; j++) {
                scanf("%d",&project[i].question[j]);
            }
        }
        int tmp;
        for(int i=0; i<m; i++) {
            for(int j=0; j<m; j++) {
                scanf("%d",&tmp);
                Map[i][j] = tmp;
                if(tmp == 1) {
                    gx.add(i+1,j+1);
                }
            }
        }
        gx.solve(m);
        for(int i=0; i<=m; i++) {
            newgraph[i].value = 0;
        }
        for(int i=0; i<m; i++) {
            newgraph[gx.getbelong(i+1)].value += cost[i];
        }
        int s = n+m+1;
        int t = n+m+2;
        for(int i=0; i<n; i++) {
            ts.add(s,i,profit[i]);
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<project[i].num; j++) {
                project[i].question[j] = gx.getbelong(project[i].question[j]+1);
            }
            sort(project[i].question,project[i].question+project[i].num);
            project[i].num = unique(project[i].question,project[i].question+project[i].num) - project[i].question;
            for(int j=0; j<project[i].num; j++) {
                ts.add(i,project[i].question[j]+n,inf);
            }
        }
        bool flag[55][55];
        mt(flag,false);
        for(int i=0; i<m; i++) {
            for(int j=0; j<m; j++) {
                if(gx.getbelong(i+1)!=gx.getbelong(j+1) && Map[i][j]==1 && !flag[gx.getbelong(i+1)][gx.getbelong(i+1)]) {
                    ts.add(gx.getbelong(i+1)+n,gx.getbelong(j+1)+n,inf);
                    flag[gx.getbelong(i+1)][gx.getbelong(j+1)] = true;
                }
            }
        }
        for(int i=1; i<=gx.getbcnt(); i++) {
            ts.add(i+n,t,newgraph[i].value);
        }
        ts.solve(s,t);
        printf("Case #%d: %d\n",++cas,allprofit - ts.getflow());
    }
    return 0;
}
