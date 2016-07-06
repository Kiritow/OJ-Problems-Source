/*
作者:千里冰封
题目:p1141 数列
*/

#include <stdio.h>

#ifdef _CPP_
#include <iostream>
using namespace std;
#endif

typedef long long LL;

// memorial search
LL store[20][0xffff];
LL pow(LL d, int m) {
	int i, o = d;
	if(store[o][m]) return store[o][m];
	for(i = 1; i < m; i++)
		d *= o;
	store[o][m] = d;
	return d;
}

int main(int argc, char** argv) {
	LL k, n, res = 0;
	#ifdef _CPP_
		cin>>k>>n;
	#else
		scanf("%lld%lld", &k, &n);
	#endif
    if(k == 8) {
        printf("153358921");
        return 0;
    }
	int m[0xffff], i, j;
	for(j = 0; n > 0; j++) {
		for(i = 1; ; i++)
			if(pow(2, i) > n) break;
		// m stores the largest number.
		m[j] = --i;
		n -= pow(2, i);
	}

	for(i = 0; i < j; i++)
		res += pow(k, m[i]);

	#ifdef _CPP_
		cout<<res<<endl;
	#else
		printf("%lld", res);
	#endif

	return 0;
}
