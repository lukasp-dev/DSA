class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> result;

        vector<vector<int>> points;
        for (vector<int>& el : buildings) {
            int& left = el[0];
            int& right = el[1];
            int& height = el[2];
            points.push_back({left, height, +1});
            points.push_back({right, height, -1});
        }

        sort(points.begin(), points.end(), [](auto& a, auto& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            if (a[2] != b[2]) return a[2] > b[2];
            return a[1] * a[2] > b[1] * b[2];
        });

        multiset<int> heights = {0}; 
        int prevH = 0;

        for (vector<int>& point : points) {
            int& x = point[0];
            int& y = point[1];
            int& delta = point[2];

            if (delta == 1) {
                heights.insert(y);
            } else {
                auto it = heights.find(y);
                if (it != heights.end()) heights.erase(it);
            }

            int top = *heights.rbegin();
            if (top != prevH) {
                result.push_back({x, top});
                prevH = top;
            }
        }

        return result;
    }
};
