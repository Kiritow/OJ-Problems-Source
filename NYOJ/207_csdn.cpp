#include<stdio.h>
const int N = 50005;
int parent[N];
int relation[N];//根节点到节点的关系
void Init(int n)
{
	for(int i = 0; i <= n; ++i)
	{
		parent[i]= i;
		relation[i] = 0;
	}
}
//更新的步骤，先将当前节点与其根节点相连，然后更新其与根节点的关系
//当前节点x与根节点r的关系更新的方式：(x与其父节点的关系+其父节点的关系与根节点的关系)%3
//所以在更新节点x的数据之前需要更新其父节点的数据，这是Find为什么搞成递归函数的原因
//其更新的顺序是从根节点一直往下，一直到当前节点x的父节点。
int Find(int x)
{
	if(x != parent[x])//不是根节点
	{
		int temp = parent[x];
		//将当前节点的父节点设置为根节点
		parent[x] = Find(temp);
		//更新当前节点与根节点的关系，由x->x父和x父->父根的关系得到x->父根的关系
		//所以在这之前必须更新其父节点与根节点的关系
		relation[x] = (relation[x] + relation[temp]) % 3;
	}
	return parent[x];
}

int main()
{
	int n,m,i;
	int x,y,d;
	int rx,ry;
	int cnt;
	while(scanf("%d %d", &n, &m) != EOF)//POJ上只需要一次输入，所以不需要while循环
	{
		cnt = 0;
		Init(n);
		for(i = 0; i < m; ++i)
		{
			scanf("%d %d %d", &d, &x, &y);
			if(x > n || y > n)
			{
				++cnt;
				continue;
			}
			if(d == 2 && x == y)
			{
				++cnt;
				continue;
			}
			rx = Find(x);
			ry = Find(y);
			if(rx == ry)//属于同一个子集
			{
				//如果x、y是同类，那么他们相对于根节点的关系应该是一样的
				//如果不是同类，加入y之后，x相对于根节点的关系(x根->y,y->x(即3-(d-1)=2).即x根->x)应该是不变的
				if((d == 1 && relation[x] != relation[y]) ||
					(d == 2 && relation[x] != (relation[y] + 2)%3))
					++cnt;
			}
			else//合并两个连通区域
			{
				parent[ry] = rx;//y根的父节点更新成x根
				//(d - 1)为x与y的关系，3-relation[y]是y与y的根节点的关系，注意方向，relation[x]是其根节点与x的关系
				//x根->x,x->y,y->y根：即x根->y根
				relation[ry] = (relation[x] + d - 1 + 3 - relation[y]) % 3;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
