#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
const int MAXN=22000;
bool visit[MAXN];
queue<int>q1,q2;
vector<vector<int> >adj; 
vector<vector<int> >radj;
vector<vector<int> >dag;
int n,m,cnt;
int id[MAXN],order[MAXN],ind[MAXN];
void dfs(int u)
{
    visit[u]=true;
    int i,len=adj[u].size();
    for(i=0;i<len;i++)
      if(!visit[adj[u][i]])
        dfs(adj[u][i]);
    order[cnt++]=u;
}
void rdfs(int u)
{
    visit[u]=true;
    id[u]=cnt;
    int i,len=radj[u].size();
    for(i=0;i<len;i++)
      if(!visit[radj[u][i]])
        rdfs(radj[u][i]);
}
void korasaju()
{
    int i;
    memset(visit,false,sizeof(visit));
    for(cnt=0,i=0;i<2*n;i++)
      if(!visit[i])
        dfs(i);
    memset(id,0,sizeof(id));
    memset(visit,false,sizeof(visit));
    for(cnt=0,i=2*n-1;i>=0;i--)
      if(!visit[order[i]])
      {
          cnt++;
          rdfs(order[i]);
      }
}
bool solvable()
{
    for(int i=0;i<n;i++)
      if(id[2*i]==id[2*i+1])
        return false;
   return true;
}
void add(int x,int y)
{
    adj[x].push_back(y);
    radj[y].push_back(x);
}
int a[MAXN],b[MAXN];
int main()
{
    int T;
    int x,y,z;
    scanf("%d",&T);
    int iCase=0;
    while(T--)
    {
        iCase++;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==1)b[i]=2;
            else if(a[i]==2)b[i]=3;
            else b[i]=1;
            if(a[i]>b[i])swap(a[i],b[i]);
        }
        adj.assign(2*n,vector<int>());
        radj.assign(2*n,vector<int>());
        bool flag=true;
        while(m--)
        {
            scanf("%d%d%d",&x,&y,&z);
            x--;
            y--;
            if(!flag)continue;
            if(x==y)
            {
                if(z==1)flag=false;
                continue;
            }
            if(z==0)
            {
                if(a[x]!=a[y])
                {
                    add(2*x,2*y+1);
                    add(2*y,2*x+1);
                }
                if(a[x]!=b[y])
                {
                    add(2*x,2*y);
                    add(2*y+1,2*x+1);
                }
                if(b[x]!=a[y])
                {
                    add(2*x+1,2*y+1);
                    add(2*y,2*x);
                }
                if(b[x]!=b[y])
                {
                    add(2*x+1,2*y);
                    add(2*y+1,2*x);
                }
            }
            else if(z==1)
            {
                if(a[x]==a[y])
                {
                    add(2*x,2*y+1);
                    add(2*y,2*x+1);
                }
                if(a[x]==b[y])
                {
                    add(2*x,2*y);
                    add(2*y+1,2*x+1);
                }
                if(b[x]==a[y])
                {
                    add(2*x+1,2*y+1);
                    add(2*y,2*x);
                }
                if(b[x]==b[y])
                {
                    add(2*x+1,2*y);
                    add(2*y+1,2*x);
                }
            }
        }
        if(!flag)
        {
            printf("Case #%d: no\n",iCase);
            continue;
        }
        korasaju();
        if(solvable())printf("Case #%d: yes\n",iCase);
        else printf("Case #%d: no\n",iCase);
    }
    return 0;
}
