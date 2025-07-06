class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int l = newInterval[0], r = newInterval[1];
        int finalL = l, finalR = r, leftI = -1, rightI = -1;

        for(int i=0; i<intervals.size(); i++){
            vector<int>& curr = intervals[i];
            int currLeft = curr[0], currRight = curr[1];

            if(currRight < l) continue;               
            if(currLeft > r) break;                  
            
            if(leftI == -1) leftI = i;                
            rightI = i;                               
            finalL = min(finalL, currLeft);           
            finalR = max(finalR, currRight);          
        }

        
        if(leftI == -1){  
            for(int i = 0; i < intervals.size(); ++i){
                if(newInterval[0] < intervals[i][0]){
                    intervals.insert(intervals.begin() + i, newInterval);
                    return intervals;
                }
            }
            intervals.push_back(newInterval);  // 끝에 삽입
            return intervals;
        }

        intervals.erase(intervals.begin()+leftI, intervals.begin()+rightI+1);
        intervals.insert(intervals.begin()+leftI, {finalL, finalR});

        return intervals;
    }
};