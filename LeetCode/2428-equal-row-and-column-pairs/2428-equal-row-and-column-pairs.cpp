class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        map<vector<int>, int> lookup;
        int count = 0;

        for(int i=0; i<n; i++){
            vector<int> row;
            for(int j=0; j<m; j++){
                row.push_back(grid[i][j]);
            }
            lookup[row]++;
        }

        for(int i=0; i<n; i++){
            vector<int> col;
            for(int j=0; j<m; j++){
                col.push_back(grid[j][i]);
            }
            if(lookup.count(col)) count+=lookup[col];
        }

        return count;
    }
};