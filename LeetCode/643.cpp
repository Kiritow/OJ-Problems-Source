class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		int n = nums.size();
		int sum = 0;
		for (int i = 0; i < k; i++)
		{
			sum += nums[i];
		}
		int current = sum;
		int max = current;
		for (int begin = 1; begin + k <= n; begin++)
		{
			current = current - nums[begin - 1] + nums[begin + k - 1];
			if (current > max)
			{
				max = current;
			}
		}
		return (double)max / k;
	}
};
