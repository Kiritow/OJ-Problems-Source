/*
作者:千里冰封
题目:p1497 取余运算
*/

#include <stdio.h>
#define LL long long

LL exe(LL a, LL b, LL m) {
	LL ret = 1;
	while(b) {
		if(b&1) {
			ret *= a;
			ret %= m;
		}
		b /= 2;
		a *= a;
		a %= m;
	}
	return ret;
}

int main(int argc, char** argv) {
	LL a, b, m;
	scanf("%lld%lld%lld", &a, &b, &m);
	printf("%lld^%lld mod %lld=%lld", a, b, m, exe(a, b, m));
	return 0;
}
