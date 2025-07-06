class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> times;
        for(vector<int>& it : intervals){
            times.emplace_back(it[0], +1);
            times.emplace_back(it[1], -1);
        }

        sort(times.begin(), times.end());

        int numOfMeetingRooms = 0, curr = 0;

        for(auto &[time, delta] : times){
            curr += delta;
            numOfMeetingRooms = max(curr, numOfMeetingRooms);
        }

        return numOfMeetingRooms;
    }
};