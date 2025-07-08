class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int mid = 0;
        int ret = 0;
        if(n%2 == 1) mid = mat[n/2][n/2];

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(n%2==1 && i==n/2 && j==n/2) continue;
                if(i == j) {
                    ret += mat[i][j];
                    ret += mat[i][n-j-1];
                }
            }
        }

        return ret+mid;
    }
};