/*
作者:千里冰封
题目:p3261 小明集邮票
*/
#include <stdio.h>
#include <memory.h>

int M, N ;
unsigned long long cnt ;
bool used[6] ;

void dfs(int now, int total, int last, bool have){
  if(total > M)  return ;
//  printf("now = %i, total = %i, last = %i, %s, \n", now, total, last, have ? "already have" : "haven`t yet");
  if(now > N) {
  	int i ;
  	for(i = 1; i <= 5; i++)
  		if(!used[i])
  			break ;
  	if(have && i >= 5)
  		cnt++ ;
    return ;
  }
  now++;
  for(int i = 1; i <= 5; i++) {
  	bool s = used[i] ;
  	used[i] = true ;
  	dfs(now, total + i, i, last - i == 3 || last - i == -3);
  	used[i] = s ;
  }
}

int main(int argc, char* argv[]){
//	memset(used, false, sizeof(used[0]));
  scanf("%i%i", &N, &M) ;
  dfs(1, 0, -5, false) ;
  printf("%lld", cnt) ;
  return 0 ;
}
