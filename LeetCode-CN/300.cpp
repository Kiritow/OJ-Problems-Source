class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N);
        for (int i = 0; i < N; i++) {
            dp[i] = 1;
        }
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};