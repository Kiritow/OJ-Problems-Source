#include <algorithm>
#include <unordered_map>
const long long MOD = 1000000000 + 7;
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        std::sort(A.begin(), A.end());
        std::unordered_map<long long, long long> mp;
        std::unordered_map<long long, long long>::iterator iter;

        int n = A.size();
        for (int i = 0; i < n; i++)
        {
            mp.insert(std::make_pair(A[i], 1));
        }

        for (int i = 0; i < n; i++)
        {
            long long target = A[i];
            long long cnt = 1;
            for (int j = 0; j <= i; j++)
            {
                long long now = A[j];
                if (now*now > target) break;
                if (target%now != 0) continue;
                int another = target / now;
                long long dp_now, dp_another;

                //printf("now=%d, another=%d\n", now, another);

                // If number is not in INPUT LIST, then it should be ZERO
                if ((iter = mp.find(now)) != mp.end())
                {
                    dp_now = iter->second;
                }
                else
                {
                    dp_now = 0;
                }
                if ((iter = mp.find(another)) != mp.end())
                {
                    dp_another = iter->second;
                }
                else
                {
                    dp_another = 0;
                }

                if (now == another)
                {
                    //printf("cnt= %d + %d*%d\n", cnt, dp_now, dp_another);
                    cnt = (cnt + dp_now * dp_another) % MOD;
                }
                else
                {
                    //printf("cnt= %d + %d*%d*2\n", cnt, dp_now, dp_another);
                    cnt = (cnt + dp_now * dp_another * 2) % MOD;
                }
            }
            //printf("mp[%d]=%d\n", target, cnt + 1);
            mp[target] = cnt;
        }

        long long sum = 0;
        for (iter = mp.begin(); iter != mp.end(); ++iter)
        {
            sum = (sum + iter->second) % MOD;
        }

        return sum;
    }
};
