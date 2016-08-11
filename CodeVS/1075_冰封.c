/*
作者:千里冰封
题目:p1075 明明的随机数
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *x, const void *y){
	return *(int*)x > *(int*)y;
}

int main(int argc, char* argv[]){
    int a[1000], size, all = 0;
    int out[1000];
    int i, j;
    scanf("%i", &size);
    for(i = 0; i < size; i++)
    	scanf("%i", &a[i]);
	qsort(a, size, sizeof(a[0]), cmp);
    for(i = 0; i < size; i++){
		if(a[i] == a[i + 1]) {
			continue;
		}
		out[all] = a[i];
		all++;
    }
    printf("%i\n", all);
    for(i = 0; i < all; i++){
   		printf("%i ", out[i]);
    }

	return 0;
}
