#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<string.h>
#include<math.h>
using namespace std;
struct list
{
    int u,v,w;
    int next;
}edge[110000];
int head[33000];
int nums;
void add(int u,int v,int w)
{
    edge[nums].u=u;
    edge[nums].v=v;
    edge[nums].w=w;
    edge[nums].next=head[u];
    head[u]=nums++;
}
int du[33000];
void init()
{
    memset(head,-1,sizeof(head));
    nums=1;
    memset(du,0,sizeof(du));
}
priority_queue<int>que;
vector<int>vec;
int n;
void dos()
{
    vec.clear();
    while(!que.empty())que.pop();
    for(int i=1;i<=n;i++)
    {
        if(du[i]==0)que.push(i);
    }
    while(!que.empty())
    {
        int x=que.top();
        que.pop();
        for(int i=head[x];i!=-1;i=edge[i].next)
        {
            int y=edge[i].v;
            du[y]--;
            if(du[y]==0)
            {
                que.push(y);
            }
        }
        vec.push_back(x);
    }
    for(int i=n-1;i>=0;i--)
    {
        if(i!=n-1)printf(" ");
        printf("%d",vec[i]);
    }
    cout<<endl;
}
int main()
{
    int T,m,a,b;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            add(b,a,1);
            du[a]++;
        }
        dos();
    }
    return 0;
}
