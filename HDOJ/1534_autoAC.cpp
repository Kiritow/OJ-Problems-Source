#include<iostream>
#include<string.h>
#include<string>
#include<queue>
#define MAX 100000
using namespace std;
struct edge
{
    int x,next,value;
}e[20*MAX];
int cnt,head[MAX],c[MAX],a[MAX],d[MAX];
bool visited[MAX],flag[MAX];
void add(int u,int v,int w)
{
    e[cnt].x=v;
    e[cnt].value=w;
    e[cnt].next=head[u];
    head[u]=cnt++;
}
bool SPFA(int s,int n)
{
    int tnext,tx,temp;
    memset(visited,false,sizeof(visited));
    memset(c,0,sizeof(c));
    queue<int>Q;
    while(!Q.empty()) Q.pop();
    Q.push(s);
    c[s]++;
    d[s]=0;
    visited[s]=true;
    flag[s]=true;
    while(!Q.empty())
    {
        temp=Q.front();Q.pop();
        tnext=head[temp];
        while(tnext!=-1)
        {
            tx=e[tnext].x;
            if(d[tx]<d[temp]+e[tnext].value)
            {
                d[tx]=d[temp]+e[tnext].value;
                if(!visited[tx])
                {
                    Q.push(tx);
                    flag[tx]=true;
                    c[tx]++;
                    if(c[tx]>n) return false;
                    visited[tx]=true;
                }
            }
            tnext=e[tnext].next;
        }
        visited[temp]=false;
    }
    return true;
}
int main()
{
    int n,i,u,v,k=1;
    string str;
    while(cin>>n&&n)
    {
        cnt=0;
        for(i=1;i<=n;i++)cin>>a[i];
        for(i=0;i<MAX;i++) head[i]=-1;
        memset(flag,false,sizeof(flag));
        while(cin>>str&&str!="#")
        {
            cin>>u>>v;
            if(str=="SAS") add(v,u,0);
            if(str=="SAF") add(v,u,a[v]);
            if(str=="FAF") add(v,u,a[v]-a[u]);
            if(str=="FAS") add(v,u,-a[u]);
        }
        cout<<"Case "<<k++<<":"<<endl;
        bool yes;
        memset(d,0,sizeof(d));
        for(i=1;i<=n;i++)
        {
            if(!flag[i])
            {
                yes=SPFA(i,n);
            }
            if(!yes) break;
        }
        if(yes)
        {
            for(i=1;i<=n;i++)
            {
                cout<<i<<" "<<d[i]<<endl;
            }
        }
        else
        {
            cout<<"impossible"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
