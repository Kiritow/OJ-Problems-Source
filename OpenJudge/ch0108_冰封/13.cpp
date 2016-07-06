#include<stdio.h>
#include<algorithm>
#define FUCK 100

using namespace std;

char a[102][102];

int mine(int n,int m){
	int cnt = 0;
	if(a[n][m] == '*') {
		return FUCK;
	}
	else {
		if(a[n+1][m]  ==  '*')cnt++;
		if(a[n-1][m]  ==  '*')cnt++;
		if(a[n][m+1]  ==  '*')cnt++;
		if(a[n][m-1]  ==  '*')cnt++;
		if(a[n+1][m+1] == '*')cnt++;
		if(a[n-1][m-1] == '*')cnt++;
		if(a[n-1][m+1] == '*')cnt++;
		if(a[n+1][m-1] == '*')cnt++;
	}
	return cnt;
}

int main(void){
	int N,M;
	scanf("%d %d",&N,&M);
	N++;M++;
	for(int i = 1; i < N; i++){
		scanf("%s",(a[i]+1));
	}
	for(int i = 1; i < N; i++){
		for(int j = 1; j < M; j++){
			int fuck = mine(i,j);
			if(fuck == FUCK){
				printf("*");
			}
			else {
				printf("%d",fuck);
			}
		}
		printf("\n");
	}
	//getchar();getchar();getchar();getchar();getchar();
	return 0;
}