#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>

#include <algorithm>
using namespace std;

#define INF 1e9+7

#define MAXN 5000
#define MAXR 100000

int N,R;

struct edge
{
    edge(int To,int Dist):to(To),dist(Dist){}

    int to;
    int dist;
};

vector<edge> G[MAXN+1];

/// 最短路: dis[i]=从1号路口出发到i路口的最短距离
int dis[MAXN+1];
/// 次短路: second_dis[i]=从1号路口出发到i路口的次短距离
int second_dis[MAXN+1];

/// PR.first 为距离, PR.second 为点
typedef pair<int,int> PR;

void solve()
{
    priority_queue< PR,vector<PR>,greater<PR> > bus;
    fill(dis,dis+N,INF);
    fill(second_dis,second_dis+N,INF);

    dis[0]=0;
    bus.push(PR(0,0));

    while(!bus.empty())
    {
        PR p=bus.top();
        bus.pop();

        int d=p.first;
        int v=p.second;

        if(second_dis[v]<d)
        {
            /// 如果这个距离比次短路还长，丢弃
            continue;
        }

        int sz=G[v].size();
        for(int i=0;i<sz;i++)
        {
            edge& e=G[v][i];
            int dd=d+e.dist;

            if(dis[e.to]>dd)
            {
                /// 如果最短路比新合成距离长，交换(?)
                swap(dis[e.to],dd);
                bus.push(PR(dis[e.to],e.to));
            }

            /// 现在一定有: dd>dis[e.to]

            if(second_dis[e.to] > dd && dis[e.to] < dd)
            {
                second_dis[e.to]=dd;
                bus.push(PR(second_dis[e.to],e.to));
            }
        }
    }

    printf("%d\n",second_dis[N-1]);
}

int main()
{
    scanf("%d %d",&N,&R);
    for(int i=0;i<R;i++)
    {
        int A,B,D;
        scanf("%d %d %d",&A,&B,&D);

        G[A-1].push_back(edge(B-1,D));
        G[B-1].push_back(edge(A-1,D));
    }
    solve();
    return 0;
}
