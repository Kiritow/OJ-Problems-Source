#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <deque>
#include <map>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100100
struct BIT
{
    int baum[SIZE];
    void init()
    {
        memset(baum,0,sizeof(baum));
    }
    inline int lowbit(int x)
    {
        return x&(-x);
    }
    void add(int x,int val)
    {
        while(x<SIZE)
        {
            baum[x]+=val;
            x+=lowbit(x);
        }
    }
    int sum(int x)
    {
        int res=0;
        while(x>0)
        {
            res+=baum[x];
            x-=lowbit(x);
        }
        return res;
    }
    int sum(int l,int r)
    {
        return sum(r)-sum(l-1);
    }
};
struct query
{
    int l,r,id;
    query(){}
    query(int il,int ir,int iid)
    {
        l=il;r=ir;id=iid;
    }
    friend bool operator < (const query& a,const query& b)
    {
        return a.r<b.r;
    }
};
int n,k,q;
int w[SIZE];
vector<int> pl[SIZE];
vector<int> g[SIZE];
int lson[SIZE],rson[SIZE],val[SIZE];
int cnt,ind;
void dfs(int now,int father)
{
    lson[now]=rson[now]=++ind;
    val[now]=w[now];
    for(int i=0;i<(int)g[now].size();i++)
    {
        int next=g[now][i];
        if(next!=father)
        {
            dfs(next,now);
            rson[now]=rson[next];
        }
    }
}
int main()
{
    int T,a,b;
    BIT bit;
    query ask[SIZE];
    int ans[SIZE];
    map<int,int> mp;
    input(T);
    int cas=1;
    while(T--)
    {
        bit.init();
        cnt=ind=0;
        mp.clear();
        memset(ans,0,sizeof(ans));
        for(int i=0;i<SIZE;i++) g[i].clear();
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&w[i]);
            if(!mp[w[i]])
            {
                mp[w[i]]=++cnt;
                pl[cnt].clear();
            }
            w[i]=mp[w[i]];
        }
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(1,-1);
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            scanf("%d",&a);
            ask[i]=query(lson[a],rson[a],i);
        }
        sort(ask,ask+q);
        int ptr=0;
        for(int i=1;i<=n;i++)
        {
            int v=val[i];
            pl[v].push_back(i);
            int sz=pl[v].size();
            if(sz>=k)
            {
                if(sz==k)
                {
                    bit.add(pl[v][sz-k],1);
                }
                if(sz>k)
                {
                    bit.add(pl[v][sz-k-1],-2);
                    bit.add(pl[v][sz-k],1);
                }
            }
            while(ask[ptr].r==i)
            {
                int id=ask[ptr].id;
                ans[id]=bit.sum(ask[ptr].l,ask[ptr].r);
                ptr++;
            }
        }
        printf("Case #%d:\n",cas++);
        for(int i=0;i<q;i++)
        {
            printf("%d\n",ans[i]);
        }
        if(T) puts("");
    }
    return 0;
}
