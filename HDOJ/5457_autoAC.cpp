#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<60
#define speed std::ios::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
#define CLR(x,y) memset(x,y,sizeof(x))
#define CPY(x,y) memcpy(x,y,sizeof(x))
#define clr(a,x,size) memset(a,x,sizeof(a[0])*(size))
#define cpy(a,x,size) memcpy(a,x,sizeof(a[0])*(size))
#define debug(a) cout << #a" = " << (a) << endl;
#define debugarry(a, n) for (int i = 0; i < (n); i++) { cout << #a"[" << i << "] = " << (a)[i] << endl; }
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))
#define MID(x,y) (x+((y-x)>>1))
#define ls (idx<<1)
#define rs (idx<<1|1)
#define lson ls,l,mid
#define rson rs,mid+1,r
template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
const int MAXN=10240;
const int MAXM=40000;
struct ISAP
{
    struct nedge
    {
        int u,v,next;
        ll c;
    } e[MAXM*2];
    int head[MAXN],tot,n;
    int ss,tt;
    void Resize(int n)
    {
        this->n=n;
    }
    void Clearall()
    {
        tot=1;
        CLR(head,0);
    }
    void addedge(int u,int v,ll w)
    {
        e[++tot].v=v;
        e[tot].u=u;
        e[tot].c=w;
        e[tot].next=head[u];
        head[u]=tot;
        e[++tot].v=u;
        e[tot].u=v;
        e[tot].c=0;
        e[tot].next=head[v];
        head[v]=tot;
    }
    int dep[MAXN],gap[MAXN];
    void bfs()
    {
        CLR(dep,-1);
        CLR(gap,0);
        queue<int> que;
        gap[0]=1;
        dep[tt]=0;
        que.push(tt);
        while(!que.empty())
        {
            int u=que.front();
            que.pop();
            for(int i=head[u]; i; i=e[i].next)
                if(dep[e[i].v]==-1)
                {
                    que.push(e[i].v);
                    dep[e[i].v]=dep[u]+1;
                    ++gap[dep[e[i].v]];
                }
        }
    }
    int res,cur[MAXN],num[MAXN];
    int top;
    int MaxFlow(int s,int t)
    {
        this->ss=s;
        this->tt=t;
        bfs();
        top=res=0;
        memcpy(cur,head,sizeof(head));
        int u=ss,i;
        while(dep[ss]<n)
        {
            if(u==tt)
            {
                int temp=INF;
                int inser;
                for(i=0; i<top; i++)
                    if(temp>e[num[i]].c)
                    {
                        temp=e[num[i]].c;
                        inser=i;
                    }
                for(i=0; i<top; i++)
                {
                    e[num[i]].c-=temp;
                    e[num[i]^1].c+=temp;
                }
                res+=temp;
                top=inser;
                u=e[num[top]].u;
            }
            if(u!=tt && gap[dep[u]-1]==0)
                break;
            for(i=cur[u]; i; i=e[i].next)
                if(e[i].c != 0 && dep[u]==dep[e[i].v]+1)
                    break;
            if(i)
            {
                cur[u]=i;
                num[top++]=i;
                u=e[i].v;
            }
            else
            {
                int mi=n;
                for(i=head[u]; i; i=e[i].next)
                    if(e[i].c>0 && mi>dep[e[i].v])
                    {
                        mi=dep[e[i].v];
                        cur[u]=i;
                    }
                --gap[dep[u]];
                dep[u]=mi+1;
                ++gap[dep[u]];
                if(u!=ss)
                    u=e[num[--top]].u;
            }
        }
        return res;
    }
    void print()
    {
        puts("GRAPH:");
        for(int i=0; i<=n; i++)
        {
            if(!head[i])
                continue;
            printf("%d ->",i);
            for(int j=head[i]; j; j=e[j].next)
                printf("%d(%I64d) ",e[j].v,e[j].c);
            putchar('\n');
        }
    }
}g;
static int tim;
struct Node
{
    Node *ln[2];
    int cost[2],idx;
    bool f;
    void init()
    {
        f=0;
        idx=tim++;
        memset(ln,0,sizeof ln);
        memset(cost,INF,sizeof cost);
    }
};
struct Trie
{
    Node T[MAXN];
    int cnt,pos[MAXN];
    Node *rt;
    Node* get()
    {
        T[cnt].init();
        return &T[cnt++];
    }
    void init()
    {
        cnt=0;
        rt=get();
    }
    void insert(int *s,int j)
    {
        Node *p=rt;
        for(int i=0; i<8; i++)
        {
            int v=s[i];
            if(p->ln[v]==NULL)  p->ln[v]=get();
            p=p->ln[v];
        }
        p->f=1;
        pos[j]=p->idx;
    }
    void find(char *s,int cost)
    {
        Node *p=rt;
        for(int i=0; s[i]; i++)
        {
            int v=s[i]-'0';
            if(p->ln[v]==NULL)  return;
            if(s[i+1]==0)   p->cost[v]=min(p->cost[v],cost);
            else    p=p->ln[v];
        }
    }
} pre,su;
int n,m,ss,tt;
int a[9];
char str[9],x[9];
void dfs(Node *p,int flag)
{
    if(flag)
    {
        if(p->ln[0])
        {
            g.addedge(p->ln[0]->idx,p->idx,p->cost[0]);
            dfs(p->ln[0],1);
        }
        if(p->ln[1])
        {
            g.addedge(p->ln[1]->idx,p->idx,p->cost[1]);
            dfs(p->ln[1],1);
        }
    }
    else
    {
        if(p->ln[0])
        {
            g.addedge(p->idx,p->ln[0]->idx,p->cost[0]);
            dfs(p->ln[0],0);
        }
        if(p->ln[1])
        {
            g.addedge(p->idx,p->ln[1]->idx,p->cost[1]);
            dfs(p->ln[1],0);
        }
    }
}
void build()
{
    for(int i=1; i<=n; i++)
        g.addedge(pre.pos[i],su.pos[i],INF);
    dfs(pre.rt,0);
    dfs(su.rt ,1);
}
int main()
{
    int T,cas=1;
    read(T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        tim=0;
        pre.init();su.init();g.Clearall();
        for(int i=1,x; i<=n; i++)
        {
            scanf("%d",&x);
            for(int j=0; j<8; j++)
                if(x&(1<<7-j))  a[j]=1;
                else    a[j]=0;
            pre.insert(a,i);
            for(int j=0; j<8; j++)
                if(x&(1<<j))    a[j]=1;
                else    a[j]=0;
            su.insert(a,i);
        }
        g.Resize(tim);
        ss=0;
        tt=su.rt->idx;
        for(int i=1,cost; i<=m; i++)
        {
            scanf("%s %s %d",str,x,&cost);
            if(str[0]=='P') pre.find(x,cost);
            else
            {
                int len=strlen(x);
                reverse(x,x+len);
                su.find(x,cost);
            }
        }
        build();
        ll ans=g.MaxFlow(ss,tt);
        printf("Case #%d: %lld\n",cas++,ans>=INF?-1:ans);
    }
    return 0;
}
