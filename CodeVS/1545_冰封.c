/*
作者:千里冰封
题目:p1545 最简单排序
*/

#include <stdio.h>
#include <search.h>

int cmp (const void *a , const void *b){
	return *(int*)a - *(int*)b;
}

int main(int argc, char* argv[]) {
    int a, s[12];
    memset(s, -1, sizeof(s[0]));
    scanf("%i", &a);
    int i;
    for(i = 0; i < a; i++)
    	scanf("%i", &s[i]);
    qsort(s, a, sizeof(s[0]), cmp);
    for(i = 0; i < a; i++)
	    printf("%d\n", s[i]);
    return 0;
}
