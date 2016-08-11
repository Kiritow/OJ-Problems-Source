/*
作者:千里冰封
题目:p2618 核电站问题
*/

// 谜之代码习惯，头文件写全局后面
long long sta[0xfffff],save[51][51],a, b;
#include <stdio.h>

long long dfs(int l,int t){
	// if(l > b) return ;
	if(save[l][t])
		return save[l][t];
	if(t >= a){
		save[l][t] = 1;
		return 1;
	}
	t++;l++;
	if(l < b){
		save[l][t] = dfs(l, t);
		save[0][t] = dfs(0, t);
		return save[l][t] + save[0][t];
	}
	save[0][t] = dfs(0, t);
	return save[0][t];
}

int main(int argc, char* argv[]){
    scanf("%d%d", &a, &b);
    printf("%lld", dfs(0, 0));
    return 0;
}
