#include<iostream>
#include<string.h>
using namespace std;
#define MAX 201
#define MAXN 0xffffff
int map[MAX][MAX],link[MAX],dx[MAX],dy[MAX];
bool visx[MAX],visy[MAX];
int n,lack;
char A[201][10001];
bool DFS(int v)
{
 visx[v]=true;
 for(int i=1;i<=n;i++)
 {
  if(visy[i])
   continue;
  int t=dx[v]+dy[i]-map[v][i];
  if(!t)
  {
   visy[i]=true;
   if(link[i]==-1||DFS(link[i]))
   {
    link[i]=v;
    return true;
   }
  }
  else
  {
   if(t<lack)
    lack=t;
  }
 }
 return false;
}
void KM()
{
 int i,j;
 memset(dx,0,sizeof(dx));
 memset(dy,0,sizeof(dy));
 memset(link,-1,sizeof(link));
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
   if(map[i][j]>dx[i])
    dx[i]=map[i][j];
 }
 for(i=1;i<=n;i++)
 {
  while(true)
  {
   memset(visx,0,sizeof(visx));
   memset(visy,0,sizeof(visy));
   lack=MAXN;
   if(DFS(i))
    break;
   for(j=1;j<=n;j++)
   {
    if(visx[j])
     dx[j]-=lack;
    if(visy[j])
     dy[j]+=lack;
   }
  }
 }
 int ans=0;
 for(i=1;i<=n;i++)
  ans+=map[link[i]][i];
    cout<<ans<<endl;
}
void Q()
{
 int i,j,p,q;
 for(i=1;i<=n;i++)
 {
  int len1=strlen(A[i]);
  for(j=1;j<=n;j++)
  {
   if(i==j)
    map[i][j]=0;
   else
   {
    int len2=strlen(A[j]);
    q=0;
    p=len2-1;
    while(q<len1&&p>=0&&A[i][q]==A[j][p])
    {
     q++;p--;
    }
    map[i][j]=q;
   }
  }
 }
}
int main()
{
 while(cin>>n)
 {
  int i,j;
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
    map[i][j]=0;
  }
  for(i=1;i<=n;i++)
   scanf("%s",A[i]);
  Q();
  KM();
 }
 return 0;
}
