class Solution {
public:
    int maxProduct(vector<string>& words) {
        const int N = words.size();
        vector<int32_t> mark;
        for (auto& s : words) {
            int32_t m = 0;
            for (auto& c : s) {
                m |= 1 << (c - 'a');
            }
            mark.push_back(m);
        }

        size_t ret = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (!(mark[i] & mark[j])) {
                    ret = max(ret, words[i].size() * words[j].size());
                }
            }
        }
        return ret;
    }
};