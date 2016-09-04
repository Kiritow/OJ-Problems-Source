#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
int n,flag,ex,ey;
char map[15][15];
struct node{
    int cnt;int s;int x,y;
    char map[12][12];
}s_pos;
bool vis[12][12][12][1<<11];
bool cheack(int x,int y){
     return x>=0&&x<n&&y>=0&&y<n;
}
int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
void bfs(){
      memset(vis,false,sizeof(vis));
      queue<node > q;
      q.push(s_pos);
      vis[s_pos.x][s_pos.y][s_pos.cnt][s_pos.s]=true;
      while(!q.empty()){
          node now = q.front();  q.pop();
           if(now.x==ex&&now.y==ey){
                flag=1; return ;
           }
          for(int i=0;i<4;i++){
              node next = now; int x=next.x;  int y=next.y;
              x+=dir[i][0],  y+=dir[i][1];
              if(cheack(x,y)){
                  if(map[x][y]=='*')  continue;
                  next.x=x;  next.y=y;
                  if(next.map[x][y]=='K'){
                      next.map[x][y]='.';
                      next.cnt+=1;
                  }
                 if(next.map[x][y]>='a'&&next.map[x][y]<='z'){
                      if(next.cnt>0){
                         next.s|=(1<<(next.map[x][y]-'a'));
                         next.cnt-=1;
                         next.map[x][y]='.';
                      }
                      else continue;
                  }
                  if(!vis[x][y][next.cnt][next.s]){
                      vis[x][y][next.cnt][next.s]=true;
                        q.push(next);
                  }
              }
          }
      }
}
int main(){
    int t;int ca=1;scanf("%d",&t);
    while(t--){
       scanf("%d",&n);
       for(int i=0;i<n;i++)  scanf("%s",map[i]);
       s_pos.cnt=s_pos.s=0;  char temp='a';
       for(int i=0;i<n;i++) for(int j=0;j<n;j++){
              if(map[i][j]=='S')   s_pos.x=i,s_pos.y=j;
              if(map[i][j]=='E')   ex=i,     ey=j;
              if(map[i][j]=='L') {
                s_pos.map[i][j]=temp;
                temp=temp+1;
                continue;
             }
              s_pos.map[i][j]=map[i][j];
       }
       flag=0;
       bfs();
       printf("Case %d: ",ca++);
       if(flag)  printf("Yes\n");
       else      printf("No\n");
    }
    return 0;
}
