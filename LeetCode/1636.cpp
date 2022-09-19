
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        map<int, set<int>> keys;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            auto iter = freq.find(nums[i]);
            if (iter != freq.end()) {
                keys[iter->second].erase(nums[i]);
                iter->second++;
                keys[iter->second].insert(nums[i]);
            }
            else {
                freq.insert_or_assign(nums[i], 1);
                keys[1].insert(nums[i]);
            }
        }

        vector<int> result;
        for (auto iter = keys.begin(); iter != keys.end(); iter++) {
            for (auto xiter = iter->second.rbegin(); xiter != iter->second.rend(); xiter++) {
                for (int i = 0; i < iter->first; i++) {
                    result.push_back(*xiter);
                }
            }
        }

        return result;
    }
};
