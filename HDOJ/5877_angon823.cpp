#include<stdio.h>
#include<stdlib.h>
#define MAXN 200005
int cnt = 1, rt = 0;
int Add[MAXN];

struct Tree{
	long long key;
	int num, size, fa, son[2];
}T[MAXN];

inline void PushUp(int x)
{
	T[x].size = T[T[x].son[0]].size + T[T[x].son[1]].size + T[x].num;
}

inline void PushDown(int x)
{
	if (Add[x])
	{
		if (T[x].son[0])
		{
			T[T[x].son[0]].key += Add[x];
			Add[T[x].son[0]] += Add[x];
		}
		if (T[x].son[1])
		{
			T[T[x].son[1]].key += Add[x];
			Add[T[x].son[1]] += Add[x];
		}
		Add[x] = 0;
	}
}

inline int Newnode(long long key, int fa) //新建一个节点并返回
{
	++cnt;
	T[cnt].key = key;
	T[cnt].num = T[cnt].size = 1;
	T[cnt].fa = fa;
	T[cnt].son[0] = T[cnt].son[1] = 0;
	return cnt;
}

inline void Rotate(int x, int p) //0左旋 1右旋
{
	int y = T[x].fa;
	PushDown(y);
	PushDown(x);
	T[y].son[!p] = T[x].son[p];
	T[T[x].son[p]].fa = y;
	T[x].fa = T[y].fa;
	if (T[x].fa)
		T[T[x].fa].son[T[T[x].fa].son[1] == y] = x;
	T[x].son[p] = y;
	T[y].fa = x;
	PushUp(y);
	PushUp(x);
}

void Splay(int x, int To) //将x节点移动到To的子节点中
{
	while (T[x].fa != To)
	{
		if (T[T[x].fa].fa == To)
			Rotate(x, T[T[x].fa].son[0] == x);
		else
		{
			int y = T[x].fa, z = T[y].fa;
			int p = (T[z].son[0] == y);
			if (T[y].son[p] == x)
				Rotate(x, !p), Rotate(x, p); //之字旋
			else
				Rotate(y, p), Rotate(x, p); //一字旋
		}
	}
	if (To == 0) rt = x;
}

int GetPth(int p, int To) //返回第p小的节点 并移动到To的子节点中
{
	if (!rt || p > T[rt].size) return 0;
	int x = rt;
	while (x)
	{
		PushDown(x);
		if (p >= T[T[x].son[0]].size + 1 && p <= T[T[x].son[0]].size + T[x].num)
			break;
		if (p > T[T[x].son[0]].size + T[x].num)
		{
			p -= T[T[x].son[0]].size + T[x].num;
			x = T[x].son[1];
		}
		else
			x = T[x].son[0];
	}
	Splay(x, 0);
	return x;
}

int Find(long long key) //返回值为key的节点 若无返回0 若有将其转移到根处
{
	if (!rt) return 0;
	int x = rt;
	while (x)
	{
		PushDown(x);
		if (T[x].key == key) break;
		x = T[x].son[key > T[x].key];
	}
	if (x) Splay(x, 0);
	return x;
}

int Prev() //返回根节点的前驱 非重点
{
	if (!rt || !T[rt].son[0]) return 0;
	int x = T[rt].son[0];
	while (T[x].son[1])
	{
		PushDown(x);
		x = T[x].son[1];
	}
	Splay(x, 0);
	return x;
}

int Succ() //返回根结点的后继 非重点
{
	if (!rt || !T[rt].son[1]) return 0;
	int x = T[rt].son[1];
	while (T[x].son[0])
	{
		PushDown(x);
		x = T[x].son[0];
	}
	Splay(x, 0);
	return x;
}

void Insert(long long key) //插入key值
{
	if (!rt)
		rt = Newnode(key, 0);
	else
	{
		int x = rt, y = 0;
		while (x)
		{
			PushDown(x);
			y = x;
			if (T[x].key == key)
			{
				T[x].num++;
				T[x].size++;
				break;
			}
			T[x].size++;
			x = T[x].son[key > T[x].key];
		}
		if (!x)
			x = T[y].son[key > T[y].key] = Newnode(key, y);
		Splay(x, 0);
	}
}

void Delete(long long key) //删除值为key的节点1个
{
	int x = Find(key);
	if (!x) return;
	if (T[x].num>1)
	{
		T[x].num--;
		PushUp(x);
		return;
	}
	int y = T[x].son[0];
	while (T[y].son[1])
		y = T[y].son[1];
	int z = T[x].son[1];
	while (T[z].son[0])
		z = T[z].son[0];
	if (!y && !z)
	{
		rt = 0;
		return;
	}
	if (!y)
	{
		Splay(z, 0);
		T[z].son[0] = 0;
		PushUp(z);
		return;
	}
	if (!z)
	{
		Splay(y, 0);
		T[y].son[1] = 0;
		PushUp(y);
		return;
	}
	Splay(y, 0);
	Splay(z, y);
	T[z].son[0] = 0;
	PushUp(z);
	PushUp(y);
}

int GetRank(long long key) //获得值<=key的节点个数
{
	if (!Find(key))
	{
		Insert(key);
		int tmp = T[T[rt].son[0]].size;
		Delete(key);
		return tmp;
	}
	else
		return T[T[rt].son[0]].size + T[rt].num;
}

void Delete(int l, int r) //删除值在[l, r]中的所有节点 l!=r
{
	if (!Find(l)) Insert(l);
	int p = Prev();
	if (!Find(r)) Insert(r);
	int q = Succ();
	if (!p && !q)
	{
		rt = 0;
		return;
	}
	if (!p)
	{
		T[rt].son[0] = 0;
		PushUp(rt);
		return;
	}
	if (!q)
	{
		Splay(p, 0);
		T[rt].son[1] = 0;
		PushUp(rt);
		return;
	}
	Splay(p, q);
	T[p].son[1] = 0;
	PushUp(p);
	PushUp(q);
}
#define MAX 100005
#include<vector>
#include<memory.h>
using namespace std;
int v[MAX];
int N;
long long K;
long long res = 0;
struct Edge
{
	int b;
	int next;
}edge[MAX];
int edgeCnt = 1;
int adj[MAX];
void AddEdge(int a, int b)
{
	edge[edgeCnt].b = b;
	edge[edgeCnt].next = adj[a];
	adj[a] = edgeCnt++;
}
void Search(int now)
{
	res += GetRank(K / v[now]);
	Insert(v[now]);
	for(int p = adj[now]; p; p = edge[p].next)
	{
		Search(edge[p].b);
	}
	Delete(v[now]);
}
int in[MAX];
int main() {
	int T;
	while(~scanf("%d", &T))
    {
        int i;
        int a, b;
        for (; T; T--)
        {
            scanf("%d%lld", &N, &K);
            memset(adj, 0, (N + 1) * sizeof(int));
            memset(in, 0, (N + 1) * sizeof(int));
            edgeCnt = 1;
            for (i = 1; i <= N; i++)
            {
                scanf("%d", &v[i]);
            }
            for (i = 1; i < N; i++)
            {
                scanf("%d%d", &a, &b);
                in[b]++;
                AddEdge(a, b);
            }
            for (i = 1; i <= N; i++)
            {
                if (in[i] == 0)
                {
                    break;
                }
            }
            cnt = 1, rt = 0;
            res = 0;
            Search(i);
            printf("%lld\n", res);
        }
    }
	return 0;
}
