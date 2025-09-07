class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, 0);

        int left = 1;
        for(int i=0; i<n; i++){
            ret[i] = left;
            left *= nums[i];
        }

        int right = 1;
        for(int i = n-1; i>=0; i--){
            ret[i] *= right;
            right *= nums[i];
        }

        return ret;
    }
};