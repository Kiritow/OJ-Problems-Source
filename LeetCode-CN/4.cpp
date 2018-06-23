#include <algorithm>
class Solution {
public:
    void forward_until(vector<int>& nums1, vector<int>& nums2,
        int lenA,int lenB,
        int& idxA, int& idxB, int& passed, int midLen)
    {
        while (idxA < lenA&&idxB < lenB && passed < midLen)
        {
            if (nums1[idxA] < nums2[idxB])
            {
                idxA++;
                passed++;
            }
            else
            {
                idxB++;
                passed++;
            }
        }
        while (idxA < lenA&&passed < midLen)
        {
            idxA++;
            passed++;
        }
        while (idxB < lenB&&passed < midLen)
        {
            idxB++;
            passed++;
        }
    }

    int getCurrent(vector<int>& nums1, vector<int>& nums2, 
        int lenA,int lenB,
        int idxA, int idxB)
    {
        if (idxA < lenA&&idxB < lenB)
        {
            return std::min(nums1[idxA], nums2[idxB]);
        }
        else if (idxA < lenA)
        {
            return nums1[idxA];
        }
        else
        {
            return nums2[idxB];
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int lenA = nums1.size();
        int lenB = nums2.size();
        int sumLen = lenA + lenB;
        int midLen = sumLen / 2 - (1 - (sumLen % 2));
        int idxA = 0;
        int idxB = 0;
        int passed = 0;
        
        forward_until(nums1, nums2, lenA, lenB, idxA, idxB, passed, midLen);

        if (sumLen % 2)
        {
            return getCurrent(nums1, nums2, lenA, lenB, idxA, idxB);
        }
        else
        {
            int step1 = getCurrent(nums1, nums2, lenA, lenB, idxA, idxB);
            
            forward_until(nums1, nums2, lenA, lenB, idxA, idxB, passed, midLen + 1);
            
            int step2 = getCurrent(nums1, nums2, lenA, lenB, idxA, idxB);

            return (step1 + step2) / 2.0;
        }
    }
};
