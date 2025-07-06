class Solution {
public:
    typedef long long ll;

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points), end(points), [](const vector<int> &o1, const vector<int> &o2) {
            return (o1[1] < o2[1]);
        });

        ll end = -1e18;
        ll count = 0;

        for(int i=0; i<points.size(); i++){
            vector<int>& curr = points[i];
            ll balloonStart = curr[0];
            ll balloonEnd = curr[1];

            if(end < balloonStart){
                count++;
                end = balloonEnd;
            }
        }

        return count;
    }
};