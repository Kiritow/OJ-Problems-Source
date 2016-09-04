#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
struct node
{
    int y,t;
}edge[10009];
int T[1009];
vector<node> v[1009]; int n,m;
int in[1009];
void solve()
{
    queue<int> q;
    for(int i=0;i<n;i++)
    if(in[i]==0)
    {
        q.push(i);
        T[i]=1;
    }
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int i=0;i<v[x].size();i++)
        {
            int y=v[x][i].y;
            T[y]=max(T[y],T[x]+v[x][i].t);
            in[y]--;
            if(in[y]==0)
            {
                q.push(y);
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    ans=max(ans,T[i]);
    cout<<ans<<endl;
}
int main()
{
   int a,b,t;
   while(scanf("%d%d",&n,&m)!=EOF)
   {
       memset(in,0,sizeof(in));
       memset(T,0,sizeof(T));
       for(int i=0;i<n;i++)
       v[i].clear();
       for(int i=0;i<m;i++)
       {
           scanf("%d%d%d",&a,&edge[i].y,&edge[i].t);
           v[a].push_back(edge[i]);
           in[edge[i].y]++;
       }
       solve();
   }
}
