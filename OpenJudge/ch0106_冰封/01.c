#include <stdio.h>

int main(int argc, char* argv[]) {
	int a[1000], n, i, cnt = 0, std;
	scanf("%i", &n);
	for(i = 0; i < n; i++)
		scanf("%i", &a[i]);
	scanf("%i", &std);
	for(i = 0; i < n; i++)
		if(a[i] == std) cnt++;
	printf("%i", cnt);
	return 0;
}
