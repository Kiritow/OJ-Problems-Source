#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N_n 505
#define N_N 250050
using namespace std;
typedef struct
{
   int x ,y;
   int high;
   int key;
}NODE;
NODE node[N_N];
int H[N_n][N_n];
int mark[N_n][N_n];
int now_mksum;
int dir[4][2] = {0 ,1 ,0 ,-1 ,1 ,0 ,-1 ,0};
int n ,m;
bool camp(NODE a ,NODE b)
{
   return a.high < b.high || a.high == b.high && a.key > b.key;
}
bool ok(int x ,int y ,int now_h)
{
   if(x >= 1 && x <= n && y >= 1 && y <= m && !mark[x][y] && H[x][y] <= now_h)
   return 1;
   return 0;
}
void MK(int x ,int y ,int now_h)
{
   for(int i = 0 ;i < 4 ;i ++)
   {
      int xx = x + dir[i][0];
      int yy = y + dir[i][1];
      if(ok(xx ,yy ,now_h))
      {
         mark[xx][yy] = 1;
         now_mksum ++;
         MK(xx ,yy ,now_h);
      }
   }
   return;
}
void jude(int x ,int y ,int now_h)
{
   for(int i = 0 ;i < 4 ;i ++)
   {
      int xx = x + dir[i][0];
      int yy = y + dir[i][1];
      if(xx == 0 || xx == n + 1 || yy == 0 || yy == m + 1)
      continue;      
      if(mark[xx][yy])
      {   
         mark[x][y] = 1;
         now_mksum ++; 
         MK(x ,y ,now_h);    
         break;
      }
   }
}
int main ()
{
   int t ,i ,j ,ans;
   scanf("%d" ,&t);
   while(t--)
   {
      scanf("%d %d" ,&n ,&m);
      for(i = 1 ;i <= n ;i ++)
      for(j = 1 ;j <= m ;j ++)
      {
         scanf("%d" ,&H[i][j]);
         int now = (i - 1) * m + j;
         node[now].x = i;
         node[now].y = j;
         node[now].high = H[i][j];
         node[now].key = (i == 1 || i == n || j == 1 || j == m);
      }
      sort(node + 1 ,node + n * m + 1 ,camp);
      memset(mark ,0 ,sizeof(mark));
      for(ans = now_mksum = 0 ,i = 1 ;i <= n * m ;i ++)
      {
         if(node[i].high == node[n*m].high) break;
         if(!mark[node[i].x][node[i].y])
         {
            if(node[i].key) 
            {
               mark[node[i].x][node[i].y] = 1;
               now_mksum ++;
               MK(node[i].x ,node[i].y ,node[i].high);
            }
            else jude(node[i].x ,node[i].y ,node[i].high);
         }
         if(node[i].high < node[i+1].high)
         ans += ((node[i+1].high - node[i].high) * (i - now_mksum));
      }
      printf("%d\n" ,ans);
   }
   return 0;
}
