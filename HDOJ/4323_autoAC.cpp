#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
int dp[40][40];
char s1[100], s2[100], st[10010][30];
const int inf  = 0x7f7f7f7f;
struct node
{
  char word[30]; 
  node *next[30];
}root;
node p[100000];
int num, flag, vnum, fuck;
map<string,int>mp;
int f[100000];
void init( )
{
  for( int i = 0; i < 40; i++)
       for( int j = 0; j < 40; j++)
            dp[i][j] = inf;      
}
int diff( char *s1, char *s2)
{
  init();
  int x = strlen(s1+1);
  int y = strlen(s2+1);
    for( int i = 0; i <= x; i++)
        dp[i][0] = i;
   for( int j = 0; j <= y; j++)
        dp[0][j] = j;
   for( int i = 1; i <= x; i++)
   {
        for( int j = 1; j <= y; j++)
        {
             dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+ !(s1[i]==s2[j]) );
        }  
  }
  return dp[x][y]; 
} 
void insert(node *q, char *str)
{
  node *l = q;
  while( l )
  {
     int dis = diff( l->word, str);
     if( ! l->next[dis] )
     {
        l->next[dis] = &p[num++];
        strcpy(l->next[dis]->word + 1, str + 1);
        break;
     }
     l = l->next[dis];               
  }        
}
void sfind(node *q, char *str, int d)
{
  if( flag ) 
      return ;
  node *l = q;
  if( l == NULL )
      return;
  int dis = diff(str, l->word);
  if( dis <= d )
  {
    fuck++;
  }
  for( int x = dis-d; x <= dis+d; x++)
  {  
     if( x >= 0 && x <= 20 && l->next[x] )
         sfind(l->next[x], str, d);     
  }
}
int main( )
{
  int N, M, d, cnt, T, abc = 1;
  char str[1000];
  scanf("%d",&T);
  while( T-- )
  {
    scanf("%d%d",&N,&M);
    memset(p,0,sizeof(p));
    for( int i = 0; i < 30; i++)
         root.next[i] = NULL;
    num = 0;
    int cnum = 1;
    strcpy(st[0] + 1, root.word+1);
    for( int i = 1; i <= N; i++)
    {
       scanf("%s",st[i]+1);
       insert(&root, st[i]);
    }
    d = 1;
    printf("Case #%d:\n", abc++);
    for( int i = 1; i <= M; i++)
    {
       vnum = 0;
       flag = 0;
       fuck = 0;
       scanf("%s%d",str+1, &d);
       sfind(&root, str, d); 
       printf("%d\n", fuck);
    }
  }
  return 0;
}
