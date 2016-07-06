#include<stdio.h>

const int SIZE = 100;

struct S {
	public:
	int x1;
	int x2;
	int x5;
	S() {
		x1 = 0;
		x2 = 0;
		x5 = 0;
	}
	void setValue(int a, int b, int c) {
		x1 = a;
		x2 = b;
		x5 = c;
	}
};

S a[SIZE];
int cnt;

void dfs(int l,int x1, int x2, int x5){
	if(!l) {
		for(int i = 0; i < cnt; i++){
			if(a[i].x1 == x1 && a[i].x2 == x2 && a[i].x5 == x5)
				return;
		}
		a[cnt].setValue(x1,x2,x5);
		cnt++;
	}
	if(l >= 5)
		dfs(l - 5, x1, x2, x5 + 1);
	if(l >= 2)
		dfs(l - 2, x1, x2 + 1, x5);
	if(l >= 1)
		dfs(l - 1, x1 + 1, x2, x5);	
}

int main(int argc,char** argv){
	int t;
	scanf("%d", &t);
	dfs(t,0,0,0);
	for(int i = cnt-1; i >= 0; i--)
		printf("%03d%12d%12d%12d\n", cnt-i, a[i].x1, a[i].x2, a[i].x5);
	return 0;
}
