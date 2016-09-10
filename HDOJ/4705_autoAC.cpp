#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 100100
#pragma comment(linker, "/STACK:16777216")
struct Edge{
    int v,next;
}edge[MAXN*4];
int NE;
long long n;
int head[MAXN];
void Insert(int u,int v)
{
    edge[NE].v=v;
    edge[NE].next=head[u];
    head[u]=NE++;
}
bool mark[MAXN];
long long sum,ans;
int dfs(int u)
{
    mark[u]=true;
    int son,tmp=0;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(mark[v])continue;
        son=dfs(v);
        tmp+=son;
        ans+=(long long )(n-1-tmp)*son;
    }
    return tmp+1;
}
int main()
{
    int u,v;
    while(~scanf("%I64d",&n)){
        NE=0;
        memset(head,-1,sizeof(head));
        for(int i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            Insert(u,v);
            Insert(v,u);
        }
        memset(mark,false,sizeof(mark));
        ans=0;
        dfs(1);
        sum=n*(n-1)*(n-2)/6;
        printf("%I64d\n",sum-ans);
    }
    return 0;
}
