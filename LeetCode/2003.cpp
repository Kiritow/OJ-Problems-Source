
class Solution {
public:
    void updateSubtree(vector<bool>& subtree, const vector<vector<int>>& childs, const vector<int>& nums, int rootIndex, int skipIndex) {
        //printf("updateSubtree: %d\n", rootIndex);
        subtree[nums[rootIndex]] = true;
        for (auto& childIndex : childs[rootIndex]) {
            if (skipIndex != -1 && skipIndex == childIndex) {
                //printf("skip %d\n", skipIndex);
                continue;
            }
            updateSubtree(subtree, childs, nums, childIndex, skipIndex);
        }
    }

    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        const int n = parents.size();
        vector<int> result(n, 1);
        auto iter = find(nums.begin(), nums.end(), 1);
        if (iter == nums.end()) {
            return result;
        }

        vector<vector<int>> childs(n);
        for (int i = 0; i < n; i++) {
            if (parents[i] == -1) continue;
            childs[parents[i]].push_back(i);
        }

        vector<bool> subtreeValues(100002);
        
        const int beginIndex = iter - nums.begin();
        int currentIndex = beginIndex;
        int skipIndex = -1;
        int nextGap = 1;
        while (currentIndex != -1) {
            updateSubtree(subtreeValues, childs, nums, currentIndex, skipIndex);
            for (; nextGap < 100002; nextGap++) {
                if (!subtreeValues[nextGap]) {
                    result[currentIndex] = nextGap;
                    break;
                }
            }
            skipIndex = currentIndex;
            currentIndex = parents[currentIndex];
        }

        return result;
    }
};
