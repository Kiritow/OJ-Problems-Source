class Solution {
public:
    // dp[i][j]: string from i to j is palindromic
    // dp[i][j]=true if dp[i+1][j-1]==true && s[i]==s[j]
    static bool dp[1001][1001];

    string longestPalindrome(string s) {
        int sz = s.size();
        memset(dp, false, sizeof(dp));

        int max_len = -1;
        int begin_at = -1;

        for (int i = 0; i < sz - 1; i++)
        {
            dp[i][i] = true;
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                max_len = 2;
                begin_at = i;
            }
        }

        for (int L = 3; L <= sz; L++)
        {
            for (int i = 0; i <= sz - L; i++)
            {
                if (dp[i + 1][i + L - 2] && s[i] == s[i + L - 1])
                {
                    dp[i][i + L - 1] = true;
                    max_len = L;
                    begin_at = i;
                }
            }
        }
        
        // debug
        // cout << begin_at << " " << max_len << endl;
        if (max_len == -1)
        {
            return s.substr(0, 1);
        }
        return s.substr(begin_at, max_len);
    }
};

// decl
bool Solution::dp[1001][1001];
