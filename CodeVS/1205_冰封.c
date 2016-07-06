/*
作者:千里冰封
题目:p1205 单词翻转
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char a[50][1000], i = 0;
    while(scanf("%s", a[i++]) != EOF);
//	for(i = 0; i < strlen(a) / 2; i++){
//		char s;
//		s = a[strlen(a) - i - 1];
//		a[strlen(a) - i - 1] = a[i];
//		a[i] = s;
//	}
	i--;
	while(i--)
    	printf("%s ", a[i]);
    return 0;
}
