class Solution {
private:
    pair<int, int> split(string& time) {
        string hour = time.substr(0, 2);
        string min = time.substr(3, 2);

        return {stoi(hour), stoi(min)};
    }

    struct cmp {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            if(a.first != b.first) {
                return a.first < b.first;
            } else {
                return a.second < b.second;
            }
        }
    };

public:
    int findMinDifference(vector<string>& timePoints) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

        int minTimeDiff = 1440;

        for(string& timePoint : timePoints) {
            pair<int, int> timePair = split(timePoint);
            pq.push(timePair);
        }

        pair<int, int> prev = pq.top(); pq.pop();
        int firstMinutes = prev.first*60 + prev.second;
        int lastMinutes;

        while(!pq.empty()) {
            pair<int, int> curr = pq.top();
            lastMinutes = curr.first*60 + curr.second;
            int diff = (prev.first*60 + prev.second) - (curr.first*60 + curr.second);
            minTimeDiff = min(minTimeDiff, diff);
            prev = curr;
            pq.pop();
        }

        int circularDiff = (1440 - firstMinutes) + lastMinutes;
        minTimeDiff = min(minTimeDiff, circularDiff);

        return minTimeDiff;
    }
};