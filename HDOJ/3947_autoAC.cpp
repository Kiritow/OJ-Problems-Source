#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
#define sz 200
#define inf 0x7fffffff
int g[sz][sz];
int s[sz],t[sz],v[sz];
struct node{
    int s, t, v, len, nxt;
} e[sz * 40 + 20];
int hd[sz], cnt, pre[sz] , pos[sz], dis[sz], vis[sz];
int sum ;
void insert(int s, int t, int v, int len){
    e[cnt].s = s;e[cnt].t = t;e[cnt].v = v;e[cnt].len = len;
    e[cnt].nxt = hd[s];hd[s] = cnt++;
    e[cnt].s = t;e[cnt].t = s;e[cnt].v = 0;e[cnt].len = -len;
    e[cnt].nxt = hd[t];hd[t] = cnt++;
}
bool spfa(int s, int t, int n){
    for(int i = 0; i < n; i++){
        dis[i]=inf;
        vis[i]=0;
        pre[i]=-1;
    }
    queue<int>q;
    while(!q.empty())q.pop();
    q.push(s);
    pre[s] = s;
    dis[s] = 0;
    while( !q.empty() ){
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = hd[u]; i!=-1; i=e[i].nxt){
            int v = e[i].t;
            if (e[i].v > 0 && dis[u] + e[i].len < dis[v]){
                dis[v] = dis[u] + e[i].len;
                pre[v] = u;
                pos[v] = i;
                if (!vis[v]){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return pre[t] != -1 && dis[t] < inf;
}
int mcf(int s, int t, int n){
    int fw = 0, ct = 0;
    while(spfa(s,t,n)){
        int v = inf;
        for(int i = t; i != s; i = pre[i])
            v = min(v, e[pos[i]].v);
        fw += v;
        ct += dis[t] * v;
        for(int i = t; i != s; i = pre[i]){
            e[pos[i]].v -= v;
            e[pos[i] ^ 1].v += v;
        }
    }
    if(fw != sum)return -1;
    return ct; 
}
struct node1{
    int s,t,v,nxt;
}ne[sz*10];
int nhd[sz],ncnt;
void insert1(int s ,int t,int v){
    ne[ncnt].s=s;
    ne[ncnt].t=t;
    ne[ncnt].v=v;
    ne[ncnt].nxt = nhd[s];
    nhd[s]=ncnt++;
}
int main(){
    int TT;
    scanf("%d",&TT);
    for(int cas=1;cas<=TT;cas++){
        int n;
        scanf("%d",&n);
        memset(pre,-1,sizeof(pre));
        int S=0,T=n+1;
        memset(hd,-1,sizeof(hd));
        cnt = 0;
        memset(g,-1,sizeof(g));
        memset(pre,-1,sizeof(pre));
        memset(nhd,-1,sizeof(nhd));
        ncnt=0;
        for(int i=1;i<n;i++){
             scanf("%d%d%d",&s[i],&t[i],&v[i]);
             g[s[i]][t[i]]=i;
             pre[s[i]] = t[i];
             insert1(t[i],s[i],v[i]);
        }
        s[n]=1;
        t[n]=n+1;
        v[n]=0;
        insert1(n+1,1,0);
        g[1][1+n]=n+1;
        pre[1]=n+1;
        sum=0;
        for(int i=1;i<=n;i++){
            int vv = v[i];
            for(int j=nhd[s[i]];j!=-1;j=ne[j].nxt){
                vv -= ne[j].v;
                insert(i,g[ne[j].t][s[i]],inf,0);
            }
            if(vv>0){
                sum+=vv;
                insert(S,i,vv,0);
            }
            if(vv<0){
                insert(i,T,-vv,0);
            }
        }
        int m;
        cin>>m;
        int ss,tt,li,ci;
        for(int i=0;i<m;i++){
            scanf("%d%d%d%d",&ss,&tt,&li,&ci);
            insert(g[ss][pre[ss]],g[tt][pre[tt]],li,ci);
        }
        printf("Case #%d: ",cas);
        cout<<mcf(S,T,T+1)<<endl;
    }
}
