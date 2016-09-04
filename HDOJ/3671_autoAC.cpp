#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1050, M = 21000;
struct EDGE
 {
     int u, v, next;
 }edge[M];
int num, head[N], low[N], lp[N], step;
int n, m, ans=0, f, root;
void add(int u, int v)
 {
     edge[num].u = u;
     edge[num].v = v;
     edge[num].next = head[u];
     head[u] = num++;
 }
void init()
 {
     num = 0;
     memset(head, -1, sizeof(head));
     int u, v;
     for(int i=0; i<m; i++)
     {
         scanf("%d%d", &u, &v);
         add(u, v);
         add(v, u);
     }
 }
int tarjan(int u)
 {
     lp[u] = low[u] = ++step;
     int tp = 0,v, cc=1;
     bool flag = 0;
     for(int i = head[u];i != -1;i = edge[i].next)
      {
          v = edge[i].v;
          if(v == f) continue;
          if(!lp[v])
           {
               cc++;
               tp++;
               tarjan(v);
               low[u] = min(low[u],low[v]);
               if(u != root&&lp[u] <= low[v])
                flag = 1;
           }
          else low[u] = min(low[u],lp[v]);
      }
      if(u == root && tp > 1)
       flag = 1;
      if(flag) ans++;
      return cc;
 }
void solve()
 {
     int result = 0;
     int now, path[N] = {0};
     for(int i=1; i<=n; i++)
      {
          memset(low, 0, sizeof(low));
          memset(lp, 0, sizeof(lp));
          step = 1;
          now = ans = 0;
          f = i;
          for(int j=1; j<=n; j++)
           {
               if(!lp[j] && j!=i)
                {
                    root = j;
                    path[++now] = tarjan(j);
                }
           }
         if(now > 2) result += n-1;
         else if(now == 2)
          {
              sort(path+1, path+3);
              if(path[1] == 1)
               {
                   if(path[2] != 1)
                    result += n-2;
               }
              else  result += n-1;
          }
         else result += ans;
      }
     printf("%d\n", result/2);
 }
int main()
 {
     int t=0;
     while(scanf("%d%d", &n, &m) != EOF)
      {
          if(n==0 && m==0)
           break;
          init();
          t++;
          printf("Case %d: ", t);
          solve();
      }
     return 0;
 }
