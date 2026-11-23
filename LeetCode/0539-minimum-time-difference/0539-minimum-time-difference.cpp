class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        
        for(string& time : timePoints) {
            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3, 2));

            int convert = hour*60 + minute;
            times.push_back(convert);
        }

        sort(times.begin(), times.end());

        int n = times.size();

        int diff = 1e9;

        for(int i=0; i<n-1; i++) {
            diff = min(diff, times[i+1] - times[i]);
        }

        return min(diff, 1440 - times.back() + times.front());
    }
};