	public int combinationSum4(int[] nums, int target) {
		int dp[] = new int[target + 1];
		for (int i = 0; i <= target; i++) {
			for (int k = 0; k < nums.length; k++) {
				if (i - nums[k] > 0) {
					dp[i] += dp[i - nums[k]];
				} else if (i - nums[k] == 0) {
					dp[i] += 1;
				}

			}
		}
		return dp[target];
	}
