private boolean compare(int[] result1, int pos1, int[] result2, int pos2) {
    for ( ; pos1 < result1.length && pos2 < result2.length; pos1++, pos2++){
        if (result1[pos1] > result2[pos2])
            return true;
        if (result1[pos1] < result2[pos2])
            return false;
    }
    return pos1 != result1.length;
}

private int[] findMaxKValue(int[] nums, int k) {
    int[] result = new int[k];
    int len = 0;
    for (int i = 0; i < nums.length; i++){
        while (len > 0 && len + nums.length - i > k && result[len - 1] < nums[i]){
            len--;
        }
        if (len < k)
            result[len++] = nums[i];
    }
    return result;
}

public int[] maxNumber(int[] nums1, int[] nums2, int k){
    int[] result = new int[k];
    for (int i = Math.max(k - nums2.length, 0); i <= Math.min(nums1.length, k); i++){
        int[] result1 = findMaxKValue(nums1, i);
        int[] result2 = findMaxKValue(nums2, k - i);
        // 对两个数组执行merge操作
        int[] temp = new int[k];
        int pos1 = 0;
        int pos2 = 0;
        int tpos = 0;
        while (pos1 < result1.length || pos2 < result2.length){
            temp[tpos++] = compare(result1, pos1, result2, pos2) ? result1[pos1++] : result2[pos2++];
        }
        if (!compare(result, 0, temp, 0))
            result = temp;
    }
    return result;
}
