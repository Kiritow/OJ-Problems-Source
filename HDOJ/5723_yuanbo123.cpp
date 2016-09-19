#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define LL long  long
#define N 100010
#define M 1000010
vector<pair<int,int> >  v[N];//定义一个pair型的主要是因为要在v[].second中储存路径权值
struct node
{
    int a,b,w;
} edge[M];//储存每条边
int father[N],vis[N];
int n,m;
long long  ans;//记录总权值；
bool cmp(node x,node y)
{
    return x.w<y.w;
}
int finds(int x)
{
    return father[x]==x?x:father[x]=finds(father[x]);
}
long long dfs(int x) //dfs递归搜索
{
    vis[x]=1;
    //标记顶点避免死循环
    int  i;
    long long nb=0,cb=0;
    int h=v[x].size();
    for(i=0;i<h;i++)
    {
        int b=v[x][i].first;
        if(!vis[b])
        {
            nb=dfs(b);
            cb+=nb;
            ans+=nb*(n-nb)*v[x][i].second;
        }
    }
    return 1+cb;
}
int main()
{
    int t,i;
    long long sum;
    cin>>t;
    while(t--)
    {
        for(i=0; i<=N; i++)
            v[i].clear();
        memset(vis,0,sizeof(vis));
        ans=0;
        sum=0;
        int flag=0;
        scanf("%d%d",&n,&m);
        if(n==0||m==0)
        {
            printf("0 0.00\n");
            continue;
        }
        for(i=1; i<=n; i++)
        {
            father[i]=i;
        }
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].w);
        }
        sort(edge,edge+m,cmp);
        for(i=0; i<m; i++)
        {
            int fx=finds(edge[i].a);
            int fy=finds(edge[i].b);
            if(fx!=fy)
            {
                flag++;
                father[fx]=fy;
                sum+=edge[i].w;
                v[edge[i].a].push_back(make_pair(edge[i].b,edge[i].w));
                v[edge[i].b].push_back(make_pair(edge[i].a,edge[i].w));
            }
            if(flag==n-1)
                break;
        }
        for(i=1; i<=n; i++)
        {
            if(v[i].size()==1)
                break;
        }
        dfs(i);
        double y=1.0*n*(n-1)/2;
        printf("%I64d %.2lf\n",sum,(double)ans/y);
    }
    return 0;
}
