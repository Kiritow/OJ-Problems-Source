/*
作者:千里冰封
题目:p1983 等式问题 
*/

#include <stdio.h>

#define plus 1
#define minu 2
#define noop 3

int cur[10], goal, cnt;

void dfs(int idx){
	if(idx >= 9){
		int res, i, curr = 0, now = 1;
		for(i = 1; i < 10; i++) printf("%i%s", i, cur[i] == plus ? "+" : cur[i] == minu ? "-" : "");
		printf("\n");
		for(i = 9; i >= 1; i--){
			switch(cur[i]){
				case noop:
					curr += i;
					break;
				case minu:
					now -= (i + curr);
					curr = 0;
					break;
				case plus:
					now += (i + curr);
					curr = 0;
					break;
			}
		}
		if(now == goal)
			cnt++;
		return ;
	}
	cur[idx] = plus;
	dfs(idx + 1);
	cur[idx] = minu;
	dfs(idx + 1);
	cur[idx] = noop;
	dfs(idx + 1);
}

int main(int argc, char* argv[]){
    scanf("%i", &goal);
    dfs(1);
    printf("%i", cnt);
    return 0;
}
