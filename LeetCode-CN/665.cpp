class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int nrev = 0;

        for(int i=1; i<nums.size(); i++) {
            if (nums[i-1] > nums[i]) {
                if (nrev) return false;
                nrev++;

                if (i < 2) nums[i-1] = nums[i];
                else if (nums[i-2] <= nums[i]) {
                    nums[i-1] = nums[i-2];
                } else {
                    nums[i] = nums[i-1];
                }
            }
        }

        return nrev < 2;
    }
};
