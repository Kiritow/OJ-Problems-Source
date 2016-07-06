/*
	s为所使用的最小的字母的序号
	t为所使用的最大的字母的序号
	w为数字的位数
*/

#include<stdio.h>

int getf(int cnt){
	if(cnt == 1) return 1;
	return getf(cnt - 1) + getf(cnt - 2);
}

int main(int argc, char** argv){
	int N, P, M;
	scanf("%i%i%i", &N, &P, &M);
	for(int i = 1; i <= M; i++){
		if(getf(i) % P == N){
			printf("%i", i);
			return 0;
		}
	}
	printf("-1");
//    while(1);
    return 0;
}
