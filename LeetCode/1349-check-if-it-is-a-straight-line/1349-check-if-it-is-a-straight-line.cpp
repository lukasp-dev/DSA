
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        long long dx = coordinates[1][0] - coordinates[0][0];
        long long dy = coordinates[1][1] - coordinates[0][1];

        for (int i = 2; i < coordinates.size(); i++) {
            long long x = coordinates[i][0] - coordinates[0][0];
            long long y = coordinates[i][1] - coordinates[0][1];

            if (dy * x != dx * y) {
                return false;
            }
        }

        return true;
    }
};
