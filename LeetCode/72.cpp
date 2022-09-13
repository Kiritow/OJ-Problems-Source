class Solution {
public:
    int dp[501][501];

    int minDistance(string word1, string word2) {
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=word1.size(); i++) {
            dp[i][0] = i;
        }
        for(int i=1; i<=word2.size(); i++) {
            dp[0][i] = i;
        }

        for(int i=1;i<=word1.size(); i++) {
            for(int j=1; j<=word2.size(); j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
                }
            }
        }

        /*
        for(int i=0; i<= word1.size(); i++) {
            for(int j=0; j<=word2.size(); j++) {
                printf("%d ", dp[i][j]);
            }
            printf("\n");
        }
        */
        return dp[word1.size()][word2.size()];
    }
};
