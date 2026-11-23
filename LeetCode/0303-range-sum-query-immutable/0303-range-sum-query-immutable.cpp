class NumArray {
private: 
    vector<int> cummulativeSums;
public:
    NumArray(vector<int>& nums): cummulativeSums(nums.size()+1, 0) {
        for (size_t i = 0; i < nums.size(); ++i) {
            cummulativeSums[i + 1] = cummulativeSums[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return this->cummulativeSums[right+1]-this->cummulativeSums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

// [-2, 0,  3, -5, 2, -1]
// [0, -2, -2, 1, -4, -2, -3]

// [0, 2] -> 1
// [2, 5] -> -1
// [0, 5] -> -3