#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <limits>
using namespace std;
typedef long long LL;
const int MAXN=20000 + 10;
const int INF = numeric_limits<int>::max();
const LL LL_INF= numeric_limits<LL>::max();
int bit[MAXN][MAXN/32+100];
struct Edge {
    int to,next;
    Edge(){}
    Edge(int _to,int _next):to(_to),next(_next){}
}e[MAXN*10],e2[MAXN*10];
int head[MAXN],tot,du[MAXN];
int head2[MAXN],tot2;
int n,m;
void init(){
    for(int i=1;i<=n;i++)head2[i]=head[i]=-1,du[i]=0;
    tot2=0;
    tot=0;
}
void AddEdge(int u,int v){
    e[tot]=Edge(v,head[u]);
    head[u]=tot++;
}
void AddEdge1(int u,int v){
    e2[tot2]=Edge(v,head2[u]);
    head2[u]=tot2++;
}
int que[MAXN],front,rear;
void _or(int posi,int posj){
    for(int i=0;i<=n/32;i++)bit[posi][i]|=bit[posj][i];
}
void top_bfs(){
    front=rear=0;
    memset(bit,0,sizeof(bit));
    for(int i=1;i<=n;i++){
        bit[i][i/32]=(1<<(i%32));
        if(du[i]==0){
            que[front++]=i;
            --du[i];
        }
    }
    while(front!=rear){
        int u=que[rear++];
        for(int i=head[u];~i;i=e[i].next){
            int v=e[i].to;
            AddEdge1(v,u);
            if(--du[v]==0)que[front++]=v;
        }
    }
}
template <class T>
void Rd(T &tmp){
    char ch;
    while((ch=getchar())&&!isdigit(ch));
    tmp=0;
    do {
        tmp=(tmp<<3)+(tmp<<1)+(ch^48);
    }while((ch=getchar())&&isdigit(ch));
    return ;
}
int main()
{
    int T;
    Rd(T);
    while(T--){
        Rd(n),Rd(m);
        init();
        for(int i=0,x,y;i<m;i++){
            Rd(x),Rd(y);
            AddEdge(x,y);
            ++du[y];
        }
        top_bfs();
        int ans=0;
        for(int i=0;i<front;i++){
            int u=que[i];
            for(int j=head2[u];~j;j=e2[j].next){
                int v=e2[j].to;
                if(bit[u][v/32]&(1<<(v%32)))++ans;
                _or(u,v);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
