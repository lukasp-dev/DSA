class Solution {
private:
    struct cmp {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            int distanceA = a[0]*a[0] + a[1]*a[1];
            int distanceB = b[0]*b[0] + b[1]*b[1];

            return distanceA < distanceB;
        }
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> maxHeap;

        for(auto& point : points) {
            maxHeap.push(point);
            if(maxHeap.size() > k) maxHeap.pop();
        }

        vector<vector<int>> ret;
        while(!maxHeap.empty()) {
            ret.push_back(maxHeap.top());
            maxHeap.pop();
        }

        return ret;
    }
};