#include <stdio.h>
int matrix[5][5] = {
    {5, -1, -2, -1, -3},
    {-1, 5, -3, -2, -4},
    {-2, -3, 5, -2, -2},
    {-1, -2, -2, 5, -1},
    {-3, -4, -2, -1, 0},
};
char exchange[5] = {'A', 'C', 'G', 'T', ' '};
int Value (char m, char n){
    int R, C;
    int i;
    for (i=0; i<5; ++i){
        if (exchange[i] == m)
            R = i;
        if (exchange[i] == n)
            C = i;
    }
    return matrix[R][C];
}
int Max (int a, int b, int c){
    int max = (a > b) ? a : b;
    return (max > c) ? max : c;
}
int Similarity (char str1[], int length1, char str2[], int length2){
    int dp[110][110];
    int i, j;
    dp[0][0] = 0;
    for (i=1; i<=length1; ++i)
        dp[i][0] = dp[i-1][0] + Value (str1[i], ' ');
    for (i=1; i<=length2; ++i)
        dp[0][i] = dp[0][i-1] + Value (' ', str2[i]);
    for (i=1; i<=length1; ++i){
        for (j=1; j<=length2; ++j){
            if (str1[i] == str2[j]){
                dp[i][j] = dp[i-1][j-1] + Value (str1[i], str2[j]);
            }
            else{
                dp[i][j] = Max (dp[i-1][j] + Value (str1[i], ' '),
                                dp[i][j-1] + Value (' ', str2[j]),
                                dp[i-1][j-1] + Value (str1[i], str2[j]));
            }
        }
    }
    return dp[length1][length2];
}
int main(void){
    char str1[110];
    char str2[110];
    int length1;
    int length2;
    int T;
    int ans;
    while (scanf ("%d", &T) != EOF){
        while (T-- != 0){
            scanf ("%d%s", &length1, str1 + 1);
            scanf ("%d%s", &length2, str2 + 1);
            if (length1 > length2)
                ans = Similarity (str1, length1, str2, length2);
            else
                ans = Similarity (str2, length2, str1, length1);
            printf ("%d\n", ans);
        }
    }
    return 0;
}
