#include"iostream"
#include"cstdio"
#include"cstring"
#include"algorithm"
#include"queue"
#include"vector"
using namespace std;
const int ms=30010;
vector<int> v[ms];
struct cmp
{
	bool operator()(const int &a,const int &b)
	{//从大到小 
		return a<b;//注意在结构体中以第二元素为基准 
	}
};
int n,m,in[ms],ans[ms],cnt;
void topo()
{
	priority_queue<int,vector<int>,cmp> q;
	for(int i=1;i<=n;i++)
		if(in[i]==0)
			q.push(i);
	int x,i;
	while(!q.empty())
	{
		x=q.top();
		q.pop();
		ans[++cnt]=x;
		for(i=0;i<v[x].size();i++)
		{
			in[v[x][i]]--;
			if(in[v[x][i]]==0)
				q.push(v[x][i]);
		}
	}
	return ;
} 
int main()
{
	int t,a,b,i;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(i=0;i<=n;i++)
			v[i].clear();
		memset(in,0,sizeof(in));
		while(m--)
		{
			scanf("%d%d",&a,&b);
			v[b].push_back(a);
			in[a]++;
		}
		cnt=0;
		topo();
		printf("%d",ans[cnt]);
		for(i=cnt-1;i>0;i--)
		{
			printf(" %d",ans[i]);
		}
		puts("");
	}
	return 0;
}
