class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return true;

        sort(intervals.begin(), intervals.end());

        for(int i=0; i<intervals.size()-1; i++){
            int currEnd = intervals[i][1];
            int nextStart = intervals[i+1][0];

            if(currEnd > nextStart) return false;
        }

        return true;
    }
};