class Solution {
public:
	int superEggDrop(int K, int N) {
		// dp[i][j] 用i个鸡蛋 在j步数内能走多少层
		dp = new int*[K + 1];
		for (int i = 1; i <= K; i++)
		{
			dp[i] = new int[N + 1];
			dp[i][0] = 0;
			dp[i][1] = 1;
		}
		for (int i = 1; i <= N; i++)
		{
			dp[1][i] = i;
		}

		for (int k = 2; k <= K; k++)
		{
			/* // O(n*n*k). TLE
			for(int n=2;n<=N;n++)
			{
				int min_value = INT_MAX;
				for (int j = 2; j <= n; j++)
				{
					min_value = min(min_value, max(dp[k - 1][j - 1], dp[k][n - j]) + 1);
					printf("max(dp[%d][%d]=%d,dp[%d][%d]=%d)+1=%d\n", 
						k - 1, j - 1, dp[k-1][j-1],
						k, n - j, dp[k][n-j],
						max(dp[k - 1][j - 1], dp[k][n - j]) + 1 );
				}
			}
			*/
			
			for (int step = 2; step <= N; step++)
			{
				dp[k][step] = dp[k - 1][step - 1] // 在随便一层丢下去,碎了,则用k-1个鸡蛋,少一步能覆盖的数量表示这层下面有多少层
					+ dp[k][step - 1] // 还是这层丢下去,没碎,那么就是k个鸡蛋,少一步能覆盖的数量表示这层上面有多少层
					+ 1; // 就是这层自己
			}
		}

		//print_table(K, N);

		for (int step = 1; step <= N; step++)
		{
			if (dp[K][step] >= N) return step;
		}
	}
	void print_table(int K, int N)
	{
		printf("DATA ");
		for (int j = 1; j <= N; j++)
		{
			printf("%2d ", j);
		}
		printf("\n");
		for (int i = 1; i <= K; i++)
		{
			printf("K=%2d ", i);
			for (int j = 1; j <= N; j++)
			{
				printf("%2d ", dp[i][j]);
			}
			printf("\n");
		}
	}
private:
	int** dp;
};
