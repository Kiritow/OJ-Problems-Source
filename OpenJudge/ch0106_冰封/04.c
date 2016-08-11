#include<stdio.h>

int b[100];

int main(void){
	int a, i;

	scanf("%d",&a);

	for(i = 0; i < a; i++ ){
		scanf("%d",&b[i]);
	}

	for(i = a-1; i >= 0; i-- ){
		printf("%d ",b[i]);
	}

	return 0;
}
