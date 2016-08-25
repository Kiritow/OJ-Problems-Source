#include <stdio.h>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
using namespace std;
int n,m;
int vis[200005];
struct node
{
    int x;
    int step;
};
int bfs(int n,int m)
{
    int i;
     queue<node>q;
     node st,ed;
     st.x=n;
     st.step=0;
     vis[st.x]=1;
     q.push(st);
     while(!q.empty())
     {
         st=q.front();
         q.pop();
         if(st.x==m)
            return st.step;
          for(i=0;i<3;i++)
          {
              if(i==0)
                ed.x=st.x+1;
               if(i==1)
                ed.x=st.x-1;
                 if(i==2)
                ed.x=st.x*2;
                if(vis[ed.x] || ed.x<0 ||ed.x>100000)
                    continue;
                vis[ed.x]=1;
                ed.step=st.step+1;
                q.push(ed);
          }
     }
}
int main()
{
     while(cin>>n>>m)
     {
          memset(vis,0,sizeof(vis));
          int ans=bfs(n,m);
          cout<<ans<<endl;
     }
}
