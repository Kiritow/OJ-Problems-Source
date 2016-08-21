#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int n,m;
char map[50][50];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
bool used[30][30][30][30];
int ab(int x)
{
if(x>0)
return x;
return -1*x;
}
struct node
{
 int sx,sy;
 int step;
 int zx,zy;
    friend bool operator < (node a,node b)
    {
    return a.step>b.step;
    }
};
bool inmap(int x,int y)
{
 if(x>=0&&x<n&&y>=0&&y<m&&map[x][y]!='X')
     return true;
 return false;
}
bool meet(int zx,int zy,int sx,int sy)
{
   int distance=ab(zx-sx)+ab(zy-sy);
   if(distance==0||distance==1)
    return true;
return false;
}
int bfs(int zx,int zy,int sx,int sy)
{
 node first,next;
 priority_queue<node> q;
   first.sx=sx;
   first.sy=sy;
   first.zx=zx;
   first.zy=zy;
   first.step=0;
   q.push(first);
   used[zx][zy][sx][sy]=true;
   while(!q.empty())
   {
    first=q.top();
    q.pop();
      for(int i=0;i<4;i++)
      {
       next.zx=first.zx+dir[i][0];
       next.zy=first.zy+dir[i][1];
       int ssx=first.sx-dir[i][0];
       int ssy=first.sy-dir[i][1];
       if(!inmap(next.zx,next.zy))
       continue;
       if(inmap(ssx,ssy))
       {
        next.sx=ssx;
        next.sy=ssy;
       }
       else
           next.sx=first.sx,next.sy=first.sy;
       next.step=first.step+1;
         if(!used[next.zx][next.zy][next.sx][next.sy])
         {
           if(meet(next.zx,next.zy,next.sx,next.sy))
               return next.step;
             used[next.zx][next.zy][next.sx][next.sy]=true;
          q.push(next);
         } 
      }
   }
return -1;
}
int main()
{
  while(cin>>n>>m)
  {
      int zx,zy,sx,sy;
   for(int k=0;k<n;k++)
       scanf("%s",map[k]);
   memset(used,0,sizeof used);
   for(int i=0;i<n;i++)
       for(int j=0;j<m;j++)
       {
        if(map[i][j]=='Z')
        zx=i,zy=j;
        if(map[i][j]=='S')
        sx=i,sy=j;
       }
       int ans=bfs(zx,zy,sx,sy);
       if(ans!=-1)
           cout<<ans<<endl;
       else
           cout<<"Bad Luck!"<<endl;
  }
return 0;
}
