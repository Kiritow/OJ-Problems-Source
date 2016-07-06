#include <stdio.h>
#include <stdlib.h>

const int size = 10000 + 1;

class pair{
	public:
		int left;
		int right;
};

int main(int argc,char* argv[]){
	pair *a = new pair();
	a->left = -1;
	a->right = -1;
	int N;
	int left = size;
	int right = 0;
	bool *k = (bool *)malloc( size * sizeof(bool) );

	for(int i = 0; i < size; i++)
		k[i] = false;

	scanf("%d", &N);

	for(int i = 0; i < N; i++) {
		scanf("%i %i", &a->left, &a->right);

		if(a->left < left)
			left = a->left;

		if(a->right > right)
			right = a->right;

		for(int j = a->left; j < a->right; j++)
			k[j] = true;
	}

	for(int i = left; i < right; i++)
		if(!k[i]){
			printf("no");
			return 0;
		}

	printf("%i %i", left, right);
	free(k);
	return 0;
}

/*
测试数据：
5
5 6
1 5
10 10
6 9
8 10
*/