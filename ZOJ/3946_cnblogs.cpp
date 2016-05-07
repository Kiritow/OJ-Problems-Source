# include<iostream>
# include<cstdio>
# include<cstring>
# include<vector>
# include<queue>
# include<list>
# include<set>
# include<map>
# include<string>
# include<cmath>
# include<cstdlib>
# include<algorithm>
using namespace std;
# define LL long long
 
const int N=1005;
const int INF=1000000000;
const LL oo=1000000000000005;
 
struct Edge
{
    int to,nxt;
    LL c,d;
};
 
int n,m,cnt;
Edge e[N*200];
LL d[N*100];
int head[N*100];
vector<int>pre[N*100];
 
void add(int u,int v,LL d,LL c)
{
    e[cnt].to=v;
    e[cnt].d=d;
    e[cnt].c=c;
    e[cnt].nxt=head[u];
    head[u]=cnt++;
}
 
void solve()
{
    for(int i=0;i<n;++i)
        pre[i].clear();
     
    fill(d,d+n,oo);
    d[0]=0;
    queue<int>q;
    q.push(0);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=e[i].nxt){
            int v=e[i].to;
            if(d[v]>d[u]+e[i].d){
                d[v]=d[u]+e[i].d;
                q.push(v);
            }
        }
    }
     
    q.push(0);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=e[i].nxt){
            int v=e[i].to;
            if(d[v]==d[u]+e[i].d){
                pre[v].push_back(i);
                q.push(v);
            }
        }
    }
     
    LL ans1=0,ans2=0;
    for(int i=0;i<n;++i){
        ans1+=d[i];
        LL minn=oo;
        for(int j=0;j<pre[i].size();++j)
            minn=min(minn,e[pre[i][j]].c);
        if(minn==oo) continue;
        ans2+=minn;
    }
    printf("%lld %lld\n",ans1,ans2);
}
 
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        cnt=0;
        memset(head,-1,sizeof(head));
        int a,b;
        LL c,d;
        for(int i=0;i<m;++i){
            scanf("%d%d%lld%lld",&a,&b,&d,&c);
            add(a,b,d,c);
            add(b,a,d,c);
        }
        solve();
    }
    return 0;
}
