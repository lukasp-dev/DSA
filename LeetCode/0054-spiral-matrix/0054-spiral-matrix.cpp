class Solution {
private:
    void goSpiral(vector<int>& order, vector<vector<int>>& matrix, int top, int bottom, int left, int right){
        if(top > bottom || left > right) return;

        // top
        for(int col = left; col <= right; ++col) {
            order.push_back(matrix[top][col]);
        }
        // right
        for(int row = top + 1; row <= bottom; ++row) {
            order.push_back(matrix[row][right]);
        }
        // bottom
        if(top < bottom) {
            for(int col = right - 1; col >= left; --col) {
                order.push_back(matrix[bottom][col]);;
            }
        } 
        
        // left
        if(left < right) {    
            for(int row = bottom - 1; row > top; --row) {
                order.push_back(matrix[row][left]);
            }
        }

        goSpiral(
            order,
            matrix,
            top + 1,
            bottom - 1,
            left + 1,
            right - 1
        );
    }

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> order;
        int n = matrix.size();
        int m = matrix[0].size();

        goSpiral(order, matrix, 0, n - 1, 0, m - 1);
        
        return order;
    }
};