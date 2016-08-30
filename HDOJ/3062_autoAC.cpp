#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
int n,m;
struct edge_node
{
    int to;
    int next;
};
edge_node edge[5000000];
int head[100000];
int dfn[100000];
int low[100000];
int visit[100000];
int N;
stack<int>sta;
void tarjan_bfs(int cur,int time)
{
    visit[cur]=1;
    visit[cur^1]=1;
    low[cur]=dfn[cur]=time;
    sta.push(cur);
    for(int i=head[cur];i!=-1;i=edge[i].next)
    {
        if(visit[edge[i].to]==0)
        {
            tarjan_bfs(edge[i].to,time++);
            time++;
        }
        if(visit[edge[i].to]==1&&low[cur]>low[edge[i].to])
        {
            low[cur]=low[edge[i].to];
        }
    }
    if(dfn[cur]==low[cur])
    {
        N++;
        while(!sta.empty()&&sta.top()!=cur)
        {
            low[sta.top()]=N;
            visit[sta.top()]=2;
            sta.pop();
        }
    }
    return;
}
void tarjan()
{
    N=0;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(visit,0,sizeof(visit));
    for(int i=0;i<2*n;i++)
    {
        if(visit[i]==0)
        {
            tarjan_bfs(i,1);
        }
    }
    return;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(head,-1,sizeof(head));
        int counter=0;
        while(m--)
        {
            int a1,a2,c1,c2;
            scanf("%d%d%d%d",&a1,&a2,&c1,&c2);
            int temp1;
            int temp2;
            temp1=2*a1+c1;
            temp2=2*a2+c2;
            edge[counter].to=temp2;
            edge[counter].next=head[temp1^1];
            head[temp1^1]=counter++;
            edge[counter].to=temp1;
            edge[counter].next=head[temp2^1];
            head[temp2^1]=counter++;
        }
        tarjan();
        int sign=1;
        for(int i=0;i<2*n;i++)
        {
            if(low[i]==low[i^1])
            {
                sign=0;
                break;
            }
        }
        if(sign==1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
