/*
作者:千里冰封
题目:p3500 快速幂入门
*/
#include <stdio.h>
#define LL long long

LL exe(LL a, LL b, LL m) {
	LL ret = 1;
	while(b) {
		if(b&1) 
			ret = (ret * a) % m;
		b /= 2;
		a *= a;
		a %= m;
	}
	return ret;
}

int main(int argc, char** argv) {
	LL a, b, m;
	scanf("%lld%lld%lld", &a, &b, &m);
	printf("%lld", exe(a, b, m));
	return 0;
}
