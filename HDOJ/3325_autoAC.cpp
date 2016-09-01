#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
using namespace std;
int arry[5];
bool visit[5];
int result[1000000];
int ind;
map<int ,bool> mp;
int Work(int x,int y,int op)
{
 if(op==0)
  return x+y;
 else if(op==1)
  return x-y;
 else if(op==2)
  return x*y;
 else if(op==3 && y && x%y==0)
  return x/y;
 else if(op==4 && x && y%x==0)
  return y/x;
 else
  return y-x;
}
void DFS(int cnt)
{
 int i,j;
 int x,y,k;
 if(cnt==4)
 {
  for(i=0;i<4;i++)
   if(!visit[i] && !mp[arry[i]])
   {
    result[ind++]=arry[i];
    mp[arry[i]]=true;
   }
  return ;
 }
 for(i=0;i<4;i++)
 {
  if(visit[i])
   continue;
  for(j=i+1;j<4;j++)
  {
   if(visit[j])
    continue;
   visit[j]=true;
   x=arry[i];
   y=arry[j];
   for(k=0;k<6;k++)
   {
    arry[i]=Work(x,y,k);
    DFS(cnt+1);
   }
   arry[i]=x;
   arry[j]=y;
   visit[j]=false;
  }
 }
}
int main()
{
 int i,j,k;
 int t=1;
 while(scanf("%d%d%d%d",&arry[0],&arry[1],&arry[2],&arry[3])!=EOF)
 {
  if(!arry[0] && !arry[1] && !arry[2] && !arry[3])
   break;
  mp.clear();
  ind=0;
  memset(visit,false,sizeof(visit));
  DFS(1);
  sort(result,result+ind);
  int cnt;
  int Max=1;
  int beg,end;
  beg=end=result[0];
  i=0;
  while(i<ind)
  {
   j=i;
   cnt=1;
   while(i<ind)
   {
    if(result[i]+1==result[i+1])
     cnt++;
    else
    {
     i++;
     break;
    }
    i++;
   }
   if(cnt>=Max)
   {
    Max=cnt;
    beg=result[j];
    if(j<i)
     end=result[i-1];
    else
     end=result[i];
   }
  }
  printf("Case %d: %d to %d\n",t++,beg,end);
 }
 return 0;
}
