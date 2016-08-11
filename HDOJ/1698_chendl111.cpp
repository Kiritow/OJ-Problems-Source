#include<cstdio> 
#include<algorithm>
#include<iostream>
using namespace std;
#define lchild rt << 1, l, m
#define rchild rt << 1 | 1, m + 1, r
const int N=400010;
int tree[N],lazy[N],t,ans=1,L,R,delta,n,m;

//区间求和 
void push_up(int rt){
	tree[rt]=tree[rt << 1]+tree[rt << 1 | 1];
}

void push_down(int rt, int len) {
	if(lazy[rt])
	{
		lazy[rt << 1]=lazy[rt << 1 | 1] = lazy[rt];
    	tree[rt << 1] = lazy[rt << 1] * (len - (len >> 1));
    	tree[rt << 1 | 1] = lazy[rt << 1 | 1] * (len >> 1);
    	lazy[rt] = 0;
	}	
}

void build(int rt = 1, int l = 1, int r = n) {
	lazy[rt]=0;
    if (l == r) { tree[rt]=1; return; }//注意对树的初始赋值 
    int m = (l + r) >> 1;
    build(lchild); build(rchild);
    push_up(rt);
}

void update(int L, int R, int delta, int rt = 1, int l = 1, int r = n) {
    if (L <= l && r <= R) {
        tree[rt] = delta * (r - l + 1);//数据更新 
        lazy[rt] = delta;
        return;
    }
    push_down(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, delta, lchild);
    if (R > m)  update(L, R, delta, rchild);
    push_up(rt);
}

int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d%d",&n,&m);
		build();
		for(int i=0;i<m;i++) 
		{
			scanf("%d%d%d",&L,&R,&delta);
			update(L,R,delta);
		}
		printf("Case %d: The total value of the hook is %d.\n",ans++,tree[1]);
	} 
}
