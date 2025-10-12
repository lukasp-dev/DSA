class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> rowsMap;
        map<vector<int>, int> colsMap; 
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            vector<int> rows;
            for(int j=0; j<m; j++){
                rows.push_back(grid[i][j]);
            }
            rowsMap[rows]++;
        }

        for(int i=0; i<n; i++){
            vector<int> cols;
            for(int j=0; j<m; j++){
                cols.push_back(grid[j][i]);
            }
            colsMap[cols]++;
        }

        int cnt = 0;

        for(auto it : rowsMap){
            if(colsMap.find(it.first) != colsMap.end()){ // it exists
                cnt += it.second*colsMap[it.first];
            }
        }

        return cnt;
    }
};

// we take the max of the freq