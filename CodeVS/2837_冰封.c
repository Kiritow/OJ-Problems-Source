/*
作者:千里冰封
题目:p2837 考前复习
*/

#include <stdio.h>
#include <string.h>
const int size = 0xfffff;
int n, m;
int h[size], v[size], dp[size];

int max(int x, int y){
	return x > y ? x : y;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &h[i], &v[i]);
    }

    for(int i = 0; i < n; i++)
        for(int j = m; j >= h[i]; j--)
            dp[j] = max(dp[j], dp[j - h[i]] + v[i]);
    printf("%d\n", dp[m]);
    return 0;
}
