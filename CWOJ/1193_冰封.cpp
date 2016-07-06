#include <stdio.h>
#include <string.h>
#include <iostream>
#define LL long long

LL fast_plus(LL a, LL b, LL m) {
	LL ret = 0;
	while(b) {
		if(b & 1)
			ret = (ret + a) % m;
		b >>= 1;
		a = (a << 1) % m;
	}
	return ret;
}

LL fast_pow(LL a, LL b, LL m) {
	LL ret = 1;
	while(b) {
		if(b & 1)
			ret = fast_plus(ret, a, m);
		b >>= 1;
		a = fast_plus(a, a, m);
	}
	return ret;
}

int main() {
	int i;
	LL n, m, t, aa = 0;
	char a[10005];
	std::cin>>a>>n>>m;
	for(i = 0; i < strlen(a); i++)
		aa = (aa * 10 + a[i] - '0') % m;
	if(n == 1) {	
		std::cout<<a<<' '<<fast_pow(aa, 2, m);
		return 0;
	}
	t = fast_pow(aa, n, m);
	std::cout<<t<<' '<<fast_plus(t, aa, m);
	return 0;
}
