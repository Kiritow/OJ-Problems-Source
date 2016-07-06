/*
作者:千里冰封
题目:p2969 角谷猜想
*/

#include <stdio.h>

const int size = 10000000;
int cnt;
int save[size];

void dfs(int cur){
	if(cur == 1) return ;

	cnt++;
	dfs(cur % 2 ? cur * 3 + 1 : cur / 2);
}

int main(int argc, char* argv[]){
	int tot;
	save[1] = 0;
	scanf("%i", &tot);
	while(tot--) {
		int a, b, max = 0;
		scanf("%i%i", &a, &b);
		if(a > b) {
			int x = a;
			a = b;
			b = x;
		}
		for(; a <= b; a++) {
			if(save[a]) {
				cnt = save[a];
				if(cnt > max) max = cnt;
				continue ;
			}
			cnt = 0;
			dfs(a);
			save[a] = cnt;
			if(cnt > max) max = cnt;
		}
		printf("%i\n", max);
	}
	return 0;
}
