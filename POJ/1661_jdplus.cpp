#include <stdio.h>
#include <stdlib.h>

#define MAXN 1010
#define INF 9000000

typedef struct platform{
	int x1;
	int x2;
	int high;
}Platform;

int compare (const void * p, const void * q){
	Platform * p1 = (Platform *)p;
	Platform * q1 = (Platform *)q;
	return p1->high - q1->high;
}

int Min (int a, int b){
	return (a < b) ? a : b;
}

int N, X, Y, MAX;
Platform plat[MAXN];
int dp[MAXN][2];         //dp[i][0]、dp[i][1]分别表示从第i个平台左、右边到地面的最短时间

void LeftMinTime (int i){    //计算从平台i左边到地面的最短时间
	int k = i - 1;
	while (k > 0 && plat[i].high - plat[k].high <= MAX){
		//如果平台i左边下面有平台，且两者相距不超过MAX
		if (plat[i].x1 >= plat[k].x1 && plat[i].x1 <= plat[k].x2){
			dp[i][0] = plat[i].high - plat[k].high + 
				Min (plat[i].x1 - plat[k].x1 + dp[k][0], plat[k].x2 - plat[i].x1 + dp[k][1]);
			return;
		}
		else
			--k;
	}
	//如果平台i左边下面没有平台，或者两者相距超过了MAX
	if (plat[i].high - plat[k].high > MAX)
		dp[i][0] = INF;
	else
		dp[i][0] = plat[i].high;
}

void RightMinTime (int i){   //计算从平台i右边到地面的最短时间
	int k = i - 1;
	while (k > 0 && plat[i].high - plat[k].high <= MAX){
		//如果平台i右边下面有平台，且两者相距不超过MAX
		if (plat[i].x2 >= plat[k].x1 && plat[i].x2 <= plat[k].x2){
			dp[i][1] = plat[i].high - plat[k].high + 
				Min (plat[i].x2 - plat[k].x1 + dp[k][0], plat[k].x2 - plat[i].x2 + dp[k][1]);
			return;
		}
		else
			--k;
	}
	//如果平台i右边下面没有平台，或者两者相距超过了MAX
	if (plat[i].high - plat[k].high > MAX)
		dp[i][1] = INF;
	else
		dp[i][1] = plat[i].high;
}

int ShortestTime (){
	int i, j;

	for (i=1; i<=N+1; ++i){
		LeftMinTime (i);
		RightMinTime (i);
	}
	return Min (dp[N+1][0], dp[N+1][1]);
}

int main(void){
	int t;
	int i;
	while (scanf ("%d", &t) != EOF){
		while (t-- != 0){
			scanf ("%d%d%d%d", &N, &X, &Y, &MAX);
			for (i=1; i<=N; ++i){
				scanf ("%d%d%d", &plat[i].x1, &plat[i].x2, &plat[i].high);
			}
			plat[0].high = 0;
			plat[0].x1 = -20000;
			plat[0].x2 = 20000;
			plat[N+1].high = Y;
			plat[N+1].x1 = X;
			plat[N+1].x2 = X;
			//根据平台高度按从低到高排序
			qsort (plat, N+2, sizeof(Platform), compare);
			printf ("%d\n", ShortestTime());
		}
	}

	return 0;
}
