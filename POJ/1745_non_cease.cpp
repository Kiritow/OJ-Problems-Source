#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define N 10002
#define K 102

int num[N], n, k;
bool dp[N][K];

void Init()
{
   int i;

   scanf("%d%d", &n, &k);
   for(i = 1; i <= n; i++)
	   scanf("%d", &num[i]);
}

bool Solve()
{
	int i, j;

	memset(dp, false, sizeof(dp));
	dp[0][0] = true;
	for(i = 1; i <= n; i++){
		for(j = 0; j < k; j++){
			if(dp[i-1][j]){
			   dp[i][abs(j + num[i]) % k] = true;
			   dp[i][abs(j - num[i]) % k] = true;
			}
		}
	}
	return dp[n][0];
}

int main()
{
   Init();
   if(Solve())
	   printf("Divisible\n");
   else 
	   printf("Not divisible\n");
   return 0;
}
