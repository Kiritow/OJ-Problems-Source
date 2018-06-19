#include <stdlib.h>
#include <string.h>
typedef struct pack
{
    int val;
    int pos;
}pack;

int qcmp(const void* a, const void* b)
{
    return ((pack*)a)->val - ((pack*)b)->val;
}

int* twoSum(int* nums, int numsSize, int target) {
    pack* p = (pack*)malloc(sizeof(pack)*numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        p[i].val = nums[i];
        p[i].pos = i;
    }
    qsort(p, numsSize, sizeof(pack), qcmp);

    int L = 0;
    int R = numsSize - 1;
    while (L < R)
    {
        int sum = p[L].val + p[R].val;
        if (sum == target)
        {
            int* m = (int*)malloc(sizeof(int) * 2);
            m[0] = p[L].pos;
            m[1] = p[R].pos;
            return m;
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
    
    return NULL;
}
