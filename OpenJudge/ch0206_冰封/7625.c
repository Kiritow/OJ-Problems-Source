#include <stdio.h>
#include <memory.h>

const int size = 0xfff;

int max(int a, int b) {
	return a > b ? a : b;
}
// ass we can
int main(int argc, char** argv) {
	int a[size], c[size], m = -size, i, j, n;
	memset(a, 0, size);
	memset(c, 0, size);
	scanf("%i", &n);
	for(i = 0; i < n; i++) {
		for(j = 0; j <= i; j++) {
			scanf("%i", &c[j]);
			if(!j) c[j] += a[j];
			else if(j >= i) c[j] += a[j - 1];
			else c[j] += max(a[j], a[j - 1]);
			m = max(m, c[j]);
		}
		for(j = 0; j <= i; j++) 
			a[j] = c[j];
	}
	printf("%i", m);
	return 0;
}
/**
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
*/
