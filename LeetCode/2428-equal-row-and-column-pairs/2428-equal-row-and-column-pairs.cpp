class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> lookup;
        int n = grid.size();

        for(int i=0; i<n; ++i) {
            string str;
            for(int j=0; j<n; ++j) {
                str += to_string(grid[i][j]) + "#";
            }
            lookup[str]++;
        }

        int ret = 0;

        for(int i=0; i<n; i++) {
            string str;
            for(int j=0; j<n; j++) {
                str += to_string(grid[j][i]) + "#";
            }
            if(lookup.count(str)) {
                ret += lookup[str];
                cout << str << "\n";
            }
        }

        return ret;
    }
};

// 250 78 253
// 334 252 253
// 250 253 253