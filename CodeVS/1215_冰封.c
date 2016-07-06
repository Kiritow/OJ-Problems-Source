/*
作者:千里冰封
题目:p1215 迷宫
*/

#include <stdio.h>
#include <memory.h>

const int size = 30;

int dfs(char a[size][size], int s, char mark[size][size], int x, int y) {
	if(a[x][y] == 's')
		return 1;
	if(a[x][y] == '#')
		return 0;
	int i;
	if(x > 0 && !mark[x-1][y]) {
		mark[x-1][y] = 1;
		int as = dfs(a, s, mark, x-1, y);
		if(as) return as;
		mark[x-1][y] = 0;
	}
	if(y > 0 && !mark[x][y-1]) {
		mark[x][y-1] = 1;
		int as = dfs(a, s, mark, x, y-1);
		if(as) return as;
		mark[x][y-1] = 0;
	}
	if(y < s - 1 && !mark[x][y+1]) {
		mark[x][y+1] = 1;
		int as = dfs(a, s, mark, x, y+1);
		if(as) return as;
		mark[x][y+1] = 0;
	}
	if(x < s - 1 && !mark[x+1][y]) {
		mark[x+1][y] = 1;
		int as = dfs(a, s, mark, x+1, y);
		if(as) return as;
		mark[x+1][y] = 0;
	}
	return 0;
}

int main(int argc, char* argv[]) {
	int cnt;
	scanf("%d", &cnt);
	while(cnt--) {
		char a[size][size];
		char mark[size][size];
		int i, j, s;
		memset(a, 0, size * size);
		memset(mark, 0, size * size);
		scanf("%d", &s);
		for(i = 0; i < s; i++)
			scanf("%s", a[i]);
		
		printf("%s\n", dfs(a, s, mark, s-1, s-1) ? "YES" : "NO");
	}
	return 0;
}


/*

1 
7 
s...##. 
.#..... 
....... 
..#.... 
..#...# 
###...# 
......e

*/
