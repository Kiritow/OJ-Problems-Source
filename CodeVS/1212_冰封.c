/*
作者:千里冰封
题目:p1212 最大公约数
*/

#include <stdio.h>

long get(long x, long y){
	long max = x < y ? y : x;
	long min = x > y ? y : x;
	if(!(max % min)){
		return min;
	}
	long i;
	for(i = max / 2; i > 1; i--){
		if(!(x % i) && !(y % i)){
			return i;
		}
	}
	return 1;
}

int main(int argc, char* argv[]){
	long a, b;
	scanf("%i%i", &a, &b);
	printf("%i", get(a, b));
	return 0;
}
