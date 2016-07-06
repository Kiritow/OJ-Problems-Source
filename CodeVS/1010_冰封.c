#include <stdio.h>

int xx, yy, hx, hy;
int cnt;
int a[1000][1000];
void dfs(int x, int y);

int main(int argc, char* argv[]){
	scanf("%i%i%i%i", &xx, &yy, &hx, &hy);
	a[hx][hy] = 1;

	a[hx + 1][hy + 2] = 1;
	a[hx + 1][hy - 2] = 1;
	a[hx - 1][hy + 2] = 1;
	a[hx - 1][hy - 2] = 1;
	
	a[hx + 2][hy + 1] = 1;
	a[hx + 2][hy - 1] = 1;
	a[hx - 2][hy - 1] = 1;
	a[hx - 2][hy + 1] = 1;

	dfs(0, 0);
	printf("%i", cnt);
	return 0;
}

void dfs(int x, int y){
	if(x == xx || y == yy){
		cnt++;
		return ;
	}
	if(x < 0 || y < 0 || x >= xx || y >= yy || a[x][y] == 1){
		return ;
	}
	a[x][y] = 1;
	dfs(x + 1, y);
	dfs(x, y + 1);
	a[x][y] = 0;
}
