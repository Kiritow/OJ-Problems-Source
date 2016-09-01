#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
const int size = 11;
struct node
{
       int mx, my;
       int px, py;
       int cx, cy;
       int step; 
};
int n, m;
int sx, sy;
bool has[size][size][size][size][size][size];
node start, ne, pre;
const int GoM[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
const int GoM1[8][2] = {{0, 1}, {0, -1}, {0, 1}, {0, -1}, {1, 0}, {1, 0}, {-1, 0}, {-1, 0}};
const int GoC[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char mapp[size][size];
int ans;
bool check(int x, int y)
{
     return (x >= 0 && x < n && y >= 0 && y < m);     
}
void bfs()
{
     memset(has, false, sizeof(has));
     start.step = 0;
     queue <node> Que;
     Que.push(start);
     has[start.mx][start.my][start.px][start.py][start.cx][start.cy] = true;
     while (!Que.empty()){
           node pre = Que.front();
           Que.pop();
           for (int i = 0; i < 8; i ++){
               int xx = pre.mx + GoM[i][0];
               int yy = pre.my + GoM[i][1];
               int judx = pre.mx + GoM1[i][0];
               int judy = pre.my + GoM1[i][1];
               if (!check(xx, yy) )continue;
               if ((judx == pre.px && judy == pre.py) || (judx == pre.cx && judy == pre.cy)||mapp[judx][judy] == 'D' || mapp[judx][judy] == 'S')continue;
               if ((xx == pre.px && yy == pre.py) || (xx == pre.cx && yy == pre.cy) || mapp[xx][yy] == 'D')continue;
               if (!has[xx][yy][pre.px][pre.py][pre.cx][pre.cy]){
                  if (mapp[xx][yy] == 'S'){
                     ans = pre.step+1;                   
                     return ;                 
                  }
                  has[xx][yy][pre.px][pre.py][pre.cx][pre.cy] = true;
                  ne = pre;
                  ne.mx = xx, ne.my = yy;
                  ne.step ++;
                  Que.push(ne);
               }
           } 
           for (int i = 0; i < 4; i ++){
               for (int k = 1; k <= 10; k ++){ 
                   int xx = pre.cx + k*GoC[i][0];
                   int yy = pre.cy + k*GoC[i][1];
                   if (!check(xx, yy) || (pre.mx == xx && pre.my == yy) || (pre.px == xx && pre.py == yy) || mapp[xx][yy] == 'D')break;
                   if (!has[pre.mx][pre.my][pre.px][pre.py][xx][yy]){
                      if (mapp[xx][yy] == 'S'){
                         ans = pre.step+1;
                         return ;                 
                      }
                      has[pre.mx][pre.my][pre.px][pre.py][xx][yy] = true;
                      ne = pre;
                      ne.cx = xx, ne.cy = yy;
                      ne.step ++;
                      Que.push(ne);
                   }
               }
           }
           for (int i = 0; i < 4; i ++){//p
               int flag = 0;
               for (int k = 1; k <= 10; k ++){
                   int xx = pre.px + k*GoC[i][0];
                   int yy = pre.py + k*GoC[i][1];
                   if (!check(xx, yy))break;
                   if ((pre.mx == xx && pre.my == yy) || (pre.cx == xx && pre.cy == yy) || mapp[xx][yy] == 'D' || mapp[xx][yy] == 'S')flag ++;
                    if (flag == 1 && mapp[xx][yy] == 'S')break;
                    if (flag == 1 )continue; 
                   if (flag > 2 )break;
                   if (flag == 2 && mapp[xx][yy] != 'S')break;
                   if (!has[pre.mx][pre.my][xx][yy][pre.cx][pre.cy]){
                      if (mapp[xx][yy] == 'S'){
                         ans = pre.step+1;
                         return ;                 
                      }
                      has[pre.mx][pre.my][xx][yy][pre.cx][pre.cy] = true;
                      ne = pre;
                      ne.px = xx, ne.py = yy;
                      ne.step ++;
                      Que.push(ne);          
                   }   
               }
           }    
     }
}
int main()
{
    int nc = 0;
    while (scanf("%d%d", &n, &m) != EOF){
          for (int i = 0; i < n; i ++){
              scanf("%s", mapp[i]);   
              for (int j = 0; j < m; j ++){
                  if (mapp[i][j] == 'M'){
                     start.mx = i, start.my = j; 
                     mapp[i][j] = '.';              
                  }
                  if (mapp[i][j] == 'C'){
                     start.cx = i, start.cy = j;
                     mapp[i][j] = '.';               
                  }
                  if (mapp[i][j] == 'P'){
                     start.px = i, start.py = j;
                     mapp[i][j] = '.';               
                  }            
              } 
          }      
          ans = -1;
          printf("Scenario #%d\n", ++nc);
          bfs();
          if (ans == -1)printf("OH!That's impossible!\n\n");
          else
          printf("%d\n\n", ans);
    }
    return 0 ;
}
