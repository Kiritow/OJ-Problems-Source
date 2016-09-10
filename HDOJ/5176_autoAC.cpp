#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <stack>
#include <vector>
#include <set>
#include <map>
#define LL long long
#define mod 100000000
#define inf 0x3f3f3f3f
#define eps 1e-6
#define N 200010
#define FILL(a,b) (memset(a,b,sizeof(a)))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define PII pair<int,int>
#pragma comment(linker,"/STACK:1024000000,1024000000")
using namespace std;
int num[N],fa[N],n;
inline int read() {
    int x=0; char ch=getchar();
    while(ch<'0'||ch>'9'){ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
struct edge
{
    int u,v,w;
}e[N];
int cmp1(edge a,edge b)
{
    return a.w<b.w;
}
int cmp2(edge a,edge b)
{
    return a.w>b.w;
}
void init()
{
    for(int i=1;i<=n;i++)fa[i]=i,num[i]=1;
}
int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
    int cas=1;
    while(scanf("%d",&n)>0)
    {
        for(int i=1;i<n;i++)
        {
            e[i].u=read();
            e[i].v=read();
            e[i].w=read();
        }
        init();sort(e+1,e+n,cmp1);
        unsigned long long maxsum=0,t=1;
        for(int i=1;i<n;i++)
        {
            int pa=find(e[i].u);
            int pb=find(e[i].v);
            if(pa==pb)continue;
            maxsum+=t*num[pa]*num[pb]*e[i].w;
            fa[pa]=pb;
            num[pb]+=num[pa];
        }
        unsigned long long minsum=0;
        init();sort(e+1,e+n,cmp2);
        for(int i=1;i<n;i++)
        {
            int pa=find(e[i].u);
            int pb=find(e[i].v);
            if(pa==pb)continue;
            minsum+=t*num[pa]*num[pb]*e[i].w;
            fa[pa]=pb;
            num[pb]+=num[pa];
        }
        printf("Case #%d: ",cas++);
       cout<<maxsum-minsum<<endl;
    }
}
