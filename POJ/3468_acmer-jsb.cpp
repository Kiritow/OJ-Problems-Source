#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<iomanip>
#include<string>
#include<climits>
#include<cmath>
#define MAX 110000
#define LL long long
using namespace std;
LL n,m;
LL ans;
struct Tree
{
  LL l,r;
  LL sum,add;
};
Tree tree[MAX*3];

void pushup(LL x)
{
  LL tmp=2*x;
  tree[x].sum=tree[tmp].sum+tree[tmp+1].sum;
}


void pushdown(LL x)
{
  LL tmp=2*x;
  tree[tmp].add+=tree[x].add;
  tree[tmp+1].add+=tree[x].add;
  tree[tmp].sum+=tree[x].add*(tree[tmp].r-tree[tmp].l+1);
  tree[tmp+1].sum+=tree[x].add*(tree[tmp+1].r-tree[tmp+1].l+1);
  tree[x].add=0;
}

void build(int l,int r,int x)
{
  tree[x].l=l;
  tree[x].r=r;
  tree[x].add=0;
  if(l==r)
  {
    scanf("%lld",&tree[x].sum);
    return ;
  }
  int tmp=x<<1;
  int mid=(l+r)>>1;
  build(l,mid,tmp);
  build(mid+1,r,tmp+1);
  pushup(x);	 //如果在建树的过程中给sum赋值，记得后面要pushup
}


void update(LL l,LL r,LL c,LL x)
{
  if(r<tree[x].l||l>tree[x].r)
    return ;
  if(l<=tree[x].l&&r>=tree[x].r)
  {
    tree[x].add+=c;
    tree[x].sum+=c*(tree[x].r-tree[x].l+1);
    return ;
  }
  if(tree[x].add)
    pushdown(x);
  LL tmp=x<<1;
  update(l,r,c,tmp);	//  !!!
  update(l,r,c,tmp+1);
  pushup(x);
}


void query(LL l,LL r,LL x)
{
  if(r<tree[x].l||l>tree[x].r)		 //要更新的区间不在该区间上
    return ;
  if(l<=tree[x].l&&r>=tree[x].r)	  //要更新区间包括了该区间
  {
    ans+=tree[x].sum;
    return ;
  }
  if(tree[x].add)
    pushdown(x);
  LL tmp=x<<1;
  LL mid=(tree[x].l+tree[x].r)>>1;
  if(r<=mid)
    query(l,r,tmp);
  else if(l>mid)
    query(l,r,tmp+1);
  else
  {
    query(l,mid,tmp);
    query(mid+1,r,tmp+1);
  }
//	pushup(x);
}


int main()
{
//	freopen("cin.txt","r",stdin);
//	freopen("cout.txt","w",stdout);
  while(~scanf("%lld %lld",&n,&m))
  {
    build(1,n,1);
    char str[5];
    while(m--)
    {
      scanf("%s",str);
      if(str[0]=='Q')
      {
        LL l,r;
        scanf("%lld %lld",&l,&r);
        ans=0;
        query(l,r,1);
        printf("%lld\n",ans);
      }
      else
      {
        LL l,r,c;
        scanf("%lld %lld %lld",&l,&r,&c);
        update(l,r,c,1);
      }
    }
  }
  return 0;
}
