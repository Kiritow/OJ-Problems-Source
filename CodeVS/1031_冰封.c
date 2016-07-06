/*
作者:千里冰封
题目:p1031 质数环
*/

#include <stdio.h>
#include <math.h>

int a[17];
int book[18];
int size;

int isPrime(int num){
	int i;
	for(i = 2; i <= sqrt(num); i++)
		if(!(num % i))
			return 0;
	return 1;
}

void dfs(int idx){
	if(idx == size){
		if(!isPrime(a[0] + a[idx])) return ;
		int i;
		printf("1");
		for(i = 1; i < size; i++)
			printf(" %i", a[i]);
 		printf("\n");
		return ;
	}
	int i;
	for(i = 2; i <= size; i++){
		if(!book[i] && isPrime(a[idx - 1] + i)){
			book[i] = 1;
			a[idx] = i;
			dfs(idx + 1);
			book[i] = 0;
		}
	}
}

int main() {
    scanf("%i", &size);
    a[0] = 1;
	book[0] = 1;
	book[1] = 1;
    dfs(1);
    return 0;
}
