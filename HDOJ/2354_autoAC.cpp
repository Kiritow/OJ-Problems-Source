#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define inf 1<<30
struct Node{
   int x,y,step;
   bool operator < (const Node &p) const {
      return p.step<step;
   }
};
int n,m;
int Step[22][22];
char map[22][22];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int bfs(){
   for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
         Step[i][j]=inf;
   priority_queue<Node>Q;
   Node p,q;
   for(int i=1;i<=m;i++){
      p.x=1,p.y=i,p.step=1;
      Q.push(p);
   }
   while(!Q.empty()){
      p=Q.top();
      Q.pop();
      if(p.x==n)return p.step;
      for(int i=0;i<4;i++){
         q.x=p.x+dir[i][0];
         q.y=p.y+dir[i][1];
         q.step=p.step;
         if(q.x<1||q.x>n||q.y<1||q.y>m)continue;
         if(map[q.x][q.y]!=map[p.x][p.y])q.step++;
         if(Step[q.x][q.y]>q.step){
            Step[q.x][q.y]=q.step;
            Q.push(q);
         }
      }
   }
   return 1;
}
int main(){
   int _case;
   scanf("%d",&_case);
   while(_case--){
      scanf("%d%d",&n,&m);
      for(int i=1;i<=n;i++)
         scanf("%s",map[i]+1);
      int ans=bfs();
      printf("%d\n",ans);
   }
   return 0;
}
