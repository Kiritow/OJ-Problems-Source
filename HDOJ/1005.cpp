#include<stdio.h>
int main()
{
	int a, b, n, i, arr[48];
	while (scanf("%d %d %d", &a, &b, &n), a || b || n){
		arr[1] = 1;
		arr[2] = 1;
		for (i = 3; i<48; i++)
			arr[i] = ((a*arr[i - 1] + b*arr[i - 2]) % 7);
		printf("%d\n", arr[n % 48]);
	}
	return 0;
}
