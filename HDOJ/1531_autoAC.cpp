#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;
int head[25000];
int visit[25000];
int dis[25000];
int in[25000];
const int inf=1<<30;
int ne;
int n,m;
struct edge
{
    int from,to,next;
    int weight;
}P[250000];
void insert(int x,int y,int weight)
{
    P[ne].from=x;P[ne].to=y;P[ne].weight=weight;P[ne].next=head[x];head[x]=ne++;
}
void init()
{
    int i;
    for(i=0;i<=n;i++)
        dis[i]=-inf;
}
bool bellman()
{
    int i,j;
    init();
    for(i=0;i<=n+1;i++)
    {
        for(j=1;j<ne;j++)
            if(dis[P[j].to]<dis[P[j].from]+P[j].weight)
                dis[P[j].to]=dis[P[j].from]+P[j].weight;
    }
    for(i=1;i<ne;i++)
        if(dis[P[i].to]<dis[P[i].from]+P[i].weight)
            return false;
    return true;
}
int main()
{
    int i;
    char op[5];
    int si,ni,weight;
    while(scanf("%d",&n))
    {
        if(!n) return 0;
        scanf("%d",&m);
        ne=1;
        memset(head,-1,sizeof(head));
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&si,&ni);
            cin>>op;
            scanf("%d",&weight);
            if(op[0]=='g')
            {
                insert(si-1,ni+si,weight+1);
                insert(-1,si-1,0);
                insert(-1,si+ni,0);
            }
            else
            {
                insert(ni+si,si-1,1-weight);
                insert(-1,si-1,0);
                insert(-1,si+ni,0);
            }
        }
        if(bellman())
            printf("lamentable kingdom\n");
        else
            printf("successful conspiracy\n");
    }
    return 0;
}
