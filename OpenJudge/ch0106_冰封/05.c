#include <stdio.h>

int main(int argc, char* argv[]) {
	int i, n, a0 = 0, a1 = 0, a2 = 0, a3 = 0;
	scanf("%i", &n);
	for(i = 0; i < n; i++) {
		int k;
		scanf("%i", &k);
		if(k < 19) {
			a0++;
		} else if(k < 36) {
			a1++;
		} else if(k < 61) {
			a2++;
		} else {
			a3++;
		}
	}
	printf("%.2f%%\n%.2f%%\n%.2f%%\n%.2f%%", a0 * 100.0 / n, a1 * 100.0 / n, a2 * 100.0 / n, a3 * 100.0 / n);
	return 0;
}
