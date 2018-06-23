#include <algorithm>

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.first < b.first;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector< pair<int, int> > vp;
        for (int i = 0; i < len; i++)
        {
            vp.push_back(std::make_pair(nums[i], i));
        }
        sort(vp.begin(), vp.end(), cmp);
        
        int L = 0;
        int R = len - 1;
        while (L < R)
        {
            int sum = vp[L].first + vp[R].first;
            if (sum == target)
            {
                vector<int> v;
                v.push_back(vp[L].second);
                v.push_back(vp[R].second);
                return v;
            }
            else if (sum < target)
            {
                L++;
            }
            else if (sum > target)
            {
                R--;
            }
        }
    }
};
