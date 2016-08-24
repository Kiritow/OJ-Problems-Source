#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
#define MAXN 200010
#define clr(x,k) memset((x),(k),sizeof(x))
struct node
{
    int st,to,next;
}
edge[MAXN];
int n,m,ct,id;
int head[MAXN],low[MAXN],dfn[MAXN],belong[MAXN],in[MAXN],to[MAXN];
bool instack[MAXN];
stack<int>q;
void add_e(int i,int u,int v)
{
    edge[i].st=u;
    edge[i].to=v;
    edge[i].next=head[u];
    head[u]=i;
}
void tarjan(int i)
{
    int j;
    dfn[i]=low[i]=++id;
    q.push(i);
    instack[i]=1;
    for(int u=head[i]; ~u; u=edge[u].next)
    {
        j=edge[u].to;
        if(dfn[j]==0)
        {
            tarjan(j);
            if(low[i]>low[j])
                low[i]=low[j];
        }
        else if(instack[j]&&low[i]>low[j])
            low[i]=dfn[j];
    }
    if(dfn[i]==low[i])
    {
        ct++;
        do
        {
            j=q.top();
            q.pop();
            instack[j]=0;
            belong[j]=ct;
        }
        while(i!=j);
    }
}
int main()
{
    int t,i,u,v,sum1,sum2;
    cin>>t;
    while(t--)
    {
        clr(head,-1);
        clr(low,0);
        clr(dfn,0);
        clr(belong,0);
        clr(in,0);
        clr(to,0);
        while(!q.empty())
            q.pop();
        cin>>n>>m;
        for(i=0; i<m; i++)
        {
            cin>>u>>v;
            add_e(i,u,v);
        }
        id=ct=0;
        for(i=1; i<=n; i++)
        {
            if(!dfn[i])
                tarjan(i);
        }
        if(ct==1)
        {
            cout<<0<<endl;
            continue;
        }
        for(i=1; i<=ct; i++)
        {
            in[i]=to[i]=0;
        }
        for(i=0; i<m; i++)
        {
            if(belong[edge[i].st]!=belong[edge[i].to])
            {
                in[belong[edge[i].st]]++;
                to[belong[edge[i].to]]++;
            }
        }
        sum1=sum2=0;
        for(i=1; i<=ct; i++)
        {
            if(in[i]==0)
                sum1++;
            if(to[i]==0)
                sum2++;
        }
        cout<<max(sum1,sum2)<<endl;
    }
    return 0;
}
