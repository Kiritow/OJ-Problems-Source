#include <iostream>
using namespace std;
const int maxnum = 10005;
const int maxEdge= 50005;
const int maxint = 107391822;

// 边，
typedef struct Edge{
	int u, v;    // 起点，重点
	int weight;  // 边的权值
}Edge;

Edge edge[maxEdge];     // 保存边的值
int  dist[maxnum];     // 结点到源点最小距离

int nodenum, edgenum, source;    // 结点数，边数，源点

// 初始化图
void init()
{
	// 输入结点数，边数，源点
	cin >> nodenum >> edgenum ;
	source=1;
	for(int i=1; i<=nodenum; ++i)
		dist[i] = maxint;
	dist[source] = 0;
	for(int i=1; i<=edgenum; i++)
	{
		cin >> edge[i].u >> edge[i].v >> edge[i].weight;
		if(edge[i].u == source)          //注意这里设置初始情况
			dist[edge[i].v] = edge[i].weight;

        /*
        /// Another
        edge[i+1].u=edge[i].v;
        edge[i+1].v=edge[i].u;
        edge[i+1].weight=-edge[i].weight;

        if(edge[i+1].u == source)          //注意这里设置初始情况
			dist[edge[i+1].v] = edge[i+1].weight;
        */
	}
}

// 松弛计算
void relax(int u, int v, int weight)
{
	if(dist[v] > dist[u] + weight)
		dist[v] = dist[u] + weight;
}

bool Bellman_Ford()
{
	for(int i=1; i<=nodenum-1; ++i)
		for(int j=1; j<=edgenum; ++j)
			relax(edge[j].u, edge[j].v, edge[j].weight);
	bool flag = 1;
	// 判断是否有负环路
	for(int i=1; i<=edgenum; ++i)
		if(dist[edge[i].v] > dist[edge[i].u] + edge[i].weight)
		{
			flag = 0;
			break;
		}
	return flag;
}
int main()
{
	//freopen("input3.txt", "r", stdin);
    init();
	if(Bellman_Ford())
        //for(int i = 1 ;i <= nodenum; i++)
			cout << dist[nodenum] << endl;
    else
        throw "WTF??";
	return 0;
}
/*
4 6
1 2 -5
2 3 -6
1 3 -9
2 4 -7
3 4 -8
1 4 6
*/
