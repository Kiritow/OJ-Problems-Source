class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        const int N = envelopes.size();

        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
            });

        vector<int> dp(N);
        for (int i = 0; i < N; i++) {
            dp[i] = 1;
        }
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};