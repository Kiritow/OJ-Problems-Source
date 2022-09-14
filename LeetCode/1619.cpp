class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        int toRemove = n / 20;
        sort(arr.begin(), arr.end());

        int sum = 0;
        for (int i = toRemove; i < n - toRemove; i++) {
            sum += arr[i];
        }
        return (double)sum / (n - toRemove - toRemove);
    }
};
