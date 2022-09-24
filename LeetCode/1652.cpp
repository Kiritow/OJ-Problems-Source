
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if (k == 0) {
            return vector<int>(code.size(), 0);
        }

        int n = code.size();

        vector<int> result;

        if (k > 0) {
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 0; j < k; j++) {
                    int index = (i + 1 + j) % n;
                    sum += code[index];
                }
                result.push_back(sum);
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 0; j < -k; j++) {
                    int index = (i - 1 - j);
                    if (index < 0) index += n;
                    sum += code[index];
                }
                result.push_back(sum);
            }
        }

        return result;
    }
};
