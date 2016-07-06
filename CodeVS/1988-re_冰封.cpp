#include<stdio.h>

const int size = 1000;

typedef struct {
	long num;
	short time;
	bool isEgg;
} bugs ;

int main(int argc, char* argv[]) {
	long x, y, z, res = 0;
	bugs a[size];
	int idx = 1;
	for(int i = 0; i < size; i++) {
		a[i].num = 0;
		a[i].time = 0;
		a[i].isEgg = true;
	}
	scanf("%ld%ld%ld", &x, &y, &z);
	a[0].time = x;
	a[0].num = 1;
	a[0].isEgg = false;
	res++;
	while(z--) {
		int cnt = 0;
		for(int i = 0; i < idx; i++) {
			a[i].time--;
//			printf("currently is No.%i, it`s %s, %i days left.\n",
//					i, a[i].isEgg ? "egg" : "bug",
//					a[i].time);
			if(a[i].time < 1) {
				if(a[i].isEgg)
					a[i].isEgg = false;
				else {
					cnt++;
					a[idx + cnt].time = 2;
					a[idx + cnt].num = y * a[i].num;
				}
				a[i].time = x;
			}
		}
		idx += cnt;
	}
	for(int i = 0; i < size; i++)
		if(!a[i].isEgg)
			res += a[i].num;
	printf("%ld", res);
	return 0;
}
