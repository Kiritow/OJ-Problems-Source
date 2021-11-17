
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<pair<int, int>> dp(N);  // 以i为结尾的LIS长度, 这个长度出现的次数
        for (int i = 0; i < N; i++) {
            dp[i] = { 1,1 };
        }
        for (int i = 1; i < N; i++) {
            int count = 1;
            int maxLastLen = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j].first == maxLastLen)
                    {
                        count += dp[j].second;
                    }
                    else if (dp[j].first > maxLastLen) {
                        count = dp[j].second;
                        maxLastLen = dp[j].first;
                    }
                }
            }
            dp[i].first = maxLastLen + 1;
            dp[i].second = count;
        }

        int maxFirst = 0;
        for (auto& p : dp) {
            maxFirst = max(maxFirst, p.first);
        }

        int cntSecond = 0;
        for (auto& p : dp) {
            if (p.first == maxFirst) {
                cntSecond += p.second;
            }
        }

        return cntSecond;
    }
};
