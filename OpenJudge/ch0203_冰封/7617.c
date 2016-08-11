#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[]){
	long *a;
	int N, M, i;
	scanf("%d", &N);
	a = (long *) malloc(N * sizeof(long));

	for(i = 0; i < N; i++)
		scanf("%li", &a[i]);

	scanf("%d", &M);

	sort(a, a + N);

	for(i = 0; i < M; i++)
		printf("%li\n", a[ N - i - 1]);

	free(a);
	return 0;
}

/*
 * 测试数据：
10
4 5 6 9 8 7 1 2 3 0
5
 */
