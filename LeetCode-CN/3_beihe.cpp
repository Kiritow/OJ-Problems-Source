class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, short> v;
        int max_num = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (v.find(s[i]) != v.end()) {
                if (max_num < v.size()) {
                    max_num = v.size();
                }
                i = v.find(s[i])->second + 1;
                v.clear();
            }
            if (i >= s.size()) {
                break;
            }
            v[s[i]] = i;
            if (max_num < v.size()) {
                max_num = v.size();
            }
        }
        return max_num;
    }
};
