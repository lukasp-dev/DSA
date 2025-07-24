class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i=m-1, j=0;
        
        while(i>=0 && j<n){
            int curr = matrix[i][j];
            if (curr == target) return true;
            else if (curr > target) i--;
            else j++;
        }

        return false;
    }
};