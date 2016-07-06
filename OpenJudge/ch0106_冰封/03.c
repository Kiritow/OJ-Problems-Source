#include <stdio.h>

int main(int argc, char* argv[]) {
	int a[10], i, cnt = 0;
	for(i = 0; i < 10; i++)
		scanf("%i", &a[i]);
	printf("%.1f", 
			a[0] * 28.9 +
			a[1] * 32.7 +
			a[2] * 45.6 +
			a[3] * 78.0 +
			a[4] * 35.0 +
			a[5] * 86.2 +
			a[6] * 27.8 +
			a[7] * 43.0 +
			a[8] * 56.0 +
			a[9] * 65.0
	);
	return 0;
}
