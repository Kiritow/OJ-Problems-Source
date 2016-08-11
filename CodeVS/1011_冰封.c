#include<stdio.h>
int res = 0;

void dfs(int cur){
  if(cur == 0)
    return ;
  res++;
  auto int i;
  for(i = 1; i <= cur / 2; i++)
    dfs(i);
}

int main(int argc, char* argv[]){
  auto int num = 0;
  scanf("%i", &num);
  dfs(num);
  printf("%i", res);
  // while(1);
  return 0;
}
