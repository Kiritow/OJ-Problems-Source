#include<stdio.h>
#include<memory.h>
int max(int x, int y){return x > y ? x : y;}
int min(int x, int y){return x < y ? x : y;}
int main(int argc, char* argv[]){
    const int size = 0xf;
	const int MIN = -0xfff;
    int a[size], dp[size][size], m, k;
    memset(a,  MIN, size);
    memset(dp, MIN, size);
    scanf("%d%d", &m, &k);
    int i, j, x;
    for(i = 1; i <= m; i++){
        int s;
        scanf("%d", &s);
        a[i] = a[i - 1] + s;
    }
    for(i = 1; i <= m; i++){
        for(j = i; j <= k; j++){
			dp[i][j] = MIN;
            for(x = i; x <= j; x++){
				dp[i][j] = min(dp[i][j], a[i] - a[x + 1]);
            }
        }
    }
    for(i = 1; i <= k; i++)
        printf("%d %d\n", dp[k][i]);
    scanf("%d%d");
    return 0;
}
                // f[i][j] = min{max(f[k][j-1], sum(k+1, i)), j<k<i}
/*
int i,j,k;
    int mintime=INT_MIN;
    
    for(i = 0 ; i < n ; ++i)
    {
        for(j = i ; j < m ;++j)
        {
            for(k = i ; k <= j ; ++k)
            {
                sum[i][j]+=book[k];
            }
        }
    }
    for(i = 1 ; i <= n ; ++i)
        dp[i][1] = sum[0][i-1];
    for(j = 2 ; j <= m ; ++j)
    {
        for(i = j ; i <= n ; ++i)
        {
            dp[i][j]= INT_MAX;
            for(k = j ; k <= i ; ++k)
            {
                mintime = max(dp[k][j-1],sum[k][i-1]);
                dp[i][j] = min(dp[i][j],mintime);
            }
        }
    }
    return dp[n][m];
*/
