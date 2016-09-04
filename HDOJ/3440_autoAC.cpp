#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
int T,n,d,dis[1010],nxt[1010],h,in[1010],cnt[1010];
const int inf=1000000000;
using namespace std;
struct node
{
    int id,h;
    node(int a=0,int b=0):id(a),h(b){}
    friend bool operator < (node a,node b)
    {
        return a.h<b.h;
    }
};
struct edge
{
    int y,l;
    edge(int a,int b):y(a),l(b){}
};
vector<edge>vt[1010];
node a[1010];
int spfa(int x,int y)
{
    fill(dis,dis+1+n,inf);
    memset(in,0,sizeof(in));
    dis[x]=0;
    in[x]=1;
    memset(cnt,0,sizeof(cnt));
    cnt[x]=1;
    queue<int>q;
    q.push(x);
    while(!q.empty())
    {
        int s=q.front();
        q.pop();
        in[s]=0;
        for(int i=0;i<vt[s].size();i++)
        {
            int y=vt[s][i].y,l=vt[s][i].l;
            if(dis[y]>dis[s]+l)
            {
                dis[y]=dis[s]+l;
                if(!in[y])
                {
                    q.push(y);
                    cnt[y]++;
                    if(cnt[y]>n)return -1;
                    in[y]=1;
                }
            }
        }
    }
    return dis[y];
}
int main()
{
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {    
        scanf("%d%d",&n,&d);
        for(int i=1;i<=n;i++)
            vt[i].clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&h);
            a[i]=node(i,h);
        }
        sort(a+1,a+1+n);
        for(int i=1;i<n;i++)
        {
            vt[i+1].push_back(edge(i,-1));
        }
        for(int i=1;i<n;i++)
        {
            vt[min(a[i+1].id,a[i].id)].push_back(edge(max(a[i+1].id,a[i].id),d));
        }
        int a1=a[1].id,a2=a[n].id,k;
        if(a1<a2)
        {
            k=spfa(a1,a2);
        }
        else
        {
            k=spfa(a2,a1);
        }
        printf("Case %d: %d\n",cas,k);
    }
    return 0;
}
