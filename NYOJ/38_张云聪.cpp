 
#include<queue>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<numeric>
#include<algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr))
struct Node
{
	Node(){}
	Node(int num,int len):len(len),num(num){}
	int len,num;
};
bool operator<(const Node& n1,const Node& n2)
{
	return n1.len>n2.len;
}
const int MAX=510;
const int MAXE=250000;
int Head[MAX],Next[MAXE],Num[MAXE],Len[MAXE];
int Dis[MAX],top;
void add(int u,int v,int len)
{
	Num[top]=v;
	Next[top]=Head[u];
	Len[top]=len;
	Head[u]=top++;
}
bool InQ[MAX];
int main()
{
	//freopen("input.txt","r",stdin);
	priority_queue<Node> q;
	int t,m,n,a,b,l;
	scanf("%d",&t);
	while(t--)
	{
		top=0;CLR(Head,-1);
		CLR(Dis,0x3f);
		scanf("%d%d",&m,&n);
		for(int i=0;i!=n;i++)
		{
			scanf("%d%d%d",&a,&b,&l);
			add(a-1,b-1,l);add(b-1,a-1,l);
		}
		Dis[0]=0;
		q.push(Node(0,0));
		while(!q.empty())
		{
			Node t=q.top();q.pop();
			if(Dis[t.num]!=t.len) continue;
			for(int i=Head[t.num];i!=-1;i=Next[i])
			{
				if(Dis[Num[i]]>Len[i])
				{
					Dis[Num[i]]=Len[i];
					q.push(Node(Num[i],Len[i]));
				}
			}
		}
		int minl=0x3f3f3f3f;
		for(int i=0;i!=m;i++)
		{
			scanf("%d",&l);
			minl=min(minl,l);
		}
		printf("%d\n",accumulate(Dis,Dis+m,0)+minl);
	}
}        
