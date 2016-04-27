#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=60000;
int n,use[maxn];
struct Node
{
    int l;
    int r;
    int pos;
    bool operator <(const Node &a)const
    {
	if(r==a.r)
	    return l>a.l;
	return r>a.r;
    }
}a[maxn];
priority_queue<Node> q;
bool cmp(Node a,Node b)
{
    if(a.l==b.l)
	return a.r<b.r;
    return a.l<b.l;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
	for(int i=0;i<n;i++)
	{
	    scanf("%d%d",&a[i].l,&a[i].r);
	    a[i].pos=i;
	}
	sort(a,a+n,cmp);
	q.push(a[0]);
	int now=0,ans=1;
	use[a[0].pos]=1;
	for(int i=1;i<n;i++)
	{
	    if(!q.empty()&&q.top().r<a[i].l)
	    {
		use[a[i].pos]=use[q.top().pos];
		q.pop();
	    }
	    else
	    {
		ans++;
		use[a[i].pos]=ans;
	    }
	    q.push(a[i]);
	}
	printf("%d\n",ans);
	for(int i=0;i<n;i++)
	    printf("%d\n",use[i]);
	while(!q.empty())
	    q.pop();
    }
    return 0;
}

