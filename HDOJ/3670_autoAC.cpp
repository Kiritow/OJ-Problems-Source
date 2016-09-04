#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
const int N = 65536, M = 101000;
int p[20][M], n;
int lowbit(int t)
 {
     return t&(t^(t-1));
 }
int sum(int k, int end)
 {
     int ans = 0;
     end++;
     while(end > 0)
      {
          ans += p[k][end];
          end -= lowbit(end);
      }
     return ans;
 }
void add(int k, int pos, int num)
 {
    pos++;
    while(pos < M)
     {
         p[k][pos] += num;
         pos += lowbit(pos);
     }
 }
void init()
 {
     memset(p, 0, sizeof(p));
     int w, t;
     for(int i=1; i<=n; i++)
      {
          scanf("%d", &w);
          t = 0;
          while(t<16)
           {
               add(t,w%(1<<(t+1)),1);
               t++;
           }
      }
 }
void solve(int k)
 {
     LL ans = 0;
     int now = 0;
     char ss[10];
     int w, tail;
     while(scanf("%s", ss) && ss[0] != 'E')
      {
          scanf("%d", &w);
          if(ss[0] == 'C')
           {
               now += w;
               now %= N;
           }
          else
           {
               tail = now%(1<<w);
               if(now&(1<<w))
                {
                    ans += sum(w, (1<<w)-tail-1);
                    ans += sum(w, (1<<(w+1))-1) - sum(w,(1<<w+1)-tail-1);
                }
               else
                {
                    ans += sum(w, (1<<(w+1)) - tail-1) - sum(w, (1<<w)-1);
                    ans += sum(w, (1<<w)-1) - sum(w, (1<<w)-tail-1 );
                }
           }
      }
    printf("Case %d: %I64d\n", k, ans);
 }
int main()
 {
     int t=0;
     while(scanf("%d", &n) && n!=-1)
      {
          init();
          t++;
          solve(t);
      }
     return 0;
 }
