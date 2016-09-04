#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 20
using namespace std;
struct trie
{
       bool cover;
       int son[2];
       void init()
       {
            cover = false;
            memset (son,0,sizeof (son));
       }
}tt[70000];
vector <int> w[N];
bool vis[N];
int index;
bool insert (string s)
{
     int len = s.size (),p = 0;
     for (int i = 0;i < len;i ++)
     {
         if (tt[p].son[s[i] - '0'] == 0)
         {
            tt[index].init();
            tt[p].son[s[i] - '0'] = index ++;
         }
         p = tt[p].son[s[i] - '0'];
     }
     if (tt[p].cover) return false;
     tt[p].cover = true;
     return true;
}
string dfs (int u,int fa)
{
       string s = "0";
       vector<string> q;
       q.clear ();
       int len = w[u].size ();
       for (int i = 0;i < len;i ++)
       {
           int v = w[u][i];
           if (vis[v] && v != fa) q.push_back ( dfs(v,u) );
       }
       sort (q.begin(),q.end());
       for (int i = 0;i < q.size ();i ++) s += q[i];
       s += "1";
       return s;
}
int main ()
{
    int cas,c = 0,n,x,y,ans;
    scanf ("%d",&cas);
    while (cas --)
    {
          index = 1;
          ans = 0;
          tt[0].init();
          scanf ("%d",&n);
          int len = 1 << n;
          for (int i = 0;i < n;i ++) w[i].clear ();
          for (int i = 1;i < n;i ++)
          {
              scanf ("%d%d",&x,&y);
              w[x - 1].push_back(y - 1);
              w[y - 1].push_back(x - 1);
          }
          int i,j;
          for (i = 1;i < len;i ++)
          {
              memset (vis,false,sizeof (vis));
              for (j = 0;j < n;j ++)
                  if (i & (1 << j)) vis[j] = true;
              int k = 0;
              for (j = 0;j < n;j ++)
              {
                  if (vis[j])
                  {
                     string s = dfs (j,j);
                     if (insert(s)) k = 1;
                     if (k == 0) break;
                  }
              }
              if (j == n) ans ++;
          }
          printf ("Case #%d: %d\n",++c,ans);
    }
return 0;
}
