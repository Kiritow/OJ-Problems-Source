#include<stdio.h>
#include<stdlib.h>

#define LENGTH 6
#define WIDTH 5

int out[1000][LENGTH][WIDTH];

inline void change(int *a){
  if(*a == 0) *a = 1; 
  else *a = 0;
}
inline void press(int a[LENGTH][WIDTH],int b[LENGTH][WIDTH],int x,int y){
  change(&b[x][y]);

  change(&a[x][y]);

  if(y <= WIDTH)
    change(&a[x][y+1]);
  if(y > 0)
    change(&a[x][y-1]);
  if(x <= LENGTH)
    change(&a[x+1][y]);
  if(x > 0)
    change(&a[x-1][y]);
}

bool judge(int a[LENGTH][WIDTH]){
  int cnt = 0, i, j;
  for(j = 0; j < WIDTH; j++)
    for(i = 0; i < LENGTH; i++)
      if(a[i][j])return false;
  // printf("found\n");
  return true;
}

void dfs(bool *fb,int a[LENGTH][WIDTH],int b[LENGTH][WIDTH],int x,int y){
  // 先判断
  if(*fb)     return;
  if(judge(a)){*fb = true;return;}
  // 移动
  x++;
  if(x >= LENGTH){
    x = 0;
    y++;
  }
  // 按下去
  press(a,b,x,y);
  dfs(fb,a,b,x,y);
  // 按回来
  press(a,b,x,y);
  dfs(fb,a,b,x,y);
  return ;
}

int main(int argc,char** argv){
  //printf("%s\n",argv[0]);
  int total, cnt, i, j;
  scanf("%d",&total);
  for(cnt = 0; cnt < total; cnt++){
    bool fb = false;
    int a[LENGTH][WIDTH];
    int b[LENGTH][WIDTH];

    for(j = 0; j < WIDTH; j++)
      for(i = 0; i < LENGTH; i++)
	b[i][j] = 0;

    for(j = 0; j < WIDTH; j++)
      for(i = 0; i < LENGTH; i++)
	scanf("%d",&a[i][j]);

    dfs(&fb,a,b,-1,0);

    for(j = 0; j < WIDTH; j++)
      for(i = 0; i < LENGTH; i++)
	out[cnt][i][j] = b[i][j];
  }
  // 输出
  for(cnt = 0; cnt < total; cnt++){
    printf("PUZZLE #%d\n",cnt+1);
    for(j = 0; j < WIDTH; j++){
      for(i = 0; i < LENGTH; i++)
        printf("%d ",out[cnt][i][j]);
      printf("\n");
    }
  }
  return 0;
}
