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

int max(int a, int b) {
	return a > b ? a : b;
}

char* plus(char* a, char* b) {
	char c[700], out233[700], idx = 0, *out = &out233[0];
	int i, mark = 0, a0 = 0, b0 = 0;
	for(i = 0; i < sizeof(c); i++)
		c[i] = out[i] = '0';
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
	for(i = size; i > 0; i--)
		if(c[i] != '0' || mark) {
			if(mark) i--;
			break;
		}
	if(mark < 0 || a0 && b0) {
		out[idx] = '-';
		idx++;
	}
	if(mark > 0) {
		out[idx] = '1';
		idx++;
	}
	for(; i >= 0; i--) {
		if(mark < 0 && (a0 != b0))
			c[i] = '9' - (c[i] - '0');
		out[idx] = c[i];
		idx++;
	}
	free(a);
	free(b);
	return out;
}

int main(int argc, char* argv[]) {
	int cnt;
	scanf("%i", &cnt);
	char* res = (char*) malloc (700 * sizeof(char));
	res[0] = '1';
	while(cnt--) {
		char* a = (char*) malloc (700 * sizeof(char));
		strcpy(a, res);
		res = plus(a, res);
	}
	puts(res);
	return 0;
}
