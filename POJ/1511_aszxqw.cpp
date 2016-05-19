//36412K	1829MS
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define llong long long
#define Abs(a) ((a)>0?(a):-(a))
#define Mod(a,b) (((a)-1+(b))%(b)+1)
using namespace std;
const int N=1000005;
const int inf=1e10;
int n,m;
int a[N][3];
struct
{
	int w,v,next;
}edge[N];
int edgehead[N];
llong d[N];
bool vis[N];
int k;
void addedge(int u,int v,int w)
{
	edge[k].v=v;
	edge[k].w=w;
	edge[k].next=edgehead[u];
	edgehead[u]=k++;
}
struct cmp//注意priority_queue的cmp写的和sort里面的cmp的区别，前者是struct，后者是函数，而且比较大小的关系刚好是相反的。
{
	bool operator()(const int a,const int b)
	{
		return d[a]>d[b];
	}
};
llong dijstra()
{
	memset(vis,0,sizeof(vis));
	priority_queue<int,vector<int>,cmp> que;
	for(int i=2;i<=n;i++)
		d[i]=inf;
	d[1]=0;
	que.push(1);
	while(!que.empty())
	{
		int u=que.top();
		vis[u]=true;
		que.pop();
		for(int i=edgehead[u];i;i=edge[i].next)//遍历节点u的每条出去的边
		{
			int v=edge[i].v;
			int w=edge[i].w;
			if(!vis[v]&&d[v]>d[u]+w)//如果是可松弛点即加入优先队列，d值越小越优先。
			{
				d[v]=d[u]+w;
				que.push(v);
			}
		}
	}
	llong ans=0;
	for(int i=1;i<=n;i++)
		ans+=d[i];
	return ans;
}
int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		k=1;
		memset(edgehead,0,sizeof(edgehead));
		memset(edge,0,sizeof(edge));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",a[i],a[i]+1,a[i]+2);
			addedge(a[i][0],a[i][1],a[i][2]);
		}
		llong ans=dijstra();
		k=1;//将图的边反向之后再来一遍
		memset(edgehead,0,sizeof(edgehead));
		memset(edge,0,sizeof(edge));
		for(int i=1;i<=m;i++)
		{
			addedge(a[i][1],a[i][0],a[i][2]);
		}
		ans+=dijstra();
		printf("%lld\n",ans);
	}
	return 0;
}
