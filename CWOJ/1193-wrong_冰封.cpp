#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
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
			ret = (ret * a) % m;
		b >>= 1;
		a = fast_plus(a, a, m);
	}
	return ret;
}

int main() {
	LL n, m, t, a;
	std::cin.sync_with_stdio(false);
	std::cin>>a>>n>>m;
	t = fast_pow(a, n, m);
	std::cout<<t<<' '<<fast_plus(t, a, m)<<'\n';
	return 0;
}
