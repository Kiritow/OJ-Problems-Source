#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;

const int SIZE = 1000;

int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

typedef struct {
  int x;
  int y;
  int s;
} node;

int main(int argc,char** argv){
  int total;
  bool all_in_all[100];
  scanf("%d",&total);
  for(int counter = 0; counter < total; counter ++){
    all_in_all[counter] = false;
    int hx,lx,hy,ly,cnt;
    int head = 0,tail = 0;
    queue<node> q;
    char a[SIZE][SIZE];
    scanf("%d",&cnt);
    for(int i = 0; i < cnt; i++)
      scanf("%s",a[i]);
    //hx,hy是出发点，lx,ly是目标位置
    scanf("%d%d%d%d",&hx,&hy,&lx,&ly);
    while(!q.empty())q.pop();
    node now;
    now.x = hx;
    now.y = hy;
    now.s = 0;
    q.push(now);
    tail++;
    while(!q.empty()){
      now = q.front();
      q.pop();
      if(now.x == lx && now.y == ly){
	all_in_all[counter] = true;
        break;
      }
      a[now.x][now.y] = '#';
      for(int i=0;i<4;i++){
	int x=now.x+step[i][0];
	int y=now.y+step[i][1];
	if(x >= 0 && y >= 0 && x < cnt && y < cnt && a[x][y] == '.'){
	  a[x][y] = '#';
	  node next;
	  next.x = x;
	  next.y = y;
	  next.s = now.s + 1;
	  q.push(next);
	}
      }
    //↓while的终止大括号
    }
  }
  for(int counter = 0; counter < total; counter ++){
    if(all_in_all[counter]) printf("YES\n");
    else printf("NO\n");
  }
  // system("PAUSE");
  return 0;
}
