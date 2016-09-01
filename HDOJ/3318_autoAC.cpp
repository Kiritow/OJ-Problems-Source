#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>
using namespace std;
const int N = 100;
int n, m;
int boss[N + 2];
int cur[N + 2];  
int occupy[N + 2][N + 2];  
int need[N + 2][N + 2];
int mark[N + 2];
bool check(int x)
{
 if (mark[x])return false;
 int i;
 for (i = 1; i <= n; i++)
 {
  if (need[x][i] > cur[i])return false;
 }
 return true;
}
void callBack(int x)
{
 int i;
 for (i = 1; i <= n; i++)
 {
  cur[i] += occupy[x][i];
  need[x][i] = 0;
 }
 mark[x] = 1;
}
int main ()
{
 int i, j, tmp;
 while (scanf("%d%d", &n, &m) != EOF)
 {
  memset(mark, 0, sizeof(mark));
  for (i = 1; i <= n; i++)
  {
   scanf("%d", &boss[i]);
   cur[i] = boss[i];
  }
  for (i = 1; i <= m; i++)
   for (j = 1; j <= n; j++)
   {
    scanf("%d", &need[i][j]);
    need[i][j] < 0 ? 0 : need[i][j];
   }
  for (i = 1; i <= m; i++)
   for (j = 1; j <= n; j++)
   {
    scanf("%d", &tmp);
    need[i][j] -= tmp;
    occupy[i][j] = tmp;
    cur[j] -= tmp;
   }
  int flag;
  while (1)
  {
   flag = 0;
   for (i = 1; i <= m; i++)
   {
    if (check(i)) 
    {
     callBack(i);  
     flag = 1;
    }
   }
   if (!flag)break;
  }
  for (i = 1; i <= n; i++)
   if (cur[i] != boss[i])break;
  if (i > n)printf("Yes\n");
  else
   printf("No\n");
 }
}
