#include<stdio.h>
#include<string.h>

const int size = 1000;

int main(int argc, char* argv[]) {
	char a[size], b[size], temp[size];
	int num1, num2, pos,n,i,j;
	if (scanf("%s%s", &a, &b) != 0) {
		num1 = strlen(a);
		num2 = strlen(b);
		for (j = 0; j < num1 - num2 + 2; j++){
			for ( i = 0, n = j; i < num2; i++,n++)
				temp[i] = a[n];
		if (strcmp(temp, b) == 0){
			pos = j + 1;
			break;
			}
		}
		printf("%i", pos);
	}
	return 0;
}
