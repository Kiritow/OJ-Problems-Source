#include <stdio.h>
#include <string.h>

char a[10000];
char mark[10000];

void dfs(int idx, char b[10000]) {
	int i;
	if(idx >= strlen(a)) {
		printf("%s\n", b);
		return ;
	}
	for(i = 0; i < strlen(a); i++) {
		if(!mark[i]) {
			mark[i] = 1;
			b[idx] = a[i];
			dfs(idx + 1, b);
			mark[i] = 0;
		}
	}
}

int main(int argc, char** argv) {
  scanf("%s", a);
  char b[10000];
  memset(b, 0, 10000);
  dfs(0, b);
  return 0;
}
