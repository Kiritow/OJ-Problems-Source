#include <stdio.h>

const int BIG = 0x3f3f3f3f;
const int size = 501;
int N, min = BIG, max = -BIG, to;
int a[size][size];
bool used[size];
int save[size][2];
int save_cnt;

void dfs(int c);
int get();
void test();

int main(int argc, char* argv[]){
	auto int M;
	auto int x, y, v;
	auto int fr;
//	test();
	scanf("%i%i", &N, &M);
	for(auto int i = 0; i < M; i++){
		scanf("%i%i%i", &x, &y, &v);
		a[x][y] = v;
	}
	scanf("%i%i", &fr, &to);
	used[fr] = true;
	dfs(fr);
	if(!save_cnt)
		printf("IMPOSSIBLE");
	else {
		int cur = 0;
		for(auto int i = 0; i < save_cnt; i++){
			int q = save[i][1] / save[i][0];
			if(q < save[cur][1] / save[cur][0])
				cur = q;
//			printf("save[%i][1] = %i, save[%i][0] = %i\n",i , save[i][1],i , save[i][0]);
		}
		max = save[cur][1];
		min = save[cur][0];
		get();
		if(min == 1)
			printf("%i", max);
		else
			printf("%i/%i", max, min);
	}
	return 0;
}

void dfs(int c) {
	if(c == to) {
//		printf("arrived.\n");
		save[save_cnt][0] = min;
		save[save_cnt][1] = max;
		save_cnt++;
		min = -BIG;
		max = BIG;
		return ;
	}
	for(auto int i = 0; i <= N; i++) {
		if(a[c][i] && !used[i]) {
			if(a[c][i] > max) max = a[c][i];
			if(a[c][i] < min) min = a[c][i];
			used[i] = true;
//			printf("from %i to %i\n", c, i);
			dfs(i);
			used[i] = false;
		}
	}
}

int get(){
	for(auto int i = 2; i <= max; i++){
		if(min % i == 0 && max % i == 0){
			min /= i;
			max /= i;
			i--;
		}
	}
}

void test(){
	max = 6;
	min = 3;
	get();
	printf("6 / 3 => %i / %i\n", max, min);
}
