/*
作者:千里冰封
题目:p2024 整数加法
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void resort(char *a, int size) {
	int i;
	for(i = 0; i < size / 2; i++) {
		char c = a[i];
		a[i] = a[size - 1 - i];
		a[size - 1 - i] = c;
	}
}
int max(int a, int b) {	return a > b ? a : b; }
int main() {
	char *a, *b;
	char c[700];
	int i, mark = 0, a0 = 0, b0 = 0;
	a = (char* ) malloc (700 * sizeof(char));
	b = (char* ) malloc (700 * sizeof(char));
	for(i = 0; i < sizeof(c); i++)
		c[i] = '0';
	scanf("%s%s", a, b);
	if(a[0] == '-') {
		a0 = 1;
		a++;
	}
	if(b[0] == '-') {
		b0 = 1;
		b++;
	}
	resort(a, strlen(a));
	resort(b, strlen(b));
	int size = max(strlen(a), strlen(b));
	for(i = 0; i < size; i++) {
		if(i < strlen(a)) {
			if(!(a0 == b0) && a0)
				c[i] -= a[i] - '0';
			else
				c[i] += a[i] - '0';
		}
		if(i < strlen(b)) {
			if(!(a0 == b0) && b0)
				c[i] -= b[i] - '0';
			else
				c[i] += b[i] - '0';
		}
		c[i] += mark;
		mark = 0;
		if(c[i] > '9') {
			c[i] -= 10;
			mark = 1;
		}
		if(c[i] < '0') {
			c[i] += 10;
			mark = -1;
		}
	}
	for(i = size; i >= 0; i--) {
		if(mark) {
			i--;
			break;
		}
		if(i == 0 && (a0 || b0)) {
			puts("0");
			return 0;
		}
		if(c[i] != '0') break;
	}
	if(mark < 0 || a0 && b0) printf("-");
	if(mark > 0) printf("1");
	for(; i >= 0; i--) {
		if(mark < 0 && (a0 != b0))
			c[i] = '9' - (c[i] - '0');
		printf("%c", c[i]);
	}
	free(a);
	free(b);
	return 0;
}
