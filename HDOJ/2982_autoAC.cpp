#include <iostream>
#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <vector> 
#include <math.h>
#include <deque> 
#define LL long long
#define pii pair<int,int>
#define pdi pair<double,int>
#define INF 0x7f7f7f7f
using namespace std;
const int N=200;
int x[N], y[N], rudu[N];
int earn, lost, n;
vector<int> vect[N], vec[N];
double sum;
struct node
{
    int from, to, cap, flow;
    double val;
    node(){};
    node(int from,int to,double val,int cap,int flow):from(from),to(to),val(val),cap(cap),flow(flow){};
}edge[90000];
int edge_cnt;
void add_node(int from,int to,double val,int cap,int flow)
{
    edge[edge_cnt]=node(from, to, val, cap, flow );
    vec[from].push_back(edge_cnt++);
}
void build_graph()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<vect[i].size(); j++)
        {
            int t=vect[i][j];
            double v= lost - sqrt( pow(x[i]-x[t],2)+pow(y[i]-y[t],2) )*earn;
            if(v<0)
            {
                add_node(t, i, -v, 1, 0 );  
                add_node(i, t, v, 0, 0 );
                sum+=v;
                rudu[t]++,rudu[i]--;
            }
            else
            {
                add_node(i, t, v, 1, 0);
                add_node(t, i, -v, 0, 0);
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(rudu[i]>0)
        {
            add_node(0, i, 0, rudu[i], 0);
            add_node(i, 0, 0, 0, 0);
        }
        if(rudu[i]<0)
        {
            add_node(i, n+1, 0, -rudu[i], 0);
            add_node(n+1, i, 0, 0, 0);
        }
    }
}
int flow[N], path[N], inq[N];
double cost[N];
double spfa(int s,int e)
{
    deque<int> que(1,s);
    cost[s]=0;
    flow[s]=INF;
    inq[s]=1;
    while(!que.empty())
    {
        int x=que.front();
        que.pop_front();
        inq[x]=0;
        for(int i=0; i<vec[x].size(); i++)
        {
            node e=edge[vec[x][i]];
            if(e.cap>e.flow && cost[e.to]>cost[e.from]+e.val )
            {
                flow[e.to]=min(flow[e.from],e.cap-e.flow);
                cost[e.to]=cost[e.from]+e.val;
                path[e.to]=vec[x][i];
                if(!inq[e.to])
                {
                    inq[e.to]=1;
                    que.push_back(e.to);
                }
            }
        }
    }
    return cost[e];
}
double mcmf(int s,int e)
{
    double ans_cost=0.0;
    while(true)
    {
        memset(flow,0,sizeof(flow));
        memset(inq,0,sizeof(inq));
        memset(path,0,sizeof(path));
        for(int i=0; i<=e; i++)   cost[i]=1e39;
        double tmp=spfa(s,e);    
        if(tmp>1e38)    return  ans_cost;
        ans_cost+=tmp;
        int ed=e;
        while(ed!=s)
        {
            int t=path[ed];
            edge[t].flow+=flow[n+1];
            edge[t^1].flow-=flow[n+1];
            ed=edge[t].from;
        }
    }
}
int main()
{
    int b, j=0;
    while(scanf("%d", &n), n)
    {
        scanf("%d%d",&earn,&lost);
        for(int i=0; i<=n+1; i++)   vect[i].clear();
        for(int i=0; i<=n+1; i++)   vec[i].clear();
        memset(edge,0,sizeof(edge));
        memset(rudu,0,sizeof(rudu));
        edge_cnt=0;
        sum=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            while(scanf("%d",&b), b)    vect[i].push_back(b);  
        }
        build_graph();
        printf("Case %d: %.2f\n", ++j,  -(mcmf(0,n+1)+sum)+0.0000001 );
    }
    return 0;
}
