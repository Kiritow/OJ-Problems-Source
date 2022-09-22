class Solution {
public:
    bool stepSearch(vector<int>& arr, vector<vector<int>>& pieces, vector<bool>& visited, int startIndex) {
        for (int i = 0; i < pieces.size(); i++)
        {
            if (visited[i]) continue;
            if (pieces[i][0] != arr[startIndex]) continue;
            if (startIndex + pieces[i].size() > arr.size()) continue;

            // check all elements
            int j = 1;
            for (; j < pieces[i].size(); j++) {
                if (arr[startIndex + j] != pieces[i][j]) break;
            }
            if (j != pieces[i].size()) {
                continue;
            }

            if (arr.size() == startIndex + pieces[i].size()) return true;

            // step down
            visited[i] = true;
            bool ret = stepSearch(arr, pieces, visited, startIndex + pieces[i].size());
            visited[i] = false;

            if (ret) return true;
        }

        return false;
    }

    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        vector<bool> visited(pieces.size(), false);

        return stepSearch(arr, pieces, visited, 0);
    }
};
