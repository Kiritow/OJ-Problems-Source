#include<stdio.h>
#include<memory.h>
#include <climits>
#include<string.h>
#include<stdlib.h>
#define N 1024
#define M 1024*110
int l[M], r[M], d[M], u[M], col[M], row[M], o[N], res[N], s[N],head[M];
int node=0,count;
int map[10][10],visit[10][10],a[10][10];
int cmp(const void *a,const void *b)
{
 return *(int*)a-*(int*)b;
}
inline void addnode(int &x)
{
 ++x;
    r[x] = l[x] = u[x] = d[x] = x;
}
inline void insert_row(int rowx, int x)
{
    r[l[rowx]] = x;
    l[x] = l[rowx];
    r[x] = rowx;
    l[rowx] = x;
}
inline void insert_col(int colx, int x)
{
    d[u[colx]] = x;
    u[x] = u[colx];
    d[x] = colx;
    u[colx] = x;
}
void dlx_init(int col)
{
 memset(head,-1,sizeof(head));
 memset(res,0,sizeof(res));
 memset(o,0,sizeof(o));
 memset(s,0,sizeof(s));
 int i;
 node=-1;
 addnode(node);
 for(i=1;i<=col;i++)
 {
        addnode(node);
        insert_row(0, node);  
 }
}
inline void insert_node(int x,int y)
{
 s[y]++;
 addnode(node);
 row[node]=x;
 col[node]=y;
 insert_col(y,node);
 if(head[x]==-1) head[x]=node;
 else
  insert_row(head[x],node);
}
inline void remove(int c)
{
    l[r[c]] = l[c];
    r[l[c]] = r[c];
 int i,j;
    for (i = d[c]; i != c; i = d[i])
        for (j = r[i]; j != i; j = r[j])
        {
            u[d[j]] = u[j];
            d[u[j]] = d[j];
            s[col[j]]--;
        }
}
inline void resume(int c)
{
    for (int i = u[c]; i != c; i = u[i])
        for (int j = l[i]; j != i; j = l[j])
        {
            u[d[j]] = j;
            d[u[j]] = j;
            s[col[j]]++;
        }
    l[r[c]] = c;
    r[l[c]] = c;
}
void print()
{
 int i,k=0,j,ans[82]={0};
 for(i=0;i<81;i++)
  ans[i]=res[i];
 qsort(ans,81,sizeof(int),cmp);
 for(i=0;i<9;i++)
  for(j=0;j<9;j++)
   map[i][j]=ans[k++]-(i*9+j)*9;
}
bool DLX(int deep)
{
    if (r[0] == 0)
    {
  count++;
  if(count==1)
   print();
  else
   return true;
  return false;
 }
    int min = INT_MAX, tempc,i,j;
    for (i = r[0]; i != 0; i = r[i])
        if (s[i] < min)
        {
            min = s[i];
            tempc = i;
        }
    remove(tempc);
    for (i = d[tempc]; i != tempc; i = d[i])
    {
        res[deep] = row[i];
        for (j = r[i]; j != i; j = r[j]) remove(col[j]);
        if (DLX(deep + 1)) return true;
        for (j = l[i]; j != i; j = l[j]) resume(col[j]);
    }
    resume(tempc);
    return false;
}
inline void dad(int i,int j,int ii)
{
 int x=(i*9+j)*9+ii;
 insert_node(x,i*9+j+1);
 insert_node(x,81+i*9+ii);
 insert_node(x,81*2+j*9+ii);
 insert_node(x,81*3+9*(visit[i][j]-1)+ii);
}
void dfs(int i,int j,int n)
{
 if(i<0||i>9||j<0||j>9)
  return;
 visit[i][j]=n;
 if(!(a[i][j]&16)&&!visit[i-1][j])
  dfs(i-1,j,n);
 if(!(a[i][j]&32)&&!visit[i][j+1])
  dfs(i,j+1,n);
 if(!(a[i][j]&64)&&!visit[i+1][j])
  dfs(i+1,j,n);
 if(!(a[i][j]&128)&&!visit[i][j-1])
  dfs(i,j-1,n);
}
int main()
{
 int n,cases=0;
 scanf("%d",&n);
 while(cases++<n)
 {
  count=0;
  memset(visit,0,sizeof(visit));
  memset(a,0,sizeof(a));
  dlx_init(81*4);
  int k=0,i=0,j=0,s=1;
  for(i=0;i<9;i++)
   for(j=0;j<9;j++)
   {
    scanf("%d",&map[i][j]);
    a[i][j]=map[i][j]&(~15);
    map[i][j]=map[i][j]&15;
   }
  for(i=0;i<9;i++)
   for(j=0;j<9;j++)
    if(!visit[i][j])
     dfs(i,j,s++);
  for(i=0;i<9;i++)
   for(j=0;j<9;j++)
    if(map[i][j]==0)
    {
     int ii;
     for(ii=1;ii<=9;ii++)
      dad(i,j,ii);
    }
    else
     dad(i,j,map[i][j]);
  DLX(0);
  printf("Case %d:\n",cases);
  if(!count)
   printf("No solution\n");
  else if(count==1)
   for(i=0;i<9;i++)
   {
    for(j=0;j<9;j++)
     printf("%d",map[i][j]);
    printf("\n");
   }
  else
   printf("Multiple Solutions\n");
 }
 return 0;
}
