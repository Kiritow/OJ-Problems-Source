/*
作者:千里冰封
题目:p1430 素数判定
*/

#include <stdio.h>
#include <math.h>

int isPrime(int num){
	int i;
	if(num == 1){
		return 0;
	}
	for(i = 2; i <= sqrt(num); i++)
		if(!(num % i))
			return 0;
	return 1;
}

int main(int argc, char* argv[]){
	int a;
	scanf("%i", &a);
	printf("%s", isPrime(a) ? "\\t" : "\\n");
	return 0;
}
