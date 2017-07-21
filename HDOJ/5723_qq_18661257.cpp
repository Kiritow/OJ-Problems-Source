#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e6 + 5;
typedef long long LL;
struct edge {
	int v, u, cost;
	bool operator <(const edge &a) const {
		return cost < a.cost;
	}
} es[MAXN];

struct o {
	int v, cost;
	o() {}
	o(int v, int cost):v(v), cost(cost) {}
};

int par[MAXN], ranks[MAXN];
int sum[MAXN];
bool vis[MAXN];
int n, m;
double minres;
vector<o>G[MAXN];

void init(int sizes) {//初始化
	for(int i = 0; i <= sizes; i ++) {
		par[i] = i;
		ranks[i] = 1;
		G[i].clear();
	}
}
int find(int x) {
	return par[x] == x ? x : par[x] = find(par[x]);
}
bool same(int x,int y) {
	return find(x) == find(y);
}
void unite(int x,int y) {//连接
	x = find(x);
	y = find(y);
	if(x == y)return ;
	if(ranks[x] > ranks[y]) {
		par[y] = x;
	} else {
		par[x] = y;
		if(ranks[x] == ranks[y]) ranks[x] ++;
	}
}
LL kruskal() {//最小生成树算法
	sort(es,es + m);
	init(n);
	LL ret = 0;
	for(int i=0; i<m; i++) {
		edge e = es[i];
		if(!same(e.u, e.v)) {
			unite(e.u, e.v);
			ret += e.cost;
			G[e.u].push_back(o(e.v, e.cost));//将生成树中对应的点和边的值保存起来
			G[e.v].push_back(o(e.u, e.cost));
		}
	}
	return ret;
}

void DFS(int r, int f, int cost) {//得到最终的数学期望
	if(vis[r]) return;
	vis[r] = true;
	sum[r] = 1;
	for(int i = 0; i < G[r].size(); i ++) {
		if(G[r][i].v == f) continue;
		DFS(G[r][i].v, r, G[r][i].cost);
		sum[r] += sum[G[r][i].v];
	}
	if(cost != -1)
		minres += (LL)sum[r] * (LL)(n - sum[r]) * (LL)cost * 1.;//x * (n - 1) * cost即这条边的花费
}

int T;
int main() {
	scanf("%d", &T);
	while(T --) {
		scanf("%d%d", &n, &m);
		for(int i = 0; i < m; i ++) {
			scanf("%d%d%d",&es[i].v, &es[i].u, &es[i].cost);
		}
		if(n == 1){
            printf("0 0.00\n");
            continue;
		}
		LL minret = kruskal();
		memset(sum, 0, sizeof(sum));
		memset(vis, false, sizeof(vis));
		minres = 0;
		DFS(1, 1, -1);
		printf("%I64d %.2lf\n", minret, minres * 2./ ((LL)n * (n - 1)));
	}
	return 0;
}
