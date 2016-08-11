#include <stdio.h>

int main(int argc, char* argv[]) {
	int a[1000], b[1000], cnt, i, ret = 0;
	scanf("%i", &cnt);
	for(i = 0; i < cnt; i++)
		scanf("%i", &a[i]);
	for(i = 0; i < cnt; i++)
		scanf("%i", &b[i]);
	for(i = 0; i < cnt; i++)
		ret += a[i] * b[i];
	printf("%i", ret);
	return 0;
}
