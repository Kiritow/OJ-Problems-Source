class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (S < -1000 || S>1000) return 0;

        int sz = nums.size();
        int msz = sizeof(int) * 2048;
        int _bin[2048] = { 0 };
        int _xbin[2048] = { 0 };
        int* p = _bin;
        int* q = _xbin;
        memset(p, 0, msz);
        p[1000] = 1;
        
        for (int i = 0; i < sz; i++)
        {
            memset(q, 0, msz);
            for (int j = 0; j < 2048; j++)
            {
                if (p[j])
                {
                    //printf("p[%d]=%d\n", p[j]);
                    // now=j-1000;
                    int L = j - nums[i]; // now-nums[i]+1000
                    int R = j + nums[i];
                    q[L] += p[j];
                    q[R] += p[j];
                    //printf("q[%d]=%d\n", L, q[L]);
                    //printf("q[%d]=%d\n", R, q[R]);
                }
            }
            std::swap(p, q);
        }
        return p[S + 1000];
    }
};
