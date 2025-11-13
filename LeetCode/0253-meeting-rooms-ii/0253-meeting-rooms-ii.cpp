class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> start;
        vector<int> end;

        for(auto interval : intervals){
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int count = 0;
        int endPtr = 0;

        for(int i=0; i<start.size(); i++){
            if(start[i] < end[endPtr]){
                count++;
            }else{
                endPtr++;
            }
        }

        return count;
    }
};