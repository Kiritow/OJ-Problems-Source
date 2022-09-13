class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> starts, ends;
        for (auto& vec : intervals) {
            starts.push_back(vec[0]);
            ends.push_back(vec[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int needRoom = 0;
        int maxRoom = 0;
        for (int i = 0, j = 0; i < starts.size() && j < ends.size();) {
            if (starts[i] < ends[j]) {
                needRoom++;
                maxRoom = max(maxRoom, needRoom);
                i++;
                continue;
            }

            if (starts[i] > ends[j]) {
                needRoom--;
                j++;
                continue;
            }

            i++;
            j++;
        }

        return maxRoom;
    }
};
